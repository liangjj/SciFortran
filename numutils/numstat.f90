!  include "list/d_unordered_list.f90"
program numstat
  USE FGSL
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  implicit none
  integer                         :: i,L,iprint
  real(8)                         :: y,y1,y2
  real(8),allocatable             :: data(:,:)
  type(d_linked_list),allocatable :: array(:)
  integer                         :: stride=1,ncol=1
  logical                         :: get_all=.false.
  logical                         :: get_mean=.false.
  logical                         :: get_stddev=.false.
  logical                         :: get_var=.false.
  logical                         :: get_skew=.false.
  logical                         :: get_kurt=.false.
  logical                         :: get_min=.false.,get_max=.false.
  logical                         :: get_sum=.false.,get_autocorrelation=.false.
  logical                         :: get_covariance=.false.,get_correlation=.false.
  real(8),allocatable             :: data_mean(:)
  real(8),allocatable             :: data_stddev(:)
  real(8),allocatable             :: data_var(:)
  real(8),allocatable             :: data_skew(:)
  real(8),allocatable             :: data_kurt(:)
  real(8),allocatable             :: data_min(:),data_max(:)
  real(8),allocatable             :: data_sum(:)
  real(8),allocatable             :: data_autocorrelation(:)
  real(8)                         :: data_covariance,data_correlation
  !add more here:

  allocate(help_buffer(23))
  help_buffer=([&
       'NAME',&
       '  numstat',&
       '',&
       'SYNOPSIS',&
       '  numstat [ncol] [stride] [all/mean/std.dev/min/max/skew/kurt/sum/autocor/covar/cor]',&
       '',&
       'DESCRIPTION',&
       '  Read an array *X(:) or *Y(:,:) from stdin and return statistical description of this sample',&
       ' ',&
       'OPTIONS',&
       ' ncol=[1]    -- number of columns in the input data',&
       ' stride=[1]  -- stride or step of the data in input' ,&
       ' mean        -- mean of the sample. 1st moment.',&
       ' std.dev     -- standard deviation of the sample. 2nd moment.',&
       ' min         -- min of the sample.',&
       ' max         -- max of the sample.',&
       ' skew        -- skewness of the sample. 3rd moment.',&
       ' kurt        -- kurtosis of the sample. 4th moment.',&
       ' sum         -- sum of the sample.',&
       ' autocor     -- autocorrelation of the sample.',&
       ' covar       -- covariance of the two samples.',&
       ' cor         -- correlation of the two samples.',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(ncol,"NCOL",default=1)
  call parse_cmd_variable(stride,"STRIDE",default=1)
  do i=1,command_argument_count()
     cmd_var=get_cmd_variable(i)
     if(cmd_var%value=="mean")get_mean=.true.
     if(cmd_var%value=="std.dev")get_stddev=.true.
     if(cmd_var%value=="var")get_var=.true.
     if(cmd_var%value=="skew")get_skew=.true.
     if(cmd_var%value=="kurt")get_kurt=.true.
     if(cmd_var%value=="min")get_min=.true.
     if(cmd_var%value=="max")get_max=.true.
     if(cmd_var%value=="sum")get_sum=.true.
     if(cmd_var%value=="autocor")get_autocorrelation=.true.
     if(cmd_var%value=="covar")get_covariance=.true.
     if(cmd_var%value=="corr")get_correlation=.true.
     if(cmd_var%value=="all")get_all=.true.
  enddo


  if(get_all)then
     get_mean=.true.
     get_stddev=.true.
     get_var=.true.
     get_skew=.true.
     get_kurt=.true.
     get_min=.true.
     get_max=.true.
     get_sum=.true.
     get_autocorrelation=.true.
     get_covariance=.true.
     get_correlation=.true.
  endif

  allocate(array(ncol))
  allocate(data_mean(ncol))
  allocate(data_stddev(ncol))
  allocate(data_var(ncol))
  allocate(data_skew(ncol))
  allocate(data_kurt(ncol))
  allocate(data_min(ncol))
  allocate(data_max(ncol))
  allocate(data_sum(ncol))
  allocate(data_autocorrelation(ncol))
  if(ncol==1)then
     array(1) = init_list()
     i=0
     do 
        read(5,*,end=1) y
        call add_element(array(1),y)
        i=i+1
     end do
1    continue
     L=i ; if(L/=array(1)%size)call abort("error in counting input")
     allocate(data(ncol,L)) ; call dump_list(array(1),data(1,:))

  elseif(ncol==2)then
     array(1) = init_list()
     array(2) = init_list()
     i=0
     do 
        read(5,*,end=2) y1,y2
        call add_element(array(1),y1)
        call add_element(array(2),y2)
        i=i+1
     end do
2    continue
     L=i ; if(L/=array(1)%size .OR. L/=array(2)%size)call abort("error in counting input")
     allocate(data(ncol,L))
     call dump_list(array(1),data(1,:))
     call dump_list(array(2),data(2,:))

  endif


  !Do math on the array:
  iprint=0

  do i=1,ncol
     !MEAN
     if(get_mean)data_mean(i)     =fgsl_stats_mean(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
     !STD.DEV/VAR
     if(get_stddev)data_stddev(i) =fgsl_stats_sd(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
     if(get_var)data_var(i)       =fgsl_stats_variance(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
     !SKEWNESS
     if(get_skew)data_skew(i)     =fgsl_stats_skew(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
     !KURTOSIS
     if(get_kurt)data_kurt(i)     =fgsl_stats_kurtosis(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
     !MIN/MAX
     if(get_min)data_min(i)       =minval(data(i,:))
     if(get_max)data_max(i)       =maxval(data(i,:))
     !SUM
     if(get_sum)data_sum(i)       =sum(data(i,:))
     !AUTOCORRELATION LAG1
     if(get_autocorrelation) data_autocorrelation(i) = &
          fgsl_stats_lag1_autocorrelation(data(i,:), stride*1_fgsl_size_t, L*1_fgsl_size_t)
  enddo


  if(ncol==2)then
     if(get_covariance) data_covariance  = fgsl_stats_covariance(data(1,:),stride*1_fgsl_size_t,&
          data(2,:),stride*1_fgsl_size_t,L*1_fgsl_size_t)
     if(get_correlation)data_correlation = fgsl_stats_correlation(data(1,:),stride*1_fgsl_size_t,&
          data(2,:),stride*1_fgsl_size_t,L*1_fgsl_size_t)
  endif



  if(ncol==1)then
     if(get_mean)write(*,"(A8,f18.12)")"mean:",data_mean(1)
     if(get_stddev)write(*,"(A8,f18.12)")"std.dev:",data_stddev(1)
     if(get_var)write(*,"(A8,f18.12)")"var:",data_var(1)
     if(get_skew)write(*,"(A8,f18.12)")"skew:",data_skew(1)
     if(get_kurt)write(*,"(A8,f18.12)")"kurt:",data_kurt(1)
     if(get_min)write(*,"(A8,f18.12)")"min:",data_min(1)
     if(get_max)write(*,"(A8,f18.12)")"max:",data_max(1)
     if(get_sum)write(*,"(A8,f18.12)")"sum:",data_sum(1)
     if(get_autocorrelation)write(*,"(A8,f18.12)")"autocor:",data_autocorrelation(1)
  elseif(ncol==2)then
     if(get_mean)write(*,"(A8,2f18.12)")"mean:",(data_mean(i),i=1,2)
     if(get_stddev)write(*,"(A8,2f18.12)")"std.dev:",(data_stddev(i),i=1,2)
     if(get_var)write(*,"(A8,2f18.12)")"var:",(data_var(i),i=1,2)
     if(get_skew)write(*,"(A8,2f18.12)")"skew:",(data_skew(i),i=1,2)
     if(get_kurt)write(*,"(A8,2f18.12)")"kurt:",(data_kurt(i),i=1,2)
     if(get_min)write(*,"(A8,2f18.12)")"min:",(data_min(i),i=1,2)
     if(get_max)write(*,"(A8,2f18.12)")"max:",(data_max(i),i=1,2)
     if(get_sum)write(*,"(A8,2f18.12)")"sum:",(data_sum(i),i=1,2)
     if(get_autocorrelation)write(*,"(A8,2f18.12)")"autocor:",(data_autocorrelation(i),i=1,2)
     if(get_covariance)write(*,"(A8,f18.12)")"covar:",data_covariance
     if(get_correlation)write(*,"(A8,f18.12)")"corr:",data_correlation
  endif
  write(*,*)
end program numstat
