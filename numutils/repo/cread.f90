  include "list/z_unordered_list.f90"
  program read_c
    USE COMMON_VARS
    USE Z_UNORDERED_LIST
    implicit none
    !
    integer                 :: i,L,nmod
    complex(8)              :: y
    complex(8),allocatable  :: data(:)
    logical                 :: default=.true.,blank=.false.
    !
    type(d_linked_list)     :: array
    !
    n_command_arg=command_argument_count()
    if(n_command_arg/=0)then
       do i=1,n_command_arg
          call get_command_argument(i,arg_buffer)
          call cmd_help(arg_buffer,"cread [L=value]")
          call cmd_var(arg_buffer)
          if(nml_name=="L")then
             read(nml_value,*)L
             default=.false.
          endif
          if(nml_name=="MOD")then
             read(nml_value,*)nmod
             blank=.true.
          endif
       enddo
    endif

    if(default)then
       array = init_list()
       i=0
       do 
          read(5,*,end=1) y
          call add_element(array,y)
          i=i+1
       end do
1      continue
       L=i
       if(L/=array%size)call abort("error in counting input")
       allocate(data(L))
       call dump_list(array,data)
    else
       allocate(data(L))
       do i=1,L
          read(5,*) data(i)
       enddo
    endif
    do i=1,L
       write(*,*)real(data(i),8),dimag(data(i))
       if(blank .AND. mod(i,nmod)==0)write(*,*)
    enddo
  end program read_c
