.TH  ZLA_GBRPVGRW 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - computes the reciprocal pivot growth factor norm(A)/norm(U)
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION ZLA_GBRPVGRW( N, KL, KU, NCOLS, AB,
LDAB, AFB, LDAFB )
.TP 17
.ti +4
IMPLICIT
NONE
.TP 17
.ti +4
INTEGER
N, KL, KU, NCOLS, LDAB, LDAFB
.TP 17
.ti +4
COMPLEX*16
AB( LDAB, * ), AFB( LDAFB, * )
.SH PURPOSE
ZLA_GBRPVGRW computes the reciprocal pivot growth factor
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
 KL      (input) INTEGER
 The number of subdiagonals within the band of A.  KL >= 0.
.TP 8
 KU      (input) INTEGER
 The number of superdiagonals within the band of A.  KU >= 0.
.TP 8
 NCOLS   (input) INTEGER
 The number of columns of the matrix A.  NCOLS >= 0.
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
