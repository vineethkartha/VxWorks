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
PRJ_ROOT_DIR := /home/kartha/programs/VxWorks/DeviceDrivers
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
PROJECT_TARGETS = DeviceDrivers/$(MODE_DIR)/DeviceDrivers.out \
	 DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage.o


#Rules

# DeviceDrivers
ifeq ($(DEBUG_MODE),1)
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DeviceDrivers/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
DeviceDrivers/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DeviceDrivers/$(MODE_DIR)/% : IDE_LIBRARIES = 
DeviceDrivers/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DeviceDrivers/$(MODE_DIR)/% : DEFINES = 
DeviceDrivers/$(MODE_DIR)/% : EXPAND_DBG = 0
DeviceDrivers/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
DeviceDrivers/$(MODE_DIR)/% : CPU = SIMLINUX
DeviceDrivers/$(MODE_DIR)/% : TOOL_FAMILY = diab
DeviceDrivers/$(MODE_DIR)/% : TOOL = diab
DeviceDrivers/$(MODE_DIR)/% : TOOL_PATH = 
DeviceDrivers/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
DeviceDrivers/$(MODE_DIR)/% : LIBPATH = 
DeviceDrivers/$(MODE_DIR)/% : LIBS = 
DeviceDrivers/$(MODE_DIR)/% : OBJ_DIR := DeviceDrivers/$(MODE_DIR)

OBJECTS_DeviceDrivers = DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage.o

DeviceDrivers/$(MODE_DIR)/DeviceDrivers.out : $(OBJECTS_DeviceDrivers)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_DeviceDrivers) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_DeviceDrivers) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DeviceDrivers/$(MODE_DIR)/DeviceDrivers_compile_file : $(FILE) ;

_clean :: DeviceDrivers/$(MODE_DIR)/DeviceDrivers_clean

DeviceDrivers/$(MODE_DIR)/DeviceDrivers_clean : 
	$(TRACE_FLAG)if [ -d "DeviceDrivers" ]; then cd "DeviceDrivers"; rm -rf $(MODE_DIR); fi


# DeviceDrivers_partialImage
ifeq ($(DEBUG_MODE),1)
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
DeviceDrivers_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DeviceDrivers_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DeviceDrivers_partialImage/$(MODE_DIR)/% : DEFINES = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
DeviceDrivers_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
DeviceDrivers_partialImage/$(MODE_DIR)/% : CPU = SIMLINUX
DeviceDrivers_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
DeviceDrivers_partialImage/$(MODE_DIR)/% : TOOL = diab
DeviceDrivers_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
DeviceDrivers_partialImage/$(MODE_DIR)/% : LIBPATH = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : LIBS = 
DeviceDrivers_partialImage/$(MODE_DIR)/% : OBJ_DIR := DeviceDrivers_partialImage/$(MODE_DIR)

DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/blkDrv.o : /home/kartha/programs/VxWorks/DeviceDrivers/blkDrv.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/characterDrv.o : /home/kartha/programs/VxWorks/DeviceDrivers/characterDrv.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/lcdDrv.o : /home/kartha/programs/VxWorks/DeviceDrivers/lcdDrv.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog1.o : /home/kartha/programs/VxWorks/DeviceDrivers/prog1.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog3.o : /home/kartha/programs/VxWorks/DeviceDrivers/prog3.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_DeviceDrivers_partialImage = DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/blkDrv.o \
	 DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/characterDrv.o \
	 DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/lcdDrv.o \
	 DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog1.o \
	 DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog3.o

DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage.o : $(OBJECTS_DeviceDrivers_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_DeviceDrivers_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage_compile_file : $(FILE) ;

_clean :: DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage_clean

DeviceDrivers_partialImage/$(MODE_DIR)/DeviceDrivers_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "DeviceDrivers_partialImage" ]; then cd "DeviceDrivers_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/blkDrv.d DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/characterDrv.d DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/lcdDrv.d \
	 DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog1.d DeviceDrivers_partialImage/$(MODE_DIR)/Objects/DeviceDrivers/prog3.d
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
