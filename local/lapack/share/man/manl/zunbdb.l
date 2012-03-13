.TH  ZUNBDB 1 "April 2011" " LAPACK routine ((version 3.3.0)) " " LAPACK routine ((version 3.3.0)) " 
.SH NAME
LAPACK-3 - simultaneously bidiagonalize the blocks of an M-by-M partitioned unitary matrix X
.SH SYNOPSIS
.TP 19
SUBROUTINE ZUNBDB(
TRANS, SIGNS, M, P, Q, X11, LDX11, X12, LDX12,
X21, LDX21, X22, LDX22, THETA, PHI, TAUP1,
TAUP2, TAUQ1, TAUQ2, WORK, LWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
CHARACTER
SIGNS, TRANS
.TP 19
.ti +4
INTEGER
INFO, LDX11, LDX12, LDX21, LDX22, LWORK, M, P,
Q
.TP 19
.ti +4
DOUBLE
PRECISION PHI( * ), THETA( * )
.TP 19
.ti +4
COMPLEX*16
TAUP1( * ), TAUP2( * ), TAUQ1( * ), TAUQ2( * ),
WORK( * ), X11( LDX11, * ), X12( LDX12, * ),
X21( LDX21, * ), X22( LDX22, * )
.SH PURPOSE
ZUNBDB simultaneously bidiagonalizes the blocks of an M-by-M
partitioned unitary matrix X:
                                 [ B11 | B12 0  0 ]
.br
     [ X11 | X12 ]   [ P1 |    ] [  0  |  0 -I  0 ] [ Q1 |    ]**H
 X = [-----------] = [---------] [----------------] [---------]   .
     [ X21 | X22 ]   [    | P2 ] [ B21 | B22 0  0 ] [    | Q2 ]
                                 [  0  |  0  0  I ]
.br
 X11 is P-by-Q. Q must be no larger than P, M-P, or M-Q. (If this is
 not the case, then X must be transposed and/or permuted. This can be
 done in constant time using the TRANS and SIGNS options. See ZUNCSD
 for details.)
.br
 The unitary matrices P1, P2, Q1, and Q2 are P-by-P, (M-P)-by-
 (M-P), Q-by-Q, and (M-Q)-by-(M-Q), respectively. They are
 represented implicitly by Householder vectors.
.br
 B11, B12, B21, and B22 are Q-by-Q bidiagonal matrices represented
 implicitly by angles THETA, PHI.
.br
.SH ARGUMENTS
.TP 8
 TRANS   (input) CHARACTER
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
 The number of columns in X11 and X21. 0 <= Q <=
 MIN(P,M-P,M-Q).
.TP 8
 X11     (input/output) COMPLEX*16 array, dimension (LDX11,Q)
 On entry, the top-left block of the unitary matrix to be
 reduced. On exit, the form depends on TRANS:
 If TRANS = \(aqN\(aq, then
 the columns of tril(X11) specify reflectors for P1,
 the rows of triu(X11,1) specify reflectors for Q1;
 else TRANS = \(aqT\(aq, and
 the rows of triu(X11) specify reflectors for P1,
 the columns of tril(X11,-1) specify reflectors for Q1.
.TP 8
 LDX11   (input) INTEGER
 The leading dimension of X11. If TRANS = \(aqN\(aq, then LDX11 >=
 P; else LDX11 >= Q.
.TP 8
 X12     (input/output) COMPLEX*16 array, dimension (LDX12,M-Q)
 On entry, the top-right block of the unitary matrix to
 be reduced. On exit, the form depends on TRANS:
 If TRANS = \(aqN\(aq, then
 the rows of triu(X12) specify the first P reflectors for
 Q2;
 else TRANS = \(aqT\(aq, and
 the columns of tril(X12) specify the first P reflectors
 for Q2.
.TP 8
 LDX12   (input) INTEGER
 The leading dimension of X12. If TRANS = \(aqN\(aq, then LDX12 >=
 P; else LDX11 >= M-Q.
.TP 8
 X21     (input/output) COMPLEX*16 array, dimension (LDX21,Q)
 On entry, the bottom-left block of the unitary matrix to
 be reduced. On exit, the form depends on TRANS:
 If TRANS = \(aqN\(aq, then
 the columns of tril(X21) specify reflectors for P2;
 else TRANS = \(aqT\(aq, and
 the rows of triu(X21) specify reflectors for P2.
.TP 8
 LDX21   (input) INTEGER
 The leading dimension of X21. If TRANS = \(aqN\(aq, then LDX21 >=
 M-P; else LDX21 >= Q.
.TP 8
 X22     (input/output) COMPLEX*16 array, dimension (LDX22,M-Q)
 On entry, the bottom-right block of the unitary matrix to
 be reduced. On exit, the form depends on TRANS:
 If TRANS = \(aqN\(aq, then
 the rows of triu(X22(Q+1:M-P,P+1:M-Q)) specify the last
 M-P-Q reflectors for Q2,
 else TRANS = \(aqT\(aq, and
 the columns of tril(X22(P+1:M-Q,Q+1:M-P)) specify the last
 M-P-Q reflectors for P2.
.TP 8
 LDX22   (input) INTEGER
 The leading dimension of X22. If TRANS = \(aqN\(aq, then LDX22 >=
 M-P; else LDX22 >= M-Q.
.TP 8
 THETA   (output) DOUBLE PRECISION array, dimension (Q)
 The entries of the bidiagonal blocks B11, B12, B21, B22 can
 be computed from the angles THETA and PHI. See Further
 Details.
.TP 8
 PHI     (output) DOUBLE PRECISION array, dimension (Q-1)
 The entries of the bidiagonal blocks B11, B12, B21, B22 can
 be computed from the angles THETA and PHI. See Further
 Details.
.TP 8
 TAUP1   (output) COMPLEX*16 array, dimension (P)
 The scalar factors of the elementary reflectors that define
 P1.
.TP 8
 TAUP2   (output) COMPLEX*16 array, dimension (M-P)
 The scalar factors of the elementary reflectors that define
 P2.
.TP 8
 TAUQ1   (output) COMPLEX*16 array, dimension (Q)
 The scalar factors of the elementary reflectors that define
 Q1.
.TP 8
 TAUQ2   (output) COMPLEX*16 array, dimension (M-Q)
 The scalar factors of the elementary reflectors that define
 Q2.
.TP 8
 WORK    (workspace) COMPLEX*16 array, dimension (LWORK)
.TP 8
 LWORK   (input) INTEGER
 The dimension of the array WORK. LWORK >= M-Q.
 If LWORK = -1, then a workspace query is assumed; the routine
 only calculates the optimal size of the WORK array, returns
 this value as the first entry of the WORK array, and no error
 message related to LWORK is issued by XERBLA.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit.
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value.
.SH FURTHER DETAILS
 The bidiagonal blocks B11, B12, B21, and B22 are represented
 implicitly by angles THETA(1), ..., THETA(Q) and PHI(1), ...,
 PHI(Q-1). B11 and B21 are upper bidiagonal, while B21 and B22 are
 lower bidiagonal. Every entry in each bidiagonal band is a product
 of a sine or cosine of a THETA with a sine or cosine of a PHI. See
 [1] or ZUNCSD for details.
.br
 P1, P2, Q1, and Q2 are represented as products of elementary
 reflectors. See ZUNCSD for details on generating P1, P2, Q1, and Q2
 using ZUNGQR and ZUNGLQ.
.br
 Reference
.br
 =========
.br
 [1] Brian D. Sutton. Computing the complete CS decomposition. Numer.
     Algorithms, 50(1):33-65, 2009.
.br
