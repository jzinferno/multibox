include Config.mk

VERSION = 1.0.1
EXTRAVERSION = -jzinferno

CC = gcc
CFLAGS := -std=gnu99 -Iinclude $(CONFIG_CFLAGS)
LDFLAGS := $(CONFIG_LDFLAGS)
DEFINE_FLAGS := -D_VERSION='"$(VERSION)$(EXTRAVERSION)"'
OBJ_FILES :=

ifeq ($(V),1)
  Q =
else
  Q = @
endif

ifeq ($(CONFIG_STATIC),y)
LDFLAGS += -static
endif

ifeq ($(CONFIG_BUILD_ID),y)
LDFLAGS += -Wl,--build-id=sha1
endif

ifeq ($(CONFIG_GETENFORCE),y)
DEFINE_FLAGS += -D_GETENFORCE
endif

ifeq ($(CONFIG_SELINUXENABLED),y)
DEFINE_FLAGS += -D_SELINUXENABLED
endif

ifeq ($(CONFIG_SETENFORCE),y)
DEFINE_FLAGS += -D_SETENFORCE
endif

define cc_file
	$(Q) echo "  CC	$(notdir $(1))"
	$(Q) $(CC) -c $(CFLAGS) $(DEFINE_FLAGS) $(subst .o,.c,$(1)) -o $(1)
	$(eval OBJ_FILES += $(1))
endef


all:
	$(call cc_file, base/function_list.o)
	$(call cc_file, base/main.o)
	$(call cc_file, base/multibox.o)
	$(call cc_file, libs/file_or_dir_exists.o)
	$(call cc_file, libs/get_terminal_size.o)
	$(call cc_file, libs/open_file.o)

ifeq ($(CONFIG_GETENFORCE),y)
	$(call cc_file, utils/getenforce.o)
endif

ifeq ($(CONFIG_SELINUXENABLED),y)
	$(call cc_file, utils/selinuxenabled.o)
endif

ifeq ($(CONFIG_SETENFORCE),y)
	$(call cc_file, utils/setenforce.o)
endif

	$(Q) echo "  LINK	multibox"
	$(Q) $(CC) -s $(LDFLAGS) $(OBJ_FILES) -o multibox

clean:
	$(Q) echo "clean: multibox */*.o"
	$(Q) rm -rf multibox */*.o
