program ffcmplx
  USE COMMON_VARS
  USE TOOLS
  USE IOTOOLS
  implicit none
  integer                :: i,j,L,N,Ntot,Nnoblanks,pos1,pos2

  !Matsubara:
  real(8),allocatable    :: wm(:)
  complex(8),allocatable :: Gread(:,:)
  logical                :: ex
  character(len=64)      :: fin,fout
  character(len=256),allocatable :: help_buffer(:)
  allocate(help_buffer(16))
  help_buffer=([&
       'NAME',&
       '  ffcmplx',&
       '',&
       'SYNOPSIS',&
       '  ffcmplx [L=value] [N=value] [ex=value] [fin=value] [fout=value]',&
       '',&
       'DESCRIPTION',&
       '  Read a three columns file or input of the form X,imG,reG (or X,reG,imG if ex=T) and   ',&
       '  print to a file or output the function X,abs(G),phase(G) ',&
       ' ',&
       'OPTIONS',&
       ' L=[1024]        -- Number of points per each function (i.e. frequencies) . ',&
       ' N=[1024]        -- Number of functions samples  (separated by blank line) . ',&
       ' fin=[func.in]   -- Set the name of the input file. ',&
       ' fout=[func.out] -- Set the name of the output file. ',&
       ' ex =[F]         -- Boolean to choose between imG,reG or reG,imG form.',&
       '  '])

  if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(L,"L",default=1024)
  call parse_cmd_variable(N,"N",default=1)
  call parse_cmd_variable(fin,"FIN",default="func.in")
  call parse_cmd_variable(fout,"FOUT",default="func.out")
  call parse_cmd_variable(ex,"EX",default=.false.)

  Ntot=file_length(trim(adjustl(trim(fin))))
  print*,Ntot
  if(N==1)then
     L=Ntot
  else
     if(Ntot/=(L*N+N))call error("Error: wrong dimensions L,N")
  endif

  allocate(wm(L),Gread(N,L))
  call sread(trim(fin),Gread,wm)

  call system("rm -f "//trim(fout)//" 2>/dev/null")
  do i=1,N
     call splot(trim(fout),wm,abs(Gread(i,:)),phase(Gread(i,:)),append=.true.)
  enddo

contains

  elemental function phase(cmplx) 
    real(8) :: phase
    complex(8),intent(in) :: cmplx
    phase=atan2(dimag(cmplx),real(cmplx,8))
  end function phase

end program ffcmplx
