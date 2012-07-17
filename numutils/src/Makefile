DIREXE=$(HOME)/lib/numutils/bin

#LOAD SCIFOR LIBRARY:
#======================================================
include $(SFDIR)/etc/lib.mk
#======================================================

all: print1 deriv kdensity numstat splot func wmatsubara arange linspace fermi spline random histogram print2

print1: 
	@echo " ..................... compile: optimized .......................... "

print2:
	@echo " ........................... done .................................. "

random:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

ffcmplx:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

pade:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

kdensity:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

histogram:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

func:
	@echo "============================$@======================================="
	${FC} ${STD} ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@ -L/usr/lib -lmatheval

deriv:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

wmatsubara:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

arange:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

linspace:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

fermi:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

spline:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

numstat:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

splot:
	@echo "============================$@======================================="
	${FC} ${STD} -static ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} -o $(DIREXE)/$@

vfplot:
	@echo "============================$@======================================="
	${FC} ${STD} ${OBJS} $@.f90   ${SFMODS} ${SFLIBS} ${DSL_LIBS} -o $(DIREXE)/$@


clean: 
	@echo "Cleaning:"
	@rm -fv $(DIREXE)/deriv $(DIREXE)/kdensity $(DIREXE)/numstat $(DIREXE)/splot $(DIREXE)/func $(DIREXE)/wmatsubara $(DIREXE)/arange $(DIREXE)/linspace $(DIREXE)/fermi $(DIREXE)/spline  $(DIREXE)/histogram
	@rm -f *.mod *.o *~
#########################################################################
