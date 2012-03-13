.TH  SASUM 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - SASUM take the sum of the absolute values
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SASUM(N,SX,INCX)
.TP 14
.ti +4
INTEGER
INCX,N
.TP 14
.ti +4
REAL
SX(*)
.SH PURPOSE
   SASUM takes the sum of the absolute values.
    uses unrolled loops for increment equal to one.
.br

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

