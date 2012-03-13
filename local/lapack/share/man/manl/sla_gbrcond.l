.TH  SLA_GBRCOND 1 "April 2011" "    LAPACK routine (version 3.2.2)                               " "    LAPACK routine (version 3.2.2)                               " 
.SH NAME
LAPACK-3 - SLA_GBRCOND Estimate the Skeel condition number of op(A) * op2(C)  where op2 is determined by CMODE as follows  CMODE = 1 op2(C) = C  CMODE = 0 op2(C) = I  CMODE = -1 op2(C) = inv(C)  The Skeel condition number cond(A) = norminf( |inv(A)||A| )  is computed by computing scaling factors R such that  diag(R)*A*op2(C) is row equilibrated and computing the standard  infinity-norm condition number
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SLA_GBRCOND( TRANS, N, KL, KU, AB, LDAB, AFB, LDAFB,
IPIV, CMODE, C, INFO, WORK, IWORK )
.TP 14
.ti +4
IMPLICIT
NONE
.TP 14
.ti +4
CHARACTER
TRANS
.TP 14
.ti +4
INTEGER
N, LDAB, LDAFB, INFO, KL, KU, CMODE
.TP 14
.ti +4
INTEGER
IWORK( * ), IPIV( * )
.TP 14
.ti +4
REAL
AB( LDAB, * ), AFB( LDAFB, * ), WORK( * ),
C( * )
.SH PURPOSE
   SLA_GBRCOND Estimates the Skeel condition number of  op(A) * op2(C)
   where op2 is determined by CMODE as follows
   CMODE =  1    op2(C) = C
   CMODE =  0    op2(C) = I
   CMODE = -1    op2(C) = inv(C)
   The Skeel condition number  cond(A) = norminf( |inv(A)||A| )
   is computed by computing scaling factors R such that
   diag(R)*A*op2(C) is row equilibrated and computing the standard
   infinity-norm condition number.
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
 AB      (input) REAL array, dimension (LDAB,N)
 On entry, the matrix A in band storage, in rows 1 to KL+KU+1.
 The j-th column of A is stored in the j-th column of the
 array AB as follows:
 AB(KU+1+i-j,j) = A(i,j) for max(1,j-KU)<=i<=min(N,j+kl)
.TP 8
 LDAB    (input) INTEGER
 The leading dimension of the array AB.  LDAB >= KL+KU+1.
.TP 8
 AFB     (input) REAL array, dimension (LDAFB,N)
 Details of the LU factorization of the band matrix A, as
 computed by SGBTRF.  U is stored as an upper triangular
 band matrix with KL+KU superdiagonals in rows 1 to KL+KU+1,
 and the multipliers used during the factorization are stored
 in rows KL+KU+2 to 2*KL+KU+1.
.TP 8
 LDAFB   (input) INTEGER
 The leading dimension of the array AFB.  LDAFB >= 2*KL+KU+1.
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 The pivot indices from the factorization A = P*L*U
 as computed by SGBTRF; row i of the matrix was interchanged
 with row IPIV(i).
.TP 8
 CMODE   (input) INTEGER
 Determines op2(C) in the formula op(A) * op2(C) as follows:
 CMODE =  1    op2(C) = C
 CMODE =  0    op2(C) = I
 CMODE = -1    op2(C) = inv(C)
.TP 8
 C       (input) REAL array, dimension (N)
 The vector C in the formula op(A) * op2(C).
.TP 8
 INFO    (output) INTEGER
 = 0:  Successful exit.
.br
 i > 0:  The ith argument is invalid.
.TP 8
 WORK    (input) REAL array, dimension (5*N).
 Workspace.
.TP 8
 IWORK   (input) INTEGER array, dimension (N).
 Workspace.
