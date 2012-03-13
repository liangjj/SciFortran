.TH  IDAMAX 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - IDAMAX find the index of element having max
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
IDAMAX(N,DX,INCX)
.TP 17
.ti +4
INTEGER
INCX,N
.TP 17
.ti +4
DOUBLE
PRECISION DX(*)
.SH PURPOSE
   IDAMAX finds the index of element having max. absolute value.

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 3/93 to return if incx .le. 0.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

