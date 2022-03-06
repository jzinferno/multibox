CONFIG_CFLAGS := -Os -fomit-frame-pointer -ffunction-sections -fdata-sections
CONFIG_LDFLAGS := -Wl,--gc-sections

CONFIG_BUILD_ID = n
CONFIG_STATIC = n

CONFIG_GETENFORCE = y
CONFIG_SELINUXENABLED = y
CONFIG_SETENFORCE = y
