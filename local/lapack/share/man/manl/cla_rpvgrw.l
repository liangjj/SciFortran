.TH  CLA_RPVGRW 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - computes the reciprocal pivot growth factor norm(A)/norm(U)
.SH SYNOPSIS
.TP 14
REAL FUNCTION
CLA_RPVGRW( N, NCOLS, A, LDA, AF, LDAF )
.TP 14
.ti +4
IMPLICIT
NONE
.TP 14
.ti +4
INTEGER
N, NCOLS, LDA, LDAF
.TP 14
.ti +4
COMPLEX
A( LDA, * ), AF( LDAF, * )
.SH PURPOSE
CLA_RPVGRW computes the reciprocal pivot growth factor
norm(A)/norm(U). The "max absolute element" norm is used. If this is
 much less than 1, the stability of the LU factorization of the
 (equilibrated) matrix A could be poor. This also means that the
 solution X, estimated condition numbers, and error bounds could be
 unreliable.
.br
.SH ARGUMENTS
.TP 8
 N       (input) INTEGER
 The number of linear equations, i.e., the order of the
 matrix A.  N >= 0.
.TP 8
 NCOLS   (input) INTEGER
 The number of columns of the matrix A. NCOLS >= 0.
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
