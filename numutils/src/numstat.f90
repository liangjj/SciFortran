program numstat
  USE D_UNORDERED_LIST
  USE COMMON_VARS
  USE STATISTICS
  implicit none
  integer                         :: i,j,L,icol
  real(8),allocatable             :: data(:,:),y(:)
  type(d_linked_list),allocatable :: array(:)
  integer                         :: ncol=1
  logical                         :: get_all=.false.
  logical                         :: imean=.false.
  logical                         :: isdev=.false.
  logical                         :: ivar=.false.
  logical                         :: iskew=.false.
  logical                         :: ikurt=.false.
  logical                         :: imin=.false.,imax=.false.
  logical                         :: iminloc=.false.,imaxloc=.false.
  logical                         :: isum=.false.
  logical                         :: icov=.false.,icorr=.false.
  real(8),allocatable             :: data_mean(:)
  real(8),allocatable             :: data_sdev(:)
  real(8),allocatable             :: data_var(:)
  real(8),allocatable             :: data_skew(:)
  real(8),allocatable             :: data_kurt(:)
  real(8),allocatable             :: data_min(:),data_max(:)
  integer,allocatable             :: data_minloc(:),data_maxloc(:)
  real(8),allocatable             :: data_sum(:)
  real(8),allocatable             :: data_covariance(:,:)
  !add more here:

  allocate(help_buffer(21))
  help_buffer=([&
       'NAME',&
       '  numstat',&
       '',&
       'SYNOPSIS',&
       '  numstat [n/ncol] [all/mean/sdev/skew/kurt/min/max/minloc/maxloc/sum/covar/corr]',&
       '',&
       'DESCRIPTION',&
       '  Read an array *X(:) or *Y(:,:) from stdin and return statistical description of this sample',&
       ' ',&
       'OPTIONS',&
       ' ncol/n=[1]-- number of columns in the input data',&
       ' mean      -- mean of the sample. 1st moment.',&
       ' sdev      -- standard deviation of the sample. 2nd moment.',&
       ' min       -- min of the sample.',&
       ' max       -- max of the sample.',&
       ' minloc    -- min location of the sample.',&
       ' maxloc    -- max location of the sample.',&
       ' skew      -- skewness of the sample. 3rd moment.',&
       ' kurt      -- kurtosis of the sample. 4th moment.',&
       ' sum       -- sum of the sample.',&
       ' covar     -- covariance matrix of the ncol samples.',&
       ' corr      -- correlation matrix of the ncol samples.',&
       '  '])

  if(command_argument_count()==0)call print_cmd_help(help_buffer)
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(ncol,"NCOL","N",default=1)
  do i=1,command_argument_count()
     cmd_var=get_cmd_variable(i)
     if(cmd_var%value=="mean") imean=.true.
     if(cmd_var%value=="sdev") isdev=.true.
     if(cmd_var%value=="var")  ivar=.true.
     if(cmd_var%value=="skew") iskew=.true.
     if(cmd_var%value=="kurt") ikurt=.true.
     if(cmd_var%value=="min")  imin=.true.
     if(cmd_var%value=="max")  imax=.true.
     if(cmd_var%value=="minloc")iminloc=.true.
     if(cmd_var%value=="maxloc")imaxloc=.true.
     if(cmd_var%value=="sum")  isum=.true.
     if(cmd_var%value=="covar")icov=.true.
     if(cmd_var%value=="corr") icorr=.true.
     if(cmd_var%value=="all")  get_all=.true.
  enddo

  if(get_all)then
     imean=.true.
     isdev=.true.
     ivar=.true.
     iskew=.true.
     ikurt=.true.
     imin=.true.
     imax=.true.
     iminloc=.true.
     imaxloc=.true.
     isum=.true.
     icov=.true.
     icorr=.true.
  endif

  allocate(array(ncol),y(ncol))
  do icol=1,ncol
     array(icol)=init_list()
  enddo
  i=0
  do 
     read(5,*,end=1)(y(icol),icol=1,ncol)
     do icol=1,ncol
        call add_element(array(icol),y(icol))
     enddo
     i=i+1
  end do
1 continue
  L=i ; if(L/=array(1)%size)call abort("error in counting input")
  allocate(data(ncol,L))
  do icol=1,ncol
     call dump_list(array(icol),data(icol,:))
  enddo


  !Simple statistics on samples:
  allocate(data_mean(ncol))
  allocate(data_sdev(ncol))
  allocate(data_var(ncol))
  allocate(data_skew(ncol))
  allocate(data_kurt(ncol))
  allocate(data_min(ncol),data_minloc(ncol))
  allocate(data_max(ncol),data_maxloc(ncol))
  allocate(data_sum(ncol))
  allocate(data_covariance(ncol,ncol))


  do icol=1,ncol
     call get_moments(data(icol,:),data_mean(icol),data_sdev(icol),data_var(icol),data_skew(icol),data_kurt(icol))
     data_min(icol)=minval(data(icol,:))
     data_max(icol)=maxval(data(icol,:))
     data_minloc(icol)=minloc(data(icol,:),dim=1)
     data_maxloc(icol)=maxloc(data(icol,:),dim=1)
     data_sum(icol)=sum(data(icol,:))
  enddo


  if(imean)write(*,"(A8,100f24.12)")"mean:",(data_mean(i),i=1,ncol)
  if(isdev)write(*,"(A8,100f24.12)")"std.dev:",(data_sdev(i),i=1,ncol)
  if(ivar)write(*,"(A8,100f24.12)")"var:",(data_var(i),i=1,ncol)
  if(iskew)write(*,"(A8,100f24.12)")"skew:",(data_skew(i),i=1,ncol)
  if(ikurt)write(*,"(A8,100f24.12)")"kurt:",(data_kurt(i),i=1,ncol)
  if(imin)write(*,"(A8,100f24.12)")"min:",(data_min(i),i=1,ncol)
  if(imax)write(*,"(A8,100f24.12)")"max:",(data_max(i),i=1,ncol)
  if(iminloc)write(*,"(A8,100I12)")"minloc:",(data_minloc(i),i=1,ncol)
  if(imaxloc)write(*,"(A8,100I12)")"maxloc:",(data_maxloc(i),i=1,ncol)
  if(isum)write(*,"(A8,100f24.12)")"sum:",(data_sum(i),i=1,ncol)

  if(ncol>1)then
     data_covariance = get_covariance(data,data_mean)
     if(icov)then
        do i=1,ncol
           write(*,"(A8,100f24.12)")"cov_ij:",(data_covariance(i,j),j=1,ncol)
        enddo
     endif
     if(icorr)then
        do i=1,ncol
           do j=1,ncol
              data_covariance(i,j)=data_covariance(i,j)/(data_sdev(i)*data_sdev(j))
           enddo
        enddo
        do i=1,ncol
           write(*,"(A8,100f24.12)")"corr_ij:",(data_covariance(i,j),j=1,ncol)
        enddo
     endif
  endif
  write(*,*)

end program numstat
