.TH  CSYRFSX 1 "April 2011" "    LAPACK routine (version 3.2.2)                                 " "    LAPACK routine (version 3.2.2)                                 " 
.SH NAME
LAPACK-3 - CSYRFSX improve the computed solution to a system of linear  equations when the coefficient matrix is symmetric indefinite, and  provides error bounds and backward error estimates for the  solution
.SH SYNOPSIS
.TP 20
SUBROUTINE CSYRFSX(
UPLO, EQUED, N, NRHS, A, LDA, AF, LDAF, IPIV,
S, B, LDB, X, LDX, RCOND, BERR, N_ERR_BNDS,
ERR_BNDS_NORM, ERR_BNDS_COMP, NPARAMS, PARAMS,
WORK, RWORK, INFO )
.TP 20
.ti +4
IMPLICIT
NONE
.TP 20
.ti +4
CHARACTER
UPLO, EQUED
.TP 20
.ti +4
INTEGER
INFO, LDA, LDAF, LDB, LDX, N, NRHS, NPARAMS,
N_ERR_BNDS
.TP 20
.ti +4
REAL
RCOND
.TP 20
.ti +4
INTEGER
IPIV( * )
.TP 20
.ti +4
COMPLEX
A( LDA, * ), AF( LDAF, * ), B( LDB, * ),
X( LDX, * ), WORK( * )
.TP 20
.ti +4
REAL
S( * ), PARAMS( * ), BERR( * ), RWORK( * ),
ERR_BNDS_NORM( NRHS, * ),
ERR_BNDS_COMP( NRHS, * )
.SH PURPOSE
   CSYRFSX improves the computed solution to a system of linear
   equations when the coefficient matrix is symmetric indefinite, and
   provides error bounds and backward error estimates for the
   solution.  In addition to normwise error bound, the code provides
    maximum componentwise error bound if possible.  See comments for
    ERR_BNDS_NORM and ERR_BNDS_COMP for details of the error bounds.
    The original system of linear equations may have been equilibrated
    before calling this routine, as described by arguments EQUED and S
    below. In this case, the solution and error bounds returned are
    for the original unequilibrated system.
.br
.SH ARGUMENTS
 Some optional parameters are bundled in the PARAMS array.  These
 settings determine how refinement is performed, but often the
 defaults are acceptable.  If the defaults are acceptable, users
 can pass NPARAMS = 0 which prevents the source code from accessing
 the PARAMS argument.
.TP 8
 UPLO    (input) CHARACTER*1
 = \(aqU\(aq:  Upper triangle of A is stored;
.br
 = \(aqL\(aq:  Lower triangle of A is stored.
.TP 8
 EQUED   (input) CHARACTER*1
 Specifies the form of equilibration that was done to A
 before calling this routine. This is needed to compute
 the solution and error bounds correctly.
 = \(aqN\(aq:  No equilibration
.br
 = \(aqY\(aq:  Both row and column equilibration, i.e., A has been
 replaced by diag(S) * A * diag(S).
 The right hand side B has been changed accordingly.
.TP 8
 N       (input) INTEGER
 The order of the matrix A.  N >= 0.
.TP 8
 NRHS    (input) INTEGER
 The number of right hand sides, i.e., the number of columns
 of the matrices B and X.  NRHS >= 0.
.TP 8
 A       (input) COMPLEX array, dimension (LDA,N)
 The symmetric matrix A.  If UPLO = \(aqU\(aq, the leading N-by-N
 upper triangular part of A contains the upper triangular
 part of the matrix A, and the strictly lower triangular
 part of A is not referenced.  If UPLO = \(aqL\(aq, the leading
 N-by-N lower triangular part of A contains the lower
 triangular part of the matrix A, and the strictly upper
 triangular part of A is not referenced.
.TP 8
 LDA     (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 8
 AF      (input) COMPLEX array, dimension (LDAF,N)
 The factored form of the matrix A.  AF contains the block
 diagonal matrix D and the multipliers used to obtain the
 factor U or L from the factorization A = U*D*U**T or A =
 L*D*L**T as computed by SSYTRF.
.TP 8
 LDAF    (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 8
 IPIV    (input) INTEGER array, dimension (N)
 Details of the interchanges and the block structure of D
 as determined by SSYTRF.
.TP 8
 S       (input or output) REAL array, dimension (N)
 The scale factors for A.  If EQUED = \(aqY\(aq, A is multiplied on
 the left and right by diag(S).  S is an input argument if FACT =
 \(aqF\(aq; otherwise, S is an output argument.  If FACT = \(aqF\(aq and EQUED
 = \(aqY\(aq, each element of S must be positive.  If S is output, each
 element of S is a power of the radix. If S is input, each element
 of S should be a power of the radix to ensure a reliable solution
 and error estimates. Scaling by powers of the radix does not cause
 rounding errors unless the result underflows or overflows.
 Rounding errors during scaling lead to refining with a matrix that
 is not equivalent to the input matrix, producing error estimates
 that may not be reliable.
.TP 8
 B       (input) COMPLEX array, dimension (LDB,NRHS)
 The right hand side matrix B.
.TP 8
 LDB     (input) INTEGER
 The leading dimension of the array B.  LDB >= max(1,N).
.TP 8
 X       (input/output) COMPLEX array, dimension (LDX,NRHS)
 On entry, the solution matrix X, as computed by SGETRS.
 On exit, the improved solution matrix X.
.TP 8
 LDX     (input) INTEGER
 The leading dimension of the array X.  LDX >= max(1,N).
.TP 8
 RCOND   (output) REAL
 Reciprocal scaled condition number.  This is an estimate of the
 reciprocal Skeel condition number of the matrix A after
 equilibration (if done).  If this is less than the machine
 precision (in particular, if it is zero), the matrix is singular
 to working precision.  Note that the error may still be small even
 if this number is very small and the matrix appears ill-
 conditioned.
.TP 8
 BERR    (output) REAL array, dimension (NRHS)
 Componentwise relative backward error.  This is the
 componentwise relative backward error of each solution vector X(j)
 (i.e., the smallest relative change in any element of A or B that
 makes X(j) an exact solution).
 N_ERR_BNDS (input) INTEGER
 Number of error bounds to return for each right hand side
 and each type (normwise or componentwise).  See ERR_BNDS_NORM and
 ERR_BNDS_COMP below.
.TP 15
 ERR_BNDS_NORM  (output) REAL array, dimension (NRHS, N_ERR_BNDS)
 For each right-hand side, this array contains information about
 various error bounds and condition numbers corresponding to the
 normwise relative error, which is defined as follows:
 Normwise relative error in the ith solution vector:
 max_j (abs(XTRUE(j,i) - X(j,i)))
 ------------------------------
 max_j abs(X(j,i))
 The array is indexed by the type of error information as described
 below. There currently are up to three pieces of information
 returned.
 The first index in ERR_BNDS_NORM(i,:) corresponds to the ith
 right-hand side.
 The second index in ERR_BNDS_NORM(:,err) contains the following
 three fields:
 err = 1 "Trust/don\(aqt trust" boolean. Trust the answer if the
 reciprocal condition number is less than the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq).
 err = 2 "Guaranteed" error bound: The estimated forward error,
 almost certainly within a factor of 10 of the true error
 so long as the next entry is greater than the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq). This error bound should only
 be trusted if the previous boolean is true.
 err = 3  Reciprocal condition number: Estimated normwise
 reciprocal condition number.  Compared with the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq) to determine if the error
 estimate is "guaranteed". These reciprocal condition
 numbers are 1 / (norm(Z^{-1},inf) * norm(Z,inf)) for some
 appropriately scaled matrix Z.
 Let Z = S*A, where S scales each row by a power of the
 radix so all absolute row sums of Z are approximately 1.
 See Lapack Working Note 165 for further details and extra
 cautions.
.TP 15
 ERR_BNDS_COMP  (output) REAL array, dimension (NRHS, N_ERR_BNDS)
 For each right-hand side, this array contains information about
 various error bounds and condition numbers corresponding to the
 componentwise relative error, which is defined as follows:
 Componentwise relative error in the ith solution vector:
 abs(XTRUE(j,i) - X(j,i))
 max_j ----------------------
 abs(X(j,i))
 The array is indexed by the right-hand side i (on which the
 componentwise relative error depends), and the type of error
 information as described below. There currently are up to three
 pieces of information returned for each right-hand side. If
 componentwise accuracy is not requested (PARAMS(3) = 0.0), then
 ERR_BNDS_COMP is not accessed.  If N_ERR_BNDS .LT. 3, then at most
 the first (:,N_ERR_BNDS) entries are returned.
 The first index in ERR_BNDS_COMP(i,:) corresponds to the ith
 right-hand side.
 The second index in ERR_BNDS_COMP(:,err) contains the following
 three fields:
 err = 1 "Trust/don\(aqt trust" boolean. Trust the answer if the
 reciprocal condition number is less than the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq).
 err = 2 "Guaranteed" error bound: The estimated forward error,
 almost certainly within a factor of 10 of the true error
 so long as the next entry is greater than the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq). This error bound should only
 be trusted if the previous boolean is true.
 err = 3  Reciprocal condition number: Estimated componentwise
 reciprocal condition number.  Compared with the threshold
 sqrt(n) * slamch(\(aqEpsilon\(aq) to determine if the error
 estimate is "guaranteed". These reciprocal condition
 numbers are 1 / (norm(Z^{-1},inf) * norm(Z,inf)) for some
 appropriately scaled matrix Z.
 Let Z = S*(A*diag(x)), where x is the solution for the
 current right-hand side and S scales each row of
 A*diag(x) by a power of the radix so all absolute row
 sums of Z are approximately 1.
 See Lapack Working Note 165 for further details and extra
 cautions.
 NPARAMS (input) INTEGER
 Specifies the number of parameters set in PARAMS.  If .LE. 0, the
 PARAMS array is never referenced and default values are used.
.TP 8
 PARAMS  (input / output) REAL array, dimension NPARAMS
 Specifies algorithm parameters.  If an entry is .LT. 0.0, then
 that entry will be filled with default value used for that
 parameter.  Only positions up to NPARAMS are accessed; defaults
 are used for higher-numbered parameters.
 PARAMS(LA_LINRX_ITREF_I = 1) : Whether to perform iterative
 refinement or not.
 Default: 1.0
.br
 = 0.0 : No refinement is performed, and no error bounds are
 computed.
 = 1.0 : Use the double-precision refinement algorithm,
 possibly with doubled-single computations if the
 compilation environment does not support DOUBLE
 PRECISION.
 (other values are reserved for future use)
 PARAMS(LA_LINRX_ITHRESH_I = 2) : Maximum number of residual
 computations allowed for refinement.
 Default: 10
.br
 Aggressive: Set to 100 to permit convergence using approximate
 factorizations or factorizations other than LU. If
 the factorization uses a technique other than
 Gaussian elimination, the guarantees in
 err_bnds_norm and err_bnds_comp may no longer be
 trustworthy.
 PARAMS(LA_LINRX_CWISE_I = 3) : Flag determining if the code
 will attempt to find a solution with small componentwise
 relative error in the double-precision algorithm.  Positive
 is true, 0.0 is false.
 Default: 1.0 (attempt componentwise convergence)
.TP 8
 WORK    (workspace) COMPLEX array, dimension (2*N)
.TP 8
 RWORK   (workspace) REAL array, dimension (2*N)
.TP 8
 INFO    (output) INTEGER
.br
 = 0:  Successful exit. The solution to every right-hand side is
 guaranteed.
 < 0:  If INFO = -i, the i-th argument had an illegal value
.br
 > 0 and <= N:  U(INFO,INFO) is exactly zero.  The factorization
 has been completed, but the factor U is exactly singular, so
 the solution and error bounds could not be computed. RCOND = 0
 is returned.
 = N+J: The solution corresponding to the Jth right-hand side is
 not guaranteed. The solutions corresponding to other right-
 hand sides K with K > J may not be guaranteed as well, but
 only the first such right-hand side is reported. If a small
 componentwise error is not requested (PARAMS(3) = 0.0) then
 the Jth right-hand side is the first with a normwise error
 bound that is not guaranteed (the smallest J such
 that ERR_BNDS_NORM(J,1) = 0.0). By default (PARAMS(3) = 1.0)
 the Jth right-hand side is the first with either a normwise or
 componentwise error bound that is not guaranteed (the smallest
 J such that either ERR_BNDS_NORM(J,1) = 0.0 or
 ERR_BNDS_COMP(J,1) = 0.0). See the definition of
 ERR_BNDS_NORM(:,1) and ERR_BNDS_COMP(:,1). To get information
 about all of the right-hand sides check ERR_BNDS_NORM or
 ERR_BNDS_COMP.
