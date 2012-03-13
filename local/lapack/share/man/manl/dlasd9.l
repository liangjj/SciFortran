.TH DLASD9 l "15 June 2000" "LAPACK version 3.0" ")"
.SH NAME
DLASD9 - find the square roots of the roots of the secular equation,
.SH SYNOPSIS
.TP 19
SUBROUTINE DLASD9(
ICOMPQ, LDU, K, D, Z, VF, VL, DIFL, DIFR,
DSIGMA, WORK, INFO )
.TP 19
.ti +4
INTEGER
ICOMPQ, INFO, K, LDU
.TP 19
.ti +4
DOUBLE
PRECISION D( * ), DIFL( * ), DIFR( LDU, * ), DSIGMA( * ),
VF( * ), VL( * ), WORK( * ), Z( * )
.SH PURPOSE
DLASD9 finds the square roots of the roots of the secular equation, as defined by the values in DSIGMA and Z.  It makes the
.br
appropriate calls to DLASD4, and stores, for each  element in D,
the distance to its two nearest poles (elements in DSIGMA). It also
updates the arrays VF and VL, the first and last components of all
the right singular vectors of the original bidiagonal matrix.

DLASD9 is called from DLASD7.
.br

.SH ARGUMENTS
.TP 8
ICOMPQ  (input) INTEGER
Specifies whether singular vectors are to be computed in
factored form in the calling routine:

ICOMPQ = 0             Compute singular values only.

ICOMPQ = 1             Compute singular vector matrices in
factored form also.
K       (input) INTEGER
The number of terms in the rational function to be solved by
DLASD4.  K >= 1.
.TP 8
D       (output) DOUBLE PRECISION array, dimension(K)
D(I) contains the updated singular values.
.TP 8
DSIGMA  (input) DOUBLE PRECISION array, dimension(K)
The first K elements of this array contain the old roots
of the deflated updating problem.  These are the poles
of the secular equation.
.TP 8
Z       (input) DOUBLE PRECISION array, dimension (K)
The first K elements of this array contain the components
of the deflation-adjusted updating row vector.
.TP 8
VF      (input/output) DOUBLE PRECISION array, dimension(K)
On entry, VF contains  information passed through SBEDE8.f
On exit, VF contains the first K components of the first
components of all right singular vectors of the bidiagonal
matrix.
.TP 8
VL      (input/output) DOUBLE PRECISION array, dimension(K)
On entry, VL contains  information passed through SBEDE8.f
On exit, VL contains the first K components of the last
components of all right singular vectors of the bidiagonal
matrix.
.TP 8
DIFL    (output) DOUBLE PRECISION array, dimension (K).
On exit, DIFL(I) = D(I) - DSIGMA(I).
.TP 8
DIFR    (output) DOUBLE PRECISION array,
dimension (LDU, 2) if ICOMPQ =1 and
dimension (K) if ICOMPQ = 0.
On exit, DIFR(I, 1) = D(I) - DSIGMA(I+1), DIFR(K, 1) is not
defined and will not be referenced.

If ICOMPQ = 1, DIFR(1:K, 2) is an array containing the
normalizing factors for the right singular vector matrix.
.TP 8
WORK    (workspace) DOUBLE PRECISION array,
dimension at least (3 * K)
Workspace.
.TP 8
INFO    (output) INTEGER
= 0:  successful exit.
.br
< 0:  if INFO = -i, the i-th argument had an illegal value.
.br
> 0:  if INFO = 1, an singular value did not converge
.SH FURTHER DETAILS
Based on contributions by
.br
   Ming Gu and Huan Ren, Computer Science Division, University of
   California at Berkeley, USA
.br

