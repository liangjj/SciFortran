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
!      Intel(R) Math Kernel Library (MKL) examples interface
!******************************************************************************/

#ifndef _MKL_EXAMPLE_H_
#define _MKL_EXAMPLE_H_

#include "mkl_types.h"
#include "mkl_cblas.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define COMMENTS ':'
#define MAX_STRING_LEN  512

#define MIN(a,b)  (((a) > (b)) ? (b) : (a))
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))


#define GENERAL_MATRIX  0
#define UPPER_MATRIX    1
#define LOWER_MATRIX   -1

#define FULLPRINT  0
#define SHORTPRINT 1

#ifdef MKL_ILP64
  #define INT_FORMAT "%lld"
#else
  #define INT_FORMAT "%d"
#endif

/*
 * ===========================================
 * Prototypes for example program functions
 * ===========================================
 */

int GetIntegerParameters(FILE*, ...);
int GetScalarsD(FILE*, ...);
int GetScalarsS(FILE*, ...);
int GetScalarsC(FILE*, ...);
int GetScalarsZ(FILE*, ...);
int GetCblasCharParameters(FILE *in_file, ...);
MKL_INT MaxValue(MKL_INT, MKL_INT*);
MKL_INT GetVectorI(FILE*, MKL_INT, MKL_INT*);
MKL_INT GetVectorS(FILE*, MKL_INT, float*, MKL_INT);
MKL_INT GetVectorC(FILE*, MKL_INT, MKL_Complex8*, MKL_INT);
MKL_INT GetVectorD(FILE*, MKL_INT, double*, MKL_INT);
MKL_INT GetVectorZ(FILE*, MKL_INT, MKL_Complex16*, MKL_INT);
MKL_INT GetArrayS(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT*, MKL_INT*, float*, MKL_INT*);
MKL_INT GetArrayD(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT*, MKL_INT*, double*, MKL_INT*);
MKL_INT GetArrayC(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT*, MKL_INT*, MKL_Complex8*, MKL_INT*);
MKL_INT GetArrayZ(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT*, MKL_INT*, MKL_Complex16*, MKL_INT*);
MKL_INT GetBandArrayS(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT, MKL_INT, MKL_INT, float*, MKL_INT);
MKL_INT GetBandArrayD(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT, MKL_INT, MKL_INT, double*, MKL_INT);
MKL_INT GetBandArrayC(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT, MKL_INT, MKL_INT, MKL_Complex8*, MKL_INT);
MKL_INT GetBandArrayZ(FILE*, CBLAS_ORDER*, MKL_INT, MKL_INT, MKL_INT, MKL_INT, MKL_Complex16*, MKL_INT);
MKL_INT GetValuesI(FILE *, MKL_INT *, MKL_INT, MKL_INT);
MKL_INT GetValuesC(FILE *, MKL_Complex8*, MKL_INT, MKL_INT, MKL_INT);
MKL_INT GetValuesZ(FILE *, MKL_Complex16*, MKL_INT, MKL_INT, MKL_INT);
MKL_INT GetValuesD(FILE *, double*, MKL_INT, MKL_INT, MKL_INT);
MKL_INT GetValuesS(FILE *, float*, MKL_INT, MKL_INT, MKL_INT);
void PrintParameters( char*, ... );
void PrintTrans(MKL_INT, CBLAS_TRANSPOSE*, CBLAS_TRANSPOSE*);
void PrintOrder(CBLAS_ORDER*);
void PrintVectorI(MKL_INT, MKL_INT*, char*);
void PrintVectorS(int, MKL_INT, float*, MKL_INT, char*);
void PrintVectorC(int, MKL_INT, MKL_Complex8*, MKL_INT, char*);
void PrintVectorD(int, MKL_INT, double*, MKL_INT, char*);
void PrintVectorZ(int, MKL_INT, MKL_Complex16*,  MKL_INT, char*);
void PrintArrayS(CBLAS_ORDER*, int, int, MKL_INT*, MKL_INT*, float*, MKL_INT*, char*);
void PrintArrayD(CBLAS_ORDER*, int, int, MKL_INT*, MKL_INT*, double*, MKL_INT*, char*);
void PrintArrayC(CBLAS_ORDER*, int, int, MKL_INT*, MKL_INT*, MKL_Complex8*, MKL_INT*, char*);
void PrintArrayZ(CBLAS_ORDER*, int, int, MKL_INT*, MKL_INT*, MKL_Complex16*, MKL_INT*, char*);
void PrintBandArrayS(CBLAS_ORDER*, int, MKL_INT, MKL_INT, MKL_INT, MKL_INT, float*, MKL_INT, char*);
void PrintBandArrayD(CBLAS_ORDER*, int, MKL_INT, MKL_INT, MKL_INT, MKL_INT, double*, MKL_INT, char*);
void PrintBandArrayC(CBLAS_ORDER*, int, MKL_INT, MKL_INT, MKL_INT, MKL_INT, MKL_Complex8*, MKL_INT, char*);
void PrintBandArrayZ(CBLAS_ORDER*, int, MKL_INT, MKL_INT, MKL_INT, MKL_INT, MKL_Complex16*, MKL_INT, char*);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_EXAMPLE_H_ */
