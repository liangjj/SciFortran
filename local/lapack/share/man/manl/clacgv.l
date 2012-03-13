.TH  CLACGV 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - conjugates a complex vector of length N
.SH SYNOPSIS
.TP 19
SUBROUTINE CLACGV(
N, X, INCX )
.TP 19
.ti +4
INTEGER
INCX, N
.TP 19
.ti +4
COMPLEX
X( * )
.SH PURPOSE
CLACGV conjugates a complex vector of length N.
.SH ARGUMENTS
.TP 8
 N       (input) INTEGER
 The length of the vector X.  N >= 0.
.TP 8
 X       (input/output) COMPLEX array, dimension
 (1+(N-1)*abs(INCX))
 On entry, the vector of length N to be conjugated.
 On exit, X is overwritten with conjg(X).
.TP 8
 INCX    (input) INTEGER
 The spacing between successive elements of X.
