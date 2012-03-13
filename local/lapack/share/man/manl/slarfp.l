.TH  SLARFP 1 "November 2008" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
SLARFP - generates a real elementary reflector H of order n, such that   H * ( alpha ) = ( beta ), H\(aq * H = I
.SH SYNOPSIS
.TP 19
SUBROUTINE SLARFP(
N, ALPHA, X, INCX, TAU )
.TP 19
.ti +4
INTEGER
INCX, N
.TP 19
.ti +4
REAL
ALPHA, TAU
.TP 19
.ti +4
REAL
X( * )
.SH PURPOSE
SLARFP generates a real elementary reflector H of order n, such
that
          (   x   )   (   0  )
.br
where alpha and beta are scalars, beta is non-negative, and x is
an (n-1)-element real vector.  H is represented in the form
      H = I - tau * ( 1 ) * ( 1 v\(aq ) ,
.br
                    ( v )
.br
where tau is a real scalar and v is a real (n-1)-element
.br
vector.
.br
If the elements of x are all zero, then tau = 0 and H is taken to be
the unit matrix.
.br
Otherwise  1 <= tau <= 2.
.br
.SH ARGUMENTS
.TP 8
N       (input) INTEGER
The order of the elementary reflector.
.TP 8
ALPHA   (input/output) REAL
On entry, the value alpha.
On exit, it is overwritten with the value beta.
.TP 8
X       (input/output) REAL array, dimension
(1+(N-2)*abs(INCX))
On entry, the vector x.
On exit, it is overwritten with the vector v.
.TP 8
INCX    (input) INTEGER
The increment between elements of X. INCX > 0.
.TP 8
TAU     (output) REAL
The value tau.
