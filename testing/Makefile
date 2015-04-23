# Wind River Workbench generated Makefile.
# User-specific make rules may be added in this project's "Makefile" file.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))

all : $(BUILD_SPEC)
	@echo "make: built targets of $(BSP_DIR)"

BUILD_SPEC := bootloader

BSP_DIR := $(WIND_BASE)/target/config/integrator920t
BSP := integrator920t

TOOL := gnu



-include *.makefile

target_% : $(BUILD_SPEC)
	@echo "make: built targets of $(BSP_DIR)"

clean :
	@echo "make: removing targets and objects of $(BSP_DIR)";\
	cd $(BSP_DIR);\
	$(MAKE) clean

# Make rule to build bootloader images.
# Maps all UI bootloader build targets to BSP-internal bootrom make rules,
# changes to the BSP directory, and actually builds the bootloader image.
# Valid for following user-defined build target names (bootloader styles):
#   bootloader          (Compressed)
#   bootloader_uncmp    (Uncompressed)
#   bootloader_res      (Resident)
#   bootloader_res_high (Resident At High Address)
# Valid for following extensions (bootloader formats):
#   [none]              (Default (ELF) Format)
#   .bin                (Bin Format)
#   .hex                (Hex Format)
bootloade% :
	@target=$(subst loader,rom,$@);\
	echo "building $$target image for $(BSP_DIR)";\
	cd $(BSP_DIR);\
	$(MAKE) $$target TOOL=$(TOOL)

# Make rule to build additional vxWorks images.
# Changes to the BSP directory, and actually builds the vxWorks image.
# Valid for following images:
#   vxWorks
#   vxWorks.sym
#   vxWorks.st
#   vxWorks.st_rom
#   vxWorks.res_rom
#   ... and similar
vxWork% :
	@echo "building $@ image for $(BSP_DIR)";\
	cd $(BSP_DIR);\
	$(MAKE) $@ TOOL=$(TOOL)
