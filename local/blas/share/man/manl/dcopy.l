.TH  DCOPY 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - DCOPY copie a vector, x, to a vector, y
.SH SYNOPSIS
.TP 36
SUBROUTINE DCOPY(N,DX,INCX,DY,INCY)
.TP 36
.ti +4
INTEGER
INCX,INCY,N
.TP 36
.ti +4
DOUBLE
PRECISION DX(*),DY(*)
.SH PURPOSE
   DCOPY copies a vector, x, to a vector, y.
    uses unrolled loops for increments equal to one.
.br

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

