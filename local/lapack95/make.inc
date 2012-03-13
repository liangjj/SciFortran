#
#  -- LAPACK95 interface driver routine (version 2.0) --
#     UNI-C, Denmark; Univ. of Tennessee, USA; NAG Ltd., UK
#     August 5, 2000
#
FC	 = ifort
FC1      = ifort
# -dcfuns  Enable recognition of non-standard double
#          precision  complex intrinsic functions
# -dusty   Allows the compilation and execution of "legacy"
#          software by downgrading the category  of  common
#          errors  found  in  such software from "Error" to
# -ieee=full enables all IEEE arithmetic facilities
#          including non-stop arithmetic.

OPTS0    = -O3
#-u -V -dcfuns -dusty -ieee=full
MODLIB   = -I./../lapack95_modules
OPTS1    = -c $(OPTS0)
OPTS3    = $(OPTS1) $(MODLIB)
OPTL     = -o 
OPTLIB   =

LAPACK_PATH = /home/amaricci/lib/local/lapack

LAPACK95 = ../liblapack95_intel.a
LAPACK77 = $(LAPACK_PATH)/liblapack_intel.a
TMG77    = $(LAPACK_PATH)/libtmg_intel.a
BLAS     = /home/amaricci/lib/local/blas/libblas_intel.a

LIBS     = $(LAPACK95) $(TMG77) $(LAPACK77) $(BLAS)
SUF      = f90

XX = 'rm' -f $@; \
        'rm' -f $@.res; \
	$(FC) $(OPTS0) -o $@ $(MODLIB) $@.$(SUF) $(OPTLIB) $(LIBS); \
        $@ < $@.dat > $@.res; \
        'rm' -f $@

YY = $(FC) $(OPTS0) -o $@ $(MODLIB) $@.$(SUF) $(OPTLIB) $(LIBS)

.SUFFIXES: .f90 .f .o

.$(SUF).o: 
	$(FC) $(OPTS3) $<

.f.o:
	$(FC1) $(OPTS3) $<
