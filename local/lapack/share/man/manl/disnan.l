.TH  DISNAN 1 "April 2011" " LAPACK auxiliary routine (version 3.2.2) " " LAPACK auxiliary routine (version 3.2.2) " 
.SH NAME
LAPACK-3 - returns .TRUE
.SH SYNOPSIS
.TP 17
LOGICAL FUNCTION
DISNAN( DIN )
.TP 17
.ti +4
DOUBLE
PRECISION DIN
.SH PURPOSE
DISNAN returns .TRUE. if its argument is NaN, and .FALSE.
 otherwise.  To be replaced by the Fortran 2003 intrinsic in the
 future.
.br
.SH ARGUMENTS
.TP 8
 DIN     (input) DOUBLE PRECISION
 Input to test for NaN.
