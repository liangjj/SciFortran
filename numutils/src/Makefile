DIREXE=$(HOME)/.bin/

#LOAD SCIFOR LIBRARY:
#======================================================
include sfmake.inc
#======================================================

all: print1 deriv kdensity numstat splot func wmatsubara fftgf arange pade linspace fermi spline random histogram print2

print1: 
	@echo " ..................... compile: optimized .......................... "

print2:
	@echo " ........................... done .................................. "

random:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

diagPAM:
	@echo "============================$@======================================="
	${FC} ${STD} -static  dfftpack.o $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

ffcmplx:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

pade:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

kdensity:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

histogram:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

fftgf:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

func:
	@echo "============================$@======================================="
	${FC} ${STD}  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@ -L/opt/local/lib -lmatheval

deriv:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

wmatsubara:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

arange:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

linspace:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

fermi:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

spline:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

numstat:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

splot:
	@echo "============================$@======================================="
	${FC} ${STD} -static  $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

vfplot:
	@echo "============================$@======================================="
	${FC} ${STD}  $@.f90   ${SFMODS} ${SFLIBS} ${DSL_LIBS} -o $(DIREXE)/$@


clean: 
	@echo "Cleaning:"
	@rm -fv $(DIREXE)/deriv $(DIREXE)/kdensity $(DIREXE)/numstat $(DIREXE)/splot $(DIREXE)/func $(DIREXE)/wmatsubara $(DIREXE)/arange $(DIREXE)/linspace $(DIREXE)/fermi $(DIREXE)/spline  $(DIREXE)/fftgf $(DIREXE)/pade  $(DIREXE)/histogram $(DIREXE)/ffcmplx $(DIREXE)/pade $(DIREXE)/random $(DIREXE)/vfplot
	@rm -f *.mod *.o *~
#########################################################################
