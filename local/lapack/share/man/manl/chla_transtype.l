.TH  CHLA_TRANSTYPE 1 "April 2011" " LAPACK routine (version 3.2.2) " " LAPACK routine (version 3.2.2) " 
.SH NAME
LAPACK-3 - subroutine translate from a BLAST-specified integer constant to the character string specifying a transposition operation
.SH SYNOPSIS
.TP 21
CHARACTER*1 FUNCTION
CHLA_TRANSTYPE( TRANS )
.TP 21
.ti +4
INTEGER
TRANS
.SH PURPOSE
This subroutine translates from a BLAST-specified integer constant to
the character string specifying a transposition operation.
 CHLA_TRANSTYPE returns an CHARACTER*1.  If CHLA_TRANSTYPE is \(aqX\(aq,
 then input is not an integer indicating a transposition operator.
 Otherwise CHLA_TRANSTYPE returns the constant value corresponding to
 TRANS.
.br
.SH ARGUMENTS
 Specifies the form of the system of equations:
 = BLAS_NO_TRANS   = 111 :  No Transpose
.br
 = BLAS_TRANS      = 112 :  Transpose
.br
 = BLAS_CONJ_TRANS = 113 :  Conjugate Transpose
