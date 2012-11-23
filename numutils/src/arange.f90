program arange_
  USE COMMON_VARS
  USE PARSE_CMD
  USE TOOLS
  integer :: i,L
  real(8),allocatable :: wm(:)
  character(len=256),allocatable :: help_buffer(:)
  allocate(help_buffer(12))
  help_buffer=([&
       'NAME',&
       '  arange',&
       '',&
       'SYNOPSIS',&
       '  arange [L=value]',&
       '',&
       'DESCRIPTION',&
       '  Return an array of L real(8) numbers between 1 and L',&
       ' ',&
       'OPTIONS',&
       '  L=[1024] -- number of elements',&
       '  '])
  if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(L,"L",default=1024)
  allocate(wm(L))
  wm = real(arange(1,L),8)
  do i=1,L
     write(*,*)wm(i)
  enddo
end program arange_
