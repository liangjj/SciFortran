program fftgf_
  USE Z_UNORDERED_LIST
  USE COMMON_VARS
  USE PARSE_CMD
  USE FFTGF
  USE TOOLS
  implicit none
  !
  integer                 :: i,L,N
  real(8)                 :: rey,imy,beta
  complex(8)              :: y
  complex(8),allocatable  :: data(:),in(:),out(:)
  real(8),allocatable     :: gout(:)
  character(len=64)       :: fin,fout,type
  integer                 :: iunit,ounit
  logical :: ex
  integer :: stride
  !
  type(z_linked_list)     :: array
  !
  character(len=256),allocatable :: help_buffer(:)
  allocate(help_buffer(26))
  help_buffer=([&
       'NAME',&
       '  fftgf',&
       '',&
       'SYNOPSIS',&
       '  fftgf [type=fw(default),bw,rt2rw,rw2rt,iw2tau,tau2iw] [ex] [beta] [fin] [fout] [stride]',&
       '',&
       'DESCRIPTION',&
       '  Read two arrays reF(:),imF(:) from stdin or +fin unit, return its fourier transform function ',&
       '  of type +type to stdout of +fout unit. Input arrays are of fortran cmplx type (re,im)',& 
       '  but for +type=tau2iw which requries a real input. Each type not fw,bw',&
       '  has specific requirements as follows:',&
       '   rt2rw:  input array lenght must be L=2*N+1 (odd), output is 2*N long and already re-shifted.',&
       '   rw2rt:  input array lenght must be 2*N (even), output is -N:N=2*N+1=L long and alread shifted.',&
       '   tau2iw: input array (real) lenght is N for tau>0, output is N too for iw>0',&
       '   iw2tau: input array lenght is N for iw>0, out is N for tau>0',&
       ' ',&
       ' RESCALING: rw2rt must be rescaled with dw/(2*pi) = 1/(dt*L)',&
       '            rt2rw must be reascaled with dt',&
       'OPTIONS',&
       '  type=[fw]     -- fft type: forward(fw),backward(bw),gf specific: (rt2rw,rw2rt,tau2iw,iw2tau)',&
       '  beta=[100.0]  -- inverse temperature',&
       '  ex=[F]        -- exchange Real and Imag in both input and output',&
       '  stride=[1]    -- stride for the FFT array transformation (1:L:Stride) ',&
       '  fin=[stdin]   -- input file name, default is standard input',&
       '  fout=[stdout] -- output file name, default is standard output',&
       '  '])

  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(type,"TYPE",default="fw")
  call parse_cmd_variable(fin,"FIN",default="stdin")
  call parse_cmd_variable(fout,"FOUT",default="stdout")
  call parse_cmd_variable(beta,"BETA",default=100.d0)
  call parse_cmd_variable(stride,"STRIDE",default=1)
  call parse_cmd_variable(ex,"EX",default=.false.)

  select case(fin)
  case("stdin")
     iunit=5
  case default
     iunit=10
     open(iunit,file=trim(fin))
  end select

  array = init_list()
  i=0
  do
     read(iunit,*,end=1)rey,imy
     y=cmplx(rey,imy,8);if(ex)y=cmplx(imy,rey,8)
     call add_element(array,y)
     i=i+1
  end do
1 continue
  L=i
  if(L/=array%size)call abort("error in counting input")
  allocate(data(L))
  call dump_list(array,data)
  if(iunit/=5)close(iunit)

  select case(fout)
  case("stdout")
     ounit=6
  case default
     ounit=20
     open(ounit,file=trim(fout))
  end select

  select case(trim(type))
  case("fw")
     call cfft_1d_forward(data)
     if(ex)then
        do i=1,L
           write(ounit,*)real(data(i),8),dimag(data(i))
        enddo
     else
        do i=1,L
           write(ounit,*)dimag(data(i)),real(data(i),8)
        enddo
     endif

  case("bw")
     call cfft_1d_backward(data)
     if(ex)then
        do i=1,L
           write(ounit,*)real(data(i),8),dimag(data(i))
        enddo
     else
        do i=1,L
           write(ounit,*)dimag(data(i)),real(data(i),8)
        enddo
     endif


  case("rt2rw")
     !Check that L=2*N+1 is an ODD number== mod(L,2)/=0
     if(mod(L,2)==0)call error("wrong dimension in rt2rw")
     N=L-1;N=N/2                !L=2*N+1
     allocate(in(-N:N),out(2*N))
     forall(i=1:L)in(i-N-1)=data(i)
     call fftgf_rt2rw(in,out,N)
     call swap_fftrt2rw(out)
     if(ex)then
        do i=1,2*N
           write(ounit,*)real(out(i),8),dimag(out(i))
        enddo
     else
        do i=1,2*N
           write(ounit,*)dimag(out(i)),real(out(i),8)
        enddo
     endif
     deallocate(in,out)


  case("rw2rt")
     !Check that L=2*N is an EVEN number== mod(L,2)=0
     if(mod(L,2)/=0)call error("wrong dimension in rw2rt")
     N=L/2                      ! L=2*N
     allocate(out(-N:N))
     call fftgf_rw2rt(data,out,N)
     call cfft_1d_ex(out)
     if(ex)then
        do i=-N,N
           write(ounit,*)real(out(i),8),dimag(out(i))
        enddo
     else
        do i=-N,N
           write(ounit,*)dimag(out(i)),real(out(i),8)
        enddo
     endif
     deallocate(out)


  case("iw2tau")


     allocate(gout(0:L))
     call fftgf_iw2tau(data,gout,beta)
     do i=0,L
        write(ounit,*)gout(i)
     enddo
     deallocate(gout)

  case("tau2iw")
     allocate(out(L))
     call fftgf_tau2iw(real(data,8),out,beta)
     if(ex)then
        do i=1,L
           write(ounit,*)real(out(i),8),dimag(out(i))
        enddo
     else
        do i=1,L
           write(ounit,*)dimag(out(i)),real(out(i),8)
        enddo
     endif
     deallocate(out)


  end select




end program fftgf_
