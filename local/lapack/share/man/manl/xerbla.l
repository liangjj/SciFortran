.TH  XERBLA 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - is an error handler for the LAPACK routines
.SH SYNOPSIS
.TP 19
SUBROUTINE XERBLA(
SRNAME, INFO )
.TP 19
.ti +4
CHARACTER*(*)
SRNAME
.TP 19
.ti +4
INTEGER
INFO
.SH PURPOSE
XERBLA  is an error handler for the LAPACK routines.
 It is called by an LAPACK routine if an input parameter has an
 invalid value.  A message is printed and execution stops.
 Installers may consider modifying the STOP statement in order to
 call system-specific exception-handling facilities.
.br
.SH ARGUMENTS
.TP 8
 SRNAME  (input) CHARACTER*(*)
 The name of the routine which called XERBLA.
.TP 8
 INFO    (input) INTEGER
 The position of the invalid parameter in the parameter list
 of the calling routine.
