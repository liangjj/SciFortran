.TH  DDOT 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - DDOT form the dot product of two vectors
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION DDOT(N,DX,INCX,DY,INCY)
.TP 17
.ti +4
INTEGER
INCX,INCY,N
.TP 17
.ti +4
DOUBLE
PRECISION DX(*),DY(*)
.SH PURPOSE
   DDOT forms the dot product of two vectors.
    uses unrolled loops for increments equal to one.
.br

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

