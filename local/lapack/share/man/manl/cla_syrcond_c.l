.TH  CLA_SYRCOND_C 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - CLA_SYRCOND_C Compute the infinity norm condition number of  op(A) * inv(diag(C)) where C is a REAL vector
.SH SYNOPSIS
.TP 14
REAL FUNCTION
CLA_SYRCOND_C( UPLO, N, A, LDA, AF, LDAF, IPIV, C,
CAPPLY, INFO, WORK, RWORK )
.TP 14
.ti +4
IMPLICIT
NONE
.TP 14
.ti +4
CHARACTER
UPLO
.TP 14
.ti +4
LOGICAL
CAPPLY
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
A( LDA, * ), AF( LDAF, * ), WORK( * )
.TP 14
.ti +4
REAL
C( * ), RWORK( * )
.SH PURPOSE
   CLA_SYRCOND_C Computes the infinity norm condition number of
   op(A) * inv(diag(C)) where C is a REAL vector.
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 = \(aqU\(aq:  Upper triangle of A is stored;
.br
 = \(aqL\(aq:  Lower triangle of A is stored.
.TP 8
 N       (input) INTEGER
 The number of linear equations, i.e., the order of the
 matrix A.  N >= 0.
.TP 8
 A       (input) COMPLEX array, dimension (LDA,N)
 On entry, the N-by-N matrix A
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) COMPLEX array, dimension (LDAF,N)
 The block diagonal matrix D and the multipliers used to
 obtain the factor U or L as computed by CSYTRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the block structure of D
 as determined by CSYTRF.
.TP 8
 C       (input) REAL array, dimension (N)
 The vector C in the formula op(A) * inv(diag(C)).
.TP 8
 CAPPLY  (input) LOGICAL
 If .TRUE. then access the vector C in the formula above.
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
