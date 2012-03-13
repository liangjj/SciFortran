.TH  SCASUM 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - SCASUM take the sum of the absolute values of a complex vector and  returns a single precision result
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SCASUM(N,CX,INCX)
.TP 14
.ti +4
INTEGER
INCX,N
.TP 14
.ti +4
COMPLEX
CX(*)
.SH PURPOSE
   SCASUM takes the sum of the absolute values of a complex vector and
   returns a single precision result.

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

