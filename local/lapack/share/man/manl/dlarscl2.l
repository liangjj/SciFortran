.TH  DLARSCL2 1 "April 2011" "    LAPACK routine (version 3.2.2)                               " "    LAPACK routine (version 3.2.2)                               " 
.SH NAME
LAPACK-3 - performs a reciprocal diagonal scaling on an vector
.SH SYNOPSIS
.TP 20
SUBROUTINE DLARSCL2
( M, N, D, X, LDX )
.TP 20
.ti +4
IMPLICIT
NONE
.TP 20
.ti +4
INTEGER
M, N, LDX
.TP 20
.ti +4
DOUBLE
PRECISION D( * ), X( LDX, * )
.SH PURPOSE
DLARSCL2 performs a reciprocal diagonal scaling on an vector:
   x <-- inv(D) * x
.br
 where the diagonal matrix D is stored as a vector.
.br
 Eventually to be replaced by BLAS_dge_diag_scale in the new BLAS
 standard.
.br
.SH ARGUMENTS
.TP 8
 M       (input) INTEGER
 The number of rows of D and X. M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of D and X. N >= 0.
.TP 8
 D       (input) DOUBLE PRECISION array, dimension (M)
 Diagonal matrix D, stored as a vector of length M.
.TP 8
 X       (input/output) DOUBLE PRECISION array, dimension (LDX,N)
 On entry, the vector X to be scaled by D.
 On exit, the scaled vector.
.TP 8
 LDX     (input) INTEGER
 The leading dimension of the vector X. LDX >= 0.
