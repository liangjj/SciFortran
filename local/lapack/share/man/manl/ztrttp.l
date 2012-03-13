.TH  ZTRTTP 1 "April 2011" " LAPACK routine (version 3.3.0) " " LAPACK routine (version 3.3.0) " 
.SH NAME
LAPACK-3 - copies a triangular matrix A from full format (TR) to standard packed format (TP)
.SH SYNOPSIS
.TP 19
SUBROUTINE ZTRTTP(
UPLO, N, A, LDA, AP, INFO )
.TP 19
.ti +4
CHARACTER
UPLO
.TP 19
.ti +4
INTEGER
INFO, N, LDA
.TP 19
.ti +4
COMPLEX*16
A( LDA, * ), AP( * )
.SH PURPOSE
ZTRTTP copies a triangular matrix A from full format (TR) to standard
packed format (TP).
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 = \(aqU\(aq:  A is upper triangular;
.br
 = \(aqL\(aq:  A is lower triangular.
.TP 8
 N       (input) INTEGER
 The order of the matrices AP and A.  N >= 0.
.TP 8
 A       (input) COMPLEX*16 array, dimension (LDA,N)
 On entry, the triangular matrix A.  If UPLO = \(aqU\(aq, the leading
 N-by-N upper triangular part of A contains the upper
 triangular part of the matrix A, and the strictly lower
 triangular part of A is not referenced.  If UPLO = \(aqL\(aq, the
 leading N-by-N lower triangular part of A contains the lower
 triangular part of the matrix A, and the strictly upper
 triangular part of A is not referenced.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AP      (output) COMPLEX*16 array, dimension ( N*(N+1)/2 ),
 On exit, the upper or lower triangular matrix A, packed
 columnwise in a linear array. The j-th column of A is stored
 in the array AP as follows:
 if UPLO = \(aqU\(aq, AP(i + (j-1)*j/2) = A(i,j) for 1<=i<=j;
 if UPLO = \(aqL\(aq, AP(i + (j-1)*(2n-j)/2) = A(i,j) for j<=i<=n.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
