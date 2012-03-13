.TH  SLAPMR 1 "April 2011" " LAPACK auxiliary routine (version 3.2) " " LAPACK auxiliary routine (version 3.2) " 
.SH NAME
LAPACK-3 - rearranges the rows of the M by N matrix X as specified by the permutation K(1),K(2),...,K(M) of the integers 1,...,M
.SH SYNOPSIS
.TP 19
SUBROUTINE SLAPMR(
FORWRD, M, N, X, LDX, K )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
LOGICAL
FORWRD
.TP 19
.ti +4
INTEGER
LDX, M, N
.TP 19
.ti +4
INTEGER
K( * )
.TP 19
.ti +4
REAL
X( LDX, * )
.SH PURPOSE
SLAPMR rearranges the rows of the M by N matrix X as specified
by the permutation K(1),K(2),...,K(M) of the integers 1,...,M.
 If FORWRD = .TRUE.,  forward permutation:
.br
      X(K(I),*) is moved X(I,*) for I = 1,2,...,M.
.br
 If FORWRD = .FALSE., backward permutation:
.br
      X(I,*) is moved to X(K(I),*) for I = 1,2,...,M.
.br
.SH ARGUMENTS
.TP 8
 FORWRD  (input) LOGICAL
 = .TRUE., forward permutation
 = .FALSE., backward permutation
.TP 8
 M       (input) INTEGER
 The number of rows of the matrix X. M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of the matrix X. N >= 0.
.TP 8
 X       (input/output) REAL array, dimension (LDX,N)
 On entry, the M by N matrix X.
 On exit, X contains the permuted matrix X.
.TP 8
 LDX     (input) INTEGER
 The leading dimension of the array X, LDX >= MAX(1,M).
.TP 8
 K       (input/output) INTEGER array, dimension (M)
 On entry, K contains the permutation vector. K is used as
 internal workspace, but reset to its original value on
 output.
