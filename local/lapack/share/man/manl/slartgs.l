.TH  SLARTGS 1 "April 2011" " LAPACK routine (version 3.3.0) " " LAPACK routine (version 3.3.0) " 
.SH NAME
LAPACK-3 - generates a plane rotation designed to introduce a bulge in Golub-Reinsch-style implicit QR iteration for the bidiagonal SVD problem
.SH SYNOPSIS
.TP 20
SUBROUTINE SLARTGS(
X, Y, SIGMA, CS, SN )
.TP 20
.ti +4
IMPLICIT
NONE
.TP 20
.ti +4
REAL
CS, SIGMA, SN, X, Y
.SH PURPOSE
SLARTGS generates a plane rotation designed to introduce a bulge in
Golub-Reinsch-style implicit QR iteration for the bidiagonal SVD
problem. X and Y are the top-row entries, and SIGMA is the shift.
 The computed CS and SN define a plane rotation satisfying
    [  CS  SN  ]  .  [ X^2 - SIGMA ]  =  [ R ],
.br
    [ -SN  CS  ]     [    X * Y    ]     [ 0 ]
.br
 with R nonnegative.  If X^2 - SIGMA and X * Y are 0, then the
 rotation is by PI/2.
.br
.SH ARGUMENTS
.TP 8
 X       (input) REAL
 The (1,1) entry of an upper bidiagonal matrix.
.TP 8
 Y       (input) REAL
 The (1,2) entry of an upper bidiagonal matrix.
.TP 8
 SIGMA   (input) REAL
 The shift.
.TP 8
 CS      (output) REAL
 The cosine of the rotation.
.TP 8
 SN      (output) REAL
 The sine of the rotation.
