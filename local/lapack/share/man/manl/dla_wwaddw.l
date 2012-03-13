.TH  DLA_WWADDW 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - DLA_WWADDW add a vector W into a doubled-single vector (X, Y)
.SH SYNOPSIS
.TP 23
SUBROUTINE DLA_WWADDW(
N, X, Y, W )
.TP 23
.ti +4
IMPLICIT
NONE
.TP 23
.ti +4
INTEGER
N
.TP 23
.ti +4
DOUBLE
PRECISION X( * ), Y( * ), W( * )
.SH PURPOSE
   DLA_WWADDW adds a vector W into a doubled-single vector (X, Y).
    This works for all extant IBM\(aqs hex and binary floating point
    arithmetics, but not for decimal.
.br
.SH ARGUMENTS
.TP 7
 N      (input) INTEGER
 The length of vectors X, Y, and W.
.TP 7
 X      (input/output) DOUBLE PRECISION array, dimension (N)
 The first part of the doubled-single accumulation vector.
.TP 7
 Y      (input/output) DOUBLE PRECISION array, dimension (N)
 The second part of the doubled-single accumulation vector.
.TP 7
 W      (input) DOUBLE PRECISION array, dimension (N)
 The vector to be added.
