COMPILER=g++
COMPILERFLAGS= -std=c++11 -I
DEPENDENCIES=
OBJECTFILES=

.PHONY: buildtest test build

buildtest: test.o VulkanObjectRenderer.o
	$(COMPILER) -o test $(COMPILERFLAGS)

test:




VulkanObjectRenderer.o : VulkanObjectRenderer.cpp VulkanObjectRenderer.h
	$(COMPILER) -o VulkanObjectRenderer.o -c $(COMPILERFLAGS)
