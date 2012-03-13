.TH  ZLA_SYRCOND_C 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - ZLA_SYRCOND_C Compute the infinity norm condition number of  op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION ZLA_SYRCOND_C( UPLO, N, A, LDA, AF,
LDAF, IPIV, C, CAPPLY,
INFO, WORK, RWORK )
.TP 17
.ti +4
IMPLICIT
NONE
.TP 17
.ti +4
CHARACTER
UPLO
.TP 17
.ti +4
LOGICAL
CAPPLY
.TP 17
.ti +4
INTEGER
N, LDA, LDAF, INFO
.TP 17
.ti +4
INTEGER
IPIV( * )
.TP 17
.ti +4
COMPLEX*16
A( LDA, * ), AF( LDAF, * ), WORK( * )
.TP 17
.ti +4
DOUBLE
PRECISION C( * ), RWORK( * )
.SH PURPOSE
   ZLA_SYRCOND_C Computes the infinity norm condition number of
   op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector.
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
 A       (input) COMPLEX*16 array, dimension (LDA,N)
 On entry, the N-by-N matrix A
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) COMPLEX*16 array, dimension (LDAF,N)
 The block diagonal matrix D and the multipliers used to
 obtain the factor U or L as computed by ZSYTRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the block structure of D
 as determined by ZSYTRF.
.TP 8
 C       (input) DOUBLE PRECISION array, dimension (N)
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
 WORK    (input) COMPLEX*16 array, dimension (2*N).
 Workspace.
.TP 8
 RWORK   (input) DOUBLE PRECISION array, dimension (N).
 Workspace.
