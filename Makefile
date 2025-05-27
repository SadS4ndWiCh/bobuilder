NAME := bobuilder
DESCRIPTION := Build a beautiful house with simple commands.

CC := cc
CINCLUDES := -I./includes

SRCS = $(wildcard src/*.c)

.PHONY: house floor build

all: house floor build

house:
	$(CC) $(CINCLUDES) src/house.c -o house

floor:
	$(CC) $(CINCLUDES) src/floor.c -o floor

build:
	$(CC) $(CINCLUDES) src/build.c -o build
