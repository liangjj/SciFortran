.TH  DZNRM2 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - returns the euclidean norm of a vector via the function name, so that   DZNRM2 := sqrt( x**H*x )  Further Details ===============  -- This version written on 25-October-1982
.SH SYNOPSIS
.TP 17
DOUBLE PRECISION
FUNCTION DZNRM2(N,X,INCX)
.TP 17
.ti +4
INTEGER
INCX,N
.TP 17
.ti +4
DOUBLE
COMPLEX X(*)
.SH PURPOSE
DZNRM2 returns the euclidean norm of a vector via the function
name, so that
    Modified on 14-October-1993 to inline the call to ZLASSQ.
    Sven Hammarling, Nag Ltd.
.br

