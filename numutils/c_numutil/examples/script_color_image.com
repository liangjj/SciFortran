sine_gen -n 100 -f 2 -realvec v.dat
outpr v.dat v.dat m.dat
mat2image -color m.dat m.ppm
xv m.ppm
