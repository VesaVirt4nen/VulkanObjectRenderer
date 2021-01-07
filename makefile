COMPILER=g++
COMPILERFLAGS= -std=c++11
DEPENDENCIES=
OBJECTFILES=

.PHONY: buildtest test build

buildtest: test.o VulkanObjectRenderer.o
	$(COMPILER) test.o -o test  $(COMPILERFLAGS)

test:
	./test

test.o: test.cpp
	$(COMPILER) -o test.o -c test.cpp $(COMPILERFLAGS)

VulkanObjectRenderer.o : VulkanObjectRenderer.cpp VulkanObjectRenderer.h
	$(COMPILER) -o VulkanObjectRenderer.o VulkanObjectRenderer.cpp -c $(COMPILERFLAGS)
