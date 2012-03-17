program kdensity
  USE STATISTICS
  USE D_ORDERED_LIST
  USE COMMON_VARS
  USE TOOLS
  implicit none
  !
  integer              :: i,L,N,pos,pos1
  real(8)              :: h,shift=2.d0
  real(8)              :: y,a,b,dmin,dmax
  real(8),allocatable  :: data(:)
  real(8),allocatable  :: x(:),pdf(:)
  logical              :: print_h=.false.
  logical              :: set_h=.true.
  logical              :: set_min=.true.
  logical              :: set_max=.true.
  integer              :: set_shift
  !
  type(d_linked_list)  :: array
  type(node_object)    :: value
  !
  allocate(help_buffer(16))
  help_buffer=([character(len=256)::&
       'NAME',&
       '  kdensity',&
       '',&
       'SYNOPSIS',&
       '  kdensity [h] [n] [range] [printh]',&
       '',&
       'DESCRIPTION',&
       '  Read an array of x(:) of data and returns its probability distribution',&
       '  using Gaussian Kernel Density Estimate with Silverman`s rule.',&
       ' ',&
       'OPTIONS',&
       ' h=[1.06*sigma*y.size**1/5] -- width of the gaussian',&
       ' printh=[F]                 -- flag to print the value of h,min,max',&
       ' n=[1024]                   -- number of points in the PDF ',&
       ' range=[2*h|y.min:y.max]    -- range of the PDE, default is 2*h. min:max value are allowed',&
       '  '])
  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(n,"N",default=1024)
  call parse_cmd_variable(print_h,"PRINTH","GETH")
  do i=1,command_argument_count()
     nml_var=get_cmd_variable(i)
     select case(nml_var%name)
     case("H")
        read(nml_var%value,*)h
        set_h=.false.

     case("RANGE")
        pos1=scan(nml_var%value,":")
        if(pos1/=0)then    !passing the min:max format
           if(nml_var%value(1:pos1-1)/="")then
              read(nml_var%value(1:pos1-1),*)dmin
              set_min=.false.
           endif
           if(nml_var%value(pos1+1:)/="")then
              read(nml_var%value(pos1+1:),*)dmax
              set_max=.false.
           endif
        else               !passing a shift in unit of h
           if(trim(adjustl(trim(nml_var%value)))=="h")then
              shift=1.d0
           else
              read(nml_var%value,*)shift
           endif
        endif
     case default 
     end select
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
  allocate(data(L))
  call dump_list(array,data)

  if(set_h)then
     h = get_sd(data)
     h = (4.d0/3.d0/real(L,8))**(1.d0/5.d0)*h !Silverman's rule of thumb.
  endif

  a = minval(data) ; b = maxval(data)
  if( b < a)then
     a = maxval(data) ; b = minval(data)
  endif

  if(set_min)then
     dmin=a
     dmin=dmin-shift*h!-abs(dmin)/shift
  endif

  if(set_max)then
     dmax=b
     dmax=dmax+shift*h!+abs(dmax)/shift       
  endif

  if(print_h)then
     write(*,"(A,F12.8,1x,F12.8,A,F12.8)")"h,min:max",h,dmin,"  :",dmax
     stop
  endif

  allocate(x(N),pdf(N))
  x      = linspace(dmin,dmax,N)


  pdf=0.d0
  do i=1,L
     pdf=pdf + gaussian_kernel(x,data(i),h)/real(L,8)
  enddo
  do i=1,N
     write(*,"(F18.8,1x,F18.8)")x(i),pdf(i)
  enddo

contains

  elemental function gaussian_kernel(x,mean,sigma)
    real(8),intent(in) :: x,mean,sigma
    real(8) :: gaussian_kernel
    gaussian_kernel=exp(-0.5d0*((x-mean)/sigma)**2)/sqrt(pi2*sigma**2)
  end function gaussian_kernel

end program kdensity
