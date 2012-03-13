.TH  ZLA_PORCOND_C 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - ZLA_PORCOND_C Compute the infinity norm condition number of  op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector  Arguments =========   UPLO (input) CHARACTER*1  = \(aqU\(aq
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION ZLA_PORCOND_C( UPLO, N, A, LDA, AF,
LDAF, C, CAPPLY, INFO,
WORK, RWORK )
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
COMPLEX*16
A( LDA, * ), AF( LDAF, * ), WORK( * )
.TP 17
.ti +4
DOUBLE
PRECISION C( * ), RWORK( * )
.SH PURPOSE
   ZLA_PORCOND_C Computes the infinity norm condition number of
   op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector
      = \(aqL\(aq:  Lower triangle of A is stored.
.br
    N       (input) INTEGER
.br
    The number of linear equations, i.e., the order of the
    matrix A.  N >= 0.
.br
    A       (input) COMPLEX*16 array, dimension (LDA,N)
.br
    On entry, the N-by-N matrix A
.br
    LDA     (input) INTEGER
.br
    The leading dimension of the array A.  LDA >= max(1,N).
    AF      (input) COMPLEX*16 array, dimension (LDAF,N)
.br
    The triangular factor U or L from the Cholesky factorization
    A = U**H*U or A = L*L**H, as computed by ZPOTRF.
.br
    LDAF    (input) INTEGER
.br
    The leading dimension of the array AF.  LDAF >= max(1,N).
    C       (input) DOUBLE PRECISION array, dimension (N)
.br
    The vector C in the formula op(A) * inv(diag(C)).
.br
    CAPPLY  (input) LOGICAL
.br
    If .TRUE. then access the vector C in the formula above.
    INFO    (output) INTEGER
.br
      = 0:  Successful exit.
.br
    i > 0:  The ith argument is invalid.
.br
    WORK    (input) COMPLEX*16 array, dimension (2*N).
.br
    Workspace.
.br
    RWORK   (input) DOUBLE PRECISION array, dimension (N).
    Workspace.
.br
