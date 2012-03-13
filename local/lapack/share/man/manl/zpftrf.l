.TH  ZPFTRF 1 "April 2011" " LAPACK routine (version 3.3.1)                                    " " LAPACK routine (version 3.3.1)                                    " 
.SH NAME
LAPACK-3 - computes the Cholesky factorization of a complex Hermitian positive definite matrix A
.SH SYNOPSIS
.TP 19
SUBROUTINE ZPFTRF(
TRANSR, UPLO, N, A, INFO )
.TP 19
.ti +4
CHARACTER
TRANSR, UPLO
.TP 19
.ti +4
INTEGER
N, INFO
.TP 19
.ti +4
COMPLEX*16
A( 0: * )
.SH PURPOSE
ZPFTRF computes the Cholesky factorization of a complex Hermitian
positive definite matrix A.
 The factorization has the form
.br
    A = U**H * U,  if UPLO = \(aqU\(aq, or
.br
    A = L  * L**H,  if UPLO = \(aqL\(aq,
.br
 where U is an upper triangular matrix and L is lower triangular.
 This is the block version of the algorithm, calling Level 3 BLAS.
.SH ARGUMENTS
.TP 10
 TRANSR    (input) CHARACTER*1
 = \(aqN\(aq:  The Normal TRANSR of RFP A is stored;
.br
 = \(aqC\(aq:  The Conjugate-transpose TRANSR of RFP A is stored.
.TP 8
 UPLO    (input) CHARACTER*1
.br
 = \(aqU\(aq:  Upper triangle of RFP A is stored;
.br
 = \(aqL\(aq:  Lower triangle of RFP A is stored.
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 A       (input/output) COMPLEX array, dimension ( N*(N+1)/2 );
 On entry, the Hermitian matrix A in RFP format. RFP format is
 described by TRANSR, UPLO, and N as follows: If TRANSR = \(aqN\(aq
.br
 then RFP A is (0:N,0:k-1) when N is even; k=N/2. RFP A is
.br
 (0:N-1,0:k) when N is odd; k=N/2. IF TRANSR = \(aqC\(aq then RFP is
 the Conjugate-transpose of RFP A as defined when
 TRANSR = \(aqN\(aq. The contents of RFP A are defined by UPLO as
 follows: If UPLO = \(aqU\(aq the RFP A contains the nt elements of
 upper packed A. If UPLO = \(aqL\(aq the RFP A contains the elements
 of lower packed A. The LDA of RFP A is (N+1)/2 when TRANSR =
 \(aqC\(aq. When TRANSR is \(aqN\(aq the LDA is N+1 when N is even and N
 is odd. See the Note below for more details.
 On exit, if INFO = 0, the factor U or L from the Cholesky
 factorization RFP A = U**H*U or RFP A = L*L**H.
.TP 8
 INFO    (output) INTEGER
 = 0:  successful exit
.br
 < 0:  if INFO = -i, the i-th argument had an illegal value
.br
 > 0:  if INFO = i, the leading minor of order i is not
 positive definite, and the factorization could not be
 completed.
 Further Notes on RFP Format:
 ============================
 We first consider Standard Packed Format when N is even.
 We give an example where N = 6.
 AP is Upper             AP is Lower
 00 01 02 03 04 05       00
 11 12 13 14 15       10 11
 22 23 24 25       20 21 22
 33 34 35       30 31 32 33
 44 45       40 41 42 43 44
 55       50 51 52 53 54 55
 Let TRANSR = \(aqN\(aq. RFP holds AP as follows:
 For UPLO = \(aqU\(aq the upper trapezoid A(0:5,0:2) consists of the last
.br
 three columns of AP upper. The lower triangle A(4:6,0:2) consists of
 conjugate-transpose of the first three columns of AP upper.
 For UPLO = \(aqL\(aq the lower trapezoid A(1:6,0:2) consists of the first
.br
 three columns of AP lower. The upper triangle A(0:2,0:2) consists of
 conjugate-transpose of the last three columns of AP lower.
 To denote conjugate we place -- above the element. This covers the
 case N even and TRANSR = \(aqN\(aq.
 RFP A                   RFP A
 -- -- --
 03 04 05                33 43 53
 -- --
 13 14 15                00 44 54
 --
 23 24 25                10 11 55
 33 34 35                20 21 22
 --
 00 44 45                30 31 32
 -- --
 01 11 55                40 41 42
 -- -- --
 02 12 22                50 51 52
 Now let TRANSR = \(aqC\(aq. RFP A in both UPLO cases is just the conjugate-
 transpose of RFP A above. One therefore gets:
 RFP A                   RFP A
 -- -- -- --                -- -- -- -- -- --
 03 13 23 33 00 01 02    33 00 10 20 30 40 50
 -- -- -- -- --                -- -- -- -- --
 04 14 24 34 44 11 12    43 44 11 21 31 41 51
 -- -- -- -- -- --                -- -- -- --
 05 15 25 35 45 55 22    53 54 55 22 32 42 52
 We next  consider Standard Packed Format when N is odd.
 We give an example where N = 5.
 AP is Upper                 AP is Lower
 00 01 02 03 04              00
 11 12 13 14              10 11
 22 23 24              20 21 22
 33 34              30 31 32 33
 44              40 41 42 43 44
 Let TRANSR = \(aqN\(aq. RFP holds AP as follows:
 For UPLO = \(aqU\(aq the upper trapezoid A(0:4,0:2) consists of the last
.br
 three columns of AP upper. The lower triangle A(3:4,0:1) consists of
 conjugate-transpose of the first two   columns of AP upper.
 For UPLO = \(aqL\(aq the lower trapezoid A(0:4,0:2) consists of the first
.br
 three columns of AP lower. The upper triangle A(0:1,1:2) consists of
 conjugate-transpose of the last two   columns of AP lower.
 To denote conjugate we place -- above the element. This covers the
 case N odd  and TRANSR = \(aqN\(aq.
 RFP A                   RFP A
 -- --
 02 03 04                00 33 43
 --
 12 13 14                10 11 44
 22 23 24                20 21 22
 --
 00 33 34                30 31 32
 -- --
 01 11 44                40 41 42
 Now let TRANSR = \(aqC\(aq. RFP A in both UPLO cases is just the conjugate-
 transpose of RFP A above. One therefore gets:
 RFP A                   RFP A
 -- -- --                   -- -- -- -- -- --
 02 12 22 00 01             00 10 20 30 40 50
 -- -- -- --                   -- -- -- -- --
 03 13 23 33 11             33 11 21 31 41 51
 -- -- -- -- --                   -- -- -- --
 04 14 24 34 44             43 44 22 32 42 52
