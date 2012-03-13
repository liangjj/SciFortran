.TH  DSYTRI2 1 "April 2011" " LAPACK routine (version 3.3.1) " " LAPACK routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - computes the inverse of a DOUBLE PRECISION hermitian indefinite matrix A using the factorization A = U*D*U**T or A = L*D*L**T computed by DSYTRF
.SH SYNOPSIS
.TP 20
SUBROUTINE DSYTRI2(
UPLO, N, A, LDA, IPIV, WORK, LWORK, INFO )
.TP 20
.ti +4
CHARACTER
UPLO
.TP 20
.ti +4
INTEGER
INFO, LDA, LWORK, N
.TP 20
.ti +4
INTEGER
IPIV( * )
.TP 20
.ti +4
DOUBLE
PRECISION A( LDA, * ), WORK( * )
.SH PURPOSE
DSYTRI2 computes the inverse of a DOUBLE PRECISION hermitian indefinite matrix
A using the factorization A = U*D*U**T or A = L*D*L**T computed by
DSYTRF. DSYTRI2 sets the LEADING DIMENSION of the workspace
 before calling DSYTRI2X that actually computes the inverse.
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
 A       (input/output) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, the NB diagonal matrix D and the multipliers
 used to obtain the factor U or L as computed by DSYTRF.
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
 Details of the interchanges and the NB structure of D
 as determined by DSYTRF.
.TP 8
 WORK    (workspace) DOUBLE PRECISION array, dimension (N+NB+1)*(NB+3)
.TP 8
 LWORK   (input) INTEGER
 The dimension of the array WORK.
 WORK is size >= (N+NB+1)*(NB+3)
 If LDWORK = -1, then a workspace query is assumed; the routine
 calculates:
 - the optimal size of the WORK array, returns
 this value as the first entry of the WORK array,
 - and no error message related to LDWORK is issued by XERBLA.
.TP 8
 INFO    (output) INTEGER
 = 0: successful exit
.br
 < 0: if INFO = -i, the i-th argument had an illegal value
.br
 > 0: if INFO = i, D(i,i) = 0; the matrix is singular and its
 inverse could not be computed.
