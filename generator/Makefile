CXX = g++
CXXFLAGS = -std=c++17 -I../sources

SOURCES_DIR = ../sources
GENERATOR_FILE = generator.cpp

LIBS = -lsqlite3
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)

GENERATOR_OBJS = $(SOURCES) $(GENERATOR_FILE)

all: GENERATOR

GENERATOR: $(GENERATOR_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o generator.out $(LIBS)

clean:
	rm -f *.out
