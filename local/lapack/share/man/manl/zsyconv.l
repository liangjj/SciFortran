.TH  ZSYCONV 1 "April 2011" " LAPACK PROTOTYPE routine (version 3.2.2) " " LAPACK PROTOTYPE routine (version 3.2.2) " 
.SH NAME
LAPACK-3 - converts A given by ZHETRF into L and D or vice-versa
.SH SYNOPSIS
.TP 20
SUBROUTINE ZSYCONV(
UPLO, WAY, N, A, LDA, IPIV, WORK, INFO )
.TP 20
.ti +4
CHARACTER
UPLO, WAY
.TP 20
.ti +4
INTEGER
INFO, LDA, N
.TP 20
.ti +4
INTEGER
IPIV( * )
.TP 20
.ti +4
DOUBLE
COMPLEX A( LDA, * ), WORK( * )
.SH PURPOSE
ZSYCONV converts A given by ZHETRF into L and D or vice-versa.
 Get nondiagonal elements of D (returned in workspace) and 
 apply or reverse permutation done in TRF.
.br
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 Specifies whether the details of the factorization are stored
 as an upper or lower triangular matrix.
 = \(aqU\(aq:  Upper triangular, form is A = U*D*U**T;
.br
 = \(aqL\(aq:  Lower triangular, form is A = L*D*L**T.
.TP 8
 WAY     (input) CHARACTER*1
.br
 = \(aqC\(aq: Convert 
.br
 = \(aqR\(aq: Revert
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 A       (input) DOUBLE COMPLEX array, dimension (LDA,N)
 The block diagonal matrix D and the multipliers used to
 obtain the factor U or L as computed by ZSYTRF.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the block structure of D
 as determined by ZSYTRF.
 The length of WORK.  LWORK >=1. 
 LWORK = N
 If LWORK = -1, then a workspace query is assumed; the routine
 only calculates the optimal size of the WORK array, returns
 this value as the first entry of the WORK array, and no error
 message related to LWORK is issued by XERBLA.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
