# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMLINUXdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := /home/kartha/programs/VxWorks/TimerDrivers
WS_ROOT_DIR := /home/kartha/programs/VxWorks



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simlinux
CPU = SIMLINUX
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks66
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = TimerDrivers/$(MODE_DIR)/TimerDrivers.out \
	 TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage.o


#Rules

# TimerDrivers
ifeq ($(DEBUG_MODE),1)
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TimerDrivers/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TimerDrivers/$(MODE_DIR)/% : IDE_LIBRARIES = 
TimerDrivers/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TimerDrivers/$(MODE_DIR)/% : DEFINES = 
TimerDrivers/$(MODE_DIR)/% : EXPAND_DBG = 0
TimerDrivers/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
TimerDrivers/$(MODE_DIR)/% : CPU = SIMLINUX
TimerDrivers/$(MODE_DIR)/% : TOOL_FAMILY = diab
TimerDrivers/$(MODE_DIR)/% : TOOL = diab
TimerDrivers/$(MODE_DIR)/% : TOOL_PATH = 
TimerDrivers/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TimerDrivers/$(MODE_DIR)/% : LIBPATH = 
TimerDrivers/$(MODE_DIR)/% : LIBS = 
TimerDrivers/$(MODE_DIR)/% : OBJ_DIR := TimerDrivers/$(MODE_DIR)

OBJECTS_TimerDrivers = TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage.o

TimerDrivers/$(MODE_DIR)/TimerDrivers.out : $(OBJECTS_TimerDrivers)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_TimerDrivers) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_TimerDrivers) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TimerDrivers/$(MODE_DIR)/TimerDrivers_compile_file : $(FILE) ;

_clean :: TimerDrivers/$(MODE_DIR)/TimerDrivers_clean

TimerDrivers/$(MODE_DIR)/TimerDrivers_clean : 
	$(TRACE_FLAG)if [ -d "TimerDrivers" ]; then cd "TimerDrivers"; rm -rf $(MODE_DIR); fi


# TimerDrivers_partialImage
ifeq ($(DEBUG_MODE),1)
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TimerDrivers_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TimerDrivers_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
TimerDrivers_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TimerDrivers_partialImage/$(MODE_DIR)/% : DEFINES = 
TimerDrivers_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
TimerDrivers_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
TimerDrivers_partialImage/$(MODE_DIR)/% : CPU = SIMLINUX
TimerDrivers_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
TimerDrivers_partialImage/$(MODE_DIR)/% : TOOL = diab
TimerDrivers_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
TimerDrivers_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TimerDrivers_partialImage/$(MODE_DIR)/% : LIBPATH = 
TimerDrivers_partialImage/$(MODE_DIR)/% : LIBS = 
TimerDrivers_partialImage/$(MODE_DIR)/% : OBJ_DIR := TimerDrivers_partialImage/$(MODE_DIR)

TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/testtimer.o : /home/kartha/programs/VxWorks/TimerDrivers/testtimer.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer1.o : /home/kartha/programs/VxWorks/TimerDrivers/timer1.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer2.o : /home/kartha/programs/VxWorks/TimerDrivers/timer2.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_TimerDrivers_partialImage = TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/testtimer.o \
	 TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer1.o \
	 TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer2.o

TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage.o : $(OBJECTS_TimerDrivers_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_TimerDrivers_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage_compile_file : $(FILE) ;

_clean :: TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage_clean

TimerDrivers_partialImage/$(MODE_DIR)/TimerDrivers_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "TimerDrivers_partialImage" ]; then cd "TimerDrivers_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/testtimer.d TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer1.d TimerDrivers_partialImage/$(MODE_DIR)/Objects/TimerDrivers/timer2.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
