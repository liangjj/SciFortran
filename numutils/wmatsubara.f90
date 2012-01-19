program linsp
  USE COMMON_VARS
  USE TOOLS
  integer             :: i,L,rep
  real(8),allocatable :: wm(:)

  allocate(help_buffer(14))
  help_buffer=([&
       'NAME',&
       '  wmatsubara',&
       '',&
       'SYNOPSIS',&
       '  wmatsubara [beta=value] [L=value] rep=[1]',&
       '',&
       'DESCRIPTION',&
       '  Return an array of matsubara frequencies.',&
       '  ',&
       'OPTIONS',&
       '  L=[1024]   -- size of the on output array',&
       '  beta=[100] -- inverse temperature',&
       '  rep=[1]    -- number of repetition of the printed array',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(beta,"BETA",default=100.d0)
  call parse_cmd_variable(L,"L",default=1024)
  call parse_cmd_variable(rep,"REP",default=1)

  allocate(wm(L))
  wm = pi/beta*real(2*arange(1,L)-1,8)
  do irep=1,rep
     do i=1,L
        write(*,*)wm(i)
     enddo
     print*
  enddo
end program linsp
