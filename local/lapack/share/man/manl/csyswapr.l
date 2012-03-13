.TH  CSYSWAPR 1 "April 2011" " LAPACK auxiliary routine (version 3.3.1) " " LAPACK auxiliary routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - applies an elementary permutation on the rows and the columns of a symmetric matrix
.SH SYNOPSIS
.TP 21
SUBROUTINE CSYSWAPR(
UPLO, N, A, LDA, I1, I2)
.TP 21
.ti +4
CHARACTER
UPLO
.TP 21
.ti +4
INTEGER
I1, I2, LDA, N
.TP 21
.ti +4
COMPLEX
A( LDA, N )
.SH PURPOSE
CSYSWAPR applies an elementary permutation on the rows and the columns of
a symmetric matrix.
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
 On entry, the NB diagonal matrix D and the multipliers
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
 I1      (input) INTEGER
 Index of the first row to swap
.TP 8
 I2      (input) INTEGER
 Index of the second row to swap
