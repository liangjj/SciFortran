module statistics
  implicit none
contains

  subroutine moment(data,ave,sdev,var,skew,curt)
    REAL(8), INTENT(OUT)              :: ave,sdev,var,skew,curt
    REAL(8), DIMENSION(:), INTENT(IN) :: data
    INTEGER                           :: n
    REAL(8)                           :: ep,adev
    REAL(8), DIMENSION(size(data))    :: p,s
    n=size(data)
    if (n <= 1) call abort('data.size must be at least 2')
    ave=sum(data(:))/n
    s(:)=data(:)-ave
    ep=sum(s(:))
    adev=sum(abs(s(:)))/n
    p(:)=s(:)*s(:)
    var=sum(p(:))
    p(:)=p(:)*s(:)
    skew=sum(p(:))
    p(:)=p(:)*s(:)
    curt=sum(p(:))
    var=(var-ep**2/n)/(n-1)
    sdev=sqrt(var)
    if (var /= 0.0) then
       skew=skew/(n*sdev**3)
       curt=curt/(n*var**2)-3.0d0
    else
       skew=0.d0
       curt=0.d0
    endif
  end subroutine moment

  function get_covariance(data,mean) result(covariance)
    real(8),dimension(:,:),intent(in)            :: data
    real(8),dimension(size(data,1)),intent(in)   :: mean
    real(8),dimension(size(data,1),size(data,1)) :: covariance
    real(8),dimension(size(data,2))              :: Xi,Xj
    integer                                      :: i,j,ncol,L
    ncol=size(data,1)
    L   =size(data,2)
    covariance=0.d0
    do i=1,ncol
       Xi(:)=data(i,:)-mean(i)
       do j=1,ncol
          Xj(:)=data(j,:)-mean(j)
          covariance(i,j) = sum(Xi(:)*Xj(:))/real(L-1,8)
       enddo
    enddo
  end function get_covariance
end module statistics

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
  logical                         :: get_mean=.false.
  logical                         :: get_sdev=.false.
  logical                         :: get_var=.false.
  logical                         :: get_skew=.false.
  logical                         :: get_kurt=.false.
  logical                         :: get_min=.false.,get_max=.false.
  logical                         :: get_sum=.false.
  logical                         :: get_cov=.false.,get_corr=.false.
  real(8),allocatable             :: data_mean(:)
  real(8),allocatable             :: data_sdev(:)
  real(8),allocatable             :: data_var(:)
  real(8),allocatable             :: data_skew(:)
  real(8),allocatable             :: data_kurt(:)
  real(8),allocatable             :: data_min(:),data_max(:)
  real(8),allocatable             :: data_sum(:)
  real(8),allocatable             :: data_covariance(:,:)
  !add more here:

  allocate(help_buffer(21))
  help_buffer=([&
       'NAME',&
       '  numstat',&
       '',&
       'SYNOPSIS',&
       '  numstat [ncol] [all/mean/std.dev/min/max/skew/kurt/sum/covar/corr]',&
       '',&
       'DESCRIPTION',&
       '  Read an array *X(:) or *Y(:,:) from stdin and return statistical description of this sample',&
       ' ',&
       'OPTIONS',&
       ' ncol=[1]    -- number of columns in the input data',&
       ' mean        -- mean of the sample. 1st moment.',&
       ' std.dev     -- standard deviation of the sample. 2nd moment.',&
       ' min         -- min of the sample.',&
       ' max         -- max of the sample.',&
       ' skew        -- skewness of the sample. 3rd moment.',&
       ' kurt        -- kurtosis of the sample. 4th moment.',&
       ' sum         -- sum of the sample.',&
       ' covar       -- covariance matrix of the ncol samples.',&
       ' corr        -- correlation matrix of the ncol samples.',&
       '  '])

  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(ncol,"NCOL",default=1)
  do i=1,command_argument_count()
     cmd_var=get_cmd_variable(i)
     if(cmd_var%value=="mean")get_mean=.true.
     if(cmd_var%value=="std.dev")get_sdev=.true.
     if(cmd_var%value=="var")get_var=.true.
     if(cmd_var%value=="skew")get_skew=.true.
     if(cmd_var%value=="kurt")get_kurt=.true.
     if(cmd_var%value=="min")get_min=.true.
     if(cmd_var%value=="max")get_max=.true.
     if(cmd_var%value=="sum")get_sum=.true.
     if(cmd_var%value=="covar")get_cov=.true.
     if(cmd_var%value=="corr")get_corr=.true.
     if(cmd_var%value=="all")get_all=.true.
  enddo

  if(get_all)then
     get_mean=.true.
     get_sdev=.true.
     get_var=.true.
     get_skew=.true.
     get_kurt=.true.
     get_min=.true.
     get_max=.true.
     get_sum=.true.
     get_cov=.true.
     get_corr=.true.
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
  allocate(data_min(ncol))
  allocate(data_max(ncol))
  allocate(data_sum(ncol))
  allocate(data_covariance(ncol,ncol))
  do icol=1,ncol
     call moment(data(icol,:),data_mean(icol),data_sdev(icol),data_var(icol),data_skew(icol),data_kurt(icol))
     data_min(icol)=minval(data(icol,:))
     data_max(icol)=maxval(data(icol,:))
     data_sum(icol)=sum(data(icol,:))
  enddo


  if(get_mean)write(*,"(A8,100f24.12)")"mean:",(data_mean(i),i=1,ncol)
  if(get_sdev)write(*,"(A8,100f24.12)")"std.dev:",(data_sdev(i),i=1,ncol)
  if(get_var)write(*,"(A8,100f24.12)")"var:",(data_var(i),i=1,ncol)
  if(get_skew)write(*,"(A8,100f24.12)")"skew:",(data_skew(i),i=1,ncol)
  if(get_kurt)write(*,"(A8,100f24.12)")"kurt:",(data_kurt(i),i=1,ncol)
  if(get_min)write(*,"(A8,100f24.12)")"min:",(data_min(i),i=1,ncol)
  if(get_max)write(*,"(A8,100f24.12)")"max:",(data_max(i),i=1,ncol)
  if(get_sum)write(*,"(A8,100f24.12)")"sum:",(data_sum(i),i=1,ncol)
  if(ncol>1)then
     data_covariance = get_covariance(data,data_mean)
     if(get_cov)then
        do i=1,ncol
           write(*,"(A8,100f24.12)")"cov_ij:",(data_covariance(i,j),j=1,ncol)
        enddo
     endif
     if(get_corr)then
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
