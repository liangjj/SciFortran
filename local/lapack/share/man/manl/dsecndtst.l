.TH  DSECNDTST 1 "November 2008" " LAPACK test routine (version 3.2) " " LAPACK test routine (version 3.2) " 
.SH NAME

.SH SYNOPSIS
.TP 14
PROGRAM TEST5
.TP 14
.ti +4
INTEGER
NMAX, ITS
.TP 14
.ti +4
PARAMETER
( NMAX = 100, ITS = 5000 )
.TP 14
.ti +4
INTEGER
I, J
.TP 14
.ti +4
DOUBLE
PRECISION ALPHA, AVG, T1, T2, TNOSEC
.TP 14
.ti +4
DOUBLE
PRECISION X( NMAX ), Y( NMAX )
.TP 14
.ti +4
DOUBLE
PRECISION DSECND
.TP 14
.ti +4
EXTERNAL
DSECND
.TP 14
.ti +4
INTRINSIC
DBLE
.TP 14
.ti +4
DO
10 I = 1, NMAX
.TP 14
.ti +4
X(
I ) = DBLE( 1 ) / DBLE( I )
.TP 14
.ti +4
Y(
I ) = DBLE( NMAX-I ) / DBLE( NMAX )
.TP 14
.ti +4
10
CONTINUE
.TP 14
.ti +4
ALPHA
= 0.315D0
.TP 14
.ti +4
T1
= DSECND( )
.TP 14
.ti +4
DO
30 J = 1, ITS
.TP 14
.ti +4
DO
20 I = 1, NMAX
.TP 14
.ti +4
Y(
I ) = Y( I ) + ALPHA*X( I )
.TP 14
.ti +4
20
CONTINUE
.TP 14
.ti +4
ALPHA
= -ALPHA
.TP 14
.ti +4
30
CONTINUE
.TP 14
.ti +4
T2
= DSECND( )
.TP 14
.ti +4
WRITE(
6, 9999 )T2 - T1
.TP 14
.ti +4
IF(
T2-T1.GT.0.0D0 ) THEN
.TP 14
.ti +4
WRITE(
6, 9998 )1.0D0 / ( T2-T1 )
.TP 14
.ti +4
ELSE
.TP 14
.ti +4
WRITE(
6, 9994 )
.TP 14
.ti +4
END
IF
.TP 14
.ti +4
TNOSEC
= T2 - T1
.TP 14
.ti +4
T1
= DSECND( )
.TP 14
.ti +4
DO
50 J = 1, ITS
.TP 14
.ti +4
DO
40 I = 1, NMAX
.TP 14
.ti +4
Y(
I ) = Y( I ) + ALPHA*X( I )
.TP 14
.ti +4
40
CONTINUE
.TP 14
.ti +4
ALPHA
= -ALPHA
.TP 14
.ti +4
T2
= DSECND( )
.TP 14
.ti +4
50
CONTINUE
.TP 14
.ti +4
WRITE(
6, 9997 )T2 - T1
.TP 14
.ti +4
AVG
= ( ( T2-T1 )-TNOSEC )*1000.D0 / DBLE( ITS )
.TP 14
.ti +4
WRITE(
6, 9996 )AVG
.TP 14
.ti +4
IF(
TNOSEC.GT.0.0D0 )
WRITE( 6, 9995 )1000.D0*AVG / TNOSEC
.TP 14
.ti +4
9999
FORMAT( \(aq Time for 1,000,000 DAXPY ops = \(aq, G10.3, \(aq seconds\(aq )
.TP 14
.ti +4
9998
FORMAT( \(aq DAXPY performance rate = \(aq, G10.3, \(aq mflops \(aq )
.TP 14
.ti +4
9997
FORMAT( \(aq Including DSECND, time = \(aq, G10.3, \(aq seconds\(aq )
.TP 14
.ti +4
9996
FORMAT( \(aq Average time for DSECND = \(aq, G10.3,
\(aq milliseconds\(aq )
.TP 14
.ti +4
9995
FORMAT( \(aq Equivalent floating point ops = \(aq, G10.3, \(aq ops\(aq )
.TP 14
.ti +4
9994
FORMAT( \(aq *** Error: Time for operations was zero\(aq )
.TP 14
.ti +4
CALL
MYSUB(NMAX,X,Y)
.TP 14
.ti +4
END
.TP 14
.ti +4
SUBROUTINE
MYSUB(N,X,Y)
.TP 14
.ti +4
INTEGER
N
.TP 14
.ti +4
DOUBLE
PRECISION X(N), Y(N)
.TP 14
.ti +4
RETURN
.TP 14
.ti +4
END
.SH PURPOSE
