.TH  SGEJSV 1 "April 2011" " LAPACK routine (version 3.3.1)                                  " " LAPACK routine (version 3.3.1)                                  " 
.SH NAME
LAPACK-3 - computes the singular value decomposition (SVD) of a real M-by-N matrix [A], where M >= N
.SH SYNOPSIS
.TP 19
SUBROUTINE SGEJSV(
JOBA, JOBU, JOBV, JOBR, JOBT, JOBP,
M, N, A, LDA, SVA, U, LDU, V, LDV,
WORK, LWORK, IWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
INTEGER
INFO, LDA, LDU, LDV, LWORK, M, N
.TP 19
.ti +4
REAL
A( LDA, * ), SVA( N ), U( LDU, * ), V( LDV, * ),
WORK( LWORK )
.TP 19
.ti +4
INTEGER
IWORK( * )
.TP 19
.ti +4
CHARACTER*1
JOBA, JOBP, JOBR, JOBT, JOBU, JOBV
.SH PURPOSE
SGEJSV computes the singular value decomposition (SVD) of a real M-by-N
matrix [A], where M >= N. The SVD of [A] is written as
              [A] = [U] * [SIGMA] * [V]^t,
.br
 where [SIGMA] is an N-by-N (M-by-N) matrix which is zero except for its N
 diagonal elements, [U] is an M-by-N (or M-by-M) orthonormal matrix, and
 [V] is an N-by-N orthogonal matrix. The diagonal elements of [SIGMA] are
 the singular values of [A]. The columns of [U] and [V] are the left and
 the right singular vectors of [A], respectively. The matrices [U] and [V]
 are computed and stored in the arrays U and V, respectively. The diagonal
 of [SIGMA] is computed and stored in the array SVA.
.br
.SH ARGUMENTS
.TP 7
 JOBA   (input) CHARACTER*1
 Specifies the level of accuracy:
.br
 = \(aqC\(aq: This option works well (high relative accuracy) if A = B * D,
 with well-conditioned B and arbitrary diagonal matrix D.
 The accuracy cannot be spoiled by COLUMN scaling. The
 accuracy of the computed output depends on the condition of
 B, and the procedure aims at the best theoretical accuracy.
 The relative error max_{i=1:N}|d sigma_i| / sigma_i is
 bounded by f(M,N)*epsilon* cond(B), independent of D.
 The input matrix is preprocessed with the QRF with column
 pivoting. This initial preprocessing and preconditioning by
 a rank revealing QR factorization is common for all values of
 JOBA. Additional actions are specified as follows:
.br
 = \(aqE\(aq: Computation as with \(aqC\(aq with an additional estimate of the
 condition number of B. It provides a realistic error bound.
 = \(aqF\(aq: If A = D1 * C * D2 with ill-conditioned diagonal scalings
 D1, D2, and well-conditioned matrix C, this option gives
 higher accuracy than the \(aqC\(aq option. If the structure of the
 input matrix is not known, and relative accuracy is
 desirable, then this option is advisable. The input matrix A
 is preprocessed with QR factorization with FULL (row and
 column) pivoting.
 = \(aqG\(aq  Computation as with \(aqF\(aq with an additional estimate of the
 condition number of B, where A=D*B. If A has heavily weighted
 rows, then using this condition number gives too pessimistic
 error bound.
 = \(aqA\(aq: Small singular values are the noise and the matrix is treated
 as numerically rank defficient. The error in the computed
 singular values is bounded by f(m,n)*epsilon*||A||.
 The computed SVD A = U * S * V^t restores A up to
 f(m,n)*epsilon*||A||.
 This gives the procedure the licence to discard (set to zero)
 all singular values below N*epsilon*||A||.
 = \(aqR\(aq: Similar as in \(aqA\(aq. Rank revealing property of the initial
 QR factorization is used do reveal (using triangular factor)
 a gap sigma_{r+1} < epsilon * sigma_r in which case the
 numerical RANK is declared to be r. The SVD is computed with
 absolute error bounds, but more accurately than with \(aqA\(aq.
.TP 7
 JOBU   (input) CHARACTER*1
 Specifies whether to compute the columns of U:
.br
 = \(aqU\(aq: N columns of U are returned in the array U.
.br
 = \(aqF\(aq: full set of M left sing. vectors is returned in the array U.
.br
 = \(aqW\(aq: U may be used as workspace of length M*N. See the description
 of U.
 = \(aqN\(aq: U is not computed.
.TP 7
 JOBV   (input) CHARACTER*1
.br
 Specifies whether to compute the matrix V:
.br
 = \(aqV\(aq: N columns of V are returned in the array V; Jacobi rotations
 are not explicitly accumulated.
 = \(aqJ\(aq: N columns of V are returned in the array V, but they are
 computed as the product of Jacobi rotations. This option is
 allowed only if JOBU .NE. \(aqN\(aq, i.e. in computing the full SVD.
 = \(aqW\(aq: V may be used as workspace of length N*N. See the description
 of V.
 = \(aqN\(aq: V is not computed.
.TP 7
 JOBR   (input) CHARACTER*1
 Specifies the RANGE for the singular values. Issues the licence to
 set to zero small positive singular values if they are outside
 specified range. If A .NE. 0 is scaled so that the largest singular
 value of c*A is around SQRT(BIG), BIG=SLAMCH(\(aqO\(aq), then JOBR issues
 the licence to kill columns of A whose norm in c*A is less than
 SQRT(SFMIN) (for JOBR.EQ.\(aqR\(aq), or less than SMALL=SFMIN/EPSLN,
 where SFMIN=SLAMCH(\(aqS\(aq), EPSLN=SLAMCH(\(aqE\(aq).
 = \(aqN\(aq: Do not kill small columns of c*A. This option assumes that
 BLAS and QR factorizations and triangular solvers are
 implemented to work in that range. If the condition of A
 is greater than BIG, use SGESVJ.
 = \(aqR\(aq: RESTRICTED range for sigma(c*A) is [SQRT(SFMIN), SQRT(BIG)]
 (roughly, as described above). This option is recommended.
 ===========================
 For computing the singular values in the FULL range [SFMIN,BIG]
 use SGESVJ.
.TP 7
 JOBT   (input) CHARACTER*1
 If the matrix is square then the procedure may determine to use
 transposed A if A^t seems to be better with respect to convergence.
 If the matrix is not square, JOBT is ignored. This is subject to
 changes in the future.
 The decision is based on two values of entropy over the adjoint
 orbit of A^t * A. See the descriptions of WORK(6) and WORK(7).
 = \(aqT\(aq: transpose if entropy test indicates possibly faster
 convergence of Jacobi process if A^t is taken as input. If A is
 replaced with A^t, then the row pivoting is included automatically.
 = \(aqN\(aq: do not speculate.
 This option can be used to compute only the singular values, or the
 full SVD (U, SIGMA and V). For only one set of singular vectors
 (U or V), the caller should provide both U and V, as one of the
 matrices is used as workspace if the matrix A is transposed.
 The implementer can easily remove this constraint and make the
 code more complicated. See the descriptions of U and V.
.TP 7
 JOBP   (input) CHARACTER*1
 Issues the licence to introduce structured perturbations to drown
 denormalized numbers. This licence should be active if the
 denormals are poorly implemented, causing slow computation,
 especially in cases of fast convergence (!). For details see [1,2].
 For the sake of simplicity, this perturbations are included only
 when the full SVD or only the singular values are requested. The
 implementer/user can easily add the perturbation for the cases of
 computing one set of singular vectors.
 = \(aqP\(aq: introduce perturbation
.br
 = \(aqN\(aq: do not perturb
.TP 7
 M      (input) INTEGER
 The number of rows of the input matrix A.  M >= 0.
.TP 7
 N      (input) INTEGER
 The number of columns of the input matrix A. M >= N >= 0.
.TP 8
 A       (input/workspace) REAL array, dimension (LDA,N)
 On entry, the M-by-N matrix A.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 SVA     (workspace/output) REAL array, dimension (N)
 On exit,
 - For WORK(1)/WORK(2) = ONE: The singular values of A. During the
 computation SVA contains Euclidean column norms of the
 iterated matrices in the array A.
 - For WORK(1) .NE. WORK(2): The singular values of A are
.br
 (WORK(1)/WORK(2)) * SVA(1:N). This factored form is used if
 sigma_max(A) overflows or if small singular values have been
 saved from underflow by scaling the input matrix A.
 - If JOBR=\(aqR\(aq then some of the singular values may be returned
 as exact zeros obtained by "set to zero" because they are
 below the numerical rank threshold or are denormalized numbers.
.TP 8
 U       (workspace/output) REAL array, dimension ( LDU, N )
 If JOBU = \(aqU\(aq, then U contains on exit the M-by-N matrix of
 the left singular vectors.
 If JOBU = \(aqF\(aq, then U contains on exit the M-by-M matrix of
 the left singular vectors, including an ONB
 of the orthogonal complement of the Range(A).
 If JOBU = \(aqW\(aq  .AND. (JOBV.EQ.\(aqV\(aq .AND. JOBT.EQ.\(aqT\(aq .AND. M.EQ.N),
 then U is used as workspace if the procedure
 replaces A with A^t. In that case, [V] is computed
 in U as left singular vectors of A^t and then
 copied back to the V array. This \(aqW\(aq option is just
 a reminder to the caller that in this case U is
 reserved as workspace of length N*N.
 If JOBU = \(aqN\(aq  U is not referenced.
 The leading dimension of the array U,  LDU >= 1.
 IF  JOBU = \(aqU\(aq or \(aqF\(aq or \(aqW\(aq,  then LDU >= M.
.TP 8
 V       (workspace/output) REAL array, dimension ( LDV, N )
 If JOBV = \(aqV\(aq, \(aqJ\(aq then V contains on exit the N-by-N matrix of
 the right singular vectors;
 If JOBV = \(aqW\(aq, AND (JOBU.EQ.\(aqU\(aq AND JOBT.EQ.\(aqT\(aq AND M.EQ.N),
 then V is used as workspace if the pprocedure
 replaces A with A^t. In that case, [U] is computed
 in V as right singular vectors of A^t and then
 copied back to the U array. This \(aqW\(aq option is just
 a reminder to the caller that in this case V is
 reserved as workspace of length N*N.
 If JOBV = \(aqN\(aq  V is not referenced.
.TP 8
 LDV     (input) INTEGER
 The leading dimension of the array V,  LDV >= 1.
 If JOBV = \(aqV\(aq or \(aqJ\(aq or \(aqW\(aq, then LDV >= N.
.TP 8
 WORK    (workspace/output) REAL array, dimension at least LWORK.
 On exit,
 WORK(1) = SCALE = WORK(2) / WORK(1) is the scaling factor such
 that SCALE*SVA(1:N) are the computed singular values
 of A. (See the description of SVA().)
 WORK(2) = See the description of WORK(1).
 WORK(3) = SCONDA is an estimate for the condition number of
 column equilibrated A. (If JOBA .EQ. \(aqE\(aq or \(aqG\(aq)
 SCONDA is an estimate of SQRT(||(R^t * R)^(-1)||_1).
 It is computed using SPOCON. It holds
 N^(-1/4) * SCONDA <= ||R^(-1)||_2 <= N^(1/4) * SCONDA
 where R is the triangular factor from the QRF of A.
 However, if R is truncated and the numerical rank is
 determined to be strictly smaller than N, SCONDA is
 returned as -1, thus indicating that the smallest
 singular values might be lost.
 If full SVD is needed, the following two condition numbers are
 useful for the analysis of the algorithm. They are provied for
 a developer/implementer who is familiar with the details of
 the method.
 WORK(4) = an estimate of the scaled condition number of the
 triangular factor in the first QR factorization.
 WORK(5) = an estimate of the scaled condition number of the
 triangular factor in the second QR factorization.
 The following two parameters are computed if JOBT .EQ. \(aqT\(aq.
 They are provided for a developer/implementer who is familiar
 with the details of the method.
 WORK(6) = the entropy of A^t*A :: this is the Shannon entropy
 of diag(A^t*A) / Trace(A^t*A) taken as point in the
 probability simplex.
 WORK(7) = the entropy of A*A^t.
.TP 8
 LWORK   (input) INTEGER
 Length of WORK to confirm proper allocation of work space.
 LWORK depends on the job:
 If only SIGMA is needed ( JOBU.EQ.\(aqN\(aq, JOBV.EQ.\(aqN\(aq ) and
.br
 -> .. no scaled condition estimate required (JOBE.EQ.\(aqN\(aq):
 LWORK >= max(2*M+N,4*N+1,7). This is the minimal requirement.
 ->> For optimal performance (blocked code) the optimal value
 is LWORK >= max(2*M+N,3*N+(N+1)*NB,7). Here NB is the optimal
 block size for DGEQP3 and DGEQRF.
 In general, optimal LWORK is computed as 
 LWORK >= max(2*M+N,N+LWORK(DGEQP3),N+LWORK(DGEQRF), 7).        
 -> .. an estimate of the scaled condition number of A is
 required (JOBA=\(aqE\(aq, \(aqG\(aq). In this case, LWORK is the maximum
 of the above and N*N+4*N, i.e. LWORK >= max(2*M+N,N*N+4*N,7).
 ->> For optimal performance (blocked code) the optimal value 
 is LWORK >= max(2*M+N,3*N+(N+1)*NB, N*N+4*N, 7).
 In general, the optimal length LWORK is computed as
 LWORK >= max(2*M+N,N+LWORK(DGEQP3),N+LWORK(DGEQRF), 
 N+N*N+LWORK(DPOCON),7).
 If SIGMA and the right singular vectors are needed (JOBV.EQ.\(aqV\(aq),
 -> the minimal requirement is LWORK >= max(2*M+N,4*N+1,7).
 -> For optimal performance, LWORK >= max(2*M+N,3*N+(N+1)*NB,7),
 where NB is the optimal block size for DGEQP3, DGEQRF, DGELQ,
 DORMLQ. In general, the optimal length LWORK is computed as
 LWORK >= max(2*M+N,N+LWORK(DGEQP3), N+LWORK(DPOCON), 
 N+LWORK(DGELQ), 2*N+LWORK(DGEQRF), N+LWORK(DORMLQ)).
 If SIGMA and the left singular vectors are needed
 -> the minimal requirement is LWORK >= max(2*M+N,4*N+1,7).
 -> For optimal performance:
.br
 if JOBU.EQ.\(aqU\(aq :: LWORK >= max(2*M+N,3*N+(N+1)*NB,7),
.br
 if JOBU.EQ.\(aqF\(aq :: LWORK >= max(2*M+N,3*N+(N+1)*NB,N+M*NB,7),
 where NB is the optimal block size for DGEQP3, DGEQRF, DORMQR.
 In general, the optimal length LWORK is computed as
 LWORK >= max(2*M+N,N+LWORK(DGEQP3),N+LWORK(DPOCON),
 2*N+LWORK(DGEQRF), N+LWORK(DORMQR)). 
 Here LWORK(DORMQR) equals N*NB (for JOBU.EQ.\(aqU\(aq) or 
 M*NB (for JOBU.EQ.\(aqF\(aq).
  If the full SVD is needed: (JOBU.EQ.\(aqU\(aq or JOBU.EQ.\(aqF\(aq) and 
 -> if JOBV.EQ.\(aqV\(aq  
 the minimal requirement is LWORK >= max(2*M+N,6*N+2*N*N). 
 -> if JOBV.EQ.\(aqJ\(aq the minimal requirement is 
 LWORK >= max(2*M+N, 4*N+N*N,2*N+N*N+6).
 -> For optimal performance, LWORK should be additionally
 larger than N+M*NB, where NB is the optimal block size
 for DORMQR.
.TP 8
 IWORK   (workspace/output) INTEGER array, dimension M+3*N.
 On exit,
 IWORK(1) = the numerical rank determined after the initial
 QR factorization with pivoting. See the descriptions
 of JOBA and JOBR.
 IWORK(2) = the number of the computed nonzero singular values
 IWORK(3) = if nonzero, a warning message:
 If IWORK(3).EQ.1 then some of the column norms of A
 were denormalized floats. The requested high accuracy
 is not warranted by the data.
.TP 8
 INFO    (output) INTEGER
 < 0  : if INFO = -i, then the i-th argument had an illegal value.
.br
 = 0 :  successfull exit;
.br
 > 0 :  SGEJSV  did not converge in the maximal allowed number
 of sweeps. The computed values may be inaccurate.
.SH FURTHER DETAILS
 SGEJSV implements a preconditioned Jacobi SVD algorithm. It uses SGEQP3,
 SGEQRF, and SGELQF as preprocessors and preconditioners. Optionally, an
 additional row pivoting can be used as a preprocessor, which in some
 cases results in much higher accuracy. An example is matrix A with the
 structure A = D1 * C * D2, where D1, D2 are arbitrarily ill-conditioned
 diagonal matrices and C is well-conditioned matrix. In that case, complete
 pivoting in the first QR factorizations provides accuracy dependent on the
 condition number of C, and independent of D1, D2. Such higher accuracy is
 not completely understood theoretically, but it works well in practice.
 Further, if A can be written as A = B*D, with well-conditioned B and some
 diagonal D, then the high accuracy is guaranteed, both theoretically and
 in software, independent of D. For more details see [1], [2].
    The computational range for the singular values can be the full range
 ( UNDERFLOW,OVERFLOW ), provided that the machine arithmetic and the BLAS
 & LAPACK routines called by SGEJSV are implemented to work in that range.
 If that is not the case, then the restriction for safe computation with
 the singular values in the range of normalized IEEE numbers is that the
 spectral condition number kappa(A)=sigma_max(A)/sigma_min(A) does not
 overflow. This code (SGEJSV) is best used in this restricted range,
 meaning that singular values of magnitude below ||A||_2 / SLAMCH(\(aqO\(aq) are
 returned as zeros. See JOBR for details on this.
.br
    Further, this implementation is somewhat slower than the one described
 in [1,2] due to replacement of some non-LAPACK components, and because
 the choice of some tuning parameters in the iterative part (SGESVJ) is
 left to the implementer on a particular machine.
.br
    The rank revealing QR factorization (in this code: SGEQP3) should be
 implemented as in [3]. We have a new version of SGEQP3 under development
 that is more robust than the current one in LAPACK, with a cleaner cut in
 rank defficient cases. It will be available in the SIGMA library [4].
 If M is much larger than N, it is obvious that the inital QRF with
 column pivoting can be preprocessed by the QRF without pivoting. That
 well known trick is not used in SGEJSV because in some cases heavy row
 weighting can be treated with complete pivoting. The overhead in cases
 M much larger than N is then only due to pivoting, but the benefits in
 terms of accuracy have prevailed. The implementer/user can incorporate
 this extra QRF step easily. The implementer can also improve data movement
 (matrix transpose, matrix copy, matrix transposed copy) - this
 implementation of SGEJSV uses only the simplest, naive data movement.
 Contributors
.br
 Zlatko Drmac (Zagreb, Croatia) and Kresimir Veselic (Hagen, Germany)
 References
.br
    SIAM J. Matrix Anal. Appl. Vol. 35, No. 2 (2008), pp. 1322-1342.
    LAPACK Working note 169.
.br
    SIAM J. Matrix Anal. Appl. Vol. 35, No. 2 (2008), pp. 1343-1362.
    LAPACK Working note 170.
.br
    factorization software - a case study.
.br
    ACM Trans. math. Softw. Vol. 35, No 2 (2008), pp. 1-28.
    LAPACK Working note 176.
.br
    QSVD, (H,K)-SVD computations.
.br
    Department of Mathematics, University of Zagreb, 2008.
 Bugs, examples and comments
.br
 Please report all bugs and send interesting examples and/or comments to
 drmac@math.hr. Thank you.
.br
