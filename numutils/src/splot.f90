program plot_3d
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  USE PARSE_CMD
  USE SLPLOT
  USE TOOLS
  implicit none
  integer                         :: i,L,ix,iy,pos1,pos2,icol
  character(len=128)              :: file
  type(d_linked_list),allocatable :: array(:)
  real(8),allocatable             :: data(:,:),y(:)
  real(8),allocatable             :: xgrid(:),ygrid(:),zgrid(:,:)
  complex(8),allocatable          :: czgrid(:,:)
  real(8)                         :: xmin,xmax
  real(8)                         :: ymin,ymax
  integer                         :: xsize,ysize
  character(len=256),allocatable  :: help_buffer(:)
  logical                         :: wl=.false.,pgrid
  integer                         :: nl,ncol
  xmin=1.d0 ; xmax=10.d0 ; xsize=10
  ymin=1.d0 ; ymax=10.d0 ; ysize=10
  allocate(help_buffer(19))
  help_buffer=([&
       'NAME',&
       '  splot',&
       '',&
       'SYNOPSIS',&
       '  splot x=min:max:sizex [y=min:max:sizey] [file=value] [nl=value]',&
       '',&
       'DESCRIPTION',&
       '  Read an array *Z(:) on stdin and return a 3D plot (intensity&surface)',&
       '  using a grid on both X and Y build out of the specified dimension.',&
       '  The plot consist of a data set, in *file, and a gnuplot script to ',&
       '  plot it, *plot_file.',&
       ' ',&
       'OPTIONS',&
       '  ncol/n=[1]        -- number of columns in the input data',&
       '  x=[min:max:sizex] -- dimension of the X axis of the grid. ',&
       '  y=[min:max:sizey] -- dimension of the Y axis of the grid. If not specified is equal to X',&
       '  file=[new.plot]   -- file name of the plot. gnuplot script in plot_*file',&
       '  nl=[0]            -- if /= 0 produces a plot with lines along one direction every nl lines',&
       '  grid=[F]          -- if true write a file with continuous grid and data: X,Y,Z(X,Y)',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(ncol,"NCOL","N",default=1)
  call parse_cmd_variable(nl,"NL",default=0)
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
        ! case default
        !    write(*,"(A)")"invalid option: +"//trim(nml_var%name)//"="//trim(nml_var%value)
     end select
  enddo

  allocate(xgrid(xsize),ygrid(ysize))
  if(ncol==1)allocate(zgrid(xsize,ysize))
  if(ncol==2)allocate(czgrid(xsize,ysize))
  if(ncol>2)call error("Ncol > 2. ncol=1 (default) for real, ncol=2 for cmplx.")
  xgrid=linspace(xmin,xmax,xsize)
  ygrid=linspace(ymin,ymax,ysize)

  if(nl>0)wl=.true.

  allocate(array(ncol),y(ncol))
  do icol=1,ncol
     array(icol) = init_list()
  enddo

  i=0
  do 
     read(5,*,end=1) (y(icol),icol=1,ncol)
     do icol=1,ncol
        call add_element(array(icol),y(icol))
     enddo
     i=i+1
  end do
1 continue
  L=i ; if(L/=array(1)%size)call error("error in counting input")
  allocate(data(ncol,L)) 
  do icol=1,ncol
     call dump_list(array(icol),data(icol,:))
  enddo

  if(L/=xsize*ysize)call error("error in splot: xsize*ysize != data.size!")

  if(ncol==1)then
     i=0
     do ix=1,xsize
        do iy=1,ysize
           i=i+1
           zgrid(ix,iy)=data(1,i)
        enddo
     enddo
  else
     i=0
     do ix=1,xsize
        do iy=1,ysize
           i=i+1
           czgrid(ix,iy)=cmplx(data(1,i),data(2,i),8)
        enddo
     enddo
  endif

  if(pgrid)then
     if(ncol==1)then
        open(10,file=trim(adjustl(trim(file))))
        do ix=1,xsize
           do iy=1,ysize
              write(10,*)xgrid(ix),ygrid(iy),zgrid(ix,iy)
           enddo
        enddo
        close(10)
        stop
     else
        open(10,file=trim(adjustl(trim(file))))
        do ix=1,xsize
           do iy=1,ysize
              write(10,"(4F18.12)")xgrid(ix),ygrid(iy),real(czgrid(ix,iy),8),aimag(czgrid(ix,iy))
           enddo
        enddo
        close(10)
        stop
     endif
  end if

  if(wl)then
     if(ncol==1)then
        call splot3d(trim(adjustl(trim(file))),xgrid,ygrid,zgrid,.true.,nlines=nl)
     else
        call splot3d(trim(adjustl(trim(file))),xgrid,ygrid,czgrid,.true.,nlines=nl)
     endif
  else
     if(ncol==1)then
        call splot3d(trim(adjustl(trim(file))),xgrid,ygrid,zgrid)
     else
        call splot3d(trim(adjustl(trim(file))),xgrid,ygrid,czgrid)
     endif
  endif

  call msg("load gnuplot script plot_"//trim(adjustl(trim(file))))
end program plot_3d
