/*******************************************************************************
!                             INTEL CONFIDENTIAL
!   Copyright(C) 2007-2009 Intel Corporation. All Rights Reserved.
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
!      Intel(R) Math Kernel Library (MKL) include for transposition routines
!******************************************************************************/

#if !defined(_MKL_TRANS_H)
#define _MKL_TRANS_H

/* for size_t */
#include <stddef.h>
/* for MKL complex data types */
#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* In-place transposition routines */

#define mkl_simatcopy Mkl_Simatcopy
void Mkl_Simatcopy(
    const char ordering, const char trans,
    size_t rows, size_t cols, 
    const float alpha, 
    float * AB, size_t lda, size_t ldb);

#define mkl_dimatcopy Mkl_Dimatcopy
void Mkl_Dimatcopy(
    const char ordering, const char trans,
    size_t rows, size_t cols, 
    const double alpha, 
    double * AB, size_t lda, size_t ldb);

#define mkl_cimatcopy Mkl_Cimatcopy
void Mkl_Cimatcopy(
    const char ordering, const char trans,
    size_t rows, size_t cols, 
    const MKL_Complex8 alpha, 
    MKL_Complex8 * AB, size_t lda, size_t ldb);

#define mkl_zimatcopy Mkl_Zimatcopy
void Mkl_Zimatcopy(
    const char ordering, const char trans,
    size_t rows, size_t cols, 
    const MKL_Complex16 alpha, 
    MKL_Complex16 * AB, size_t lda, size_t ldb);

/* Out-of-place transposition routines */

#define mkl_somatcopy Mkl_Somatcopy
void Mkl_Somatcopy(
    char ordering, char trans, 
    size_t rows, size_t cols, 
    const float alpha, 
    const float * A, size_t lda, 
    float * B, size_t ldb);

#define mkl_domatcopy Mkl_Domatcopy
void Mkl_Domatcopy(
    char ordering, char trans, 
    size_t rows, size_t cols, 
    const double alpha, 
    const double * A, size_t lda, 
    double * B, size_t ldb);

#define mkl_comatcopy Mkl_Comatcopy
void Mkl_Comatcopy(
    char ordering, char trans, 
    size_t rows, size_t cols, 
    const MKL_Complex8 alpha, 
    const MKL_Complex8 * A, size_t lda, 
    MKL_Complex8 * B, size_t ldb);

#define mkl_zomatcopy Mkl_Zomatcopy
void Mkl_Zomatcopy(
    char ordering, char trans, 
    size_t rows, size_t cols, 
    const MKL_Complex16 alpha, 
    const MKL_Complex16 * A, size_t lda, 
    MKL_Complex16 * B, size_t ldb);

/* Out-of-place transposition routines (all-strided case) */

#define mkl_somatcopy2 Mkl_Somatcopy2
void Mkl_Somatcopy2(
    char ordering, char trans,
    size_t rows, size_t cols, 
    const float alpha, 
    const float * A, size_t lda, size_t stridea, 
    float * B, size_t ldb, size_t strideb);

#define mkl_domatcopy2 Mkl_Domatcopy2
void Mkl_Domatcopy2(
    char ordering, char trans,
    size_t rows, size_t cols, 
    const double alpha, 
    const double * A, size_t lda, size_t stridea, 
    double * B, size_t ldb, size_t strideb);

#define mkl_comatcopy2 Mkl_Comatcopy2
void Mkl_Comatcopy2(
    char ordering, char trans,
    size_t rows, size_t cols, 
    const MKL_Complex8 alpha, 
    const MKL_Complex8 * A, size_t lda, size_t stridea, 
    MKL_Complex8 * B, size_t ldb, size_t strideb);

#define mkl_zomatcopy2 Mkl_Zomatcopy2
void Mkl_Zomatcopy2(
    char ordering, char trans,
    size_t rows, size_t cols, 
    const MKL_Complex16 alpha, 
    const MKL_Complex16 * A, size_t lda, size_t stridea, 
    MKL_Complex16 * B, size_t ldb, size_t strideb);

/* Out-of-place memory movement routines */

#define mkl_somatadd Mkl_Somatadd
void Mkl_Somatadd(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const float alpha, 
    const float * A, size_t lda,
    const float beta, 
    const float * B, size_t ldb,
    float * C, size_t ldc);

#define mkl_domatadd Mkl_Domatadd
void Mkl_Domatadd(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const double alpha, 
    const double * A, size_t lda,
    const double beta, 
    const double * B, size_t ldb,
    double * C, size_t ldc);

#define mkl_comatadd Mkl_Comatadd
void Mkl_Comatadd(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const MKL_Complex8 alpha, 
    const MKL_Complex8 * A, size_t lda,
    const MKL_Complex8 beta, 
    const MKL_Complex8 * B, size_t ldb,
    MKL_Complex8 * C, size_t ldc);

#define mkl_zomatadd Mkl_Zomatadd
void Mkl_Zomatadd(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const MKL_Complex16 alpha, 
    const MKL_Complex16 * A, size_t lda,
    const MKL_Complex16 beta, 
    const MKL_Complex16 * B, size_t ldb,
    MKL_Complex16 * C, size_t ldc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_TRANS_H */
