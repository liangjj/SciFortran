.TH  IZAMAX 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - IZAMAX find the index of element having max
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
IZAMAX(N,ZX,INCX)
.TP 17
.ti +4
INTEGER
INCX,N
.TP 17
.ti +4
DOUBLE
COMPLEX ZX(*)
.SH PURPOSE
   IZAMAX finds the index of element having max. absolute value.

.SH FURTHER DETAILS
    jack dongarra, 1/15/85.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

