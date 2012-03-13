.TH  ILADIAG 1 "April 2011" " LAPACK routine (version 3.2.1)                                    " " LAPACK routine (version 3.2.1)                                    " 
.SH NAME
LAPACK-3 - subroutine translated from a character string specifying if a matrix has unit diagonal or not to the relevant BLAST-specified integer constant
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
ILADIAG( DIAG )
.TP 17
.ti +4
CHARACTER
DIAG
.SH PURPOSE
This subroutine translated from a character string specifying if a
matrix has unit diagonal or not to the relevant BLAST-specified
integer constant.
 ILADIAG returns an INTEGER.  If ILADIAG < 0, then the input is not a
 character indicating a unit or non-unit diagonal.  Otherwise ILADIAG
 returns the constant value corresponding to DIAG.
.br
.SH ARGUMENTS
 = \(aqN\(aq:  A is non-unit triangular;
 = \(aqU\(aq:  A is unit triangular.
