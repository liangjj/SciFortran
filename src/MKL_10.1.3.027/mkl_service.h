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
!      Intel(R) Math Kernel Library (MKL) interface for service routines
!******************************************************************************/

#ifndef _MKL_SERVICE_H_
#define _MKL_SERVICE_H_

#include <stdlib.h>
#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void MKLGetVersion(MKLVersion *ver);
void MKLGetVersionString(char * buffer, int len);
void MKLGetVersionString_c(char * buffer, int len);

void MKL_FreeBuffers(void);           /* Free the memory allocated by Memory Manager */
MKL_INT64 MKL_MemStat(int* nbuffers); /* MKL Memory Manager statistical information. */
                                      /* Returns an amount of memory, allocated by Memory Manager */
                                      /* in <nbuffers> buffers. */

/* Note: the next 2 functions are NOT the staff of MKL Memory Manager */
void* MKL_malloc(size_t size, int align); /* Allocate the aligned buffer */
void  MKL_free(void *ptr);                /* Free the memory allocated by MKL_malloc() */

void   getcpuclocks(unsigned MKL_INT64 *); /* gets CPU clocks */
double getcpufrequency(void); /* get CPU frequency in GHz */
void   setcpufrequency(double*); /* Set "MKL internal" CPU frequency in GHz */

void MKL_Set_Num_Threads(int nth);
int  MKL_Get_Max_Threads(void);
int  MKL_Domain_Set_Num_Threads(int nth, int MKL_DOMAIN);
int  MKL_Domain_Get_Max_Threads(int MKL_DOMAIN);
void MKL_Set_Dynamic(int bool_MKL_DYNAMIC);
int  MKL_Get_Dynamic(void);


#define mkl_set_num_threads         MKL_Set_Num_Threads
#define mkl_get_max_threads         MKL_Get_Max_Threads
#define mkl_domain_set_num_threads  MKL_Domain_Set_Num_Threads
#define mkl_domain_get_max_threads  MKL_Domain_Get_Max_Threads
#define mkl_set_dynamic             MKL_Set_Dynamic
#define mkl_get_dynamic             MKL_Get_Dynamic

/* MKL Progress routine */
#ifndef _MKL_PROGRESS_H_
#define _MKL_PROGRESS_H_
int MKL_PROGRESS( int* thread, int* step, char* stage, int lstage );
int MKL_PROGRESS_( int* thread, int* step, char* stage, int lstage );
int mkl_progress( int* thread, int* step, char* stage, int lstage );
int mkl_progress_( int* thread, int* step, char* stage, int lstage );
#endif /* _MKL_PROGRESS_H_ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_SERVICE_H_ */
