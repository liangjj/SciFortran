.TH  SLAPY3 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - returns sqrt(x**2+y**2+z**2), taking care not to cause unnecessary overflow
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SLAPY3( X, Y, Z )
.TP 14
.ti +4
REAL
X, Y, Z
.SH PURPOSE
SLAPY3 returns sqrt(x**2+y**2+z**2), taking care not to cause
unnecessary overflow.
.SH ARGUMENTS
.TP 8
 X       (input) REAL
 Y       (input) REAL
 Z       (input) REAL
 X, Y and Z specify the values x, y and z.
