!*******************************************************************************
!                              INTEL CONFIDENTIAL
!   Copyright(C) 2002-2009 Intel Corporation. All Rights Reserved.
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
!      Intel(R) Math Kernel Library (MKL) interface for Cluster DFT routines
!*******************************************************************************

! Include to build module MKL_DFTI
INCLUDE 'mkl_dfti.f90'

! Definition of module MKL_CDFT_DM_TYPE. It is used just to define type DFTI_DESCRIPTOR_DM
MODULE MKL_CDFT_DM_TYPE

! Definition of descriptor.
! Structure of this type is not used in Fortran code. The pointer to this type is used only
TYPE DFTI_DESCRIPTOR_DM
    PRIVATE
    INTEGER(4) DESCRIPTOR
END TYPE

END MODULE

! Definition of module MKL_CDFT. It is used to define constants and interfaces of routines
MODULE MKL_CDFT

! Module MKL_CDFT includes definitions from module MKL_DFTI and MKL_CDFT_DM_TYPE
USE MKL_DFTI
USE MKL_CDFT_DM_TYPE

! Codes of parameters for DftiGetValueDM / DftiSetValueDM
INTEGER, PARAMETER :: CDFT_LOCAL_SIZE        =1000
INTEGER, PARAMETER :: CDFT_LOCAL_X_START     =1001
INTEGER, PARAMETER :: CDFT_LOCAL_NX          =1002
INTEGER, PARAMETER :: CDFT_MPI_COMM          =1003
INTEGER, PARAMETER :: CDFT_WORKSPACE         =1004
INTEGER, PARAMETER :: CDFT_LOCAL_OUT_X_START =1005
INTEGER, PARAMETER :: CDFT_LOCAL_OUT_NX      =1006

! Codes of errors
INTEGER, PARAMETER :: CDFT_MPI_ERROR     =1000
INTEGER, PARAMETER :: CDFT_SPREAD_ERROR  =1001

! Interfaces of routines
INTERFACE DftiCreateDescriptorDM
    INTEGER FUNCTION DftiCreateDescriptorDMn(C,H,P1,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER C,P1,P2,D,L(*)
        INTENT(IN) :: C,P1,P2,D,L
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiCreateDescriptorDMn_fortran' :: DftiCreateDescriptorDMn
        !DEC$ ATTRIBUTES REFERENCE :: H
    END FUNCTION
    INTEGER FUNCTION DftiCreateDescriptorDM1(C,H,P1,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER C,P1,P2,D,L
        INTENT(IN) :: C,P1,P2,D,L
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiCreateDescriptorDM1_fortran' :: DftiCreateDescriptorDM1
        !DEC$ ATTRIBUTES REFERENCE :: H
    END FUNCTION
    MODULE PROCEDURE DftiCreateDescriptorDM1_s
    MODULE PROCEDURE DftiCreateDescriptorDM1_d
    MODULE PROCEDURE DftiCreateDescriptorDMn_s
    MODULE PROCEDURE DftiCreateDescriptorDMn_d
END INTERFACE

INTERFACE DftiGetValueDM
    INTEGER FUNCTION DftiGetValueDMs(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(4) V
        INTENT(IN) :: P
        INTENT(OUT) :: V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiGetValueDM_fortran' :: DftiGetValueDMs
        !DEC$ ATTRIBUTES REFERENCE :: V
    END FUNCTION
    INTEGER FUNCTION DftiGetValueDMd(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(8) V
        INTENT(IN) :: P
        INTENT(OUT) :: V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiGetValueDM_fortran' :: DftiGetValueDMd
        !DEC$ ATTRIBUTES REFERENCE :: V
    END FUNCTION
    INTEGER FUNCTION DftiGetValueDMi(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P,V
        INTENT(IN) :: P
        INTENT(OUT) :: V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiGetValueDM_fortran' :: DftiGetValueDMi
        !DEC$ ATTRIBUTES REFERENCE :: V
    END FUNCTION
END INTERFACE

INTERFACE DftiSetValueDM
    INTEGER FUNCTION DftiSetValueDMs(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(4) V
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMf_fortran' :: DftiSetValueDMs
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMd(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(8) V
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMd_fortran' :: DftiSetValueDMd
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMi(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P,V
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMi_fortran' :: DftiSetValueDMi
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMpc(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        COMPLEX(4) V(*)
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMp_fortran' :: DftiSetValueDMpc
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMpz(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        COMPLEX(8) V(*)
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMp_fortran' :: DftiSetValueDMpz
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMps(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(4) V(*)
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMp_fortran' :: DftiSetValueDMps
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMpd(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P
        REAL(8) V(*)
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMp_fortran' :: DftiSetValueDMpd
    END FUNCTION
    INTEGER FUNCTION DftiSetValueDMpi(H,P,V)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        INTEGER P,V(*)
        INTENT(IN) :: P,V
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiSetValueDMp_fortran' :: DftiSetValueDMpi
    END FUNCTION
END INTERFACE

INTERFACE DftiCommitDescriptorDM
    INTEGER FUNCTION DftiCommitDescriptorDM(H)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiCommitDescriptorDM_fortran' :: DftiCommitDescriptorDM
    END FUNCTION
END INTERFACE

INTERFACE DftiComputeForwardDM
    INTEGER FUNCTION DftiComputeForwardDMoc(H,IN,OUT)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(4) IN(*),OUT(*)
!        INTENT(OUT) :: OUT
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeForwardDMo_fortran' :: DftiComputeForwardDMoc
    END FUNCTION
    INTEGER FUNCTION DftiComputeForwardDMoz(H,IN,OUT)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(8) IN(*),OUT(*)
!        INTENT(OUT) :: OUT
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeForwardDMo_fortran' :: DftiComputeForwardDMoz
    END FUNCTION
    INTEGER FUNCTION DftiComputeForwardDMic(H,IN)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(4) IN(*)
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeForwardDMi_fortran' :: DftiComputeForwardDMic
    END FUNCTION
    INTEGER FUNCTION DftiComputeForwardDMiz(H,IN)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(8) IN(*)
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeForwardDMi_fortran' :: DftiComputeForwardDMiz
    END FUNCTION
END INTERFACE

INTERFACE DftiComputeBackwardDM
    INTEGER FUNCTION DftiComputeBackwardDMoc(H,IN,OUT)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(4) IN(*),OUT(*)
!        INTENT(OUT) :: OUT
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeBackwardDMo_fortran' :: DftiComputeBackwardDMoc
    END FUNCTION
    INTEGER FUNCTION DftiComputeBackwardDMoz(H,IN,OUT)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(8) IN(*),OUT(*)
!        INTENT(OUT) :: OUT
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeBackwardDMo_fortran' :: DftiComputeBackwardDMoz
    END FUNCTION
    INTEGER FUNCTION DftiComputeBackwardDMic(H,IN)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(4) IN(*)
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeBackwardDMi_fortran' :: DftiComputeBackwardDMic
    END FUNCTION
    INTEGER FUNCTION DftiComputeBackwardDMiz(H,IN)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        COMPLEX(8) IN(*)
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiComputeBackwardDMi_fortran' :: DftiComputeBackwardDMiz
    END FUNCTION
END INTERFACE

INTERFACE DftiFreeDescriptorDM
    INTEGER FUNCTION DftiFreeDescriptorDM(H)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        !DEC$ ATTRIBUTES C, DECORATE, ALIAS:'DftiFreeDescriptorDM_fortran' :: DftiFreeDescriptorDM
        !DEC$ ATTRIBUTES REFERENCE :: H
    END FUNCTION
END INTERFACE

CONTAINS

INTEGER FUNCTION DftiCreateDescriptorDM1_s(C,H,P1R,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        REAL(4), INTENT(IN) :: P1R
        INTEGER C,P1,P2,D,L
        INTENT(IN) :: C,P2,D,L
        P1 = P1R
        DftiCreateDescriptorDM1_s = DftiCreateDescriptorDM1(C,H,P1,P2,D,L)
END FUNCTION
INTEGER FUNCTION DftiCreateDescriptorDM1_d(C,H,P1R,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        REAL(8), INTENT(IN) :: P1R
        INTEGER C,P1,P2,D,L
        INTENT(IN) :: C,P2,D,L
        P1 = P1R
        DftiCreateDescriptorDM1_d = DftiCreateDescriptorDM1(C,H,P1,P2,D,L)
END FUNCTION
INTEGER FUNCTION DftiCreateDescriptorDMn_s(C,H,P1R,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        REAL(4), INTENT(IN) :: P1R
        INTEGER C,P1,P2,D,L(*)
        INTENT(IN) :: C,P2,D,L
        P1 = P1R
        DftiCreateDescriptorDMn_s = DftiCreateDescriptorDMn(C,H,P1,P2,D,L)
END FUNCTION
INTEGER FUNCTION DftiCreateDescriptorDMn_d(C,H,P1R,P2,D,L)
        USE MKL_CDFT_DM_TYPE
        TYPE(DFTI_DESCRIPTOR_DM), POINTER :: H
        REAL(8), INTENT(IN) :: P1R
        INTEGER C,P1,P2,D,L(*)
        INTENT(IN) :: C,P2,D,L
        P1 = P1R
        DftiCreateDescriptorDMn_d = DftiCreateDescriptorDMn(C,H,P1,P2,D,L)
END FUNCTION

END MODULE
