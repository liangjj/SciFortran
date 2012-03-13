.TH  DGESVJ 1 "April 2011" " LAPACK routine (version 3.3.1)                                  " " LAPACK routine (version 3.3.1)                                  " 
.SH NAME
LAPACK-3 - computes the singular value decomposition (SVD) of a real M-by-N matrix A, where M >= N
.SH SYNOPSIS
.TP 19
SUBROUTINE DGESVJ(
JOBA, JOBU, JOBV, M, N, A, LDA, SVA, MV, V,
LDV, WORK, LWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
INTEGER
INFO, LDA, LDV, LWORK, M, MV, N
.TP 19
.ti +4
CHARACTER*1
JOBA, JOBU, JOBV
.TP 19
.ti +4
DOUBLE
PRECISION A( LDA, * ), SVA( N ), V( LDV, * ),
WORK( LWORK )
.SH PURPOSE
DGESVJ computes the singular value decomposition (SVD) of a real
M-by-N matrix A, where M >= N. The SVD of A is written as
                                    [++]   [xx]   [x0]   [xx]
              A = U * SIGMA * V^t,  [++] = [xx] * [ox] * [xx]
                                    [++]   [xx]
.br
 where SIGMA is an N-by-N diagonal matrix, U is an M-by-N orthonormal
 matrix, and V is an N-by-N orthogonal matrix. The diagonal elements
 of SIGMA are the singular values of A. The columns of U and V are the
 left and the right singular vectors of A, respectively.
.br
 Further Details
.br
 The orthogonal N-by-N matrix V is obtained as a product of Jacobi plane
 rotations. The rotations are implemented as fast scaled rotations of
 Anda and Park [1]. In the case of underflow of the Jacobi angle, a
 modified Jacobi transformation of Drmac [4] is used. Pivot strategy uses
 column interchanges of de Rijk [2]. The relative accuracy of the computed
 singular values and the accuracy of the computed singular vectors (in
 angle metric) is as guaranteed by the theory of Demmel and Veselic [3].
 The condition number that determines the accuracy in the full rank case
 is essentially min_{D=diag} kappa(A*D), where kappa(.) is the
 spectral condition number. The best performance of this Jacobi SVD
 procedure is achieved if used in an  accelerated version of Drmac and
 Veselic [5,6], and it is the kernel routine in the SIGMA library [7].
 Some tunning parameters (marked with [TP]) are available for the
 implementer.
.br
 The computational range for the nonzero singular values is the  machine
 number interval ( UNDERFLOW , OVERFLOW ). In extreme cases, even
 denormalized singular values can be computed with the corresponding
 gradual loss of accurate digits.
.br
 Contributors
.br
 ~~~~~~~~~~~~
.br
 Zlatko Drmac (Zagreb, Croatia) and Kresimir Veselic (Hagen, Germany)
 References
.br
 ~~~~~~~~~~
.br
    SIAM J. matrix Anal. Appl., Vol. 15 (1994), pp. 162-174.
    singular value decomposition on a vector computer.
.br
    SIAM J. Sci. Stat. Comp., Vol. 10 (1998), pp. 359-371.
    value computation in floating point arithmetic.
.br
    SIAM J. Sci. Comp., Vol. 18 (1997), pp. 1200-1222.
.br
    SIAM J. Matrix Anal. Appl. Vol. 35, No. 2 (2008), pp. 1322-1342.
    LAPACK Working note 169.
.br
    SIAM J. Matrix Anal. Appl. Vol. 35, No. 2 (2008), pp. 1343-1362.
    LAPACK Working note 170.
.br
    QSVD, (H,K)-SVD computations.
.br
    Department of Mathematics, University of Zagreb, 2008.
 Bugs, Examples and Comments
.br
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~
.br
 Please report all bugs and send interesting test examples and comments to
 drmac@math.hr. Thank you.
.br
.SH ARGUMENTS
.TP 8
 JOBA    (input) CHARACTER* 1
 Specifies the structure of A.
 = \(aqL\(aq: The input matrix A is lower triangular;
.br
 = \(aqU\(aq: The input matrix A is upper triangular;
.br
 = \(aqG\(aq: The input matrix A is general M-by-N matrix, M >= N.
.TP 8
 JOBU    (input) CHARACTER*1
 Specifies whether to compute the left singular vectors
 (columns of U):
.br
 = \(aqU\(aq: The left singular vectors corresponding to the nonzero
 singular values are computed and returned in the leading
 columns of A. See more details in the description of A.
 The default numerical orthogonality threshold is set to
 approximately TOL=CTOL*EPS, CTOL=DSQRT(M), EPS=DLAMCH(\(aqE\(aq).
 = \(aqC\(aq: Analogous to JOBU=\(aqU\(aq, except that user can control the
 level of numerical orthogonality of the computed left
 singular vectors. TOL can be set to TOL = CTOL*EPS, where
 CTOL is given on input in the array WORK.
 No CTOL smaller than ONE is allowed. CTOL greater
 than 1 / EPS is meaningless. The option \(aqC\(aq
 can be used if M*EPS is satisfactory orthogonality
 of the computed left singular vectors, so CTOL=M could
 save few sweeps of Jacobi rotations.
 See the descriptions of A and WORK(1).
 = \(aqN\(aq: The matrix U is not computed. However, see the
 description of A.
.TP 8
 JOBV    (input) CHARACTER*1
 Specifies whether to compute the right singular vectors, that
 is, the matrix V:
.br
 = \(aqV\(aq : the matrix V is computed and returned in the array V
.br
 = \(aqA\(aq : the Jacobi rotations are applied to the MV-by-N
 array V. In other words, the right singular vector
 matrix V is not computed explicitly, instead it is
 applied to an MV-by-N matrix initially stored in the
 first MV rows of V.
 = \(aqN\(aq : the matrix V is not computed and the array V is not
 referenced
.TP 8
 M       (input) INTEGER
 The number of rows of the input matrix A. 1/DLAMCH(\(aqE\(aq) > M >= 0.  
.TP 8
 N       (input) INTEGER
 The number of columns of the input matrix A.
 M >= N >= 0.
.TP 8
 A       (input/output) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, the M-by-N matrix A.
 On exit :
.br
 If JOBU .EQ. \(aqU\(aq .OR. JOBU .EQ. \(aqC\(aq :
.br
 If INFO .EQ. 0 :
 RANKA orthonormal columns of U are returned in the
 leading RANKA columns of the array A. Here RANKA <= N
 is the number of computed singular values of A that are
 above the underflow threshold DLAMCH(\(aqS\(aq). The singular
 vectors corresponding to underflowed or zero singular
 values are not computed. The value of RANKA is returned
 in the array WORK as RANKA=NINT(WORK(2)). Also see the
 descriptions of SVA and WORK. The computed columns of U
 are mutually numerically orthogonal up to approximately
 TOL=DSQRT(M)*EPS (default); or TOL=CTOL*EPS (JOBU.EQ.\(aqC\(aq),
 see the description of JOBU.
 If INFO .GT. 0 :
 the procedure DGESVJ did not converge in the given number
 of iterations (sweeps). In that case, the computed
 columns of U may not be orthogonal up to TOL. The output
 U (stored in A), SIGMA (given by the computed singular
 values in SVA(1:N)) and V is still a decomposition of the
 input matrix A in the sense that the residual
 ||A-SCALE*U*SIGMA*V^T||_2 / ||A||_2 is small.
 If JOBU .EQ. \(aqN\(aq :
 If INFO .EQ. 0 :
 Note that the left singular vectors are \(aqfor free\(aq in the
 one-sided Jacobi SVD algorithm. However, if only the
 singular values are needed, the level of numerical
 orthogonality of U is not an issue and iterations are
 stopped when the columns of the iterated matrix are
 numerically orthogonal up to approximately M*EPS. Thus,
 on exit, A contains the columns of U scaled with the
 corresponding singular values.
 If INFO .GT. 0 :
 the procedure DGESVJ did not converge in the given number
 of iterations (sweeps).
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 SVA     (workspace/output) DOUBLE PRECISION array, dimension (N)
 On exit :
.br
 If INFO .EQ. 0 :
.br
 depending on the value SCALE = WORK(1), we have:
.br
 If SCALE .EQ. ONE :
.br
 SVA(1:N) contains the computed singular values of A.
 During the computation SVA contains the Euclidean column
 norms of the iterated matrices in the array A.
 If SCALE .NE. ONE :
.br
 The singular values of A are SCALE*SVA(1:N), and this
 factored representation is due to the fact that some of the
 singular values of A might underflow or overflow.
 If INFO .GT. 0 :
 the procedure DGESVJ did not converge in the given number of
 iterations (sweeps) and SCALE*SVA(1:N) may not be accurate.
.TP 8
 MV      (input) INTEGER
 If JOBV .EQ. \(aqA\(aq, then the product of Jacobi rotations in DGESVJ
 is applied to the first MV rows of V. See the description of JOBV.
.TP 8
 V       (input/output) DOUBLE PRECISION array, dimension (LDV,N)
 If JOBV = \(aqV\(aq, then V contains on exit the N-by-N matrix of
 the right singular vectors;
 If JOBV = \(aqA\(aq, then V contains the product of the computed right
 singular vector matrix and the initial matrix in
 the array V.
 If JOBV = \(aqN\(aq, then V is not referenced.
.TP 8
 LDV     (input) INTEGER
 The leading dimension of the array V, LDV .GE. 1.
 If JOBV .EQ. \(aqV\(aq, then LDV .GE. max(1,N).
 If JOBV .EQ. \(aqA\(aq, then LDV .GE. max(1,MV) .
.TP 8
 WORK    (input/workspace/output) DOUBLE PRECISION array, dimension max(4,M+N).
 On entry :
.br
 If JOBU .EQ. \(aqC\(aq :
 WORK(1) = CTOL, where CTOL defines the threshold for convergence.
 The process stops if all columns of A are mutually
 orthogonal up to CTOL*EPS, EPS=DLAMCH(\(aqE\(aq).
 It is required that CTOL >= ONE, i.e. it is not
 allowed to force the routine to obtain orthogonality
 below EPS.
 On exit :
.br
 WORK(1) = SCALE is the scaling factor such that SCALE*SVA(1:N)
 are the computed singular values of A.
 (See description of SVA().)
 WORK(2) = NINT(WORK(2)) is the number of the computed nonzero
 singular values.
 WORK(3) = NINT(WORK(3)) is the number of the computed singular
 values that are larger than the underflow threshold.
 WORK(4) = NINT(WORK(4)) is the number of sweeps of Jacobi
 rotations needed for numerical convergence.
 WORK(5) = max_{i.NE.j} |COS(A(:,i),A(:,j))| in the last sweep.
 This is useful information in cases when DGESVJ did
 not converge, as it can be used to estimate whether
 the output is stil useful and for post festum analysis.
 WORK(6) = the largest absolute value over all sines of the
 Jacobi rotation angles in the last sweep. It can be
 useful for a post festum analysis.
.TP 8
 LWORK   (input) INTEGER
 length of WORK, WORK >= MAX(6,M+N)
.TP 8
 INFO    (output) INTEGER
 = 0 : successful exit.
.br
 < 0 : if INFO = -i, then the i-th argument had an illegal value
.br
 > 0 : DGESVJ did not converge in the maximal allowed number (30)
 of sweeps. The output may still be useful. See the
 description of WORK.
