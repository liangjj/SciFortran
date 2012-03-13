.TH  SCNRM2 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - returns the euclidean norm of a vector via the function name, so that   SCNRM2 := sqrt( x**H*x )  Further Details ===============  -- This version written on 25-October-1982
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SCNRM2(N,X,INCX)
.TP 14
.ti +4
INTEGER
INCX,N
.TP 14
.ti +4
COMPLEX
X(*)
.SH PURPOSE
SCNRM2 returns the euclidean norm of a vector via the function
name, so that
    Modified on 14-October-1993 to inline the call to CLASSQ.
    Sven Hammarling, Nag Ltd.
.br

