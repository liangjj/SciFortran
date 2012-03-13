.TH  DLA_GERCOND 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - DLA_GERCOND estimate the Skeel condition number of op(A) * op2(C)  where op2 is determined by CMODE as follows  CMODE = 1 op2(C) = C  CMODE = 0 op2(C) = I  CMODE = -1 op2(C) = inv(C)  The Skeel condition number cond(A) = norminf( |inv(A)||A| )  is computed by computing scaling factors R such that  diag(R)*A*op2(C) is row equilibrated and computing the standard  infinity-norm condition number
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION DLA_GERCOND ( TRANS, N, A, LDA, AF,
LDAF, IPIV, CMODE, C,
INFO, WORK, IWORK )
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
N, LDA, LDAF, INFO, CMODE
.TP 17
.ti +4
INTEGER
IPIV( * ), IWORK( * )
.TP 17
.ti +4
DOUBLE
PRECISION A( LDA, * ), AF( LDAF, * ), WORK( * ),
C( * )
.SH PURPOSE
   DLA_GERCOND estimates the Skeel condition number of op(A) * op2(C)
   where op2 is determined by CMODE as follows
   CMODE =  1    op2(C) = C
   CMODE =  0    op2(C) = I
   CMODE = -1    op2(C) = inv(C)
   The Skeel condition number cond(A) = norminf( |inv(A)||A| )
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
 A       (input) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, the N-by-N matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) DOUBLE PRECISION array, dimension (LDAF,N)
 The factors L and U from the factorization
 A = P*L*U as computed by DGETRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 The pivot indices from the factorization A = P*L*U
 as computed by DGETRF; row i of the matrix was interchanged
 with row IPIV(i).
.TP 8
 CMODE   (input) INTEGER
 Determines op2(C) in the formula op(A) * op2(C) as follows:
 CMODE =  1    op2(C) = C
 CMODE =  0    op2(C) = I
 CMODE = -1    op2(C) = inv(C)
.TP 8
 C       (input) DOUBLE PRECISION array, dimension (N)
 The vector C in the formula op(A) * op2(C).
.TP 8
 INFO    (output) INTEGER
 = 0:  Successful exit.
.br
 i > 0:  The ith argument is invalid.
.TP 8
 WORK    (input) DOUBLE PRECISION array, dimension (3*N).
 Workspace.
.TP 8
 IWORK   (input) INTEGER array, dimension (N).
 Workspace.
