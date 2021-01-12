COMPILER=g++
COMPILERFLAGS= -std=c++11  -I/usr/include/stb -I/usr/include/glm -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
DEPENDENCIES=
OBJECTFILES=

.PHONY: buildtest test build clean

buildtest: test.o vulkanObjectRenderer.o utilities.o modelData.o windowManager.o deviceManager.o windowManager.o configurationValues.o debugManager.o
	$(COMPILER) test.o -o testbinary vulkanObjectRenderer.o utilities.o windowManager.o modelData.o deviceManager.o configurationValues.o debugManager.o $(COMPILERFLAGS)

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
	
	
windowManager.o: windowManager.cpp windowManager.h
	$(COMPILER) -o windowManager.o windowManager.cpp -c $(COMPILERFLAGS)
	
deviceManager.o: deviceManager.cpp deviceManager.h
	$(COMPILER) -o deviceManager.o -c deviceManager.cpp $(COMPILERFLAGS)
	
configurationValues.o: configurationValues.cpp configurationValues.h
	$(COMPILER) -o configurationValues.o -c configurationValues.cpp $(COMPILERFLAGS)
	
debugManager.o: debugManager.cpp debugManager.h
	$(COMPILER) -o debugManager.o -c debugManager.cpp $(COMPILERFLAGS)
clean:
	rm *.o testbinary -f
