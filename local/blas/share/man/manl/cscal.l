.TH  CSCAL 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - CSCAL scale a vector by a constant
.SH SYNOPSIS
.TP 31
SUBROUTINE CSCAL(N,CA,CX,INCX)
.TP 31
.ti +4
COMPLEX
CA
.TP 31
.ti +4
INTEGER
INCX,N
.TP 31
.ti +4
COMPLEX
CX(*)
.SH PURPOSE
   CSCAL scales a vector by a constant.

.SH FURTHER DETAILS
    jack dongarra, linpack,  3/11/78.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

