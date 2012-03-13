.TH  SLAMCHTST 1 "November 2008" " LAPACK test routine (version 3.2) " " LAPACK test routine (version 3.2) " 
.SH NAME

.SH SYNOPSIS
.TP 14
PROGRAM TEST2
.TP 14
.ti +4
REAL
BASE, EMAX, EMIN, EPS, RMAX, RMIN, RND, SFMIN,
T, PREC
.TP 14
.ti +4
REAL
SLAMCH
.TP 14
.ti +4
EXTERNAL
SLAMCH
.TP 14
.ti +4
EPS
= SLAMCH( \(aqEpsilon\(aq )
.TP 14
.ti +4
SFMIN
= SLAMCH( \(aqSafe minimum\(aq )
.TP 14
.ti +4
BASE
= SLAMCH( \(aqBase\(aq )
.TP 14
.ti +4
PREC
= SLAMCH( \(aqPrecision\(aq )
.TP 14
.ti +4
T
= SLAMCH( \(aqNumber of digits in mantissa\(aq )
.TP 14
.ti +4
RND
= SLAMCH( \(aqRounding mode\(aq )
.TP 14
.ti +4
EMIN
= SLAMCH( \(aqMinimum exponent\(aq )
.TP 14
.ti +4
RMIN
= SLAMCH( \(aqUnderflow threshold\(aq )
.TP 14
.ti +4
EMAX
= SLAMCH( \(aqLargest exponent\(aq )
.TP 14
.ti +4
RMAX
= SLAMCH( \(aqOverflow threshold\(aq )
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
