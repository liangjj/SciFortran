.TH  SSWAP 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - interchanges two vectors
.SH SYNOPSIS
.TP 36
SUBROUTINE SSWAP(N,SX,INCX,SY,INCY)
.TP 36
.ti +4
INTEGER
INCX,INCY,N
.TP 36
.ti +4
REAL
SX(*),SY(*)
.SH PURPOSE
   interchanges two vectors.
    uses unrolled loops for increments equal to 1.
.br

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

