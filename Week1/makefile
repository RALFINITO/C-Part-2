
CC=g++
COMPILE_OPTS=-c
VERBOSE=-v
COPTS=-std=c++11
INCLUDE_DIR=-I.
LIB_DIR=-L.
LIB=
RM=rm -f

%.o: %.cpp
	@echo "compile source " $<
	@$(CC) $(COPTS) $(COMPILE_OPTS) $(INCLUDE_DIR) -o $@ $<

all: main conversion

main: main.o
	@echo "linking main"
	@$(CC) $(COPTS) $(LIB_DIR) $(LIB) $< -o $@

main.o: main.cpp main.h


conversion: conversion.o
	@echo "linking conversion"
	@$(CC) $(COPTS) $(LIB_DIR) $(LIB) $< -o $@

conversion.o: conversion.cpp

clean:
	@echo "clearning objs, binaries and data files"
	@$(RM) main.o main conversion.o conversion
