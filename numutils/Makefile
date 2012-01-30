FC    = mpif90
DIREXE= $(HOME)/lib/bin
include $(HOME)/lib/lib.mk
all: print1 deriv histogram kdensity numstat splot func wmatsubara arange linspace fermi spline print2


print1: 
	@echo " ........... compile: optimized ........... "

print2:
	@echo " ...................... done .............................. "

kdensity:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

histogram:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

func:
	@echo "============================$@=============================================="
	${FC} ${STD} ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS} -L/usr/lib -lmatheval

deriv:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

wmatsubara:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

arange:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

linspace:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

fermi:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

spline:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

numstat:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${MODS} ${LIBS}

splot:
	@echo "============================$@=============================================="
	${FC} ${STD} -static ${OBJS} $@.f90 -o $(DIREXE)/$@  ${DSL_MODS} ${MODS} ${DSL_LIBS} ${LIBS}


clean: 
	@echo "Cleaning:"
	@rm -f *.mod
	@rm -f *.o
	@rm -f *~
#########################################################################
