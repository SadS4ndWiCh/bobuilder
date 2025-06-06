NAME := bobuilder
DESCRIPTION := Build a beautiful house with simple commands.

CC := cc
CINCLUDES := -I./includes

SRCS = $(wildcard src/*.c)

.PHONY: house floor garage build

all: house floor garage build

house:
	$(CC) $(CINCLUDES) src/house.c -o house

floor:
	$(CC) $(CINCLUDES) src/floor.c -o floor

garage:
	$(CC) $(CINCLUDES) src/garage.c -o garage

build:
	$(CC) $(CINCLUDES) src/build.c -o build
