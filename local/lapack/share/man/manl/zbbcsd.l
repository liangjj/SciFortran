.TH  ZBBCSD 1 "April 2011" " LAPACK routine (version 3.3.0) " " LAPACK routine (version 3.3.0) " 
.SH NAME
LAPACK-3 - computes the CS decomposition of a unitary matrix in bidiagonal-block form,
.SH SYNOPSIS
.TP 19
SUBROUTINE ZBBCSD(
JOBU1, JOBU2, JOBV1T, JOBV2T, TRANS, M, P, Q,
THETA, PHI, U1, LDU1, U2, LDU2, V1T, LDV1T,
V2T, LDV2T, B11D, B11E, B12D, B12E, B21D, B21E,
B22D, B22E, RWORK, LRWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
CHARACTER
JOBU1, JOBU2, JOBV1T, JOBV2T, TRANS
.TP 19
.ti +4
INTEGER
INFO, LDU1, LDU2, LDV1T, LDV2T, LRWORK, M, P, Q
.TP 19
.ti +4
DOUBLE
PRECISION B11D( * ), B11E( * ), B12D( * ), B12E( * ),
B21D( * ), B21E( * ), B22D( * ), B22E( * ),
PHI( * ), THETA( * ), RWORK( * )
.TP 19
.ti +4
COMPLEX*16
U1( LDU1, * ), U2( LDU2, * ), V1T( LDV1T, * ),
V2T( LDV2T, * )
.SH PURPOSE
ZBBCSD computes the CS decomposition of a unitary matrix in
bidiagonal-block form,
     [ B11 | B12 0  0 ]
.br
     [  0  |  0 -I  0 ]
.br
 X = [----------------]
.br
     [ B21 | B22 0  0 ]
.br
     [  0  |  0  0  I ]
.br
                               [  C | -S  0  0 ]
.br
                   [ U1 |    ] [  0 |  0 -I  0 ] [ V1 |    ]**H
                 = [---------] [---------------] [---------]   .
                   [    | U2 ] [  S |  C  0  0 ] [    | V2 ]
                               [  0 |  0  0  I ]
.br
 X is M-by-M, its top-left block is P-by-Q, and Q must be no larger
 than P, M-P, or M-Q. (If Q is not the smallest index, then X must be
 transposed and/or permuted. This can be done in constant time using
 the TRANS and SIGNS options. See ZUNCSD for details.)
.br
 The bidiagonal matrices B11, B12, B21, and B22 are represented
 implicitly by angles THETA(1:Q) and PHI(1:Q-1).
.br
 The unitary matrices U1, U2, V1T, and V2T are input/output.
 The input matrices are pre- or post-multiplied by the appropriate
 singular vector matrices.
.br
.SH ARGUMENTS
.TP 8
 JOBU1   (input) CHARACTER
 = \(aqY\(aq:      U1 is updated;
.br
 otherwise:  U1 is not updated.
.TP 8
 JOBU2   (input) CHARACTER
.br
 = \(aqY\(aq:      U2 is updated;
.br
 otherwise:  U2 is not updated.
.TP 8
 JOBV1T  (input) CHARACTER
.br
 = \(aqY\(aq:      V1T is updated;
.br
 otherwise:  V1T is not updated.
.TP 8
 JOBV2T  (input) CHARACTER
.br
 = \(aqY\(aq:      V2T is updated;
.br
 otherwise:  V2T is not updated.
.TP 8
 TRANS   (input) CHARACTER
.br
 = \(aqT\(aq:      X, U1, U2, V1T, and V2T are stored in row-major
 order;
 otherwise:  X, U1, U2, V1T, and V2T are stored in column-
 major order.
.TP 8
 M       (input) INTEGER
 The number of rows and columns in X, the unitary matrix in
 bidiagonal-block form.
.TP 8
 P       (input) INTEGER
 The number of rows in the top-left block of X. 0 <= P <= M.
.TP 8
 Q       (input) INTEGER
 The number of columns in the top-left block of X.
 0 <= Q <= MIN(P,M-P,M-Q).
.TP 8
 THETA   (input/output) DOUBLE PRECISION array, dimension (Q)
 On entry, the angles THETA(1),...,THETA(Q) that, along with
 PHI(1), ...,PHI(Q-1), define the matrix in bidiagonal-block
 form. On exit, the angles whose cosines and sines define the
 diagonal blocks in the CS decomposition.
.TP 8
 PHI     (input/workspace) DOUBLE PRECISION array, dimension (Q-1)
 The angles PHI(1),...,PHI(Q-1) that, along with THETA(1),...,
 THETA(Q), define the matrix in bidiagonal-block form.
.TP 8
 U1      (input/output) COMPLEX*16 array, dimension (LDU1,P)
 On entry, an LDU1-by-P matrix. On exit, U1 is postmultiplied
 by the left singular vector matrix common to [ B11 ; 0 ] and
 [ B12 0 0 ; 0 -I 0 0 ].
.TP 8
 LDU1    (input) INTEGER
 The leading dimension of the array U1.
.TP 8
 U2      (input/output) COMPLEX*16 array, dimension (LDU2,M-P)
 On entry, an LDU2-by-(M-P) matrix. On exit, U2 is
 postmultiplied by the left singular vector matrix common to
 [ B21 ; 0 ] and [ B22 0 0 ; 0 0 I ].
.TP 8
 LDU2    (input) INTEGER
 The leading dimension of the array U2.
.TP 8
 V1T     (input/output) COMPLEX*16 array, dimension (LDV1T,Q)
 On entry, a LDV1T-by-Q matrix. On exit, V1T is premultiplied
 by the conjugate transpose of the right singular vector
 matrix common to [ B11 ; 0 ] and [ B21 ; 0 ].
.TP 8
 LDV1T   (input) INTEGER
 The leading dimension of the array V1T.
.TP 8
 V2T     (input/output) COMPLEX*16 array, dimenison (LDV2T,M-Q)
 On entry, a LDV2T-by-(M-Q) matrix. On exit, V2T is
 premultiplied by the conjugate transpose of the right
 singular vector matrix common to [ B12 0 0 ; 0 -I 0 ] and
 [ B22 0 0 ; 0 0 I ].
.TP 8
 LDV2T   (input) INTEGER
 The leading dimension of the array V2T.
.TP 8
 B11D    (output) DOUBLE PRECISION array, dimension (Q)
 When ZBBCSD converges, B11D contains the cosines of THETA(1),
 ..., THETA(Q). If ZBBCSD fails to converge, then B11D
 contains the diagonal of the partially reduced top-left
 block.
.TP 8
 B11E    (output) DOUBLE PRECISION array, dimension (Q-1)
 When ZBBCSD converges, B11E contains zeros. If ZBBCSD fails
 to converge, then B11E contains the superdiagonal of the
 partially reduced top-left block.
.TP 8
 B12D    (output) DOUBLE PRECISION array, dimension (Q)
 When ZBBCSD converges, B12D contains the negative sines of
 THETA(1), ..., THETA(Q). If ZBBCSD fails to converge, then
 B12D contains the diagonal of the partially reduced top-right
 block.
.TP 8
 B12E    (output) DOUBLE PRECISION array, dimension (Q-1)
 When ZBBCSD converges, B12E contains zeros. If ZBBCSD fails
 to converge, then B12E contains the subdiagonal of the
 partially reduced top-right block.
.TP 8
 RWORK   (workspace) DOUBLE PRECISION array, dimension (MAX(1,LWORK))
 On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
.TP 8
 LRWORK  (input) INTEGER
 The dimension of the array RWORK. LRWORK >= MAX(1,8*Q).
 If LRWORK = -1, then a workspace query is assumed; the
 routine only calculates the optimal size of the RWORK array,
 returns this value as the first entry of the work array, and
 no error message related to LRWORK is issued by XERBLA.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit.
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value.
.br
 > 0:  if ZBBCSD did not converge, INFO specifies the number
 of nonzero entries in PHI, and B11D, B11E, etc.,
 contain the partially reduced matrix.
 Reference
 =========
 [1] Brian D. Sutton. Computing the complete CS decomposition. Numer.
 Algorithms, 50(1):33-65, 2009.
.SH PARAMETERS
.TP 8
 TOLMUL  DOUBLE PRECISION, default = MAX(10,MIN(100,EPS**(-1/8)))
 TOLMUL controls the convergence criterion of the QR loop.
 Angles THETA(i), PHI(i) are rounded to 0 or PI/2 when they
 are within TOLMUL*EPS of either bound.
