.TH  ILATRANS 1 "April 2011" " LAPACK routine (version 3.2) " " LAPACK routine (version 3.2) " 
.SH NAME
LAPACK-3 - subroutine translate from a character string specifying a transposition operation to the relevant BLAST-specified integer constant
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
ILATRANS( TRANS )
.TP 17
.ti +4
CHARACTER
TRANS
.SH PURPOSE
This subroutine translates from a character string specifying a
transposition operation to the relevant BLAST-specified integer
constant.
 ILATRANS returns an INTEGER.  If ILATRANS < 0, then the input is not
 a character indicating a transposition operator.  Otherwise ILATRANS
 returns the constant value corresponding to TRANS.
.br
.SH ARGUMENTS
 Specifies the form of the system of equations:
 = \(aqN\(aq:  No transpose
.br
 = \(aqT\(aq:  Transpose
.br
 = \(aqC\(aq:  Conjugate transpose
