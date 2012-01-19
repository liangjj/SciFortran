sine_gen -f 3.0 -n 100 swA.dat
sine_gen -f 11.0 -n 100 swB.dat
add swA.dat swB.dat composite.dat
xgraph -a -pl composite.dat time.title &
fft composite.dat composite.fft
cmag composite.fft composite.spectrum
xgraph composite.spectrum spectrum.title &
