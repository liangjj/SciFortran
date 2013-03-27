program pade_
  USE COMMON_VARS
  USE TOOLS
  USE IOTOOLS
  USE PARSE_CMD
  USE PADE
  implicit none
  integer                :: i,j,N,npade,pos1,pos2
  character(len=64)      :: fin,fout

  !Matsubara:
  real(8)                :: regf,imgf,eps
  real(8),allocatable    :: wm(:)
  complex(8),allocatable :: gm(:)

  !Real-axis:
  integer                :: Nw=1024
  real(8)                :: wmin=-10.d0,wmax=10.d0
  complex(8),allocatable :: zr(:),gr(:)
  character(len=256),allocatable :: help_buffer(:)

  allocate(help_buffer(16))
  help_buffer=([&
       'NAME',&
       '  pade',&
       '',&
       'SYNOPSIS',&
       '  pade [range=a:b:N] [npade] [fin] [fout] [eps]',&
       '',&
       'DESCRIPTION',&
       '  Returns the pade analytic continuation for the Matsubara Green`s function on input ',&
       ' ',&
       'OPTIONS',&
       ' range=[-10:10:1024] -- set the range on the real axis: w_min, w_max and number of points. ',&
       ' npade=[20]          -- set the rank of Pade` approximant. ',&
       ' fin  =[pade.in]     -- set the name of the input file. ',&
       ' fout =[pade.out]    -- set the name of the output file. ',&
       ' eps  =[0.01]        -- set the small broadening from the real-axis branch cut. ',&
       '  '])

  call parse_cmd_help(help_buffer)
  call parse_cmd_variable(npade,"NPADE",default=20)
  call parse_cmd_variable(eps,"EPS",default=0.01d0)
  call parse_cmd_variable(fin,"FIN",default="pade.in")
  call parse_cmd_variable(fout,"FOUT",default="pade.out")
  do i=1,command_argument_count()
     nml_var=get_cmd_variable(i)
     if(nml_var%name == "RANGE")then        
        pos1=scan(nml_var%value,":")
        pos2=scan(nml_var%value(pos1+1:),":")
        if(nml_var%value(1:pos1-1)/="")read(nml_var%value(1:pos1-1),*)wmin
        if(nml_var%value(pos1+1:pos1+pos2-1)/="")read(nml_var%value(pos1+1:pos1+pos2-1),*)wmax
        if(nml_var%value(pos1+pos2+1:)/="")read(nml_var%value(pos1+pos2+1:),*)Nw
     endif
  end do

  N=file_length(trim(adjustl(trim(fin))))
  allocate(wm(N),gm(N))
  call sread(trim(fin),wm,gm)

  allocate(zr(Nw),gr(Nw))
  zr=linspace(wmin,wmax,Nw)+xi*eps
  gr = pade_analytic_continuation(zr,npade,gm(:),wm(:))
  call splot(trim(fout),real(zr(:),8),gr)
end program pade_
