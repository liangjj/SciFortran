.TH  SLA_PORPVGRW 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - computes the reciprocal pivot growth factor norm(A)/norm(U)
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SLA_PORPVGRW( UPLO, NCOLS, A, LDA, AF, LDAF, WORK )
.TP 14
.ti +4
IMPLICIT
NONE
.TP 14
.ti +4
CHARACTER*1
UPLO
.TP 14
.ti +4
INTEGER
NCOLS, LDA, LDAF
.TP 14
.ti +4
REAL
A( LDA, * ), AF( LDAF, * ), WORK( * )
.SH PURPOSE
SLA_PORPVGRW computes the reciprocal pivot growth factor
norm(A)/norm(U). The "max absolute element" norm is used. If this is
 much less than 1, the stability of the LU factorization of the
 (equilibrated) matrix A could be poor. This also means that the
 solution X, estimated condition numbers, and error bounds could be
 unreliable.
.br
.SH ARGUMENTS
.TP 8
 UPLO    (input) CHARACTER*1
 = \(aqU\(aq:  Upper triangle of A is stored;
.br
 = \(aqL\(aq:  Lower triangle of A is stored.
.TP 8
 NCOLS   (input) INTEGER
 The number of columns of the matrix A. NCOLS >= 0.
.TP 8
 A       (input) REAL array, dimension (LDA,N)
 On entry, the N-by-N matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) REAL array, dimension (LDAF,N)
 The triangular factor U or L from the Cholesky factorization
 A = U**T*U or A = L*L**T, as computed by SPOTRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 WORK    (input) REAL array, dimension (2*N)
