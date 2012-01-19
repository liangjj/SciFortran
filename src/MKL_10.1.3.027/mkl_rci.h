/*******************************************************************************
!                             INTEL CONFIDENTIAL
!   Copyright(C) 2005-2009 Intel Corporation. All Rights Reserved.
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
!   Intel(R) Math Kernel Library (MKL) interface for preconditioners, RCI ISS and
!   TR solvers routines
!******************************************************************************/

#ifndef _MKL_RCISOLVER_H_
#define _MKL_RCISOLVER_H_

#include "mkl_types.h"
#include "mkl_service.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined (_WIN32) || (_WIN64)
#define dcsrilu0  DCSRILU0
#define dcsrilut  DCSRILUT
#define dcg_init  DCG_INIT
#define dcg_check DCG_CHECK
#define dcg       DCG
#define dcg_get   DCG_GET

#define dcgmrhs_init  DCGMRHS_INIT
#define dcgmrhs_check DCGMRHS_CHECK
#define dcgmrhs       DCGMRHS
#define dcgmrhs_get   DCGMRHS_GET
#else
#define dcsrilu0 dcsrilu0_
#define dcsrilut dcsrilut_
#define dcg_init  dcg_init_
#define dcg_check dcg_check_
#define dcg       dcg_
#define dcg_get   dcg_get_

#define dcgmrhs_init  dcgmrhs_init_
#define dcgmrhs_check dcgmrhs_check_
#define dcgmrhs       dcgmrhs_
#define dcgmrhs_get   dcgmrhs_get_

#define dfgmres_init  dfgmres_init_
#define dfgmres_check dfgmres_check_
#define dfgmres       dfgmres_
#define dfgmres_get   dfgmres_get_
#endif

extern void dcsrilu0(MKL_INT *n, double *a,MKL_INT *ia,MKL_INT *ja, double *alu,MKL_INT *ipar, double *dpar,MKL_INT *ierr);
extern void dcsrilut(MKL_INT *n, double *a,MKL_INT *ia,MKL_INT *ja,
                     double *alut,MKL_INT *ialut,MKL_INT *jalut,double * tol,MKL_INT *maxfil,MKL_INT *ipar, double *dpar,MKL_INT *ierr);


/* PCG/PFGMRES Lower case */

extern void dcg_init(MKL_INT *n, double *x,double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcg_check(MKL_INT *n, double *x,double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcg(MKL_INT *n, double *x,double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcg_get(MKL_INT *n, double *x, double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp, MKL_INT *itercount);

extern void dcgmrhs_init(MKL_INT *n, double *x, MKL_INT* nRhs, double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcgmrhs_check(MKL_INT *n, double *x, MKL_INT* nRhs, double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcgmrhs(MKL_INT *n, double *x, MKL_INT* nRhs, double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dcgmrhs_get(MKL_INT *n, double *x, MKL_INT* nRhs, double *b, MKL_INT *rci_request, MKL_INT *ipar, double *dpar, double *tmp, MKL_INT *itercount);

extern void dfgmres_init(MKL_INT *n, double *x, double *b, MKL_INT *RCI_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dfgmres_check(MKL_INT *n, double *x, double *b, MKL_INT *RCI_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dfgmres(MKL_INT *n, double *x, double *b, MKL_INT *RCI_request, MKL_INT *ipar, double *dpar, double *tmp);
extern void dfgmres_get(MKL_INT *n, double *x, double *b, MKL_INT *RCI_request, MKL_INT *ipar, double *dpar, double *tmp, MKL_INT *itercount);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

/* Return status values */
#define TR_SUCCESS              1501
#define TR_INVALID_OPTION       1502
#define TR_OUT_OF_MEMORY        1503

/* Basic data types */
typedef void*					_TRNSP_HANDLE_t;
typedef void*					_TRNSPBC_HANDLE_t;
typedef void*					_JACOBIMATRIX_HANDLE_t;

/* Function prototypes */
extern MKL_INT			dtrnlsp_init		(_TRNSP_HANDLE_t*, MKL_INT*, MKL_INT*, double*, double*, MKL_INT*, MKL_INT*, double*);
extern MKL_INT			dtrnlsp_solve		(_TRNSP_HANDLE_t*, double*, double*, MKL_INT*);
extern MKL_INT			dtrnlsp_get		    (_TRNSP_HANDLE_t*, MKL_INT*, MKL_INT*, double*, double*);
extern MKL_INT			dtrnlsp_delete		(_TRNSP_HANDLE_t*);

extern MKL_INT			dtrnlspbc_init		(_TRNSPBC_HANDLE_t*, MKL_INT*, MKL_INT*, double*, double*, double*, double*, MKL_INT*, MKL_INT*, double*);
extern MKL_INT			dtrnlspbc_solve		(_TRNSPBC_HANDLE_t*, double*, double*, MKL_INT*);
extern MKL_INT			dtrnlspbc_get		(_TRNSPBC_HANDLE_t*, MKL_INT*, MKL_INT*, double*, double*);
extern MKL_INT			dtrnlspbc_delete	(_TRNSPBC_HANDLE_t*);

extern MKL_INT			djacobi_init		(_JACOBIMATRIX_HANDLE_t*, MKL_INT*, MKL_INT*, double*, double*, double*);
extern MKL_INT			djacobi_solve		(_JACOBIMATRIX_HANDLE_t*, double*, double*, MKL_INT*);
extern MKL_INT			djacobi_delete		(_JACOBIMATRIX_HANDLE_t*);
extern MKL_INT			djacobi			    (void*, MKL_INT*, MKL_INT*, double*, double*, double*);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_RCISOLVER_H_ */
