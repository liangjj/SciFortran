.TH  CLA_GERCOND_X 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - CLA_GERCOND_X compute the infinity norm condition number of  op(A) * diag(X) where X is a COMPLEX vector
.SH SYNOPSIS
.TP 14
REAL FUNCTION
CLA_GERCOND_X( TRANS, N, A, LDA, AF, LDAF, IPIV, X,
INFO, WORK, RWORK )
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
N, LDA, LDAF, INFO
.TP 14
.ti +4
INTEGER
IPIV( * )
.TP 14
.ti +4
COMPLEX
A( LDA, * ), AF( LDAF, * ), WORK( * ), X( * )
.TP 14
.ti +4
REAL
RWORK( * )
.SH PURPOSE
   CLA_GERCOND_X computes the infinity norm condition number of
   op(A) * diag(X) where X is a COMPLEX vector.
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
 A       (input) COMPLEX array, dimension (LDA,N)
 On entry, the N-by-N matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) COMPLEX array, dimension (LDAF,N)
 The factors L and U from the factorization
 A = P*L*U as computed by CGETRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 The pivot indices from the factorization A = P*L*U
 as computed by CGETRF; row i of the matrix was interchanged
 with row IPIV(i).
.TP 8
 X       (input) COMPLEX array, dimension (N)
 The vector X in the formula op(A) * diag(X).
.TP 8
 INFO    (output) INTEGER
 = 0:  Successful exit.
.br
 i > 0:  The ith argument is invalid.
.TP 8
 WORK    (input) COMPLEX array, dimension (2*N).
 Workspace.
.TP 8
 RWORK   (input) REAL array, dimension (N).
 Workspace.
