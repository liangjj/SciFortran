.TH  ZDOTC 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - forms the dot product of a vector
.SH SYNOPSIS
.TP 15
DOUBLE COMPLEX
FUNCTION ZDOTC(N,ZX,INCX,ZY,INCY)
.TP 15
.ti +4
INTEGER
INCX,INCY,N
.TP 15
.ti +4
DOUBLE
COMPLEX ZX(*),ZY(*)
.SH PURPOSE
ZDOTC forms the dot product of a vector.

.SH FURTHER DETAILS
    jack dongarra, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

