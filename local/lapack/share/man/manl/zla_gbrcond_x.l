.TH  ZLA_GBRCOND_X 1 "April 2011" "    LAPACK routine (version 3.2.1)                               " "    LAPACK routine (version 3.2.1)                               " 
.SH NAME
LAPACK-3 - ZLA_GBRCOND_X Compute the infinity norm condition number of  op(A) * diag(X) where X is a COMPLEX*16 vector
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION ZLA_GBRCOND_X( TRANS, N, KL, KU, AB,
LDAB, AFB, LDAFB, IPIV,
X, INFO, WORK, RWORK )
.TP 17
.ti +4
IMPLICIT
NONE
.TP 17
.ti +4
CHARACTER
TRANS
.TP 17
.ti +4
INTEGER
N, KL, KU, KD, KE, LDAB, LDAFB, INFO
.TP 17
.ti +4
INTEGER
IPIV( * )
.TP 17
.ti +4
COMPLEX*16
AB( LDAB, * ), AFB( LDAFB, * ), WORK( * ),
X( * )
.TP 17
.ti +4
DOUBLE
PRECISION RWORK( * )
.SH PURPOSE
   ZLA_GBRCOND_X Computes the infinity norm condition number of
   op(A) * diag(X) where X is a COMPLEX*16 vector.
.SH ARGUMENTS
.TP 8
 TRANS   (input) CHARACTER*1
 Specifies the form of the system of equations:
.br
 = \(aqN\(aq:  A * X = B     (No transpose)
.br
 = \(aqT\(aq:  A**T * X = B  (Transpose)
.br
 = \(aqC\(aq:  A**H * X = B  (Conjugate Transpose = Transpose)
.TP 8
 N       (input) INTEGER
 The number of linear equations, i.e., the order of the
 matrix A.  N >= 0.
.TP 8
 KL      (input) INTEGER
 The number of subdiagonals within the band of A.  KL >= 0.
.TP 8
 KU      (input) INTEGER
 The number of superdiagonals within the band of A.  KU >= 0.
.TP 8
 AB      (input) COMPLEX*16 array, dimension (LDAB,N)
 On entry, the matrix A in band storage, in rows 1 to KL+KU+1.
 The j-th column of A is stored in the j-th column of the
 array AB as follows:
 AB(KU+1+i-j,j) = A(i,j) for max(1,j-KU)<=i<=min(N,j+kl)
.TP 8
 LDAB    (input) INTEGER
 The leading dimension of the array AB.  LDAB >= KL+KU+1.
.TP 8
 AFB     (input) COMPLEX*16 array, dimension (LDAFB,N)
 Details of the LU factorization of the band matrix A, as
 computed by ZGBTRF.  U is stored as an upper triangular
 band matrix with KL+KU superdiagonals in rows 1 to KL+KU+1,
 and the multipliers used during the factorization are stored
 in rows KL+KU+2 to 2*KL+KU+1.
.TP 8
 LDAFB   (input) INTEGER
 The leading dimension of the array AFB.  LDAFB >= 2*KL+KU+1.
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 The pivot indices from the factorization A = P*L*U
 as computed by ZGBTRF; row i of the matrix was interchanged
 with row IPIV(i).
.TP 8
 X       (input) COMPLEX*16 array, dimension (N)
 The vector X in the formula op(A) * diag(X).
.TP 8
 INFO    (output) INTEGER
 = 0:  Successful exit.
.br
 i > 0:  The ith argument is invalid.
.TP 8
 WORK    (input) COMPLEX*16 array, dimension (2*N).
 Workspace.
.TP 8
 RWORK   (input) DOUBLE PRECISION array, dimension (N).
 Workspace.
