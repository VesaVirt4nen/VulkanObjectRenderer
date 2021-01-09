COMPILER=g++
COMPILERFLAGS= -std=c++11  -I/usr/include/stb -I/usr/include/glm
DEPENDENCIES=
OBJECTFILES=

.PHONY: buildtest test build clean

buildtest: test.o vulkanObjectRenderer.o utilities.o modelData.o
	$(COMPILER) test.o -o testbinary vulkanObjectRenderer.o utilities.o  $(COMPILERFLAGS)

test:
	./testbinary

test.o: test.cpp
	$(COMPILER) -o test.o -c test.cpp $(COMPILERFLAGS)

vulkanObjectRenderer.o : vulkanObjectRenderer.cpp vulkanObjectRenderer.h
	$(COMPILER) -o vulkanObjectRenderer.o vulkanObjectRenderer.cpp -c $(COMPILERFLAGS)
	
utilities.o: utilities.cpp utilities.h
	$(COMPILER) -o utilities.o  utilities.cpp -c $(COMPILERFLAGS)

modelData.o: modelData.cpp modelData.h
	$(COMPILER) -o modelData.o modelData.cpp -c $(COMPILERFLAGS)
clean:
	rm *.o testbinary -f
