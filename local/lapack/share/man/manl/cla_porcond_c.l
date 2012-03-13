.TH  CLA_PORCOND_C 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - CLA_PORCOND_C Compute the infinity norm condition number of  op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector  Arguments =========   UPLO (input) CHARACTER*1  = \(aqU\(aq
.SH SYNOPSIS
.TP 14
REAL FUNCTION
CLA_PORCOND_C( UPLO, N, A, LDA, AF, LDAF, C, CAPPLY,
INFO, WORK, RWORK )
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
COMPLEX
A( LDA, * ), AF( LDAF, * ), WORK( * )
.TP 14
.ti +4
REAL
C( * ), RWORK( * )
.SH PURPOSE
   CLA_PORCOND_C Computes the infinity norm condition number of
   op(A) * inv(diag(C)) where C is a DOUBLE PRECISION vector
      = \(aqL\(aq:  Lower triangle of A is stored.
.br
    N       (input) INTEGER
.br
    The number of linear equations, i.e., the order of the
    matrix A.  N >= 0.
.br
    A       (input) COMPLEX array, dimension (LDA,N)
.br
    On entry, the N-by-N matrix A
.br
    LDA     (input) INTEGER
.br
    The leading dimension of the array A.  LDA >= max(1,N).
    AF      (input) COMPLEX array, dimension (LDAF,N)
.br
    The triangular factor U or L from the Cholesky factorization
    A = U**T*U or A = L*L**T, as computed by CPOTRF.
.br
    LDAF    (input) INTEGER
.br
    The leading dimension of the array AF.  LDAF >= max(1,N).
    C       (input) REAL array, dimension (N)
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
    WORK    (input) COMPLEX array, dimension (2*N).
.br
    Workspace.
.br
    RWORK   (input) REAL array, dimension (N).
.br
    Workspace.
.br
