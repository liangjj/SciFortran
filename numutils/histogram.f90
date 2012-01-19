!  include "list/d_ordered_list.f90"
program histogram
  USE FGSL
  USE D_ORDERED_LIST
  USE COMMON_VARS
  implicit none
  real(fgsl_double)    :: a, b, x 
  integer              :: n
  integer(fgsl_int)    :: status
  type(fgsl_histogram) :: h
  type(fgsl_file)      :: pfile
  !
  integer              :: i,L
  real(8)              :: y,dmin,dmax,weigth,bin_value,lower,upper
  logical              :: set_weigth=.true.
  real(8),allocatable  :: data(:)
  !
  type(d_linked_list)       :: array
  type(node_object)         :: value
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
       '  '])

  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(n,"N","NBIN",default=50)
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

  pfile  = fgsl_stdout()
  h      = fgsl_histogram_alloc(n*1_fgsl_size_t)
  status = fgsl_histogram_set_ranges_uniform(h, a, b)
  if(set_weigth)weigth = 1.d0/real(L,8)
  do i=1,L
     x = data(i)
     status = fgsl_histogram_accumulate(h, x, weigth)
  enddo

  do i=0,N-1
     status    = fgsl_histogram_get_range(h,i*1_fgsl_size_t,lower,upper)
     bin_value = fgsl_histogram_get(h,i*1_fgsl_size_t)
     write(*,"(2F12.7)")lower,bin_value
     write(*,"(2F12.7)")upper,bin_value
  enddo
  !status = fgsl_histogram_fprintf(pfile, h,'%12.7f','%12.7f')
  call fgsl_histogram_free(h)
end program histogram
