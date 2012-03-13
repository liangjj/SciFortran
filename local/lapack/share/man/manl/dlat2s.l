.TH  DLAT2S 1 "April 2011" " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " " LAPACK PROTOTYPE auxiliary routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - converts a DOUBLE PRECISION triangular matrix, SA, to a SINGLE PRECISION triangular matrix, A
.SH SYNOPSIS
.TP 19
SUBROUTINE DLAT2S(
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
REAL
SA( LDSA, * )
.TP 19
.ti +4
DOUBLE
PRECISION A( LDA, * )
.SH PURPOSE
DLAT2S converts a DOUBLE PRECISION triangular matrix, SA, to a SINGLE
PRECISION triangular matrix, A.
 RMAX is the overflow for the SINGLE PRECISION arithmetic
.br
 DLAS2S checks that all the entries of A are between -RMAX and
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
 A       (input) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, the N-by-N triangular coefficient matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 SA      (output) REAL array, dimension (LDSA,N)
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
