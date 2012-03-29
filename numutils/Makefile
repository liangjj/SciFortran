DIREXE= $(SFDIR)/bin
include $(SFDIR)/etc/lib.mk
all: print1 deriv kdensity numstat splot func wmatsubara arange linspace fermi spline random histogram print2


print1: 
	@echo " ........... compile: optimized ........... "

print2:
	@echo " ...................... done .............................. "

random:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

kdensity:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

histogram:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${FGSL_MODS} ${SFLIBS} ${FGSL}

func:
	@echo "============================$@=============================================="
	${FC} ${STD} ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS} -L/usr/lib -lmatheval

deriv:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

wmatsubara:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

arange:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

linspace:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

fermi:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

spline:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

numstat:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}

splot:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${SFMODS} ${SFLIBS}


clean: 
	@echo "Cleaning:"
	@rm -fv $(DIREXE)/deriv $(DIREXE)/kdensity $(DIREXE)/numstat $(DIREXE)/splot $(DIREXE)/func $(DIREXE)/wmatsubara $(DIREXE)/arange $(DIREXE)/linspace $(DIREXE)/fermi $(DIREXE)/spline  $(DIREXE)/histogram
	@rm -f *.mod *.o *~
#########################################################################
