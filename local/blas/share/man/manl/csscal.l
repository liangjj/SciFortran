.TH  CSSCAL 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - CSSCAL scale a complex vector by a real constant
.SH SYNOPSIS
.TP 32
SUBROUTINE CSSCAL(N,SA,CX,INCX)
.TP 32
.ti +4
REAL
SA
.TP 32
.ti +4
INTEGER
INCX,N
.TP 32
.ti +4
COMPLEX
CX(*)
.SH PURPOSE
   CSSCAL scales a complex vector by a real constant.

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

