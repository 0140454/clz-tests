CC			= gcc
CFLAGS		= -O0 -fopenmp -lgomp -I.
SRCS_COMMON = main.c

SRCS        = $(wildcard clz/*.c)
EXECUTABLE	= $(addprefix clz_, $(basename $(notdir $(SRCS))))

MODE		?= PERFORMANCE

all: $(EXECUTABLE)

clz_%: $(SRCS_COMMON) clz/%.c
	$(CC) $(CFLAGS) $^ -D$(MODE) -DOUTPUT_NAME='"$@"' -o $@

test: $(EXECUTABLE)
	time ./clz_binary_search
	time ./clz_byte_shift
	time ./clz_Harley
	time ./clz_iterative
	time ./clz_recursive

clean:
	rm -rf $(EXECUTABLE) *.txt runtime.png
