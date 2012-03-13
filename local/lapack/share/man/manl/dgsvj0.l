.TH  DGSVJ0 1 "April 2011" " LAPACK routine (version 3.3.1)                                  " " LAPACK routine (version 3.3.1)                                  " 
.SH NAME
LAPACK-3 - is called from DGESVJ as a pre-processor and that is its main purpose
.SH SYNOPSIS
.TP 19
SUBROUTINE DGSVJ0(
JOBV, M, N, A, LDA, D, SVA, MV, V, LDV, EPS,
SFMIN, TOL, NSWEEP, WORK, LWORK, INFO )
.TP 19
.ti +4
IMPLICIT
NONE
.TP 19
.ti +4
INTEGER
INFO, LDA, LDV, LWORK, M, MV, N, NSWEEP
.TP 19
.ti +4
DOUBLE
PRECISION EPS, SFMIN, TOL
.TP 19
.ti +4
CHARACTER*1
JOBV
.TP 19
.ti +4
DOUBLE
PRECISION A( LDA, * ), SVA( N ), D( N ), V( LDV, * ),
WORK( LWORK )
.SH PURPOSE
DGSVJ0 is called from DGESVJ as a pre-processor and that is its main
purpose. It applies Jacobi rotations in the same way as DGESVJ does, but
 it does not check convergence (stopping criterion). Few tuning
 parameters (marked by [TP]) are available for the implementer.
 Further Details
.br
 DGSVJ0 is used just to enable SGESVJ to call a simplified version of
 itself to work on a submatrix of the original matrix.
.br
 Contributors
.br
 ~~~~~~~~~~~~
.br
 Zlatko Drmac (Zagreb, Croatia) and Kresimir Veselic (Hagen, Germany)
 Bugs, Examples and Comments
.br
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~
.br
 Please report all bugs and send interesting test examples and comments to
 drmac@math.hr. Thank you.
.br
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
 A       (input/output) DOUBLE PRECISION array, dimension (LDA,N)
 On entry, M-by-N matrix A, such that A*diag(D) represents
 the input matrix.
 On exit,
 A_onexit * D_onexit represents the input matrix A*diag(D)
 post-multiplied by a sequence of Jacobi rotations, where the
 rotation threshold and the total number of sweeps are given in
 TOL and NSWEEP, respectively.
 (See the descriptions of D, TOL and NSWEEP.)
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
 (See the descriptions of A, TOL and NSWEEP.)
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
