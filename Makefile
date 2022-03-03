all:build

build:
	@ ./scripts/build.sh

defconfig:
	@ ./scripts/config.sh

clean:
	@ ./scripts/clean.sh
