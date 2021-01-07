COMPILER=g++
COMPILERFLAGS= -std=c++11
DEPENDENCIES=
OBJECTFILES=

.PHONY: buildtest test build clean

buildtest: test.o VulkanObjectRenderer.o
	$(COMPILER) test.o -o testbinary VulkanObjectRenderer.o  $(COMPILERFLAGS)

test:
	./testbinary

test.o: test.cpp
	$(COMPILER) -o test.o -c test.cpp $(COMPILERFLAGS)

VulkanObjectRenderer.o : VulkanObjectRenderer.cpp VulkanObjectRenderer.h
	$(COMPILER) -o VulkanObjectRenderer.o VulkanObjectRenderer.cpp -c $(COMPILERFLAGS)
	
	
clean:
	rm *.o testbinary -f
