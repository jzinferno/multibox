all:
	@gcc core/*.c libs/*.c utils/*.c -Os -s -I include -o busybox
