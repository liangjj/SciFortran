.TH  ZLA_GBAMV 1 "April 2011" "    LAPACK routine (version 3.3.1)                                 " "    LAPACK routine (version 3.3.1)                                 " 
.SH NAME
LAPACK-3 - performs one of the matrix-vector operations   y := alpha*abs(A)*abs(x) + beta*abs(y),
.SH SYNOPSIS
.TP 22
SUBROUTINE ZLA_GBAMV(
TRANS, M, N, KL, KU, ALPHA, AB, LDAB, X,
INCX, BETA, Y, INCY )
.TP 22
.ti +4
IMPLICIT
NONE
.TP 22
.ti +4
DOUBLE
PRECISION ALPHA, BETA
.TP 22
.ti +4
INTEGER
INCX, INCY, LDAB, M, N, KL, KU, TRANS
.TP 22
.ti +4
COMPLEX*16
AB( LDAB, * ), X( * )
.TP 22
.ti +4
DOUBLE
PRECISION Y( * )
.SH PURPOSE
ZLA_GBAMV  performs one of the matrix-vector operations
    or   y := alpha*abs(A)**T*abs(x) + beta*abs(y),
.br
 where alpha and beta are scalars, x and y are vectors and A is an
 m by n matrix.
.br
 This function is primarily used in calculating error bounds.
 To protect against underflow during evaluation, components in
 the resulting vector are perturbed away from zero by (N+1)
 times the underflow threshold.  To prevent unnecessarily large
 errors for block-structure embedded in general matrices,
.br
 "symbolically" zero components are not perturbed.  A zero
 entry is considered "symbolic" if all multiplications involved
 in computing that entry have at least one zero multiplicand.
.SH ARGUMENTS
.TP 8
 TRANS   (input) INTEGER
 On entry, TRANS specifies the operation to be performed as
 follows:
.TP 19
 BLAS_NO_TRANS      y := alpha*abs(A)*abs(x) + beta*abs(y)
.br
 BLAS_TRANS         y := alpha*abs(A**T)*abs(x) + beta*abs(y)
.br
 BLAS_CONJ_TRANS    y := alpha*abs(A**T)*abs(x) + beta*abs(y)
 Unchanged on exit.
.TP 9
 M        (input) INTEGER
 On entry, M specifies the number of rows of the matrix A.
 M must be at least zero.
 Unchanged on exit.
.TP 9
 N        (input) INTEGER
 On entry, N specifies the number of columns of the matrix A.
 N must be at least zero.
 Unchanged on exit.
.TP 9
 KL       (input) INTEGER
 The number of subdiagonals within the band of A.  KL >= 0.
.TP 9
 KU       (input) INTEGER
 The number of superdiagonals within the band of A.  KU >= 0.
.TP 9
 ALPHA    (input) DOUBLE PRECISION
 On entry, ALPHA specifies the scalar alpha.
 Unchanged on exit.
.TP 9
 AB       (input) COMPLEX*16 array of DIMENSION ( LDAB, n )
 Before entry, the leading m by n part of the array AB must
 contain the matrix of coefficients.
 Unchanged on exit.
.TP 9
 LDAB     (input) INTEGER
 On entry, LDAB specifies the first dimension of AB as declared
 in the calling (sub) program. LDAB must be at least
 max( 1, m ).
 Unchanged on exit.
.TP 9
 X        (input) COMPLEX*16 array, dimension
 ( 1 + ( n - 1 )*abs( INCX ) ) when TRANS = \(aqN\(aq or \(aqn\(aq
 and at least
 ( 1 + ( m - 1 )*abs( INCX ) ) otherwise.
 Before entry, the incremented array X must contain the
 vector x.
 Unchanged on exit.
.TP 9
 INCX     (input) INTEGER
 On entry, INCX specifies the increment for the elements of
 X. INCX must not be zero.
 Unchanged on exit.
.TP 9
 BETA     (input)  DOUBLE PRECISION
 On entry, BETA specifies the scalar beta. When BETA is
 supplied as zero then Y need not be set on input.
 Unchanged on exit.
.TP 9
 Y        (input/output) DOUBLE PRECISION  array, dimension
 ( 1 + ( m - 1 )*abs( INCY ) ) when TRANS = \(aqN\(aq or \(aqn\(aq
 and at least
 ( 1 + ( n - 1 )*abs( INCY ) ) otherwise.
 Before entry with BETA non-zero, the incremented array Y
 must contain the vector y. On exit, Y is overwritten by the
 updated vector y.
.TP 9
 INCY     (input) INTEGER
 On entry, INCY specifies the increment for the elements of
 Y. INCY must not be zero.
 Unchanged on exit.
 Level 2 Blas routine.
