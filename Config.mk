CONFIG_EXTRAVERSION = -jzinferno
CONFIG_CFLAGS = -Wall -fomit-frame-pointer -ffunction-sections -fdata-sections
CONFIG_LDFLAGS = -Wl,--gc-sections

CONFIG_OPTIMIZE_FOR_SIZE = n
CONFIG_BUILD_ID = n
CONFIG_STATIC = n

# functions

CONFIG_GETENFORCE = y
CONFIG_SELINUXENABLED = y
CONFIG_SETENFORCE = y
