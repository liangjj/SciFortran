.TH  SLARTGP 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - generates a plane rotation so that   [ CS SN ] 
.SH SYNOPSIS
.TP 20
SUBROUTINE SLARTGP(
F, G, CS, SN, R )
.TP 20
.ti +4
REAL
CS, F, G, R, SN
.SH PURPOSE
SLARTGP generates a plane rotation so that
    [ -SN  CS  ]     [ G ]     [ 0 ]
.br
 This is a slower, more accurate version of the Level 1 BLAS routine SROTG,
 with the following other differences:
.br
    F and G are unchanged on return.
.br
    If G=0, then CS=(+/-)1 and SN=0.
.br
    If F=0 and (G .ne. 0), then CS=0 and SN=(+/-)1.
.br
 The sign is chosen so that R >= 0.
.br
.SH ARGUMENTS
.TP 8
 F       (input) REAL
 The first component of vector to be rotated.
.TP 8
 G       (input) REAL
 The second component of vector to be rotated.
.TP 8
 CS      (output) REAL
 The cosine of the rotation.
.TP 8
 SN      (output) REAL
 The sine of the rotation.
.TP 8
 R       (output) REAL
 The nonzero component of the rotated vector.
 This version has a few statements commented out for thread safety
 (machine parameters are computed on each entry). 10 feb 03, SJH.
