.TH  CLAG2Z 1 "April 2011" " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - converts a COMPLEX matrix, SA, to a COMPLEX*16 matrix, A
.SH SYNOPSIS
.TP 19
SUBROUTINE CLAG2Z(
M, N, SA, LDSA, A, LDA, INFO )
.TP 19
.ti +4
INTEGER
INFO, LDA, LDSA, M, N
.TP 19
.ti +4
COMPLEX
SA( LDSA, * )
.TP 19
.ti +4
COMPLEX*16
A( LDA, * )
.SH PURPOSE
CLAG2Z converts a COMPLEX matrix, SA, to a COMPLEX*16 matrix, A.
 Note that while it is possible to overflow while converting
 from double to single, it is not possible to overflow when
 converting from single to double.
.br
 This is an auxiliary routine so there is no argument checking.
.SH ARGUMENTS
.TP 8
 M       (input) INTEGER
 The number of lines of the matrix A.  M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of the matrix A.  N >= 0.
.TP 8
 SA      (input) COMPLEX array, dimension (LDSA,N)
 On entry, the M-by-N coefficient matrix SA.
.TP 8
 LDSA    (input) INTEGER
 The leading dimension of the array SA.  LDSA >= max(1,M).
.TP 8
 A       (output) COMPLEX*16 array, dimension (LDA,N)
 On exit, the M-by-N coefficient matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
