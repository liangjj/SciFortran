.TH  DSWAP 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - interchanges two vectors
.SH SYNOPSIS
.TP 36
SUBROUTINE DSWAP(N,DX,INCX,DY,INCY)
.TP 36
.ti +4
INTEGER
INCX,INCY,N
.TP 36
.ti +4
DOUBLE
PRECISION DX(*),DY(*)
.SH PURPOSE
   interchanges two vectors.
    uses unrolled loops for increments equal one.
.br

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

