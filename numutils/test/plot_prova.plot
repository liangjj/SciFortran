set term wxt 0 persist
set title 'prova.plot'
set pm3d map
set xrange [2.00:3.00]
set yrange [1.00:2.00]
splot 'prova.plot'
#set term png size 1920,1280
#set out'prova.plot.png'
#rep
#
reset
set term wxt 1 persist
set title 'prova.plot'
set nokey
set grid
set view 50,10,1,1
splot 'prova.plot' with pm3d
#set term png size 1920,1280
#set out'prova.plot.png'
#rep
