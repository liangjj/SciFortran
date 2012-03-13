.TH  CGEEQUB 1 "April 2011" "    LAPACK routine (version 3.2)                                 " "    LAPACK routine (version 3.2)                                 " 
.SH NAME
LAPACK-3 - computes row and column scalings intended to equilibrate an M-by-N matrix A and reduce its condition number
.SH SYNOPSIS
.TP 20
SUBROUTINE CGEEQUB(
M, N, A, LDA, R, C, ROWCND, COLCND, AMAX,
INFO )
.TP 20
.ti +4
IMPLICIT
NONE
.TP 20
.ti +4
INTEGER
INFO, LDA, M, N
.TP 20
.ti +4
REAL
AMAX, COLCND, ROWCND
.TP 20
.ti +4
REAL
C( * ), R( * )
.TP 20
.ti +4
COMPLEX
A( LDA, * )
.SH PURPOSE
CGEEQUB computes row and column scalings intended to equilibrate an
M-by-N matrix A and reduce its condition number.  R returns the row
 scale factors and C the column scale factors, chosen to try to make
 the largest element in each row and column of the matrix B with
 elements B(i,j)=R(i)*A(i,j)*C(j) have an absolute value of at most
 the radix.
.br
 R(i) and C(j) are restricted to be a power of the radix between
 SMLNUM = smallest safe number and BIGNUM = largest safe number.  Use
 of these scaling factors is not guaranteed to reduce the condition
 number of A but works well in practice.
.br
 This routine differs from CGEEQU by restricting the scaling factors
 to a power of the radix.  Baring over- and underflow, scaling by
 these factors introduces no additional rounding errors.  However, the
 scaled entries\(aq magnitured are no longer approximately 1 but lie
 between sqrt(radix) and 1/sqrt(radix).
.br
.SH ARGUMENTS
.TP 8
 M       (input) INTEGER
 The number of rows of the matrix A.  M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of the matrix A.  N >= 0.
.TP 8
 A       (input) COMPLEX array, dimension (LDA,N)
 The M-by-N matrix whose equilibration factors are
 to be computed.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 R       (output) REAL array, dimension (M)
 If INFO = 0 or INFO > M, R contains the row scale factors
 for A.
.TP 8
 C       (output) REAL array, dimension (N)
 If INFO = 0,  C contains the column scale factors for A.
.TP 8
 ROWCND  (output) REAL
 If INFO = 0 or INFO > M, ROWCND contains the ratio of the
 smallest R(i) to the largest R(i).  If ROWCND >= 0.1 and
 AMAX is neither too large nor too small, it is not worth
 scaling by R.
.TP 8
 COLCND  (output) REAL
 If INFO = 0, COLCND contains the ratio of the smallest
 C(i) to the largest C(i).  If COLCND >= 0.1, it is not
 worth scaling by C.
.TP 8
 AMAX    (output) REAL
 Absolute value of largest matrix element.  If AMAX is very
 close to overflow or very close to underflow, the matrix
 should be scaled.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
.br
 > 0:  if INFO = i,  and i is
.br
 <= M:  the i-th row of A is exactly zero
.br
 >  M:  the (i-M)-th column of A is exactly zero
