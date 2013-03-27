program vfplot
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  USE DLPLOT
  USE TOOLS
  USE VECTORS
  implicit none
  integer                  :: i,L,ix,iy,pos1,pos2
  character(len=128)       :: file
  real(8)                  :: Vx,Vy
  real(8),allocatable      :: dataX(:),dataY(:),xgrid(:),ygrid(:),zgrid(:,:)
  real(8)                  :: xmin,xmax
  real(8)                  :: ymin,ymax
  integer                  :: xsize,ysize
  type(vect2D),allocatable :: vfield(:,:)
  type(d_linked_list)      :: arrayVx,arrayVy
  logical                  :: wl=.false.,pgrid
  integer                  :: nl
  character(len=256),allocatable :: help_buffer(:)
  xmin=1.d0 ; xmax=10.d0 ; xsize=10
  ymin=1.d0 ; ymax=10.d0 ; ysize=10
  allocate(help_buffer(17))
  help_buffer=([&
       'NAME',&
       '  splot',&
       '',&
       'SYNOPSIS',&
       '  splot x=min:max:sizex [y=min:max:sizey] [file=value] [grid=value]',&
       '',&
       'DESCRIPTION',&
       '  Read an array *Z(:) on stdin and return a 3D plot (intensity&surface)',&
       '  using a grid on both X and Y build out of the specified dimension.',&
       '  The plot consist of a data set, in *file, and a gnuplot script to ',&
       '  plot it, *plot_file.',&
       ' ',&
       'OPTIONS',&
       '  x=[min:max:sizex] -- dimension of the X axis of the grid. ',&
       '  y=[min:max:sizey] -- dimension of the Y axis of the grid. If not specified is equal to X',&
       '  file=[new.plot]   -- file name of the plot. gnuplot script in plot_*file',&
       '  grid=[F]          -- if true write a file with continuous grid and data: X,Y,Z(X,Y)',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(file,"FILE",default="new.plot")
  call parse_cmd_variable(pgrid,"GRID",default=.false.)
  do i=1,command_argument_count()
     nml_var=get_cmd_variable(i)
     select case(nml_var%name)
     case("X")
        pos1=scan(nml_var%value,":")
        pos2=scan(nml_var%value(pos1+1:),":")
        if(nml_var%value(1:pos1-1)/="")read(nml_var%value(1:pos1-1),*)xmin
        if(nml_var%value(pos1+1:pos1+pos2-1)/="")read(nml_var%value(pos1+1:pos1+pos2-1),*)xmax
        if(nml_var%value(pos1+pos2+1:)/="")read(nml_var%value(pos1+pos2+1:),*)xsize
        ymin=xmin ; ymax=xmax ; ysize=xsize
     case("Y")
        pos1=scan(nml_var%value,":")
        pos2=scan(nml_var%value(pos1+1:),":")
        if(nml_var%value(1:pos1-1)/="")read(nml_var%value(1:pos1-1),*)ymin
        if(nml_var%value(pos1+1:pos1+pos2-1)/="")read(nml_var%value(pos1+1:pos1+pos2-1),*)ymax
        if(nml_var%value(pos1+pos2+1:)/="")read(nml_var%value(pos1+pos2+1:),*)ysize
     end select
  enddo

  allocate(xgrid(xsize),ygrid(ysize),zgrid(xsize,ysize))
  xgrid=linspace(xmin,xmax,xsize)
  ygrid=linspace(ymin,ymax,ysize)

  if(nl>0)wl=.true.

  arrayVx = init_list()
  arrayVy = init_list()
  i=0
  do 
     read(5,*,end=1) Vx,Vy
     call add_element(arrayVx,Vx)
     call add_element(arrayVy,Vy)
     i=i+1
  end do
1 continue
  L=i ; if(L/=arrayVx%size)call abort("error in counting input")
  allocate(dataX(L),dataY(L),vfield(L,L))
  call dump_list(arrayVx,dataX)
  call dump_list(arrayVy,dataY)

  if(L/=xsize*ysize)then
     print*,L,xsize,ysize
     call error("error in splot: xsize*ysize != data.size!")
  endif
  i=0
  do ix=1,xsize
     do iy=1,ysize
        i=i+1
        vfield(ix,iy)%x=dataX(i)
        vfield(ix,iy)%y=dataY(i)
     enddo
  enddo

  if(pgrid)then
     open(10,file=trim(adjustl(trim(file))))
     do ix=1,xsize
        do iy=1,ysize
           write(10,"(4F18.12)")xgrid(ix),ygrid(iy),vfield(ix,iy)%x,vfield(ix,iy)%y
        enddo
     enddo
     close(10)
     stop
  end if

  ! !Vector Field:
  call dplot_vector_field("plot_"//trim(adjustl(trim(file))),xgrid(1:xsize),ygrid(1:ysize),vfield(:,:)%x,vfield(:,:)%y,XLABEL="X",YLABEL="Y")
  call msg("plot file is plot_"//trim(adjustl(trim(file))))
end program vfplot
