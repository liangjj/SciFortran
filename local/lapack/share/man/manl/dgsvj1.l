.TH  DGSVJ1 1 "April 2011" " LAPACK routine (version 3.3.1)                                  " " LAPACK routine (version 3.3.1)                                  " 
.SH NAME
LAPACK-3 - is called from SGESVJ as a pre-processor and that is its main purpose
.SH SYNOPSIS
.TP 19
SUBROUTINE DGSVJ1(
JOBV, M, N, N1, A, LDA, D, SVA, MV, V, LDV,
EPS, SFMIN, TOL, NSWEEP, WORK, LWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
DOUBLE
PRECISION EPS, SFMIN, TOL
.TP 19
.ti +4
INTEGER
INFO, LDA, LDV, LWORK, M, MV, N, N1, NSWEEP
.TP 19
.ti +4
CHARACTER*1
JOBV
.TP 19
.ti +4
DOUBLE
PRECISION A( LDA, * ), D( N ), SVA( N ), V( LDV, * ),
WORK( LWORK )
.SH PURPOSE
DGSVJ1 is called from SGESVJ as a pre-processor and that is its main
purpose. It applies Jacobi rotations in the same way as SGESVJ does, but
 it targets only particular pivots and it does not check convergence
 (stopping criterion). Few tunning parameters (marked by [TP]) are
 available for the implementer.
.br
 Further Details
.br
 DGSVJ1 applies few sweeps of Jacobi rotations in the column space of
 the input M-by-N matrix A. The pivot pairs are taken from the (1,2)
 off-diagonal block in the corresponding N-by-N Gram matrix A^T * A. The
 block-entries (tiles) of the (1,2) off-diagonal block are marked by the
 [x]\(aqs in the following scheme:
.br
    | *   *   * [x] [x] [x]|
.br
    | *   *   * [x] [x] [x]|    Row-cycling in the nblr-by-nblc [x] blocks.
    | *   *   * [x] [x] [x]|    Row-cyclic pivoting inside each [x] block.
    |[x] [x] [x] *   *   * |
.br
    |[x] [x] [x] *   *   * |
.br
    |[x] [x] [x] *   *   * |
.br
 In terms of the columns of A, the first N1 columns are rotated \(aqagainst\(aq
 the remaining N-N1 columns, trying to increase the angle between the
 corresponding subspaces. The off-diagonal block is N1-by(N-N1) and it is
 tiled using quadratic tiles of side KBL. Here, KBL is a tunning parmeter.
 The number of sweeps is given in NSWEEP and the orthogonality threshold
 is given in TOL.
.br
 Contributors
.br
 ~~~~~~~~~~~~
.br
 Zlatko Drmac (Zagreb, Croatia) and Kresimir Veselic (Hagen, Germany)
.SH ARGUMENTS
.TP 8
 JOBV    (input) CHARACTER*1
 Specifies whether the output from this procedure is used
 to compute the matrix V:
.br
 = \(aqV\(aq: the product of the Jacobi rotations is accumulated
 by postmulyiplying the N-by-N array V.
 (See the description of V.)
 = \(aqA\(aq: the product of the Jacobi rotations is accumulated
 by postmulyiplying the MV-by-N array V.
 (See the descriptions of MV and V.)
 = \(aqN\(aq: the Jacobi rotations are not accumulated.
.TP 8
 M       (input) INTEGER
 The number of rows of the input matrix A.  M >= 0.
.TP 8
 N       (input) INTEGER
 The number of columns of the input matrix A.
 M >= N >= 0.
.TP 8
 N1      (input) INTEGER
 N1 specifies the 2 x 2 block partition, the first N1 columns are
 rotated \(aqagainst\(aq the remaining N-N1 columns of A.
.TP 8
 A       (input/output) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, M-by-N matrix A, such that A*diag(D) represents
 the input matrix.
 On exit,
 A_onexit * D_onexit represents the input matrix A*diag(D)
 post-multiplied by a sequence of Jacobi rotations, where the
 rotation threshold and the total number of sweeps are given in
 TOL and NSWEEP, respectively.
 (See the descriptions of N1, D, TOL and NSWEEP.)
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,M).
.TP 8
 D       (input/workspace/output) DOUBLE PRECISION array, dimension (N)
 The array D accumulates the scaling factors from the fast scaled
 Jacobi rotations.
 On entry, A*diag(D) represents the input matrix.
 On exit, A_onexit*diag(D_onexit) represents the input matrix
 post-multiplied by a sequence of Jacobi rotations, where the
 rotation threshold and the total number of sweeps are given in
 TOL and NSWEEP, respectively.
 (See the descriptions of N1, A, TOL and NSWEEP.)
.TP 8
 SVA     (input/workspace/output) DOUBLE PRECISION array, dimension (N)
 On entry, SVA contains the Euclidean norms of the columns of
 the matrix A*diag(D).
 On exit, SVA contains the Euclidean norms of the columns of
 the matrix onexit*diag(D_onexit).
.TP 8
 MV      (input) INTEGER
 If JOBV .EQ. \(aqA\(aq, then MV rows of V are post-multipled by a
 sequence of Jacobi rotations.
 If JOBV = \(aqN\(aq,   then MV is not referenced.
.TP 8
 V       (input/output) DOUBLE PRECISION array, dimension (LDV,N)
 If JOBV .EQ. \(aqV\(aq then N rows of V are post-multipled by a
 sequence of Jacobi rotations.
 If JOBV .EQ. \(aqA\(aq then MV rows of V are post-multipled by a
 sequence of Jacobi rotations.
 If JOBV = \(aqN\(aq,   then V is not referenced.
.TP 8
 LDV     (input) INTEGER
 The leading dimension of the array V,  LDV >= 1.
 If JOBV = \(aqV\(aq, LDV .GE. N.
 If JOBV = \(aqA\(aq, LDV .GE. MV.
.TP 8
 EPS     (input) DOUBLE PRECISION
 EPS = DLAMCH(\(aqEpsilon\(aq)
.TP 8
 SFMIN   (input) DOUBLE PRECISION
 SFMIN = DLAMCH(\(aqSafe Minimum\(aq)
.TP 8
 TOL     (input) DOUBLE PRECISION
 TOL is the threshold for Jacobi rotations. For a pair
 A(:,p), A(:,q) of pivot columns, the Jacobi rotation is
.br
 applied only if DABS(COS(angle(A(:,p),A(:,q)))) .GT. TOL.
.TP 8
 NSWEEP  (input) INTEGER
 NSWEEP is the number of sweeps of Jacobi rotations to be
 performed.
.TP 8
 WORK    (workspace) DOUBLE PRECISION array, dimension (LWORK)
.TP 8
 LWORK   (input) INTEGER
 LWORK is the dimension of WORK. LWORK .GE. M.
.TP 8
 INFO    (output) INTEGER
 = 0 : successful exit.
.br
 < 0 : if INFO = -i, then the i-th argument had an illegal value
