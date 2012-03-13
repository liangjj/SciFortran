.TH  DLAMCHTST 1 "November 2008" " LAPACK test routine (version 3.2) " " LAPACK test routine (version 3.2) " 
.SH NAME

.SH SYNOPSIS
.TP 14
PROGRAM TEST3
.TP 14
.ti +4
DOUBLE
PRECISION BASE, EMAX, EMIN, EPS, PREC, RMAX, RMIN, RND,
SFMIN, T
.TP 14
.ti +4
DOUBLE
PRECISION DLAMCH
.TP 14
.ti +4
EXTERNAL
DLAMCH
.TP 14
.ti +4
EPS
= DLAMCH( \(aqEpsilon\(aq )
.TP 14
.ti +4
SFMIN
= DLAMCH( \(aqSafe minimum\(aq )
.TP 14
.ti +4
BASE
= DLAMCH( \(aqBase\(aq )
.TP 14
.ti +4
PREC
= DLAMCH( \(aqPrecision\(aq )
.TP 14
.ti +4
T
= DLAMCH( \(aqNumber of digits in mantissa\(aq )
.TP 14
.ti +4
RND
= DLAMCH( \(aqRounding mode\(aq )
.TP 14
.ti +4
EMIN
= DLAMCH( \(aqMinimum exponent\(aq )
.TP 14
.ti +4
RMIN
= DLAMCH( \(aqUnderflow threshold\(aq )
.TP 14
.ti +4
EMAX
= DLAMCH( \(aqLargest exponent\(aq )
.TP 14
.ti +4
RMAX
= DLAMCH( \(aqOverflow threshold\(aq )
.TP 14
.ti +4
WRITE(
6, * )\(aq Epsilon = \(aq, EPS
.TP 14
.ti +4
WRITE(
6, * )\(aq Safe minimum = \(aq, SFMIN
.TP 14
.ti +4
WRITE(
6, * )\(aq Base = \(aq, BASE
.TP 14
.ti +4
WRITE(
6, * )\(aq Precision = \(aq, PREC
.TP 14
.ti +4
WRITE(
6, * )\(aq Number of digits in mantissa = \(aq, T
.TP 14
.ti +4
WRITE(
6, * )\(aq Rounding mode = \(aq, RND
.TP 14
.ti +4
WRITE(
6, * )\(aq Minimum exponent = \(aq, EMIN
.TP 14
.ti +4
WRITE(
6, * )\(aq Underflow threshold = \(aq, RMIN
.TP 14
.ti +4
WRITE(
6, * )\(aq Largest exponent = \(aq, EMAX
.TP 14
.ti +4
WRITE(
6, * )\(aq Overflow threshold = \(aq, RMAX
.TP 14
.ti +4
WRITE(
6, * )\(aq Reciprocal of safe minimum = \(aq, 1 / SFMIN
.TP 14
.ti +4
END
.SH PURPOSE
