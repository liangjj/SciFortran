.TH  CLASCL2 1 "April 2011" "    LAPACK routine (version 3.2.1)                               " "    LAPACK routine (version 3.2.1)                               " 
.SH NAME
LAPACK-3 - performs a diagonal scaling on a vector
.SH SYNOPSIS
.TP 19
SUBROUTINE CLASCL2
( M, N, D, X, LDX )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
INTEGER
M, N, LDX
.TP 19
.ti +4
REAL
D( * )
.TP 19
.ti +4
COMPLEX
X( LDX, * )
.SH PURPOSE
CLASCL2 performs a diagonal scaling on a vector:
   x <-- D * x
.br
 where the diagonal REAL matrix D is stored as a vector.
.br
 Eventually to be replaced by BLAS_cge_diag_scale in the new BLAS
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
 D       (input) REAL array, length M
 Diagonal matrix D, stored as a vector of length M.
.TP 8
 X       (input/output) COMPLEX array, dimension (LDX,N)
 On entry, the vector X to be scaled by D.
 On exit, the scaled vector.
.TP 8
 LDX     (input) INTEGER
 The leading dimension of the vector X. LDX >= 0.
