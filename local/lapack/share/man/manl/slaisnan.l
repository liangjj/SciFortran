.TH  SLAISNAN 1 "April 2011" " LAPACK auxiliary routine (version 3.2.2) " " LAPACK auxiliary routine (version 3.2.2) " 
.SH NAME
LAPACK-3 - routine i not for general use
.SH SYNOPSIS
.TP 17
LOGICAL FUNCTION
SLAISNAN( SIN1, SIN2 )
.TP 17
.ti +4
REAL
SIN1, SIN2
.SH PURPOSE
This routine is not for general use.  It exists solely to avoid
 over-optimization in SISNAN.
.br
 SLAISNAN checks for NaNs by comparing its two arguments for
 inequality.  NaN is the only floating-point value where NaN != NaN
 returns .TRUE.  To check for NaNs, pass the same variable as both
 arguments.
.br
 A compiler must assume that the two arguments are
.br
 not the same variable, and the test will not be optimized away.
 Interprocedural or whole-program optimization may delete this
 test.  The ISNAN functions will be replaced by the correct
 Fortran 03 intrinsic once the intrinsic is widely available.
.SH ARGUMENTS
.TP 9
 SIN1     (input) REAL
.TP 9
 SIN2     (input) REAL
 Two numbers to compare for inequality.
