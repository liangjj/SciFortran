!  include "list/d_unordered_list.f90"
program fermi_
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  USE TOOLS
  implicit none
  !
  integer              :: i,L
  real(8)              :: y
  real(8),allocatable  :: data(:)
  !
  type(d_linked_list)  :: array
  !

  allocate(help_buffer(13))
  help_buffer=([&
       'NAME',&
       '  fermi',&
       '',&
       'SYNOPSIS',&
       '  fermi [beta=value]',&
       '',&
       'DESCRIPTION',&
       '  Read an array A(:) from stdin and return the fermi function ',&
       '  Y = 1/(1+exp(beta*A). ',&
       ' ',&
       'OPTIONS',&
       '  beta=[100.0] -- inverse temperature',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(beta,"BETA",default=100.d0)
  array = init_list()
  i=0
  do
     read(5,*,end=1) y
     call add_element(array,y)
     i=i+1
  end do
1 continue
  L=i
  if(L/=array%size)call abort("error in counting input")
  allocate(data(L))
  call dump_list(array,data)
  do i=1,L
     write(*,*)data(i),fermi(data(i),beta)
  enddo
end program fermi_
