.TH  SROT 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - applies a plane rotation
.SH SYNOPSIS
.TP 39
SUBROUTINE SROT(N,SX,INCX,SY,INCY,C,S)
.TP 39
.ti +4
REAL
C,S
.TP 39
.ti +4
INTEGER
INCX,INCY,N
.TP 39
.ti +4
REAL
SX(*),SY(*)
.SH PURPOSE
   applies a plane rotation.

.SH FURTHER DETAILS
    jack dongarra, linpack, 3/11/78.
.br
    modified 12/3/93, array(1) declarations changed to array(*)

