.TH  ZPSTRF 1 "April 2011" " LAPACK routine (version 3.2.2)                                  " " LAPACK routine (version 3.2.2)                                  " 
.SH NAME
LAPACK-3 - computes the Cholesky factorization with complete pivoting of a complex Hermitian positive semidefinite matrix A
.SH SYNOPSIS
.TP 19
SUBROUTINE ZPSTRF(
UPLO, N, A, LDA, PIV, RANK, TOL, WORK, INFO )
.TP 19
.ti +4
DOUBLE
PRECISION TOL
.TP 19
.ti +4
INTEGER
INFO, LDA, N, RANK
.TP 19
.ti +4
CHARACTER
UPLO
.TP 19
.ti +4
COMPLEX*16
A( LDA, * )
.TP 19
.ti +4
DOUBLE
PRECISION WORK( 2*N )
.TP 19
.ti +4
INTEGER
PIV( N )
.SH PURPOSE
ZPSTRF computes the Cholesky factorization with complete
pivoting of a complex Hermitian positive semidefinite matrix A.
 The factorization has the form
.br
    P**T * A * P = U**H * U ,  if UPLO = \(aqU\(aq,
.br
    P**T * A * P = L  * L**H,  if UPLO = \(aqL\(aq,
.br
 where U is an upper triangular matrix and L is lower triangular, and
 P is stored as vector PIV.
.br
 This algorithm does not attempt to check that A is positive
 semidefinite. This version of the algorithm calls level 3 BLAS.
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 Specifies whether the upper or lower triangular part of the
 symmetric matrix A is stored.
 = \(aqU\(aq:  Upper triangular
.br
 = \(aqL\(aq:  Lower triangular
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 A       (input/output) COMPLEX*16 array, dimension (LDA,N)
 On entry, the symmetric matrix A.  If UPLO = \(aqU\(aq, the leading
 n by n upper triangular part of A contains the upper
 triangular part of the matrix A, and the strictly lower
 triangular part of A is not referenced.  If UPLO = \(aqL\(aq, the
 leading n by n lower triangular part of A contains the lower
 triangular part of the matrix A, and the strictly upper
 triangular part of A is not referenced.
 On exit, if INFO = 0, the factor U or L from the Cholesky
 factorization as above.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 PIV     (output) INTEGER array, dimension (N)
 PIV is such that the nonzero entries are P( PIV(K), K ) = 1.
.TP 8
 RANK    (output) INTEGER
 The rank of A given by the number of steps the algorithm
 completed.
.TP 8
 TOL     (input) DOUBLE PRECISION
 User defined tolerance. If TOL < 0, then N*U*MAX( A(K,K) )
 will be used. The algorithm terminates at the (K-1)st step
 if the pivot <= TOL.
.TP 8
 WORK    (workspace) DOUBLE PRECISION array, dimension (2*N)
 Work space.
.TP 8
 INFO    (output) INTEGER
 < 0: If INFO = -K, the K-th argument had an illegal value,
.br
 = 0: algorithm completed successfully, and
.br
 > 0: the matrix A is either rank deficient with computed rank
 as returned in RANK, or is indefinite.  See Section 7 of
 LAPACK Working Note #161 for further information.
