program random_
  USE COMMON_VARS
  USE PARSE_CMD
  USE RANDOM
  implicit none
  integer             :: i,N,pos1,pos2
  real(8)             :: xmin,xmax,re,im,interval
  character(len=1)   :: type
  integer,allocatable    :: ir(:)
  real(8),allocatable    :: rr(:)
  complex(8),allocatable :: cr(:)
  character(len=256),allocatable :: help_buffer(:)
  allocate(help_buffer(15))
  help_buffer=([character(len=256)::&
       'NAME',&
       '  random',&
       '',&
       'SYNOPSIS',&
       '  random [range=min:max:n min= max= n= type=]',&
       '',&
       'DESCRIPTION',&
       '  Return a random number/array of N real(8) numbers between MIN and MAX',&
       ' ',&
       'OPTIONS',&
       '  range=[0:1:1] -- range of the interval and number of samples (do not need to complete)',&
       '  min=[1]       -- Min of the interval',&
       '  max=[10]      -- Max of the interval',&
       '  n=[1]         -- Number of random numbers',&
       '  type=[R]      -- Number of random numbers',&
       '  '])
if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(N,"N",default=1)
  call parse_cmd_variable(xmin,"MIN",default=0.d0)
  call parse_cmd_variable(xmax,"MAX",default=1.d0)
  call parse_cmd_variable(type,"TYPE",default="r")
  do i=1,command_argument_count()
     nml_var=get_cmd_variable(i)
     if(nml_var%name=="RANGE")then
        pos1=scan(nml_var%value,":")
        pos2=scan(nml_var%value(pos1+1:),":")
        if(pos2==0)pos2=len(trim(adjustl(trim(nml_var%value))))
        if(nml_var%value(1:pos1-1)/="")read(nml_var%value(1:pos1-1),*)xmin
        if(nml_var%value(pos1+1:pos1+pos2-1)/="")read(nml_var%value(pos1+1:pos1+pos2-1),*)xmax
        if(nml_var%value(pos1+pos2+1:)/="")read(nml_var%value(pos1+pos2+1:),*)N
     endif
  enddo
  interval=abs(xmax-xmin)
  call init_random_number()
  select case(type)
  case default               !real
     allocate(rr(N))
     call random_number(rr)
     rr=xmin + rr*interval
     do i=1,N
        write(*,*)rr(i)
     enddo
  case ("c")
     allocate(cr(N))
     do i=1,N
        call random_number(re)
        call random_number(im)
        cr(i)=xmin+ cmplx(re,im,8)*interval
        write(*,*)cr(i)
     enddo
  case("i")
     allocate(ir(N),rr(N))
     call random_number(rr)
     rr=xmin + rr*interval
     ir=nint(rr)
     do i=1,N
        write(*,*)ir(i)
     enddo
  end select



end program random_
