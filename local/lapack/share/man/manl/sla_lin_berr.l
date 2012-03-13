.TH  SLA_LIN_BERR 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - SLA_LIN_BERR compute componentwise relative backward error from  the formula  max(i) ( abs(R(i)) / ( abs(op(A_s))*abs(Y) + abs(B_s) )(i) )  where abs(Z) is the componentwise absolute value of the matrix  or vector Z
.SH SYNOPSIS
.TP 24
SUBROUTINE SLA_LIN_BERR
( N, NZ, NRHS, RES, AYB, BERR )
.TP 24
.ti +4
IMPLICIT
NONE
.TP 24
.ti +4
INTEGER
N, NZ, NRHS
.TP 24
.ti +4
REAL
AYB( N, NRHS ), BERR( NRHS )
.TP 24
.ti +4
REAL
RES( N, NRHS )
.SH PURPOSE
   SLA_LIN_BERR computes componentwise relative backward error from
   the formula
       max(i) ( abs(R(i)) / ( abs(op(A_s))*abs(Y) + abs(B_s) )(i) )
   where abs(Z) is the componentwise absolute value of the matrix
   or vector Z.
.SH ARGUMENTS
.TP 8
 N       (input) INTEGER
 The number of linear equations, i.e., the order of the
 matrix A.  N >= 0.
.TP 8
 NZ      (input) INTEGER
 We add (NZ+1)*SLAMCH( \(aqSafe minimum\(aq ) to R(i) in the numerator to
 guard against spuriously zero residuals. Default value is N.
.TP 8
 NRHS    (input) INTEGER
 The number of right hand sides, i.e., the number of columns
 of the matrices AYB, RES, and BERR.  NRHS >= 0.
.TP 7
 RES    (input) REAL array, dimension (N,NRHS)
 The residual matrix, i.e., the matrix R in the relative backward
 error formula above.
.TP 7
 AYB    (input) REAL array, dimension (N, NRHS)
 The denominator in the relative backward error formula above, i.e.,
 the matrix abs(op(A_s))*abs(Y) + abs(B_s). The matrices A, Y, and B
 are from iterative refinement (see sla_gerfsx_extended.f).
  BERR   (output) REAL array, dimension (NRHS)
 The componentwise relative backward error from the formula above.
