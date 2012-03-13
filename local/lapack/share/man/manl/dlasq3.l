.TH  DLASQ3 1 "April 2011" " LAPACK routine (version 3.2.2)                                    " " LAPACK routine (version 3.2.2)                                    " 
.SH NAME
LAPACK-3 - checks for deflation, computes a shift (TAU) and calls dqds
.SH SYNOPSIS
.TP 19
SUBROUTINE DLASQ3(
I0, N0, Z, PP, DMIN, SIGMA, DESIG, QMAX, NFAIL,
ITER, NDIV, IEEE, TTYPE, DMIN1, DMIN2, DN, DN1,
DN2, G, TAU )
.TP 19
.ti +4
LOGICAL
IEEE
.TP 19
.ti +4
INTEGER
I0, ITER, N0, NDIV, NFAIL, PP
.TP 19
.ti +4
DOUBLE
PRECISION DESIG, DMIN, DMIN1, DMIN2, DN, DN1, DN2, G,
QMAX, SIGMA, TAU
.TP 19
.ti +4
DOUBLE
PRECISION Z( * )
.SH PURPOSE
DLASQ3 checks for deflation, computes a shift (TAU) and calls dqds.
 In case of failure it changes shifts, and tries again until output
 is positive.
.br
.SH ARGUMENTS
.TP 7
 I0     (input) INTEGER
 First index.
.TP 7
 N0     (input/output) INTEGER
 Last index.
.TP 7
 Z      (input) DOUBLE PRECISION array, dimension ( 4*N )
 Z holds the qd array.
.TP 7
 PP     (input/output) INTEGER
 PP=0 for ping, PP=1 for pong.
 PP=2 indicates that flipping was applied to the Z array   
 and that the initial tests for deflation should not be 
 performed.
.TP 7
 DMIN   (output) DOUBLE PRECISION
 Minimum value of d.
.TP 7
 SIGMA  (output) DOUBLE PRECISION
 Sum of shifts used in current segment.
.TP 7
 DESIG  (input/output) DOUBLE PRECISION
 Lower order part of SIGMA
.TP 7
 QMAX   (input) DOUBLE PRECISION
 Maximum value of q.
.TP 7
 NFAIL  (output) INTEGER
 Number of times shift was too big.
.TP 7
 ITER   (output) INTEGER
 Number of iterations.
.TP 7
 NDIV   (output) INTEGER
 Number of divisions.
.TP 7
 IEEE   (input) LOGICAL
 Flag for IEEE or non IEEE arithmetic (passed to DLASQ5).
.TP 7
 TTYPE  (input/output) INTEGER
 Shift type.
.TP 7
 DMIN1  (input/output) DOUBLE PRECISION
.TP 7
 DMIN2  (input/output) DOUBLE PRECISION
.TP 7
 DN     (input/output) DOUBLE PRECISION
.TP 7
 DN1    (input/output) DOUBLE PRECISION
.TP 7
 DN2    (input/output) DOUBLE PRECISION
.TP 7
 G      (input/output) DOUBLE PRECISION
.TP 7
 TAU    (input/output) DOUBLE PRECISION
 These are passed as arguments in order to save their values
 between calls to DLASQ3.
