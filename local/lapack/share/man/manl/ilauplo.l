.TH  ILAUPLO 1 "April 2011" " LAPACK routine (version 3.2) " " LAPACK routine (version 3.2) " 
.SH NAME
LAPACK-3 - subroutine translated from a character string specifying a upper- or lower-triangular matrix to the relevant BLAST-specified integer constant
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
ILAUPLO( UPLO )
.TP 17
.ti +4
CHARACTER
UPLO
.SH PURPOSE
This subroutine translated from a character string specifying a
upper- or lower-triangular matrix to the relevant BLAST-specified
integer constant.
 ILAUPLO returns an INTEGER.  If ILAUPLO < 0, then the input is not
 a character indicating an upper- or lower-triangular matrix.
 Otherwise ILAUPLO returns the constant value corresponding to UPLO.
.SH ARGUMENTS
 = \(aqU\(aq:  A is upper triangular;
 = \(aqL\(aq:  A is lower triangular.
