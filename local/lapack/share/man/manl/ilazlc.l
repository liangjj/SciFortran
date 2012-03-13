.TH  ILAZLC 1 "April 2011" " LAPACK auxiliary routine (version 3.2.2)                        " " LAPACK auxiliary routine (version 3.2.2)                        " 
.SH NAME
LAPACK-3 - scans A for its last non-zero column
.SH SYNOPSIS
.TP 17
INTEGER FUNCTION
ILAZLC( M, N, A, LDA )
.TP 17
.ti +4
IMPLICIT
NONE
.TP 17
.ti +4
INTEGER
M, N, LDA
.TP 17
.ti +4
COMPLEX*16
A( LDA, * )
.SH PURPOSE
ILAZLC scans A for its last non-zero column.
.SH ARGUMENTS
.TP 8
 M       (input) INTEGER
 The number of rows of the matrix A.
.TP 8
 N       (input) INTEGER
 The number of columns of the matrix A.
.TP 8
 A       (input) COMPLEX*16 array, dimension (LDA,N)
 The m by n matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A. LDA >= max(1,M).
