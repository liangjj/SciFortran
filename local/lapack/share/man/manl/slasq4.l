.TH  SLASQ4 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - computes an approximation TAU to the smallest eigenvalue using values of d from the previous transform
.SH SYNOPSIS
.TP 19
SUBROUTINE SLASQ4(
I0, N0, Z, PP, N0IN, DMIN, DMIN1, DMIN2, DN,
DN1, DN2, TAU, TTYPE, G )
.TP 19
.ti +4
INTEGER
I0, N0, N0IN, PP, TTYPE
.TP 19
.ti +4
REAL
DMIN, DMIN1, DMIN2, DN, DN1, DN2, G, TAU
.TP 19
.ti +4
REAL
Z( * )
.SH PURPOSE
SLASQ4 computes an approximation TAU to the smallest eigenvalue
using values of d from the previous transform.
.SH ARGUMENTS
.TP 6
 I0    (input) INTEGER
 First index.
.TP 6
 N0    (input) INTEGER
 Last index.
.TP 6
 Z     (input) REAL array, dimension ( 4*N )
 Z holds the qd array.
.TP 6
 PP    (input) INTEGER
 PP=0 for ping, PP=1 for pong.
.TP 6
 NOIN  (input) INTEGER
 The value of N0 at start of EIGTEST.
.TP 6
 DMIN  (input) REAL
 Minimum value of d.
 DMIN1 (input) REAL
 Minimum value of d, excluding D( N0 ).
 DMIN2 (input) REAL
 Minimum value of d, excluding D( N0 ) and D( N0-1 ).
.TP 6
 DN    (input) REAL
 d(N)
.TP 6
 DN1   (input) REAL
 d(N-1)
.TP 6
 DN2   (input) REAL
 d(N-2)
.TP 6
 TAU   (output) REAL
 This is the shift.
 TTYPE (output) INTEGER
 Shift type.
.TP 6
 G     (input/output) REAL
 G is passed as an argument in order to save its value between
 calls to SLASQ4.
.SH FURTHER DETAILS
