CC=g++
CFLAGS=-c -std=c++11
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lfu

all: $(SOURCES) $(EXECUTABLE)
	rm -rf *.o
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean