program linsp
  USE COMMON_VARS
  USE PARSE_CMD
  USE TOOLS
  implicit none
  integer             :: i,L,pos1,pos2
  real(8)             :: wmin,wmax
  real(8),allocatable :: array(:)
  character(len=256),allocatable :: help_buffer(:)
  allocate(help_buffer(15))
  help_buffer=([&
       'NAME',&
       '  linspace',&
       '',&
       'SYNOPSIS',&
       '  linspace [wmin/a] [wmax/b] [L]',&
       '',&
       'DESCRIPTION',&
       '  Returns evenly spaced numbers over a specified interval',&
       ' ',&
       'OPTIONS',&
       ' wmin/a=[-5]   -- starting value of the sequence',&
       ' wmax/b=[5]    -- the end point of the sequence ',&
       ' L=[1024]      -- length of the sequence',&
       ' range=[a:b:L] -- pass the whole range of the sequence at once',&
       '  '])

  if(command_argument_count()==0)call print_cmd_help(help_buffer)

  call parse_cmd_help(help_buffer)

  call parse_cmd_variable(L,"L",default=1024)
  call parse_cmd_variable(wmin,"WMIN","A",default=-5.d0)
  call parse_cmd_variable(wmax,"WMAX","B",default=5.d0)
  do i=1,command_argument_count()
     nml_var=get_cmd_variable(i)
     if(nml_var%name=="RANGE")then
        pos1=scan(nml_var%value,":")
        pos2=scan(nml_var%value(pos1+1:),":")
        if(nml_var%value(1:pos1-1)/="")read(nml_var%value(1:pos1-1),*)wmin
        if(nml_var%value(pos1+1:pos1+pos2-1)/="")read(nml_var%value(pos1+1:pos1+pos2-1),*)wmax
        if(nml_var%value(pos1+pos2+1:)/="")read(nml_var%value(pos1+pos2+1:),*)L
     endif
  enddo

  allocate(array(L))
  array = linspace(wmin,wmax,L)
  do i=1,L
     write(*,*)array(i)
  enddo
  deallocate(array)
end program linsp
