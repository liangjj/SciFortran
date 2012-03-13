.TH  ZLAT2C 1 "April 2011" " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - converts a COMPLEX*16 triangular matrix, SA, to a COMPLEX triangular matrix, A
.SH SYNOPSIS
.TP 19
SUBROUTINE ZLAT2C(
UPLO, N, A, LDA, SA, LDSA, INFO )
.TP 19
.ti +4
CHARACTER
UPLO
.TP 19
.ti +4
INTEGER
INFO, LDA, LDSA, N
.TP 19
.ti +4
COMPLEX
SA( LDSA, * )
.TP 19
.ti +4
COMPLEX*16
A( LDA, * )
.SH PURPOSE
ZLAT2C converts a COMPLEX*16 triangular matrix, SA, to a COMPLEX
triangular matrix, A.
 RMAX is the overflow for the SINGLE PRECISION arithmetic
.br
 ZLAT2C checks that all the entries of A are between -RMAX and
 RMAX. If not the convertion is aborted and a flag is raised.
 This is an auxiliary routine so there is no argument checking.
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 = \(aqU\(aq:  A is upper triangular;
.br
 = \(aqL\(aq:  A is lower triangular.
.TP 8
 N       (input) INTEGER
 The number of rows and columns of the matrix A.  N >= 0.
.TP 8
 A       (input) COMPLEX*16 array, dimension (LDA,N)
 On entry, the N-by-N triangular coefficient matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 SA      (output) COMPLEX array, dimension (LDSA,N)
 Only the UPLO part of SA is referenced.  On exit, if INFO=0,
 the N-by-N coefficient matrix SA; if INFO>0, the content of
 the UPLO part of SA is unspecified.
.TP 8
 LDSA    (input) INTEGER
 The leading dimension of the array SA.  LDSA >= max(1,M).
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit.
.br
 = 1:  an entry of the matrix A is greater than the SINGLE
 PRECISION overflow threshold, in this case, the content
 of the UPLO part of SA in exit is unspecified.
