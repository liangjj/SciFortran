.TH  SLAPY2 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - returns sqrt(x**2+y**2), taking care not to cause unnecessary overflow
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SLAPY2( X, Y )
.TP 14
.ti +4
REAL
X, Y
.SH PURPOSE
SLAPY2 returns sqrt(x**2+y**2), taking care not to cause unnecessary
overflow.
.SH ARGUMENTS
.TP 8
 X       (input) REAL
 Y       (input) REAL
 X and Y specify the values x and y.
