ifdef CROSS_COMPILE
# checks if the cross_compile variable is defined 

override CROSS_COMPILE=
endif
# if the variable is not defined it this will define it

CFLAGS = -g -Wall
# -g enables debugging -Wall enables all warnings

# compile
writer:
	$(CROSS_COMPILE)gcc $(CFLAGS) -o writer writer.c

# after the compile is done clean/remove the bin
clean:
	rm writer
