program histogram_
  USE D_ORDERED_LIST
  USE COMMON_VARS
  USE STATISTICS
  implicit none
  real(8)             :: a, b, x 
  integer             :: n
  type(histogram)     :: h
  !
  integer             :: i,L,unit
  real(8)             :: y,dmin,dmax,weigth,bin_value,lower,upper
  logical             :: set_weigth=.true.
  real(8),allocatable :: data(:)
  !
  type(d_linked_list) :: array
  type(node_object)   :: value
  !

  allocate(help_buffer(13))
  help_buffer=([&
       'NAME',&
       '  histogram',&
       '  ',&
       'SYNOPSIS',&
       '  histogram [n/nbin=value] [w=value]',&
       '  ',&
       'DESCRIPTION',&
       '  Read an array X(:) and returns its distribution',&
       '  ',&
       'OPTIONS',&
       '  n|nbin=[50]       -- number of bins',&
       '  weigth=[1/x.size] -- weigth of the bins',&
       '  unit=[6]          -- write unit',&
       '  '])

  if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(n,"N","NBIN",default=50)
  call parse_cmd_variable(unit,"unit",default=6)
  do i=1,command_argument_count()
     cmd_var=get_cmd_variable(i)
     if(cmd_var%name=="W")then
        set_weigth=.false.
        read(cmd_var%value,*)weigth
     endif
  enddo

  array = init_list()
  i=0
  do 
     read(5,*,end=1) y
     value%t = y
     call insert_element(array,value)
     i=i+1
  end do
1 continue
  L=i

  !
  if(n>=L)call abort("nbin > data size! exit")
  !

  allocate(data(L))
  call dump_list(array,data)
  dmin = minval(data) ; dmax = maxval(data)
  if( dmax < dmin)then
     a = dmax
     b = dmin
  else
     a = dmin
     b = dmax
  endif

  h = histogram_allocate(n)
  call histogram_set_range_uniform(h, a, b)
  if(set_weigth)weigth = 1.d0/real(L,8)
  do i=1,L
     call histogram_accumulate(h, data(i), weigth)
  enddo
  call histogram_print(h,unit)
end program histogram_
