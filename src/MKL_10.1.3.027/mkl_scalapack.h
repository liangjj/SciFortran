/*******************************************************************************
!                             INTEL CONFIDENTIAL
!   Copyright(C) 1999-2009 Intel Corporation. All Rights Reserved.
!   The source code contained  or  described herein and all documents related to
!   the source code ("Material") are owned by Intel Corporation or its suppliers
!   or licensors.  Title to the  Material remains with  Intel Corporation or its
!   suppliers and licensors. The Material contains trade secrets and proprietary
!   and  confidential  information of  Intel or its suppliers and licensors. The
!   Material  is  protected  by  worldwide  copyright  and trade secret laws and
!   treaty  provisions. No part of the Material may be used, copied, reproduced,
!   modified, published, uploaded, posted, transmitted, distributed or disclosed
!   in any way without Intel's prior express written permission.
!   No license  under any  patent, copyright, trade secret or other intellectual
!   property right is granted to or conferred upon you by disclosure or delivery
!   of the Materials,  either expressly, by implication, inducement, estoppel or
!   otherwise.  Any  license  under  such  intellectual property  rights must be
!   express and approved by Intel in writing.
!
!*******************************************************************************
!  Content:
!      Intel(R) Math Kernel Library (MKL) interface for SCALAPACK routines
!******************************************************************************/

#ifndef _MKL_SCALAPACK_H_
#define _MKL_SCALAPACK_H_

#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* <name>_ declarations */

void	psgetrf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pdgetrf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pcgetrf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pzgetrf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);

void	psgbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, float *a, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, double *a, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrf_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotrf_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotrf_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotrf_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotrf_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pspbtrf_(char *uplo, MKL_INT *n, MKL_INT *bw, float *a, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrf_(char *uplo, MKL_INT *n, MKL_INT *bw, double *a, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrf_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrf_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrf_(MKL_INT *n, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrf_(MKL_INT *n, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrf_(MKL_INT *n, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrf_(MKL_INT *n, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrf_(MKL_INT *n, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrf_(MKL_INT *n, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrf_(MKL_INT *n, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrf_(MKL_INT *n, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgetrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdgetrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcgetrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzgetrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdpotrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcpotrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzpotrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	pspbtrs_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrs_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrs_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrs_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrs_(MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrs_(MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrs_(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pstrtrs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdtrtrs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pctrtrs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pztrtrs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgecon_(char *norm, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgecon_(char *norm, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgecon_(char *norm, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgecon_(char *norm, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pspocon_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdpocon_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcpocon_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzpocon_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pstrcon_(char *norm, char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdtrcon_(char *norm, char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pctrcon_(char *norm, char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pztrcon_(char *norm, char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgerfs_(char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgerfs_(char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgerfs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgerfs_(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psporfs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdporfs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcporfs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzporfs_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pstrrfs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdtrrfs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pctrrfs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pztrrfs_(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgetri_(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgetri_(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgetri_(MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pzgetri_(MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);

void	pspotri_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotri_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotri_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotri_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pstrtri_(char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdtrtri_(char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pctrtri_(char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pztrtri_(char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	psgeequ_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, MKL_INT *info);
void	pdgeequ_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, MKL_INT *info);
void	pcgeequ_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, MKL_INT *info);
void	pzgeequ_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, MKL_INT *info);

void	pspoequ_(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, MKL_INT *info);
void	pdpoequ_(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, MKL_INT *info);
void	pcpoequ_(MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, MKL_INT *info);
void	pzpoequ_(MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, MKL_INT *info);

void	psgeqrf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqrf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqrf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgeqrf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqpf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqpf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqpf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgeqpf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psorgqr_(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgqr_(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungqr_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungqr_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormqr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormqr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmqr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmqr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgelqf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgelqf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgelqf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgelqf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorglq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorglq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunglq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunglq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormlq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormlq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmlq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmlq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqlf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqlf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqlf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgeqlf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorgql_(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgql_(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungql_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungql_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormql_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormql_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmql_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmql_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgerqf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgerqf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgerqf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgerqf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorgrq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgrq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungrq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungrq_(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormrq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormrq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmrq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmrq_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pstzrzf_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdtzrzf_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pctzrzf_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pztzrzf_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormrz_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormrz_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmrz_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmrz_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psggqrf_(MKL_INT *n, MKL_INT *m, MKL_INT *p, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *taua, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *taub, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdggqrf_(MKL_INT *n, MKL_INT *m, MKL_INT *p, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *taua, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *taub, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcggqrf_(MKL_INT *n, MKL_INT *m, MKL_INT *p, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *taua, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *taub, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzggqrf_(MKL_INT *n, MKL_INT *m, MKL_INT *p, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *taua, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *taub, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psggrqf_(MKL_INT *m, MKL_INT *p, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *taua, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *taub, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdggrqf_(MKL_INT *m, MKL_INT *p, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *taua, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *taub, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcggrqf_(MKL_INT *m, MKL_INT *p, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *taua, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *taub, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzggrqf_(MKL_INT *m, MKL_INT *p, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *taua, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *taub, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssytrd_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdsytrd_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	psormtr_(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormtr_(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pchetrd_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzhetrd_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmtr_(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmtr_(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psstebz_(MKL_INT *ictxt, char *range, char *order, MKL_INT *n, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, float *d, float *e, MKL_INT *m, MKL_INT *nsplit, float *w, MKL_INT *iblock, MKL_INT *isplit, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdstebz_(MKL_INT *ictxt, char *range, char *order, MKL_INT *n, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, double *d, double *e, MKL_INT *m, MKL_INT *nsplit, double *w, MKL_INT *iblock, MKL_INT *isplit, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);

void	psstein_(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdstein_(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);
void	pcstein_(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzstein_(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	psgehrd_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgehrd_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgehrd_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgehrd_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormhr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormhr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmhr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmhr_(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pslahqr_(MKL_INT *wantt, MKL_INT *wantz, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *desca, float *wr, float *wi, MKL_INT *iloz, MKL_INT *ihiz, float *z, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *ilwork, MKL_INT *info);
void	pdlahqr_(MKL_INT *wantt, MKL_INT *wantz, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *desca, double *wr, double *wi, MKL_INT *iloz, MKL_INT *ihiz, double *z, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *ilwork, MKL_INT *info);

void	psgebrd_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgebrd_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgebrd_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgebrd_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormbr_(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormbr_(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmbr_(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmbr_(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssygst_(MKL_INT *ibtype, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *scale, MKL_INT *info);
void	pdsygst_(MKL_INT *ibtype, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *scale, MKL_INT *info);

void	pchegst_(MKL_INT *ibtype, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *scale, MKL_INT *info);
void	pzhegst_(MKL_INT *ibtype, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *scale, MKL_INT *info);

void	psgesv_(MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdgesv_(MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcgesv_(MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzgesv_(MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgesvx_(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, float *r, float *c, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgesvx_(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, double *r, double *c, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgesvx_(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, float *r, float *c, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgesvx_(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, double *r, double *c, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbsv_(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdtsv_(MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddtsv_(MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdtsv_(MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdtsv_(MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psposv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdposv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcposv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzposv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psposvx_(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, float *sr, float *sc, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdposvx_(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, double *sr, double *sc, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcposvx_(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, float *sr, float *sc, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzposvx_(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, double *sr, double *sc, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pspbsv_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbsv_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbsv_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbsv_(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psptsv_(MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdptsv_(MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcptsv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzptsv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgels_(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgels_(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgels_(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgels_(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssyev_(char *jobz, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *w, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdsyev_(char *jobz, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *w, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *info);

void	pssyevx_(char *jobz, char *range, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdsyevx_(char *jobz, char *range, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pcheevx_(char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzheevx_(char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	psgesvd_(char *jobu, char *jobvt, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *s, float *u, MKL_INT *iu, MKL_INT *ju, MKL_INT *descu, float *vt, MKL_INT *ivt, MKL_INT *jvt, MKL_INT *descvt, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgesvd_(char *jobu, char *jobvt, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *s, double *u, MKL_INT *iu, MKL_INT *ju, MKL_INT *descu, double *vt, MKL_INT *ivt, MKL_INT *jvt, MKL_INT *descvt, double *work, MKL_INT *lwork, MKL_INT *info);

void	pssygvx_(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdsygvx_(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pchegvx_(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzhegvx_(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pclacgv_(MKL_INT *n, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzlacgv_(MKL_INT *n, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	pcmax1_(MKL_INT *n, MKL_Complex8 *amax, MKL_INT *indx, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzmax1_(MKL_INT *n, MKL_Complex16 *amax, MKL_INT *indx, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	ccombamax1_(MKL_Complex8 *v1, MKL_Complex8 *v2);
void	zcombamax1_(MKL_Complex16 *v1, MKL_Complex16 *v2);

void	pscsum1_(MKL_INT *n, float *asum, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pdzsum1_(MKL_INT *n, double *asum, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	psdbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgebd2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgebd2_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgebd2_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgebd2_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgehd2_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgehd2_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgehd2_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgehd2_(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgelq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgeql2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqr2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgerq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgetf2_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pdgetf2_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pcgetf2_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pzgetf2_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);

void	pslabrd_(MKL_INT *m, MKL_INT *n, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, float *work);
void	pdlabrd_(MKL_INT *m, MKL_INT *n, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, double *work);
void	pclabrd_(MKL_INT *m, MKL_INT *n, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_Complex8 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex8 *work);
void	pzlabrd_(MKL_INT *m, MKL_INT *n, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_Complex16 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex16 *work);

void	pslacon_(MKL_INT *n, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *isgn, float *est, MKL_INT *kase);
void	pdlacon_(MKL_INT *n, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *isgn, double *est, MKL_INT *kase);
void	pclacon_(MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *est, MKL_INT *kase);
void	pzlacon_(MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *est, MKL_INT *kase);

void	pslaconsb_(float *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *m, float *h44, float *h33, float *h43h34, float *buf, MKL_INT *lwork);
void	pdlaconsb_(double *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *m, double *h44, double *h33, double *h43h34, double *buf, MKL_INT *lwork);

void	pslacp2_(char *uplo, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pdlacp2_(char *uplo, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pclacp2_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pzlacp2_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);

void	pslacp3_(MKL_INT *m, MKL_INT *i, float *a, MKL_INT *desca, float *b, MKL_INT *ldb, MKL_INT *ii, MKL_INT *jj, MKL_INT *rev);
void	pdlacp3_(MKL_INT *m, MKL_INT *i, double *a, MKL_INT *desca, double *b, MKL_INT *ldb, MKL_INT *ii, MKL_INT *jj, MKL_INT *rev);

void	pslacpy_(char *uplo, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pdlacpy_(char *uplo, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pclacpy_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pzlacpy_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);

void	pslaevswp_(MKL_INT *n, float *zin, MKL_INT *ldzi, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, float *work, MKL_INT *lwork);
void	pdlaevswp_(MKL_INT *n, double *zin, MKL_INT *ldzi, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, double *work, MKL_INT *lwork);
void	pclaevswp_(MKL_INT *n, float *zin, MKL_INT *ldzi, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, float *rwork, MKL_INT *lrwork);
void	pzlaevswp_(MKL_INT *n, double *zin, MKL_INT *ldzi, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, double *rwork, MKL_INT *lrwork);

void	pslahrd_(MKL_INT *n, MKL_INT *k, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *t, float *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, float *work);
void	pdlahrd_(MKL_INT *n, MKL_INT *k, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *t, double *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, double *work);
void	pclahrd_(MKL_INT *n, MKL_INT *k, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex8 *work);
void	pzlahrd_(MKL_INT *n, MKL_INT *k, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex16 *work);

void	pslaiect_(float *sigma, MKL_INT *n, float *d, MKL_INT *count);
void	pdlaiectb_(float *sigma, MKL_INT *n, float *d, MKL_INT *count);
void	pdlaiectl_(float *sigma, MKL_INT *n, float *d, MKL_INT *count);

float	pslange_(char *norm, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlange_(char *norm, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclange_(char *norm, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlange_(char *norm, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

float	pslanhs_(char *norm, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlanhs_(char *norm, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclanhs_(char *norm, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlanhs_(char *norm, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

float	pslantr_(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlantr_(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclantr_(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlantr_(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

void	pslapiv_(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pdlapiv_(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pclapiv_(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pzlapiv_(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);

void	pslaqge_(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, char *equed);
void	pdlaqge_(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, char *equed);
void	pclaqge_(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, char *equed);
void	pzlaqge_(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, char *equed);

void	pslaqsy_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, char *equed);
void	pdlaqsy_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, char *equed);
void	pclaqsy_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, char *equed);
void	pzlaqsy_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, char *equed);

void	pslared1d_(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, float *bycol, float *byall, float *work, MKL_INT *lwork);
void	pdlared1d_(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, double *bycol, double *byall, double *work, MKL_INT *lwork);

void	pslared2d_(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, float *byrow, float *byall, float *work, MKL_INT *lwork);
void	pdlared2d_(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, double *byrow, double *byall, double *work, MKL_INT *lwork);

void	pslarf_(char *side, MKL_INT *m, MKL_INT *n, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarf_(char *side, MKL_INT *m, MKL_INT *n, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarf_(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarf_(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarfb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *t, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarfb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *t, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarfb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *t, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarfb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *t, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pclarfc_(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarfc_(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarfg_(MKL_INT *n, float *alpha, MKL_INT *iax, MKL_INT *jax, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *tau);
void	pdlarfg_(MKL_INT *n, double *alpha, MKL_INT *iax, MKL_INT *jax, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *tau);
void	pclarfg_(MKL_INT *n, MKL_Complex8 *alpha, MKL_INT *iax, MKL_INT *jax, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, MKL_Complex8 *tau);
void	pzlarfg_(MKL_INT *n, MKL_Complex16 *alpha, MKL_INT *iax, MKL_INT *jax, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, MKL_Complex16 *tau);

void	pslarft_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *tau, float *t, float *work);
void	pdlarft_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *tau, double *t, double *work);
void	pclarft_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *work);
void	pzlarft_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *work);

void	pslarz_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarz_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarz_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarz_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarzb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *t, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarzb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *t, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarzb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *t, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarzb_(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *t, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pclarzc_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarzc_(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarzt_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *tau, float *t, float *work);
void	pdlarzt_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *tau, double *t, double *work);
void	pclarzt_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *work);
void	pzlarzt_(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *work);

void	pslascl_(char *type, float *cfrom, float *cto, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdlascl_(char *type, double *cfrom, double *cto, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pclascl_(char *type, float *cfrom, float *cto, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzlascl_(char *type, double *cfrom, double *cto, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pslaset_(char *uplo, MKL_INT *m, MKL_INT *n, float *alpha, float *beta, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlaset_(char *uplo, MKL_INT *m, MKL_INT *n, double *alpha, double *beta, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclaset_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *alpha, MKL_Complex8 *beta, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlaset_(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *alpha, MKL_Complex16 *beta, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslasmsub_(float *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *k, float *smlnum, float *buf, MKL_INT *lwork);
void	pdlasmsub_(double *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *k, double *smlnum, double *buf, MKL_INT *lwork);

void	pslassq_(MKL_INT *n, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *scale, float *sumsq);
void	pdlassq_(MKL_INT *n, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *scale, double *sumsq);
void	pclassq_(MKL_INT *n, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *scale, float *sumsq);
void	pzlassq_(MKL_INT *n, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *scale, double *sumsq);

void	pslaswp_(char *direc, char *rowcol, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pdlaswp_(char *direc, char *rowcol, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pclaswp_(char *direc, char *rowcol, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pzlaswp_(char *direc, char *rowcol, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);

float	pslatra_(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
double	pdlatra_(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclatra_(MKL_Complex8 *, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlatra_(MKL_Complex16 *, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslatrd_(char *uplo, MKL_INT *n, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tau, float *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, float *work);
void	pdlatrd_(char *uplo, MKL_INT *n, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tau, double *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, double *work);
void	pclatrd_(char *uplo, MKL_INT *n, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tau, MKL_Complex8 *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, MKL_Complex8 *work);
void	pzlatrd_(char *uplo, MKL_INT *n, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tau, MKL_Complex16 *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, MKL_Complex16 *work);

void	pslatrs_(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *scale, float *cnorm, float *work);
void	pdlatrs_(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *scale, double *cnorm, double *work);
void	pclatrs_(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *scale, float *cnorm, MKL_Complex8 *work);
void	pzlatrs_(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *scale, double *cnorm, MKL_Complex16 *work);

void	pslatrz_(MKL_INT *m, MKL_INT *n, MKL_INT *l, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work);
void	pdlatrz_(MKL_INT *m, MKL_INT *n, MKL_INT *l, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work);
void	pclatrz_(MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work);
void	pzlatrz_(MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work);

void	pslauu2_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlauu2_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclauu2_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlauu2_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslauum_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlauum_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclauum_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlauum_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslawil_(MKL_INT *ii, MKL_INT *jj, MKL_INT *m, float *a, MKL_INT *desca, float *h44, float *h33, float *h43h34, float *v);
void	pdlawil_(MKL_INT *ii, MKL_INT *jj, MKL_INT *m, double *a, MKL_INT *desca, double *h44, double *h33, double *h43h34, double *v);

void	pspbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrsv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrsv_(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotf2_(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotf2_(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotf2_(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotf2_(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	psrscl_(MKL_INT *n, float *sa, float *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pdrscl_(MKL_INT *n, double *sa, double *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pcsrscl_(MKL_INT *n, float *sa, MKL_Complex8 *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzdrscl_(MKL_INT *n, double *sa, MKL_Complex16 *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	pstrti2_(char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdtrti2_(char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pctrti2_(char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pztrti2_(char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	slamsh_(float *s, MKL_INT *lds, MKL_INT *nbulge, MKL_INT *jblk, float *h, MKL_INT *ldh, MKL_INT *n, float *ulp);
void	dlamsh_(double *s, MKL_INT *lds, MKL_INT *nbulge, MKL_INT *jblk, double *h, MKL_INT *ldh, MKL_INT *n, double *ulp);

void	slaref_(char *type, float *a, MKL_INT *lda, MKL_INT *wantz, float *z, MKL_INT *ldz, MKL_INT *block, MKL_INT *irow1, MKL_INT *icol1, MKL_INT *istart, MKL_INT *istop, MKL_INT *itmp1, MKL_INT *itmp2, MKL_INT *liloz, MKL_INT *lihiz, float *vecs, float *v2, float *v3, float *t1, float *t2, float *t3);
void	dlaref_(char *type, double *a, MKL_INT *lda, MKL_INT *wantz, double *z, MKL_INT *ldz, MKL_INT *block, MKL_INT *irow1, MKL_INT *icol1, MKL_INT *istart, MKL_INT *istop, MKL_INT *itmp1, MKL_INT *itmp2, MKL_INT *liloz, MKL_INT *lihiz, double *vecs, double *v2, double *v3, double *t1, double *t2, double *t3);

void	slasorte_(float *s, MKL_INT *lds, MKL_INT *j, float *out, MKL_INT *info);
void	dlasorte_(double *s, MKL_INT *lds, MKL_INT *j, double *out, MKL_INT *info);

void	slasrt2_(char *id, MKL_INT *n, float *d, MKL_INT *key, MKL_INT *info);
void	dlasrt2_(char *id, MKL_INT *n, double *d, MKL_INT *key, MKL_INT *info);

void	sstein2_(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, float *z, MKL_INT *ldz, float *work, MKL_INT *iwork, MKL_INT *ifail, MKL_INT *info);
void	dstein2_(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, double *z, MKL_INT *ldz, double *work, MKL_INT *iwork, MKL_INT *ifail, MKL_INT *info);

void	sdbtf2_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, float *ab, MKL_INT *ldab, MKL_INT *info);
void	ddbtf2_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, double *ab, MKL_INT *ldab, MKL_INT *info);
void	cdbtf2_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex8 *ab, MKL_INT *ldab, MKL_INT *info);
void	zdbtf2_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex16 *ab, MKL_INT *ldab, MKL_INT *info);

void	sdbtrf_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, float *ab, MKL_INT *ldab, MKL_INT *info);
void	ddbtrf_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, double *ab, MKL_INT *ldab, MKL_INT *info);
void	cdbtrf_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex8 *ab, MKL_INT *ldab, MKL_INT *info);
void	zdbtrf_(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex16 *ab, MKL_INT *ldab, MKL_INT *info);

void	sdttrf_(MKL_INT *n, float *dl, float *d, float *du, MKL_INT *info);
void	ddttrf_(MKL_INT *n, double *dl, double *d, double *du, MKL_INT *info);
void	cdttrf_(MKL_INT *n, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *info);
void	zdttrf_(MKL_INT *n, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *info);

void	sdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, float *b, MKL_INT *ldb, MKL_INT *info);
void	ddttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, double *b, MKL_INT *ldb, MKL_INT *info);
void	cdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_Complex8 *b, MKL_INT *ldb, MKL_INT *info);
void	zdttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_Complex16 *b, MKL_INT *ldb, MKL_INT *info);

void	spttrsv_(char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, float *e, float *b, MKL_INT *ldb, MKL_INT *info);
void	dpttrsv_(char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, double *e, double *b, MKL_INT *ldb, MKL_INT *info);
void	cpttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_Complex8 *b, MKL_INT *ldb, MKL_INT *info);
void	zpttrsv_(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_Complex16 *b, MKL_INT *ldb, MKL_INT *info);

void	ssteqr2_(char *compz, MKL_INT *n, float *d, float *e, float *z, MKL_INT *ldz, MKL_INT *nr, float *work, MKL_INT *info);
void	dsteqr2_(char *compz, MKL_INT *n, double *d, double *e, double *z, MKL_INT *ldz, MKL_INT *nr, double *work, MKL_INT *info);

void	pslabad_(MKL_INT *ictxt, float *small, float *large);
void	pdlabad_(MKL_INT *ictxt, double *small, double *large);

void	pslachkieee_(MKL_INT *isieee, float *rmax, float *rmin);
void	pdlachkieee_(MKL_INT *isieee, float *rmax, float *rmin);

float	pslamch_(MKL_INT *ictxt, char *cmach);
double	pdlamch_(MKL_INT *ictxt, char *cmach);

void	pslasnbt_(MKL_INT *ieflag);
void	pdlasnbt_(MKL_INT *ieflag);

void	pxerbla_(MKL_INT *ictxt, char *srname, MKL_INT *info);


/* <name> declarations */

void	psgetrf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pdgetrf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pcgetrf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pzgetrf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);

void	psgbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, float *a, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, double *a, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrf(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotrf(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotrf(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotrf(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotrf(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pspbtrf(char *uplo, MKL_INT *n, MKL_INT *bw, float *a, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrf(char *uplo, MKL_INT *n, MKL_INT *bw, double *a, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrf(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrf(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrf(MKL_INT *n, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrf(MKL_INT *n, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrf(MKL_INT *n, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrf(MKL_INT *n, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrf(MKL_INT *n, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrf(MKL_INT *n, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrf(MKL_INT *n, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrf(MKL_INT *n, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgetrs(char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdgetrs(char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcgetrs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzgetrs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdpotrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcpotrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzpotrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	pspbtrs(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrs(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrs(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrs(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrs(MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrs(MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrs(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrs(char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrs(char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrs(char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pstrtrs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdtrtrs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pctrtrs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pztrtrs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgecon(char *norm, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgecon(char *norm, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgecon(char *norm, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgecon(char *norm, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pspocon(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdpocon(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcpocon(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *anorm, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzpocon(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *anorm, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pstrcon(char *norm, char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *rcond, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdtrcon(char *norm, char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *rcond, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pctrcon(char *norm, char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *rcond, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pztrcon(char *norm, char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *rcond, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgerfs(char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgerfs(char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgerfs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgerfs(char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psporfs(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdporfs(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcporfs(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzporfs(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pstrrfs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdtrrfs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pctrrfs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pztrrfs(char *uplo, char *trans, char *diag, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgetri(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgetri(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgetri(MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pzgetri(MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);

void	pspotri(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotri(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotri(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotri(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pstrtri(char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdtrtri(char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pctrtri(char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pztrtri(char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	psgeequ(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, MKL_INT *info);
void	pdgeequ(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, MKL_INT *info);
void	pcgeequ(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, MKL_INT *info);
void	pzgeequ(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, MKL_INT *info);

void	pspoequ(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, MKL_INT *info);
void	pdpoequ(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, MKL_INT *info);
void	pcpoequ(MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, MKL_INT *info);
void	pzpoequ(MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, MKL_INT *info);

void	psgeqrf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqrf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqrf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgeqrf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqpf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqpf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqpf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgeqpf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psorgqr(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgqr(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungqr(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungqr(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormqr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormqr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmqr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmqr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgelqf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgelqf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgelqf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgelqf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorglq(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorglq(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunglq(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunglq(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormlq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormlq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmlq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmlq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqlf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgeqlf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgeqlf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgeqlf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorgql(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgql(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungql(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungql(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormql(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormql(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmql(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmql(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgerqf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgerqf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgerqf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgerqf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psorgrq(MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdorgrq(MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcungrq(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzungrq(MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormrq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormrq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmrq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmrq(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pstzrzf(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdtzrzf(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pctzrzf(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pztzrzf(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormrz(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormrz(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmrz(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmrz(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psggqrf(MKL_INT *n, MKL_INT *m, MKL_INT *p, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *taua, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *taub, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdggqrf(MKL_INT *n, MKL_INT *m, MKL_INT *p, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *taua, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *taub, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcggqrf(MKL_INT *n, MKL_INT *m, MKL_INT *p, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *taua, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *taub, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzggqrf(MKL_INT *n, MKL_INT *m, MKL_INT *p, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *taua, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *taub, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psggrqf(MKL_INT *m, MKL_INT *p, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *taua, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *taub, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdggrqf(MKL_INT *m, MKL_INT *p, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *taua, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *taub, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcggrqf(MKL_INT *m, MKL_INT *p, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *taua, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *taub, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzggrqf(MKL_INT *m, MKL_INT *p, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *taua, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *taub, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssytrd(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdsytrd(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);

void	psormtr(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormtr(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pchetrd(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzhetrd(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmtr(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmtr(char *side, char *uplo, char *trans, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psstebz(MKL_INT *ictxt, char *range, char *order, MKL_INT *n, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, float *d, float *e, MKL_INT *m, MKL_INT *nsplit, float *w, MKL_INT *iblock, MKL_INT *isplit, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdstebz(MKL_INT *ictxt, char *range, char *order, MKL_INT *n, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, double *d, double *e, MKL_INT *m, MKL_INT *nsplit, double *w, MKL_INT *iblock, MKL_INT *isplit, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);

void	psstein(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdstein(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);
void	pcstein(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzstein(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	psgehrd(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgehrd(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgehrd(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgehrd(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormhr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormhr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmhr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmhr(char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pslahqr(MKL_INT *wantt, MKL_INT *wantz, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *desca, float *wr, float *wi, MKL_INT *iloz, MKL_INT *ihiz, float *z, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *ilwork, MKL_INT *info);
void	pdlahqr(MKL_INT *wantt, MKL_INT *wantz, MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *desca, double *wr, double *wi, MKL_INT *iloz, MKL_INT *ihiz, double *z, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *ilwork, MKL_INT *info);

void	psgebrd(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgebrd(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgebrd(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgebrd(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psormbr(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdormbr(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work, MKL_INT *lwork, MKL_INT *info);

void	pcunmbr(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzunmbr(char *vect, char *side, char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssygst(MKL_INT *ibtype, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *scale, MKL_INT *info);
void	pdsygst(MKL_INT *ibtype, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *scale, MKL_INT *info);

void	pchegst(MKL_INT *ibtype, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *scale, MKL_INT *info);
void	pzhegst(MKL_INT *ibtype, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *scale, MKL_INT *info);

void	psgesv(MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdgesv(MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcgesv(MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzgesv(MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psgesvx(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, float *r, float *c, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdgesvx(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, double *r, double *c, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcgesvx(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, float *r, float *c, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzgesvx(char *fact, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, MKL_INT *ipiv, char *equed, double *r, double *c, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	psgbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbsv(MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdtsv(MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddtsv(MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdtsv(MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdtsv(MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psposv(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pdposv(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pcposv(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);
void	pzposv(char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_INT *info);

void	psposvx(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, float *sr, float *sc, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pdposvx(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, double *sr, double *sc, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *info);
void	pcposvx(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, float *sr, float *sc, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *rcond, float *ferr, float *berr, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *info);
void	pzposvx(char *fact, char *uplo, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *af, MKL_INT *iaf, MKL_INT *jaf, MKL_INT *descaf, char *equed, double *sr, double *sc, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *rcond, double *ferr, double *berr, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *info);

void	pspbsv(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbsv(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbsv(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbsv(char *uplo, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psptsv(MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdptsv(MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcptsv(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzptsv(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgels(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgels(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgels(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgels(char *trans, MKL_INT *m, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pssyev(char *jobz, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *w, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdsyev(char *jobz, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *w, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *info);

void	pssyevx(char *jobz, char *range, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdsyevx(char *jobz, char *range, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pcheevx(char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzheevx(char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	psgesvd(char *jobu, char *jobvt, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *s, float *u, MKL_INT *iu, MKL_INT *ju, MKL_INT *descu, float *vt, MKL_INT *ivt, MKL_INT *jvt, MKL_INT *descvt, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgesvd(char *jobu, char *jobvt, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *s, double *u, MKL_INT *iu, MKL_INT *ju, MKL_INT *descu, double *vt, MKL_INT *ivt, MKL_INT *jvt, MKL_INT *descvt, double *work, MKL_INT *lwork, MKL_INT *info);

void	pssygvx(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, float *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pdsygvx(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, double *work, MKL_INT *lwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pchegvx(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, float *vl, float *vu, MKL_INT *il, MKL_INT *iu, float *abstol, MKL_INT *m, MKL_INT *nz, float *w, float *orfac, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex8 *work, MKL_INT *lwork, float *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, float *gap, MKL_INT *info);
void	pzhegvx(MKL_INT *ibtype, char *jobz, char *range, char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb, double *vl, double *vu, MKL_INT *il, MKL_INT *iu, double *abstol, MKL_INT *m, MKL_INT *nz, double *w, double *orfac, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_Complex16 *work, MKL_INT *lwork, double *rwork, MKL_INT *lrwork, MKL_INT *iwork, MKL_INT *liwork, MKL_INT *ifail, MKL_INT *iclustr, double *gap, MKL_INT *info);

void	pclacgv(MKL_INT *n, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzlacgv(MKL_INT *n, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	pcmax1(MKL_INT *n, MKL_Complex8 *amax, MKL_INT *indx, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzmax1(MKL_INT *n, MKL_Complex16 *amax, MKL_INT *indx, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	ccombamax1(MKL_Complex8 *v1, MKL_Complex8 *v2);
void	zcombamax1(MKL_Complex16 *v1, MKL_Complex16 *v2);

void	pscsum1(MKL_INT *n, float *asum, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pdzsum1(MKL_INT *n, double *asum, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	psdbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bwl, MKL_INT *bwu, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pddttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgebd2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgebd2(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgebd2(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgebd2(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgehd2(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdgehd2(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcgehd2(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzgehd2(MKL_INT *n, MKL_INT *ilo, MKL_INT *ihi, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	psgelq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgelq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgeql2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeql2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgeqr2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgeqr2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgerq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);
void	psgerq2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work, MKL_INT *lwork, MKL_INT *info);

void	psgetf2(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pdgetf2(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pcgetf2(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);
void	pzgetf2(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *info);

void	pslabrd(MKL_INT *m, MKL_INT *n, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tauq, float *taup, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, float *work);
void	pdlabrd(MKL_INT *m, MKL_INT *n, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tauq, double *taup, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, double *work);
void	pclabrd(MKL_INT *m, MKL_INT *n, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tauq, MKL_Complex8 *taup, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_Complex8 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex8 *work);
void	pzlabrd(MKL_INT *m, MKL_INT *n, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tauq, MKL_Complex16 *taup, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_Complex16 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex16 *work);

void	pslacon(MKL_INT *n, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *isgn, float *est, MKL_INT *kase);
void	pdlacon(MKL_INT *n, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *isgn, double *est, MKL_INT *kase);
void	pclacon(MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *est, MKL_INT *kase);
void	pzlacon(MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *est, MKL_INT *kase);

void	pslaconsb(float *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *m, float *h44, float *h33, float *h43h34, float *buf, MKL_INT *lwork);
void	pdlaconsb(double *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *m, double *h44, double *h33, double *h43h34, double *buf, MKL_INT *lwork);

void	pslacp2(char *uplo, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pdlacp2(char *uplo, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pclacp2(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pzlacp2(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);

void	pslacp3(MKL_INT *m, MKL_INT *i, float *a, MKL_INT *desca, float *b, MKL_INT *ldb, MKL_INT *ii, MKL_INT *jj, MKL_INT *rev);
void	pdlacp3(MKL_INT *m, MKL_INT *i, double *a, MKL_INT *desca, double *b, MKL_INT *ldb, MKL_INT *ii, MKL_INT *jj, MKL_INT *rev);

void	pslacpy(char *uplo, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pdlacpy(char *uplo, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pclacpy(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);
void	pzlacpy(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *jb, MKL_INT *descb);

void	pslaevswp(MKL_INT *n, float *zin, MKL_INT *ldzi, float *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, float *work, MKL_INT *lwork);
void	pdlaevswp(MKL_INT *n, double *zin, MKL_INT *ldzi, double *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, double *work, MKL_INT *lwork);
void	pclaevswp(MKL_INT *n, float *zin, MKL_INT *ldzi, MKL_Complex8 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, float *rwork, MKL_INT *lrwork);
void	pzlaevswp(MKL_INT *n, double *zin, MKL_INT *ldzi, MKL_Complex16 *z, MKL_INT *iz, MKL_INT *jz, MKL_INT *descz, MKL_INT *nvs, MKL_INT *key, double *rwork, MKL_INT *lrwork);

void	pslahrd(MKL_INT *n, MKL_INT *k, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *t, float *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, float *work);
void	pdlahrd(MKL_INT *n, MKL_INT *k, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *t, double *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, double *work);
void	pclahrd(MKL_INT *n, MKL_INT *k, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex8 *work);
void	pzlahrd(MKL_INT *n, MKL_INT *k, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *y, MKL_INT *iy, MKL_INT *jy, MKL_INT *descy, MKL_Complex16 *work);

void	pslaiect(float *sigma, MKL_INT *n, float *d, MKL_INT *count);
void	pdlaiectb(float *sigma, MKL_INT *n, float *d, MKL_INT *count);
void	pdlaiectl(float *sigma, MKL_INT *n, float *d, MKL_INT *count);

float	pslange(char *norm, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlange(char *norm, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclange(char *norm, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlange(char *norm, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

float	pslanhs(char *norm, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlanhs(char *norm, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclanhs(char *norm, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlanhs(char *norm, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

float	pslantr(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pdlantr(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);
float	pclantr(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *work);
double	pzlantr(char *norm, char *uplo, char *diag, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *work);

void	pslapiv(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pdlapiv(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pclapiv(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);
void	pzlapiv(char *direc, char *rowcol, char *pivroc, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *ipiv, MKL_INT *ip, MKL_INT *jp, MKL_INT *descip, MKL_INT *iwork);

void	pslaqge(MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, char *equed);
void	pdlaqge(MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, char *equed);
void	pclaqge(MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *r, float *c, float *rowcnd, float *colcnd, float *amax, char *equed);
void	pzlaqge(MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *r, double *c, double *rowcnd, double *colcnd, double *amax, char *equed);

void	pslaqsy(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, char *equed);
void	pdlaqsy(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, char *equed);
void	pclaqsy(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *sr, float *sc, float *scond, float *amax, char *equed);
void	pzlaqsy(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *sr, double *sc, double *scond, double *amax, char *equed);

void	pslared1d(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, float *bycol, float *byall, float *work, MKL_INT *lwork);
void	pdlared1d(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, double *bycol, double *byall, double *work, MKL_INT *lwork);

void	pslared2d(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, float *byrow, float *byall, float *work, MKL_INT *lwork);
void	pdlared2d(MKL_INT *n, MKL_INT *ia, MKL_INT *ja, MKL_INT *desc, double *byrow, double *byall, double *work, MKL_INT *lwork);

void	pslarf(char *side, MKL_INT *m, MKL_INT *n, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarf(char *side, MKL_INT *m, MKL_INT *n, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarf(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarf(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarfb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *t, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarfb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *t, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarfb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *t, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarfb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *t, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pclarfc(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarfc(char *side, MKL_INT *m, MKL_INT *n, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarfg(MKL_INT *n, float *alpha, MKL_INT *iax, MKL_INT *jax, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *tau);
void	pdlarfg(MKL_INT *n, double *alpha, MKL_INT *iax, MKL_INT *jax, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *tau);
void	pclarfg(MKL_INT *n, MKL_Complex8 *alpha, MKL_INT *iax, MKL_INT *jax, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, MKL_Complex8 *tau);
void	pzlarfg(MKL_INT *n, MKL_Complex16 *alpha, MKL_INT *iax, MKL_INT *jax, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, MKL_Complex16 *tau);

void	pslarft(char *direct, char *storev, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *tau, float *t, float *work);
void	pdlarft(char *direct, char *storev, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *tau, double *t, double *work);
void	pclarft(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *work);
void	pzlarft(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *work);

void	pslarz(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, float *tau, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarz(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, double *tau, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarz(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarz(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarzb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *t, float *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, float *work);
void	pdlarzb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *t, double *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, double *work);
void	pclarzb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *t, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarzb(char *side, char *trans, char *direct, char *storev, MKL_INT *m, MKL_INT *n, MKL_INT *k, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *t, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pclarzc(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex8 *tau, MKL_Complex8 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex8 *work);
void	pzlarzc(char *side, MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_INT *incv, MKL_Complex16 *tau, MKL_Complex16 *c, MKL_INT *ic, MKL_INT *jc, MKL_INT *descc, MKL_Complex16 *work);

void	pslarzt(char *direct, char *storev, MKL_INT *n, MKL_INT *k, float *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, float *tau, float *t, float *work);
void	pdlarzt(char *direct, char *storev, MKL_INT *n, MKL_INT *k, double *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, double *tau, double *t, double *work);
void	pclarzt(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex8 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex8 *tau, MKL_Complex8 *t, MKL_Complex8 *work);
void	pzlarzt(char *direct, char *storev, MKL_INT *n, MKL_INT *k, MKL_Complex16 *v, MKL_INT *iv, MKL_INT *jv, MKL_INT *descv, MKL_Complex16 *tau, MKL_Complex16 *t, MKL_Complex16 *work);

void	pslascl(char *type, float *cfrom, float *cto, MKL_INT *m, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdlascl(char *type, double *cfrom, double *cto, MKL_INT *m, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pclascl(char *type, float *cfrom, float *cto, MKL_INT *m, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzlascl(char *type, double *cfrom, double *cto, MKL_INT *m, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	pslaset(char *uplo, MKL_INT *m, MKL_INT *n, float *alpha, float *beta, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlaset(char *uplo, MKL_INT *m, MKL_INT *n, double *alpha, double *beta, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclaset(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex8 *alpha, MKL_Complex8 *beta, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlaset(char *uplo, MKL_INT *m, MKL_INT *n, MKL_Complex16 *alpha, MKL_Complex16 *beta, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslasmsub(float *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *k, float *smlnum, float *buf, MKL_INT *lwork);
void	pdlasmsub(double *a, MKL_INT *desca, MKL_INT *i, MKL_INT *l, MKL_INT *k, double *smlnum, double *buf, MKL_INT *lwork);

void	pslassq(MKL_INT *n, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *scale, float *sumsq);
void	pdlassq(MKL_INT *n, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *scale, double *sumsq);
void	pclassq(MKL_INT *n, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, float *scale, float *sumsq);
void	pzlassq(MKL_INT *n, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx, double *scale, double *sumsq);

void	pslaswp(char *direc, char *rowcol, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pdlaswp(char *direc, char *rowcol, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pclaswp(char *direc, char *rowcol, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);
void	pzlaswp(char *direc, char *rowcol, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *k1, MKL_INT *k2, MKL_INT *ipiv);

float	pslatra(MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
double	pdlatra(MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclatra(MKL_Complex8 *, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlatra(MKL_Complex16 *, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslatrd(char *uplo, MKL_INT *n, MKL_INT *nb, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, float *tau, float *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, float *work);
void	pdlatrd(char *uplo, MKL_INT *n, MKL_INT *nb, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, double *tau, double *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, double *work);
void	pclatrd(char *uplo, MKL_INT *n, MKL_INT *nb, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *d, float *e, MKL_Complex8 *tau, MKL_Complex8 *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, MKL_Complex8 *work);
void	pzlatrd(char *uplo, MKL_INT *n, MKL_INT *nb, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *d, double *e, MKL_Complex16 *tau, MKL_Complex16 *w, MKL_INT *iw, MKL_INT *jw, MKL_INT *descw, MKL_Complex16 *work);

void	pslatrs(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *scale, float *cnorm, float *work);
void	pdlatrs(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *scale, double *cnorm, double *work);
void	pclatrs(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, float *scale, float *cnorm, MKL_Complex8 *work);
void	pzlatrs(char *uplo, char *trans, char *diag, char *normin, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *x, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, double *scale, double *cnorm, MKL_Complex16 *work);

void	pslatrz(MKL_INT *m, MKL_INT *n, MKL_INT *l, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, float *tau, float *work);
void	pdlatrz(MKL_INT *m, MKL_INT *n, MKL_INT *l, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, double *tau, double *work);
void	pclatrz(MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *tau, MKL_Complex8 *work);
void	pzlatrz(MKL_INT *m, MKL_INT *n, MKL_INT *l, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *tau, MKL_Complex16 *work);

void	pslauu2(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlauu2(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclauu2(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlauu2(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslauum(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pdlauum(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pclauum(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);
void	pzlauum(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca);

void	pslawil(MKL_INT *ii, MKL_INT *jj, MKL_INT *m, float *a, MKL_INT *desca, float *h44, float *h33, float *h43h34, float *v);
void	pdlawil(MKL_INT *ii, MKL_INT *jj, MKL_INT *m, double *a, MKL_INT *desca, double *h44, double *h33, double *h43h34, double *v);

void	pspbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, float *a, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, double *a, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpbtrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *bw, MKL_INT *nrhs, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspttrsv(char *uplo, MKL_INT *n, MKL_INT *nrhs, float *d, float *e, MKL_INT *ja, MKL_INT *desca, float *b, MKL_INT *ib, MKL_INT *descb, float *af, MKL_INT *laf, float *work, MKL_INT *lwork, MKL_INT *info);
void	pdpttrsv(char *uplo, MKL_INT *n, MKL_INT *nrhs, double *d, double *e, MKL_INT *ja, MKL_INT *desca, double *b, MKL_INT *ib, MKL_INT *descb, double *af, MKL_INT *laf, double *work, MKL_INT *lwork, MKL_INT *info);
void	pcpttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex8 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex8 *af, MKL_INT *laf, MKL_Complex8 *work, MKL_INT *lwork, MKL_INT *info);
void	pzpttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_INT *ja, MKL_INT *desca, MKL_Complex16 *b, MKL_INT *ib, MKL_INT *descb, MKL_Complex16 *af, MKL_INT *laf, MKL_Complex16 *work, MKL_INT *lwork, MKL_INT *info);

void	pspotf2(char *uplo, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdpotf2(char *uplo, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pcpotf2(char *uplo, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pzpotf2(char *uplo, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	psrscl(MKL_INT *n, float *sa, float *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pdrscl(MKL_INT *n, double *sa, double *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pcsrscl(MKL_INT *n, float *sa, MKL_Complex8 *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);
void	pzdrscl(MKL_INT *n, double *sa, MKL_Complex16 *sx, MKL_INT *ix, MKL_INT *jx, MKL_INT *descx, MKL_INT *incx);

void	pstrti2(char *uplo, char *diag, MKL_INT *n, float *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pdtrti2(char *uplo, char *diag, MKL_INT *n, double *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pctrti2(char *uplo, char *diag, MKL_INT *n, MKL_Complex8 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);
void	pztrti2(char *uplo, char *diag, MKL_INT *n, MKL_Complex16 *a, MKL_INT *ia, MKL_INT *ja, MKL_INT *desca, MKL_INT *info);

void	slamsh(float *s, MKL_INT *lds, MKL_INT *nbulge, MKL_INT *jblk, float *h, MKL_INT *ldh, MKL_INT *n, float *ulp);
void	dlamsh(double *s, MKL_INT *lds, MKL_INT *nbulge, MKL_INT *jblk, double *h, MKL_INT *ldh, MKL_INT *n, double *ulp);

void	slaref(char *type, float *a, MKL_INT *lda, MKL_INT *wantz, float *z, MKL_INT *ldz, MKL_INT *block, MKL_INT *irow1, MKL_INT *icol1, MKL_INT *istart, MKL_INT *istop, MKL_INT *itmp1, MKL_INT *itmp2, MKL_INT *liloz, MKL_INT *lihiz, float *vecs, float *v2, float *v3, float *t1, float *t2, float *t3);
void	dlaref(char *type, double *a, MKL_INT *lda, MKL_INT *wantz, double *z, MKL_INT *ldz, MKL_INT *block, MKL_INT *irow1, MKL_INT *icol1, MKL_INT *istart, MKL_INT *istop, MKL_INT *itmp1, MKL_INT *itmp2, MKL_INT *liloz, MKL_INT *lihiz, double *vecs, double *v2, double *v3, double *t1, double *t2, double *t3);

void	slasorte(float *s, MKL_INT *lds, MKL_INT *j, float *out, MKL_INT *info);
void	dlasorte(double *s, MKL_INT *lds, MKL_INT *j, double *out, MKL_INT *info);

void	slasrt2(char *id, MKL_INT *n, float *d, MKL_INT *key, MKL_INT *info);
void	dlasrt2(char *id, MKL_INT *n, double *d, MKL_INT *key, MKL_INT *info);

void	sstein2(MKL_INT *n, float *d, float *e, MKL_INT *m, float *w, MKL_INT *iblock, MKL_INT *isplit, float *orfac, float *z, MKL_INT *ldz, float *work, MKL_INT *iwork, MKL_INT *ifail, MKL_INT *info);
void	dstein2(MKL_INT *n, double *d, double *e, MKL_INT *m, double *w, MKL_INT *iblock, MKL_INT *isplit, double *orfac, double *z, MKL_INT *ldz, double *work, MKL_INT *iwork, MKL_INT *ifail, MKL_INT *info);

void	sdbtf2(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, float *ab, MKL_INT *ldab, MKL_INT *info);
void	ddbtf2(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, double *ab, MKL_INT *ldab, MKL_INT *info);
void	cdbtf2(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex8 *ab, MKL_INT *ldab, MKL_INT *info);
void	zdbtf2(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex16 *ab, MKL_INT *ldab, MKL_INT *info);

void	sdbtrf(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, float *ab, MKL_INT *ldab, MKL_INT *info);
void	ddbtrf(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, double *ab, MKL_INT *ldab, MKL_INT *info);
void	cdbtrf(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex8 *ab, MKL_INT *ldab, MKL_INT *info);
void	zdbtrf(MKL_INT *m, MKL_INT *n, MKL_INT *kl, MKL_INT *ku, MKL_Complex16 *ab, MKL_INT *ldab, MKL_INT *info);

void	sdttrf(MKL_INT *n, float *dl, float *d, float *du, MKL_INT *info);
void	ddttrf(MKL_INT *n, double *dl, double *d, double *du, MKL_INT *info);
void	cdttrf(MKL_INT *n, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_INT *info);
void	zdttrf(MKL_INT *n, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_INT *info);

void	sdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *dl, float *d, float *du, float *b, MKL_INT *ldb, MKL_INT *info);
void	ddttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *dl, double *d, double *du, double *b, MKL_INT *ldb, MKL_INT *info);
void	cdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex8 *dl, MKL_Complex8 *d, MKL_Complex8 *du, MKL_Complex8 *b, MKL_INT *ldb, MKL_INT *info);
void	zdttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, MKL_Complex16 *dl, MKL_Complex16 *d, MKL_Complex16 *du, MKL_Complex16 *b, MKL_INT *ldb, MKL_INT *info);

void	spttrsv(char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, float *e, float *b, MKL_INT *ldb, MKL_INT *info);
void	dpttrsv(char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, double *e, double *b, MKL_INT *ldb, MKL_INT *info);
void	cpttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, float *d, MKL_Complex8 *e, MKL_Complex8 *b, MKL_INT *ldb, MKL_INT *info);
void	zpttrsv(char *uplo, char *trans, MKL_INT *n, MKL_INT *nrhs, double *d, MKL_Complex16 *e, MKL_Complex16 *b, MKL_INT *ldb, MKL_INT *info);

void	ssteqr2(char *compz, MKL_INT *n, float *d, float *e, float *z, MKL_INT *ldz, MKL_INT *nr, float *work, MKL_INT *info);
void	dsteqr2(char *compz, MKL_INT *n, double *d, double *e, double *z, MKL_INT *ldz, MKL_INT *nr, double *work, MKL_INT *info);

void	pslabad(MKL_INT *ictxt, float *small, float *large);
void	pdlabad(MKL_INT *ictxt, double *small, double *large);

void	pslachkieee(MKL_INT *isieee, float *rmax, float *rmin);
void	pdlachkieee(MKL_INT *isieee, float *rmax, float *rmin);

float	pslamch(MKL_INT *ictxt, char *cmach);
double	pdlamch(MKL_INT *ictxt, char *cmach);

void	pslasnbt(MKL_INT *ieflag);
void	pdlasnbt(MKL_INT *ieflag);

void	pxerbla(MKL_INT *ictxt, char *srname, MKL_INT *info);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_SCALAPACK_H_ */
