program arange_
  USE COMMON_VARS
  USE TOOLS
  integer :: i,L
  real(8),allocatable :: wm(:)
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
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(L,"L",default=1024)
  allocate(wm(L))
  wm = real(arange(1,L),8)
  do i=1,L
     write(*,*)wm(i)
  enddo
end program arange_
