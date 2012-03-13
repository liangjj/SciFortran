.TH  CTFSM 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - 3 BLAS like routine for A in RFP Format
.SH SYNOPSIS
.TP 18
SUBROUTINE CTFSM(
TRANSR, SIDE, UPLO, TRANS, DIAG, M, N, ALPHA, A,
B, LDB )
.TP 18
.ti +4
CHARACTER
TRANSR, DIAG, SIDE, TRANS, UPLO
.TP 18
.ti +4
INTEGER
LDB, M, N
.TP 18
.ti +4
COMPLEX
ALPHA
.TP 18
.ti +4
COMPLEX
A( 0: * ), B( 0: LDB-1, 0: * )
.SH PURPOSE
Level 3 BLAS like routine for A in RFP Format.
 CTFSM solves the matrix equation
.br
    op( A )*X = alpha*B  or  X*op( A ) = alpha*B
.br
 where alpha is a scalar, X and B are m by n matrices, A is a unit, or
 non-unit,  upper or lower triangular matrix  and  op( A )  is one  of
    op( A ) = A   or   op( A ) = A**H.
.br
 A is in Rectangular Full Packed (RFP) Format.
.br
 The matrix X is overwritten on B.
.br
.SH ARGUMENTS
.TP 8
 TRANSR  (input) CHARACTER*1
 = \(aqN\(aq:  The Normal Form of RFP A is stored;
.br
 = \(aqC\(aq:  The Conjugate-transpose Form of RFP A is stored.
.TP 8
 SIDE    (input) CHARACTER*1
 On entry, SIDE specifies whether op( A ) appears on the left
 or right of X as follows:
 SIDE = \(aqL\(aq or \(aql\(aq   op( A )*X = alpha*B.
 SIDE = \(aqR\(aq or \(aqr\(aq   X*op( A ) = alpha*B.
 Unchanged on exit.
.TP 8
 UPLO    (input) CHARACTER*1
 On entry, UPLO specifies whether the RFP matrix A came from
 an upper or lower triangular matrix as follows:
 UPLO = \(aqU\(aq or \(aqu\(aq RFP A came from an upper triangular matrix
 UPLO = \(aqL\(aq or \(aql\(aq RFP A came from a  lower triangular matrix
 Unchanged on exit.
.TP 8
 TRANS   (input) CHARACTER*1
 On entry, TRANS  specifies the form of op( A ) to be used
 in the matrix multiplication as follows:
.TP 7
 TRANS  = \(aqN\(aq or \(aqn\(aq   op( A ) = A.
.TP 7
 TRANS  = \(aqC\(aq or \(aqc\(aq   op( A ) = conjg( A\(aq ).
 Unchanged on exit.
.TP 8
 DIAG    (input) CHARACTER*1
 On entry, DIAG specifies whether or not RFP A is unit
 triangular as follows:
 DIAG = \(aqU\(aq or \(aqu\(aq   A is assumed to be unit triangular.
 DIAG = \(aqN\(aq or \(aqn\(aq   A is not assumed to be unit
 triangular.
 Unchanged on exit.
.TP 8
 M       (input) INTEGER
 On entry, M specifies the number of rows of B. M must be at
 least zero.
 Unchanged on exit.
.TP 8
 N       (input) INTEGER
 On entry, N specifies the number of columns of B.  N must be
 at least zero.
 Unchanged on exit.
.TP 8
 ALPHA   (input) COMPLEX
 On entry,  ALPHA specifies the scalar  alpha. When  alpha is
 zero then  A is not referenced and  B need not be set before
 entry.
 Unchanged on exit.
.TP 8
 A       (input) COMPLEX array, dimension (N*(N+1)/2)
 NT = N*(N+1)/2. On entry, the matrix A in RFP Format.
 RFP Format is described by TRANSR, UPLO and N as follows:
.br
 If TRANSR=\(aqN\(aq then RFP A is (0:N,0:K-1) when N is even;
.br
 K=N/2. RFP A is (0:N-1,0:K) when N is odd; K=N/2. If
 TRANSR = \(aqC\(aq then RFP is the Conjugate-transpose of RFP A as
 defined when TRANSR = \(aqN\(aq. The contents of RFP A are defined
 by UPLO as follows: If UPLO = \(aqU\(aq the RFP A contains the NT
 elements of upper packed A either in normal or
 conjugate-transpose Format. If UPLO = \(aqL\(aq the RFP A contains
 the NT elements of lower packed A either in normal or
 conjugate-transpose Format. The LDA of RFP A is (N+1)/2 when
 TRANSR = \(aqC\(aq. When TRANSR is \(aqN\(aq the LDA is N+1 when N is
 even and is N when is odd.
 See the Note below for more details. Unchanged on exit.
.TP 8
 B       (input/output) COMPLEX array,  dimension (LDB,N)
 Before entry,  the leading  m by n part of the array  B must
 contain  the  right-hand  side  matrix  B,  and  on exit  is
 overwritten by the solution matrix  X.
.TP 8
 LDB     (input) INTEGER
 On entry, LDB specifies the first dimension of B as declared
 in  the  calling  (sub)  program.   LDB  must  be  at  least
 max( 1, m ).
 Unchanged on exit.
.SH FURTHER DETAILS
 We first consider Standard Packed Format when N is even.
.br
 We give an example where N = 6.
.br
     AP is Upper             AP is Lower
.br
  00 01 02 03 04 05       00
.br
     11 12 13 14 15       10 11
.br
        22 23 24 25       20 21 22
.br
           33 34 35       30 31 32 33
.br
              44 45       40 41 42 43 44
.br
                 55       50 51 52 53 54 55
.br
 Let TRANSR = \(aqN\(aq. RFP holds AP as follows:
.br
 For UPLO = \(aqU\(aq the upper trapezoid A(0:5,0:2) consists of the last
 three columns of AP upper. The lower triangle A(4:6,0:2) consists of
 conjugate-transpose of the first three columns of AP upper.
 For UPLO = \(aqL\(aq the lower trapezoid A(1:6,0:2) consists of the first
 three columns of AP lower. The upper triangle A(0:2,0:2) consists of
 conjugate-transpose of the last three columns of AP lower.
 To denote conjugate we place -- above the element. This covers the
 case N even and TRANSR = \(aqN\(aq.
.br
        RFP A                   RFP A
.br
                               -- -- --
.br
       03 04 05                33 43 53
.br
                                  -- --
.br
       13 14 15                00 44 54
.br
                                     --
.br
       23 24 25                10 11 55
.br
       33 34 35                20 21 22
.br
       --
.br
       00 44 45                30 31 32
.br
       -- --
.br
       01 11 55                40 41 42
.br
       -- -- --
.br
       02 12 22                50 51 52
.br
 Now let TRANSR = \(aqC\(aq. RFP A in both UPLO cases is just the conjugate-
 transpose of RFP A above. One therefore gets:
.br
          RFP A                   RFP A
.br
    -- -- -- --                -- -- -- -- -- --
.br
    03 13 23 33 00 01 02    33 00 10 20 30 40 50
.br
    -- -- -- -- --                -- -- -- -- --
.br
    04 14 24 34 44 11 12    43 44 11 21 31 41 51
.br
    -- -- -- -- -- --                -- -- -- --
.br
    05 15 25 35 45 55 22    53 54 55 22 32 42 52
.br
 We next  consider Standard Packed Format when N is odd.
.br
 We give an example where N = 5.
.br
    AP is Upper                 AP is Lower
.br
  00 01 02 03 04              00
.br
     11 12 13 14              10 11
.br
        22 23 24              20 21 22
.br
           33 34              30 31 32 33
.br
              44              40 41 42 43 44
.br
 Let TRANSR = \(aqN\(aq. RFP holds AP as follows:
.br
 For UPLO = \(aqU\(aq the upper trapezoid A(0:4,0:2) consists of the last
 three columns of AP upper. The lower triangle A(3:4,0:1) consists of
 conjugate-transpose of the first two   columns of AP upper.
 For UPLO = \(aqL\(aq the lower trapezoid A(0:4,0:2) consists of the first
 three columns of AP lower. The upper triangle A(0:1,1:2) consists of
 conjugate-transpose of the last two   columns of AP lower.
 To denote conjugate we place -- above the element. This covers the
 case N odd  and TRANSR = \(aqN\(aq.
.br
        RFP A                   RFP A
.br
                                  -- --
.br
       02 03 04                00 33 43
.br
                                     --
.br
       12 13 14                10 11 44
.br
       22 23 24                20 21 22
.br
       --
.br
       00 33 34                30 31 32
.br
       -- --
.br
       01 11 44                40 41 42
.br
 Now let TRANSR = \(aqC\(aq. RFP A in both UPLO cases is just the conjugate-
 transpose of RFP A above. One therefore gets:
.br
          RFP A                   RFP A
.br
    -- -- --                   -- -- -- -- -- --
.br
    02 12 22 00 01             00 10 20 30 40 50
.br
    -- -- -- --                   -- -- -- -- --
.br
    03 13 23 33 11             33 11 21 31 41 51
.br
    -- -- -- -- --                   -- -- -- --
.br
    04 14 24 34 44             43 44 22 32 42 52
.br
