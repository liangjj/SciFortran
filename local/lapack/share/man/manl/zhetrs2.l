.TH  ZHETRS2 1 "April 2011" " LAPACK PROTOTYPE routine (version 3.3.1) " " LAPACK PROTOTYPE routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - solves a system of linear equations A*X = B with a complex Hermitian matrix A using the factorization A = U*D*U**H or A = L*D*L**H computed by ZHETRF and converted by ZSYCONV
.SH SYNOPSIS
.TP 20
SUBROUTINE ZHETRS2(
UPLO, N, NRHS, A, LDA, IPIV, B, LDB,
WORK, INFO )
.TP 20
.ti +4
CHARACTER
UPLO
.TP 20
.ti +4
INTEGER
INFO, LDA, LDB, N, NRHS
.TP 20
.ti +4
INTEGER
IPIV( * )
.TP 20
.ti +4
DOUBLE
COMPLEX A( LDA, * ), B( LDB, * ), WORK( * )
.SH PURPOSE
ZHETRS2 solves a system of linear equations A*X = B with a complex
Hermitian matrix A using the factorization A = U*D*U**H or
A = L*D*L**H computed by ZHETRF and converted by ZSYCONV.
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 Specifies whether the details of the factorization are stored
 as an upper or lower triangular matrix.
 = \(aqU\(aq:  Upper triangular, form is A = U*D*U**H;
.br
 = \(aqL\(aq:  Lower triangular, form is A = L*D*L**H.
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 NRHS    (input) INTEGER
 The number of right hand sides, i.e., the number of columns
 of the matrix B.  NRHS >= 0.
.TP 8
 A       (input) DOUBLE COMPLEX array, dimension (LDA,N)
 The block diagonal matrix D and the multipliers used to
 obtain the factor U or L as computed by ZHETRF.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the block structure of D
 as determined by ZHETRF.
.TP 8
 B       (input/output) DOUBLE COMPLEX array, dimension (LDB,NRHS)
 On entry, the right hand side matrix B.
 On exit, the solution matrix X.
.TP 8
 LDB     (input) INTEGER
 The leading dimension of the array B.  LDB >= max(1,N).
.TP 8
 WORK    (workspace) REAL array, dimension (N)
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
