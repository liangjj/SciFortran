.TH  ILAPREC 1 "April 2011" " LAPACK routine (version 3.2.2)                                    " " LAPACK routine (version 3.2.2)                                    " 
.SH NAME
LAPACK-3 - subroutine translated from a character string specifying an intermediate precision to the relevant BLAST-specified integer constant
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
ILAPREC( PREC )
.TP 17
.ti +4
CHARACTER
PREC
.SH PURPOSE
This subroutine translated from a character string specifying an
intermediate precision to the relevant BLAST-specified integer
constant.
 ILAPREC returns an INTEGER.  If ILAPREC < 0, then the input is not a
 character indicating a supported intermediate precision.  Otherwise
 ILAPREC returns the constant value corresponding to PREC.
.SH ARGUMENTS
 Specifies the form of the system of equations:
 = \(aqS\(aq:  Single
.br
 = \(aqD\(aq:  Double
.br
 = \(aqI\(aq:  Indigenous
.br
 = \(aqX\(aq, \(aqE\(aq:  Extra
