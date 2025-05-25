NAME := bobuilder
DESCRIPTION := Build a beautiful house with simple commands.

CC := cc
CINCLUDES := -I./includes

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CINCLUDES) $< -o $(basename $@)

build: $(OBJS)

