.TH  CLANHF 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - returns the value of the one norm, or the Frobenius norm, or the infinity norm, or the element of largest absolute value of a complex Hermitian matrix A in RFP format
.SH SYNOPSIS
.TP 14
REAL FUNCTION
CLANHF( NORM, TRANSR, UPLO, N, A, WORK )
.TP 14
.ti +4
CHARACTER
NORM, TRANSR, UPLO
.TP 14
.ti +4
INTEGER
N
.TP 14
.ti +4
REAL
WORK( 0: * )
.TP 14
.ti +4
COMPLEX
A( 0: * )
.SH PURPOSE
CLANHF  returns the value of the one norm,  or the Frobenius norm, or
the  infinity norm,  or the  element of  largest absolute value  of a
complex Hermitian matrix A in RFP format.
.SH DESCRIPTION
 CLANHF returns the value
.br
    CLANHF = ( max(abs(A(i,j))), NORM = \(aqM\(aq or \(aqm\(aq
.br
             (
.br
             ( norm1(A),         NORM = \(aq1\(aq, \(aqO\(aq or \(aqo\(aq
.br
             (
.br
             ( normI(A),         NORM = \(aqI\(aq or \(aqi\(aq
.br
             (
.br
             ( normF(A),         NORM = \(aqF\(aq, \(aqf\(aq, \(aqE\(aq or \(aqe\(aq
 where  norm1  denotes the  one norm of a matrix (maximum column sum),
 normI  denotes the  infinity norm  of a matrix  (maximum row sum) and
 normF  denotes the  Frobenius norm of a matrix (square root of sum of
 squares).  Note that  max(abs(A(i,j)))  is not a  matrix norm.
.SH ARGUMENTS
.TP 10
 NORM      (input) CHARACTER
 Specifies the value to be returned in CLANHF as described
 above.
.TP 10
 TRANSR    (input) CHARACTER
 Specifies whether the RFP format of A is normal or
 conjugate-transposed format.
 = \(aqN\(aq:  RFP format is Normal
.br
 = \(aqC\(aq:  RFP format is Conjugate-transposed
.TP 10
 UPLO      (input) CHARACTER
 On entry, UPLO specifies whether the RFP matrix A came from
 an upper or lower triangular matrix as follows:
 UPLO = \(aqU\(aq or \(aqu\(aq RFP A came from an upper triangular
 matrix
 UPLO = \(aqL\(aq or \(aql\(aq RFP A came from a  lower triangular
 matrix
.TP 10
 N         (input) INTEGER
 The order of the matrix A.  N >= 0.  When N = 0, CLANHF is
 set to zero.
.TP 9
 A        (input) COMPLEX*16 array, dimension ( N*(N+1)/2 );
 On entry, the matrix A in RFP Format.
 RFP Format is described by TRANSR, UPLO and N as follows:
.br
 If TRANSR=\(aqN\(aq then RFP A is (0:N,0:K-1) when N is even;
.br
 K=N/2. RFP A is (0:N-1,0:K) when N is odd; K=N/2. If
 TRANSR = \(aqC\(aq then RFP is the Conjugate-transpose of RFP A
 as defined when TRANSR = \(aqN\(aq. The contents of RFP A are
 defined by UPLO as follows: If UPLO = \(aqU\(aq the RFP A
 contains the ( N*(N+1)/2 ) elements of upper packed A
 either in normal or conjugate-transpose Format. If
 UPLO = \(aqL\(aq the RFP A contains the ( N*(N+1) /2 ) elements
 of lower packed A either in normal or conjugate-transpose
 Format. The LDA of RFP A is (N+1)/2 when TRANSR = \(aqC\(aq. When
 TRANSR is \(aqN\(aq the LDA is N+1 when N is even and is N when
 is odd. See the Note below for more details.
 Unchanged on exit.
.TP 10
 WORK      (workspace) REAL array, dimension (LWORK),
 where LWORK >= N when NORM = \(aqI\(aq or \(aq1\(aq or \(aqO\(aq; otherwise,
 WORK is not referenced.
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
