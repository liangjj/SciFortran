.TH  DORCSD 1 "April 2011" " LAPACK routine (version 3.3.1) " " LAPACK routine (version 3.3.1) " 
.SH NAME
LAPACK-3 - computes the CS decomposition of an M-by-M partitioned orthogonal matrix X
.SH SYNOPSIS
.TP 21
RECURSIVE SUBROUTINE
DORCSD( JOBU1, JOBU2, JOBV1T, JOBV2T, TRANS,
SIGNS, M, P, Q, X11, LDX11, X12,
LDX12, X21, LDX21, X22, LDX22, THETA,
U1, LDU1, U2, LDU2, V1T, LDV1T, V2T,
LDV2T, WORK, LWORK, IWORK, INFO )
.TP 21
.ti +4
IMPLICIT
NONE
.TP 21
.ti +4
CHARACTER
JOBU1, JOBU2, JOBV1T, JOBV2T, SIGNS, TRANS
.TP 21
.ti +4
INTEGER
INFO, LDU1, LDU2, LDV1T, LDV2T, LDX11, LDX12,
LDX21, LDX22, LWORK, M, P, Q
.TP 21
.ti +4
INTEGER
IWORK( * )
.TP 21
.ti +4
DOUBLE
PRECISION THETA( * )
.TP 21
.ti +4
DOUBLE
PRECISION U1( LDU1, * ), U2( LDU2, * ), V1T( LDV1T, * ),
V2T( LDV2T, * ), WORK( * ), X11( LDX11, * ),
X12( LDX12, * ), X21( LDX21, * ), X22( LDX22,
* )
.SH PURPOSE
DORCSD computes the CS decomposition of an M-by-M partitioned
orthogonal matrix X:
                                 [  I  0  0 |  0  0  0 ]
.br
                                 [  0  C  0 |  0 -S  0 ]
.br
     [ X11 | X12 ]   [ U1 |    ] [  0  0  0 |  0  0 -I ] [ V1 |    ]**T
 X = [-----------] = [---------] [---------------------] [---------]   .
     [ X21 | X22 ]   [    | U2 ] [  0  0  0 |  I  0  0 ] [    | V2 ]
                                 [  0  S  0 |  0  C  0 ]
.br
                                 [  0  0  I |  0  0  0 ]
.br
 X11 is P-by-Q. The orthogonal matrices U1, U2, V1, and V2 are P-by-P,
 (M-P)-by-(M-P), Q-by-Q, and (M-Q)-by-(M-Q), respectively. C and S are
 R-by-R nonnegative diagonal matrices satisfying C^2 + S^2 = I, in
 which R = MIN(P,M-P,Q,M-Q).
.br
.SH ARGUMENTS
.TP 8
 JOBU1   (input) CHARACTER
 = \(aqY\(aq:      U1 is computed;
.br
 otherwise:  U1 is not computed.
.TP 8
 JOBU2   (input) CHARACTER
.br
 = \(aqY\(aq:      U2 is computed;
.br
 otherwise:  U2 is not computed.
.TP 8
 JOBV1T  (input) CHARACTER
.br
 = \(aqY\(aq:      V1T is computed;
.br
 otherwise:  V1T is not computed.
.TP 8
 JOBV2T  (input) CHARACTER
.br
 = \(aqY\(aq:      V2T is computed;
.br
 otherwise:  V2T is not computed.
.TP 8
 TRANS   (input) CHARACTER
.br
 = \(aqT\(aq:      X, U1, U2, V1T, and V2T are stored in row-major
 order;
 otherwise:  X, U1, U2, V1T, and V2T are stored in column-
 major order.
.TP 8
 SIGNS   (input) CHARACTER
 = \(aqO\(aq:      The lower-left block is made nonpositive (the
 "other" convention);
 otherwise:  The upper-right block is made nonpositive (the
 "default" convention).
.TP 8
 M       (input) INTEGER
 The number of rows and columns in X.
.TP 8
 P       (input) INTEGER
 The number of rows in X11 and X12. 0 <= P <= M.
.TP 8
 Q       (input) INTEGER
 The number of columns in X11 and X21. 0 <= Q <= M.
.TP 8
 X       (input/workspace) DOUBLE PRECISION array, dimension (LDX,M)
 On entry, the orthogonal matrix whose CSD is desired.
.TP 8
 LDX     (input) INTEGER
 The leading dimension of X. LDX >= MAX(1,M).
.TP 8
 THETA   (output) DOUBLE PRECISION array, dimension (R), in which R =
 MIN(P,M-P,Q,M-Q).
 C = DIAG( COS(THETA(1)), ... , COS(THETA(R)) ) and
 S = DIAG( SIN(THETA(1)), ... , SIN(THETA(R)) ).
.TP 8
 U1      (output) DOUBLE PRECISION array, dimension (P)
 If JOBU1 = \(aqY\(aq, U1 contains the P-by-P orthogonal matrix U1.
.TP 8
 LDU1    (input) INTEGER
 The leading dimension of U1. If JOBU1 = \(aqY\(aq, LDU1 >=
 MAX(1,P).
.TP 8
 U2      (output) DOUBLE PRECISION array, dimension (M-P)
 If JOBU2 = \(aqY\(aq, U2 contains the (M-P)-by-(M-P) orthogonal
 matrix U2.
.TP 8
 LDU2    (input) INTEGER
 The leading dimension of U2. If JOBU2 = \(aqY\(aq, LDU2 >=
 MAX(1,M-P).
.TP 8
 V1T     (output) DOUBLE PRECISION array, dimension (Q)
 If JOBV1T = \(aqY\(aq, V1T contains the Q-by-Q matrix orthogonal
 matrix V1**T.
.TP 8
 LDV1T   (input) INTEGER
 The leading dimension of V1T. If JOBV1T = \(aqY\(aq, LDV1T >=
 MAX(1,Q).
.TP 8
 V2T     (output) DOUBLE PRECISION array, dimension (M-Q)
 If JOBV2T = \(aqY\(aq, V2T contains the (M-Q)-by-(M-Q) orthogonal
 matrix V2**T.
.TP 8
 LDV2T   (input) INTEGER
 The leading dimension of V2T. If JOBV2T = \(aqY\(aq, LDV2T >=
 MAX(1,M-Q).
.TP 8
 WORK    (workspace) DOUBLE PRECISION array, dimension (MAX(1,LWORK))
 On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
 If INFO > 0 on exit, WORK(2:R) contains the values PHI(1),
 ..., PHI(R-1) that, together with THETA(1), ..., THETA(R),
 define the matrix in intermediate bidiagonal-block form
 remaining after nonconvergence. INFO specifies the number
 of nonzero PHI\(aqs.
.TP 8
 LWORK   (input) INTEGER
 The dimension of the array WORK.
 If LWORK = -1, then a workspace query is assumed; the routine
 only calculates the optimal size of the WORK array, returns
 this value as the first entry of the work array, and no error
 message related to LWORK is issued by XERBLA.
.TP 8
 IWORK   (workspace) INTEGER array, dimension (M-MIN(P, M-P, Q, M-Q))
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit.
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value.
.br
 > 0:  DBBCSD did not converge. See the description of WORK
 above for details.
 Reference
 =========
 [1] Brian D. Sutton. Computing the complete CS decomposition. Numer.
 Algorithms, 50(1):33-65, 2009.
