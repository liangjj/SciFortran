.TH  DLAG2S 1 "April 2011" " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - converts a DOUBLE PRECISION matrix, SA, to a SINGLE PRECISION matrix, A
.SH SYNOPSIS
.TP 19
SUBROUTINE DLAG2S(
M, N, A, LDA, SA, LDSA, INFO )
.TP 19
.ti +4
INTEGER
INFO, LDA, LDSA, M, N
.TP 19
.ti +4
REAL
SA( LDSA, * )
.TP 19
.ti +4
DOUBLE
PRECISION A( LDA, * )
.SH PURPOSE
DLAG2S converts a DOUBLE PRECISION matrix, SA, to a SINGLE
PRECISION matrix, A.
 RMAX is the overflow for the SINGLE PRECISION arithmetic
.br
 DLAG2S checks that all the entries of A are between -RMAX and
 RMAX. If not the convertion is aborted and a flag is raised.
 This is an auxiliary routine so there is no argument checking.
.SH ARGUMENTS
.TP 8
 M       (input) INTEGER
 The number of lines of the matrix A.  M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of the matrix A.  N >= 0.
.TP 8
 A       (input) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, the M-by-N coefficient matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 SA      (output) REAL array, dimension (LDSA,N)
 On exit, if INFO=0, the M-by-N coefficient matrix SA; if
 INFO>0, the content of SA is unspecified.
.TP 8
 LDSA    (input) INTEGER
 The leading dimension of the array SA.  LDSA >= max(1,M).
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit.
.br
 = 1:  an entry of the matrix A is greater than the SINGLE
 PRECISION overflow threshold, in this case, the content
 of SA in exit is unspecified.
