.TH  SISNAN 1 "April 2011" " LAPACK auxiliary routine (version 3.2.2) " " LAPACK auxiliary routine (version 3.2.2) " 
.SH NAME
LAPACK-3 - returns .TRUE
.SH SYNOPSIS
.TP 17
LOGICAL FUNCTION
SISNAN( SIN )
.TP 17
.ti +4
REAL
SIN
.SH PURPOSE
SISNAN returns .TRUE. if its argument is NaN, and .FALSE.
 otherwise.  To be replaced by the Fortran 2003 intrinsic in the
 future.
.br
.SH ARGUMENTS
.TP 8
 SIN     (input) REAL
 Input to test for NaN.
