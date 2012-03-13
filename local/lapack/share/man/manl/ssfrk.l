.TH  SSFRK 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - 3 BLAS like routine for C in RFP Format
.SH SYNOPSIS
.TP 18
SUBROUTINE SSFRK(
TRANSR, UPLO, TRANS, N, K, ALPHA, A, LDA, BETA,
C )
.TP 18
.ti +4
REAL
ALPHA, BETA
.TP 18
.ti +4
INTEGER
K, LDA, N
.TP 18
.ti +4
CHARACTER
TRANS, TRANSR, UPLO
.TP 18
.ti +4
REAL
A( LDA, * ), C( * )
.SH PURPOSE
Level 3 BLAS like routine for C in RFP Format.
 SSFRK performs one of the symmetric rank--k operations
.br
    C := alpha*A*A**T + beta*C,
.br
 or
.br
    C := alpha*A**T*A + beta*C,
.br
 where alpha and beta are real scalars, C is an n--by--n symmetric
 matrix and A is an n--by--k matrix in the first case and a k--by--n
 matrix in the second case.
.br
.SH ARGUMENTS
.TP 9
 TRANSR   (input) CHARACTER*1
 = \(aqN\(aq:  The Normal Form of RFP A is stored;
.br
 = \(aqT\(aq:  The Transpose Form of RFP A is stored.
.TP 9
 UPLO     (input) CHARACTER*1
 On  entry, UPLO specifies whether the upper or lower
 triangular part of the array C is to be referenced as
 follows:
 UPLO = \(aqU\(aq or \(aqu\(aq   Only the upper triangular part of C
 is to be referenced.
 UPLO = \(aqL\(aq or \(aql\(aq   Only the lower triangular part of C
 is to be referenced.
 Unchanged on exit.
.TP 9
 TRANS    (input) CHARACTER*1
 On entry, TRANS specifies the operation to be performed as
 follows:
 TRANS = \(aqN\(aq or \(aqn\(aq   C := alpha*A*A**T + beta*C.
 TRANS = \(aqT\(aq or \(aqt\(aq   C := alpha*A**T*A + beta*C.
 Unchanged on exit.
.TP 8
 N       (input) INTEGER
 On entry, N specifies the order of the matrix C. N must be
 at least zero.
 Unchanged on exit.
.TP 8
 K       (input) INTEGER
 On entry with TRANS = \(aqN\(aq or \(aqn\(aq, K specifies the number
 of  columns of the matrix A, and on entry with TRANS = \(aqT\(aq
 or \(aqt\(aq, K specifies the number of rows of the matrix A. K
 must be at least zero.
 Unchanged on exit.
.TP 8
 ALPHA   (input) REAL
 On entry, ALPHA specifies the scalar alpha.
 Unchanged on exit.
.TP 8
 A       (input) REAL array of DIMENSION (LDA,ka)
 where KA
 is K  when TRANS = \(aqN\(aq or \(aqn\(aq, and is N otherwise. Before
 entry with TRANS = \(aqN\(aq or \(aqn\(aq, the leading N--by--K part of
 the array A must contain the matrix A, otherwise the leading
 K--by--N part of the array A must contain the matrix A.
 Unchanged on exit.
.TP 8
 LDA     (input) INTEGER
 On entry, LDA specifies the first dimension of A as declared
 in  the  calling  (sub)  program.   When  TRANS = \(aqN\(aq or \(aqn\(aq
 then  LDA must be at least  max( 1, n ), otherwise  LDA must
 be at least  max( 1, k ).
 Unchanged on exit.
.TP 8
 BETA    (input) REAL
 On entry, BETA specifies the scalar beta.
 Unchanged on exit.
.TP 8
 C       (input/output) REAL array, dimension (NT)
 NT = N*(N+1)/2. On entry, the symmetric matrix C in RFP
 Format. RFP Format is described by TRANSR, UPLO and N.
