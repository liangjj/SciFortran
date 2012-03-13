.TH  DROT 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - DROT applie a plane rotation
.SH SYNOPSIS
.TP 39
SUBROUTINE DROT(N,DX,INCX,DY,INCY,C,S)
.TP 39
.ti +4
DOUBLE
PRECISION C,S
.TP 39
.ti +4
INTEGER
INCX,INCY,N
.TP 39
.ti +4
DOUBLE
PRECISION DX(*),DY(*)
.SH PURPOSE
   DROT applies a plane rotation.

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

