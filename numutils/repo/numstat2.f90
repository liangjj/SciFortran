  include "list/d_unordered_list.f90"
  program numstat
    USE FGSL
    USE D_UNORDERED_LIST
    USE COMMON_VARS
    implicit none
    integer             :: i,L,iprint
    real(8)             :: y
    real(8),allocatable :: data(:),dummy(:)
    type(d_linked_list) :: array
    integer :: stride=1
    logical :: get_mean=.false.
    real(8) :: data_mean
    logical :: get_stddev=.false.
    real(8) :: data_stddev
    logical :: get_min=.false.,get_max=.false.
    real(8) :: data_min,data_max
    logical :: get_sum=.false.
    real(8) :: data_sum
    !add more here:

    n_command_arg=command_argument_count()
    if(n_command_arg/=0)then
       do i=1,n_command_arg
          call get_command_argument(i,arg_buffer)
          call cmd_help(arg_buffer,"numstat operation=mean/std.dev/min/max/sum/...")
          nml_name = arg_buffer  ; call s_cap(nml_name)
          if(nml_name=="STRIDE")read(nml_value,*)stride
          if(nml_name=="MEAN")get_mean=.true.
          if(nml_name=="STD.DEV")get_stddev=.true.
          if(nml_name=="MIN")get_min=.true.
          if(nml_name=="MAX")get_max=.true.
          if(nml_name=="SUM")get_sum=.true.
          !add more here:
       enddo
    endif

    !
    array = init_list()
    i=0
    do 
       read(5,*,end=1) y
       call add_element(array,y)
       i=i+1
    end do
1   continue
    L=i ; if(L/=array%size)call abort("error in counting input")
    allocate(data(L)) ; call dump_list(array,data)


    !Do math on the array:
    iprint=0
    if(get_mean)then
       !data_mean=sum(data)/real(size(data),8)
       data_mean=fgsl_stats_mean(data, stride*1_fgsl_size_t, L*1_fgsl_size_t)
       write(*,"(f18.12)",advance="no")data_mean
    endif
    if(get_stddev)then
       data_mean=sum(data)/real(size(data),8)
       data_stddev = 0.d0
       do i=1,L
          data_stddev = data_stddev + (data(i)-data_mean)**2
       enddo
       data_stddev=sqrt(data_stddev/dble(L))
       write(*,"(f18.12)",advance="no")data_stddev
    endif
    if(get_bound)then
       data_min=minval(data);data_max=maxval(data)
       write(*,"(2f18.12)",advance="no")data_min,data_max
    endif
    if(get_sum)then
       data_sum=sum(data)
       write(*,"(f18.12)",advance="no")data_sum
    endif

    write(*,*)
  end program numstat
