.TH  SLANSF 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - returns the value of the one norm, or the Frobenius norm, or the infinity norm, or the element of largest absolute value of a real symmetric matrix A in RFP format
.SH SYNOPSIS
.TP 14
REAL FUNCTION
SLANSF( NORM, TRANSR, UPLO, N, A, WORK )
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
A( 0: * ), WORK( 0: * )
.SH PURPOSE
SLANSF returns the value of the one norm, or the Frobenius norm, or
the infinity norm, or the element of largest absolute value of a
real symmetric matrix A in RFP format.
.SH DESCRIPTION
 SLANSF returns the value
.br
    SLANSF = ( max(abs(A(i,j))), NORM = \(aqM\(aq or \(aqm\(aq
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
.TP 8
 NORM    (input) CHARACTER*1
 Specifies the value to be returned in SLANSF as described
 above.
.TP 8
 TRANSR  (input) CHARACTER*1
 Specifies whether the RFP format of A is normal or
 transposed format.
 = \(aqN\(aq:  RFP format is Normal;
.br
 = \(aqT\(aq:  RFP format is Transpose.
.TP 8
 UPLO    (input) CHARACTER*1
 On entry, UPLO specifies whether the RFP matrix A came from
 an upper or lower triangular matrix as follows:
.br
 = \(aqU\(aq: RFP A came from an upper triangular matrix;
.br
 = \(aqL\(aq: RFP A came from a lower triangular matrix.
.TP 8
 N       (input) INTEGER
 The order of the matrix A. N >= 0. When N = 0, SLANSF is
 set to zero.
.TP 8
 A       (input) REAL array, dimension ( N*(N+1)/2 );
 On entry, the upper (if UPLO = \(aqU\(aq) or lower (if UPLO = \(aqL\(aq)
 part of the symmetric matrix A stored in RFP format. See the
 "Notes" below for more details.
 Unchanged on exit.
.TP 8
 WORK    (workspace) REAL array, dimension (MAX(1,LWORK)),
 where LWORK >= N when NORM = \(aqI\(aq or \(aq1\(aq or \(aqO\(aq; otherwise,
 WORK is not referenced.
.SH FURTHER DETAILS
 We first consider Rectangular Full Packed (RFP) Format when N is
 even. We give an example where N = 6.
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
 the transpose of the first three columns of AP upper.
.br
 For UPLO = \(aqL\(aq the lower trapezoid A(1:6,0:2) consists of the first
 three columns of AP lower. The upper triangle A(0:2,0:2) consists of
 the transpose of the last three columns of AP lower.
.br
 This covers the case N even and TRANSR = \(aqN\(aq.
.br
        RFP A                   RFP A
.br
       03 04 05                33 43 53
.br
       13 14 15                00 44 54
.br
       23 24 25                10 11 55
.br
       33 34 35                20 21 22
.br
       00 44 45                30 31 32
.br
       01 11 55                40 41 42
.br
       02 12 22                50 51 52
.br
 Now let TRANSR = \(aqT\(aq. RFP A in both UPLO cases is just the
 transpose of RFP A above. One therefore gets:
.br
          RFP A                   RFP A
.br
    03 13 23 33 00 01 02    33 00 10 20 30 40 50
.br
    04 14 24 34 44 11 12    43 44 11 21 31 41 51
.br
    05 15 25 35 45 55 22    53 54 55 22 32 42 52
.br
 We then consider Rectangular Full Packed (RFP) Format when N is
 odd. We give an example where N = 5.
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
 the transpose of the first two columns of AP upper.
.br
 For UPLO = \(aqL\(aq the lower trapezoid A(0:4,0:2) consists of the first
 three columns of AP lower. The upper triangle A(0:1,1:2) consists of
 the transpose of the last two columns of AP lower.
.br
 This covers the case N odd and TRANSR = \(aqN\(aq.
.br
        RFP A                   RFP A
.br
       02 03 04                00 33 43
.br
       12 13 14                10 11 44
.br
       22 23 24                20 21 22
.br
       00 33 34                30 31 32
.br
       01 11 44                40 41 42
.br
 Now let TRANSR = \(aqT\(aq. RFP A in both UPLO cases is just the
 transpose of RFP A above. One therefore gets:
.br
          RFP A                   RFP A
.br
    02 12 22 00 01             00 10 20 30 40 50
.br
    03 13 23 33 11             33 11 21 31 41 51
.br
    04 14 24 34 44             43 44 22 32 42 52
.br
 Reference
.br
 =========
.br
