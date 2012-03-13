.TH  ZLA_GERFSX_EXTENDED 1 "April 2011" "    LAPACK routine (version 3.2.1)                                 " "    LAPACK routine (version 3.2.1)                                 " 
.SH NAME
LAPACK-3 - improves the computed solution to a system of linear equations by performing extra-precise iterative refinement and provides error bounds and backward error estimates for the solution
.SH SYNOPSIS
.TP 32
SUBROUTINE ZLA_GERFSX_EXTENDED(
PREC_TYPE, TRANS_TYPE, N, NRHS, A,
LDA, AF, LDAF, IPIV, COLEQU, C, B,
LDB, Y, LDY, BERR_OUT, N_NORMS,
ERRS_N, ERRS_C, RES, AYB, DY,
Y_TAIL, RCOND, ITHRESH, RTHRESH,
DZ_UB, IGNORE_CWISE, INFO )
.TP 32
.ti +4
IMPLICIT
NONE
.TP 32
.ti +4
INTEGER
INFO, LDA, LDAF, LDB, LDY, N, NRHS, PREC_TYPE,
TRANS_TYPE, N_NORMS
.TP 32
.ti +4
LOGICAL
COLEQU, IGNORE_CWISE
.TP 32
.ti +4
INTEGER
ITHRESH
.TP 32
.ti +4
DOUBLE
PRECISION RTHRESH, DZ_UB
.TP 32
.ti +4
INTEGER
IPIV( * )
.TP 32
.ti +4
COMPLEX*16
A( LDA, * ), AF( LDAF, * ), B( LDB, * ),
Y( LDY, * ), RES( * ), DY( * ), Y_TAIL( * )
.TP 32
.ti +4
DOUBLE
PRECISION C( * ), AYB( * ), RCOND, BERR_OUT( * ),
ERRS_N( NRHS, * ), ERRS_C( NRHS, * )
.SH PURPOSE
ZLA_GERFSX_EXTENDED improves the computed solution to a system of
linear equations by performing extra-precise iterative refinement
and provides error bounds and backward error estimates for the solution.
 This subroutine is called by ZGERFSX to perform iterative refinement.
 In addition to normwise error bound, the code provides maximum
 componentwise error bound if possible. See comments for ERR_BNDS_NORM
 and ERR_BNDS_COMP for details of the error bounds. Note that this
 subroutine is only resonsible for setting the second fields of
 ERR_BNDS_NORM and ERR_BNDS_COMP.
.br
.SH ARGUMENTS
.TP 15
 PREC_TYPE      (input) INTEGER
 Specifies the intermediate precision to be used in refinement.
 The value is defined by ILAPREC(P) where P is a CHARACTER and
 P    = \(aqS\(aq:  Single
.br
 = \(aqD\(aq:  Double
.br
 = \(aqI\(aq:  Indigenous
.br
 = \(aqX\(aq, \(aqE\(aq:  Extra
.TP 15
 TRANS_TYPE     (input) INTEGER
 Specifies the transposition operation on A.
 The value is defined by ILATRANS(T) where T is a CHARACTER and
 T    = \(aqN\(aq:  No transpose
.br
 = \(aqT\(aq:  Transpose
.br
 = \(aqC\(aq:  Conjugate transpose
.TP 15
 N              (input) INTEGER
 The number of linear equations, i.e., the order of the
 matrix A.  N >= 0.
.TP 15
 NRHS           (input) INTEGER
 The number of right-hand-sides, i.e., the number of columns of the
 matrix B.
.TP 15
 A              (input) COMPLEX*16 array, dimension (LDA,N)
 On entry, the N-by-N matrix A.
.TP 15
 LDA            (input) INTEGER
 The leading dimension of the array A.  LDA >= max(1,N).
.TP 15
 AF             (input) COMPLEX*16 array, dimension (LDAF,N)
 The factors L and U from the factorization
 A = P*L*U as computed by ZGETRF.
.TP 15
 LDAF           (input) INTEGER
 The leading dimension of the array AF.  LDAF >= max(1,N).
.TP 15
 IPIV           (input) INTEGER array, dimension (N)
 The pivot indices from the factorization A = P*L*U
 as computed by ZGETRF; row i of the matrix was interchanged
 with row IPIV(i).
.TP 15
 COLEQU         (input) LOGICAL
 If .TRUE. then column equilibration was done to A before calling
 this routine. This is needed to compute the solution and error
 bounds correctly.
.TP 15
 C              (input) DOUBLE PRECISION array, dimension (N)
 The column scale factors for A. If COLEQU = .FALSE., C
 is not accessed. If C is input, each element of C should be a power
 of the radix to ensure a reliable solution and error estimates.
 Scaling by powers of the radix does not cause rounding errors unless
 the result underflows or overflows. Rounding errors during scaling
 lead to refining with a matrix that is not equivalent to the
 input matrix, producing error estimates that may not be
 reliable.
.TP 15
 B              (input) COMPLEX*16 array, dimension (LDB,NRHS)
 The right-hand-side matrix B.
.TP 15
 LDB            (input) INTEGER
 The leading dimension of the array B.  LDB >= max(1,N).
.TP 15
 Y              (input/output) COMPLEX*16 array, dimension (LDY,NRHS)
 On entry, the solution matrix X, as computed by ZGETRS.
 On exit, the improved solution matrix Y.
.TP 15
 LDY            (input) INTEGER
 The leading dimension of the array Y.  LDY >= max(1,N).
.TP 15
 BERR_OUT       (output) DOUBLE PRECISION array, dimension (NRHS)
 On exit, BERR_OUT(j) contains the componentwise relative backward
 error for right-hand-side j from the formula
 max(i) ( abs(RES(i)) / ( abs(op(A_s))*abs(Y) + abs(B_s) )(i) )
 where abs(Z) is the componentwise absolute value of the matrix
 or vector Z. This is computed by ZLA_LIN_BERR.
.TP 15
 N_NORMS        (input) INTEGER
 Determines which error bounds to return (see ERR_BNDS_NORM
 and ERR_BNDS_COMP).
 If N_NORMS >= 1 return normwise error bounds.
 If N_NORMS >= 2 return componentwise error bounds.
.TP 15
 ERR_BNDS_NORM  (input/output) DOUBLE PRECISION array, dimension
 (NRHS, N_ERR_BNDS)
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
 This subroutine is only responsible for setting the second field
 above.
 See Lapack Working Note 165 for further details and extra
 cautions.
.TP 15
 ERR_BNDS_COMP  (input/output) DOUBLE PRECISION array, dimension
 (NRHS, N_ERR_BNDS)
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
 This subroutine is only responsible for setting the second field
 above.
 See Lapack Working Note 165 for further details and extra
 cautions.
.TP 15
 RES            (input) COMPLEX*16 array, dimension (N)
 Workspace to hold the intermediate residual.
.TP 15
 AYB            (input) DOUBLE PRECISION array, dimension (N)
 Workspace.
.TP 15
 DY             (input) COMPLEX*16 array, dimension (N)
 Workspace to hold the intermediate solution.
.TP 15
 Y_TAIL         (input) COMPLEX*16 array, dimension (N)
 Workspace to hold the trailing bits of the intermediate solution.
.TP 15
 RCOND          (input) DOUBLE PRECISION
 Reciprocal scaled condition number.  This is an estimate of the
 reciprocal Skeel condition number of the matrix A after
 equilibration (if done).  If this is less than the machine
 precision (in particular, if it is zero), the matrix is singular
 to working precision.  Note that the error may still be small even
 if this number is very small and the matrix appears ill-
 conditioned.
.TP 15
 ITHRESH        (input) INTEGER
 The maximum number of residual computations allowed for
 refinement. The default is 10. For \(aqaggressive\(aq set to 100 to
 permit convergence using approximate factorizations or
 factorizations other than LU. If the factorization uses a
 technique other than Gaussian elimination, the guarantees in
 ERR_BNDS_NORM and ERR_BNDS_COMP may no longer be trustworthy.
.TP 15
 RTHRESH        (input) DOUBLE PRECISION
 Determines when to stop refinement if the error estimate stops
 decreasing. Refinement will stop when the next solution no longer
 satisfies norm(dx_{i+1}) < RTHRESH * norm(dx_i) where norm(Z) is
 the infinity norm of Z. RTHRESH satisfies 0 < RTHRESH <= 1. The
 default value is 0.5. For \(aqaggressive\(aq set to 0.9 to permit
 convergence on extremely ill-conditioned matrices. See LAWN 165
 for more details.
.TP 15
 DZ_UB          (input) DOUBLE PRECISION
 Determines when to start considering componentwise convergence.
 Componentwise convergence is only considered after each component
 of the solution Y is stable, which we definte as the relative
 change in each component being less than DZ_UB. The default value
 is 0.25, requiring the first bit to be stable. See LAWN 165 for
 more details.
.TP 15
 IGNORE_CWISE   (input) LOGICAL
 If .TRUE. then ignore componentwise convergence. Default value
 is .FALSE..
.TP 15
 INFO           (output) INTEGER
 = 0:  Successful exit.
.br
 < 0:  if INFO = -i, the ith argument to ZGETRS had an illegal
 value
