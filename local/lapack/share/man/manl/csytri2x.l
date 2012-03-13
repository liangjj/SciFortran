.TH  CSYTRI2X 1 "April 2011" " LAPACK routine (version 3.3.1) " " LAPACK routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - computes the inverse of a real symmetric indefinite matrix A using the factorization A = U*D*U**T or A = L*D*L**T computed by CSYTRF
.SH SYNOPSIS
.TP 21
SUBROUTINE CSYTRI2X(
UPLO, N, A, LDA, IPIV, WORK, NB, INFO )
.TP 21
.ti +4
CHARACTER
UPLO
.TP 21
.ti +4
INTEGER
INFO, LDA, N, NB
.TP 21
.ti +4
INTEGER
IPIV( * )
.TP 21
.ti +4
COMPLEX
A( LDA, * ), WORK( N+NB+1,* )
.SH PURPOSE
CSYTRI2X computes the inverse of a real symmetric indefinite matrix
A using the factorization A = U*D*U**T or A = L*D*L**T computed by
CSYTRF.
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 Specifies whether the details of the factorization are stored
 as an upper or lower triangular matrix.
 = \(aqU\(aq:  Upper triangular, form is A = U*D*U**T;
.br
 = \(aqL\(aq:  Lower triangular, form is A = L*D*L**T.
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 A       (input/output) COMPLEX array, dimension (LDA,N)
 On entry, the NNB diagonal matrix D and the multipliers
 used to obtain the factor U or L as computed by CSYTRF.
 On exit, if INFO = 0, the (symmetric) inverse of the original
 matrix.  If UPLO = \(aqU\(aq, the upper triangular part of the
 inverse is formed and the part of A below the diagonal is not
 referenced; if UPLO = \(aqL\(aq the lower triangular part of the
 inverse is formed and the part of A above the diagonal is
 not referenced.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the NNB structure of D
 as determined by CSYTRF.
.TP 8
 WORK    (workspace) COMPLEX array, dimension (N+NNB+1,NNB+3)
.TP 8
 NB      (input) INTEGER
 Block size
.TP 8
 INFO    (output) INTEGER
 = 0: successful exit
.br
 < 0: if INFO = -i, the i-th argument had an illegal value
.br
 > 0: if INFO = i, D(i,i) = 0; the matrix is singular and its
 inverse could not be computed.
