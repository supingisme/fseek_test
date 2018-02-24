
CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)ld
FLAG := -L${SDK_PATH}/${TARGET_SYS}/usr/lib -static

testing-ddr: fseek_test.c
	$(CC) fseek_test.c -o fseek_test $(FLAG)

