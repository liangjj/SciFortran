.TH  ZTRTTF 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - copies a triangular matrix A from standard full format (TR) to rectangular full packed format (TF) 
.SH SYNOPSIS
.TP 19
SUBROUTINE ZTRTTF(
TRANSR, UPLO, N, A, LDA, ARF, INFO )
.TP 19
.ti +4
CHARACTER
TRANSR, UPLO
.TP 19
.ti +4
INTEGER
INFO, N, LDA
.TP 19
.ti +4
COMPLEX*16
A( 0: LDA-1, 0: * ), ARF( 0: * )
.SH PURPOSE
ZTRTTF copies a triangular matrix A from standard full format (TR)
to rectangular full packed format (TF) .
.SH ARGUMENTS
.TP 9
 TRANSR   (input) CHARACTER*1
 = \(aqN\(aq:  ARF in Normal mode is wanted;
.br
 = \(aqC\(aq:  ARF in Conjugate Transpose mode is wanted;
.TP 8
 UPLO    (input) CHARACTER*1
.br
 = \(aqU\(aq:  A is upper triangular;
.br
 = \(aqL\(aq:  A is lower triangular.
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 A       (input) COMPLEX*16 array, dimension ( LDA, N ) 
 On entry, the triangular matrix A.  If UPLO = \(aqU\(aq, the
 leading N-by-N upper triangular part of the array A contains
 the upper triangular matrix, and the strictly lower
 triangular part of A is not referenced.  If UPLO = \(aqL\(aq, the
 leading N-by-N lower triangular part of the array A contains
 the lower triangular matrix, and the strictly upper
 triangular part of A is not referenced.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the matrix A.  LDA >= max(1,N).
.TP 8
 ARF     (output) COMPLEX*16 array, dimension ( N*(N+1)/2 ),
 On exit, the upper or lower triangular matrix A stored in
 RFP format. For a further discussion see Notes below.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
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
