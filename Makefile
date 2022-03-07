include Config.mk

VERSION = 1.0.0

CC      = $(CROSS_COMPILE)gcc
STRIP   = $(CROSS_COMPILE)strip

PROG_NAME = multibox
PROG_VERSION = $(VERSION)$(CONFIG_EXTRAVERSION)
CFLAGS := -std=gnu99 -Iinclude $(CONFIG_CFLAGS)
DFLAGS := -D_PROG_NAME_='"$(PROG_NAME)"' -D_PROG_VERSION_='"$(PROG_VERSION)"'
LDFLAGS := $(CONFIG_LDFLAGS)
OBJS := base/function_list.o base/main.o base/run_util_function.o libs/file_or_dir_exists.o libs/get_terminal_size.o libs/open_file.o

ifeq ($(CONFIG_OPTIMIZE_FOR_SIZE),y)
  CFLAGS += -Os
else
  CFLAGS += -O2
endif

ifeq ($(CONFIG_STATIC),y)
  LDFLAGS += -static
endif

ifeq ($(CONFIG_BUILD_ID),y)
  LDFLAGS += -Wl,--build-id=sha1
endif

ifeq ($(CONFIG_GETENFORCE),y)
  DFLAGS += -D_GETENFORCE_
  OBJS += utils/getenforce.o
endif

ifeq ($(CONFIG_SELINUXENABLED),y)
  DFLAGS += -D_SELINUXENABLED_
  OBJS += utils/selinuxenabled.o
endif

ifeq ($(CONFIG_SETENFORCE),y)
  DFLAGS += -D_SETENFORCE_
  OBJS += utils/setenforce.o
endif

ifeq ($(V),1)
  Q =
else
  Q = @
endif

%.o:%.c Makefile Config.mk
	$(Q) echo "  CC	$(notdir $(@))"
	$(Q) $(CC) -c $(CFLAGS) $(DFLAGS) $< -o $@

all:$(OBJS)
	$(Q) echo "  LINK	$(PROG_NAME)"
	$(Q) $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROG_NAME)_unstripped
	$(Q) cp $(PROG_NAME)_unstripped $(PROG_NAME)
	$(Q) $(STRIP) $(PROG_NAME)

clean:
	$(Q) echo "clean: $(PROG_NAME) $(PROG_NAME)_unstripped $(OBJS)"
	$(Q) rm -rf $(PROG_NAME) $(PROG_NAME)_unstripped $(OBJS)
