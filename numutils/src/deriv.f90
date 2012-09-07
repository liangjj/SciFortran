!include "list/d_unordered_list.f90"
program deriv_
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  USE TOOLS
  USE SPLINE
  implicit none
  !
  integer              :: i,L
  real(8)              :: x,y,dh
  real(8),allocatable  :: fi(:),xin(:),deriv(:)
  logical              :: xyflag
  !
  type(d_linked_list)  :: arraX,arraY
  !  

  allocate(help_buffer(14))
  help_buffer=([&
       'NAME',&
       '  deriv',&
       '',&
       'SYNOPSIS',&
       '  deriv [dh=value]',&
       '',&
       'DESCRIPTION',&
       '  Read an array A(:,:) or B(:) from stdin and return its derivative ',&
       '  By default it needs an X, Y array of data. If *dh is given, then ',&
       '  only Y is required. ',&
       ' ',&
       'OPTIONS',&
       '  dh=[0.0] -- infinitesimal increment.',&
       '  '])

  !if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(dh,"DH",default=0.d0)
  !
  if(dh==0.d0)then
     xyflag=.true.
     arraY=init_list()
     arraX=init_list()
     i=0
     do 
        read(5,*,end=1)x,y
        call add_element(arraX,x)
        call add_element(arraY,y)
        i=i+1
     end do
1    continue
     L=i
     !
     allocate(fi(L),xin(L))
     call dump_list(arraY,fi)
     call dump_list(arraX,xin)
     dh=xin(2)-xin(1)
  elseif(dh/=0.d0)then
     xyflag=.false.
     arraY=init_list()
     i=0
     do 
        read(5,*,end=2)y
        call add_element(arraY,y)
        i=i+1
     end do
2    continue
     L=i
     !
     allocate(fi(L))
     call dump_list(arraY,fi)
  endif

  allocate(deriv(L))
  deriv(1)= (fi(2)-fi(1))/dh
  deriv(L)= (fi(L)-fi(L-1))/dh
  do i=2,L-1
     deriv(i) = (fi(i+1)-fi(i-1))/(2*dh)
  enddo

  if(xyflag)then
     do i=1,L
        write(*,*)xin(i),deriv(i)
     enddo
  else
     do i=1,L
        write(*,*)deriv(i)
     enddo
  endif
  !
end program deriv_
