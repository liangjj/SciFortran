.TH  XERBLA_ARRAY 1 "April 2011" "BLAS routine" "BLAS routine" 
.SH NAME
LAPACK-3 - assists other languages in calling XERBLA, the LAPACK and BLAS error handler
.SH SYNOPSIS
.TP 38
SUBROUTINE XERBLA_ARRAY(SRNAME_ARRAY,
SRNAME_LEN, INFO)
.TP 38
.ti +4
IMPLICIT
NONE
.TP 38
.ti +4
INTEGER
SRNAME_LEN, INFO
.TP 38
.ti +4
CHARACTER(1)
SRNAME_ARRAY(SRNAME_LEN)
.SH PURPOSE
XERBLA_ARRAY assists other languages in calling XERBLA, the LAPACK
and BLAS error handler.  Rather than taking a Fortran string argument
 as the function\(aqs name, XERBLA_ARRAY takes an array of single
 characters along with the array\(aqs length.  XERBLA_ARRAY then copies
 up to 32 characters of that array into a Fortran string and passes
 that to XERBLA.  If called with a non-positive SRNAME_LEN,
 XERBLA_ARRAY will call XERBLA with a string of all blank characters.

 Say some macro or other device makes XERBLA_ARRAY available to C99
 by a name lapack_xerbla and with a common Fortran calling convention.
 Then a C99 program could invoke XERBLA via:
.br
    {
.br
      int flen = strlen(__func__);
.br
      lapack_xerbla(__func__, &flen, &info);
.br
    }
.br

 Providing XERBLA_ARRAY is not necessary for intercepting LAPACK
 errors.  XERBLA_ARRAY calls XERBLA.
.br

.SH ARGUMENTS

 SRNAME_ARRAY (input) CHARACTER(1) array, dimension (SRNAME_LEN)
 The name of the routine which called XERBLA_ARRAY.

 SRNAME_LEN (input) INTEGER
 The length of the name in SRNAME_ARRAY.
.TP 8
 INFO    (input) INTEGER
 The position of the invalid parameter in the parameter list
 of the calling routine.
