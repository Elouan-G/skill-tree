CXX = g++

INCLUDE_DIRS := $(shell find ../sources -type d)
CXXFLAGS = -std=c++17 $(addprefix -I, $(INCLUDE_DIRS))

SOURCES_DIR = ../sources
GENERATOR_FILE = cli.cpp

LIBS = -lsqlite3
SOURCES = $(shell find $(SOURCES_DIR) -name "*.cpp")

GENERATOR_OBJS = $(SOURCES) $(GENERATOR_FILE)

all: CLI

CLI: $(GENERATOR_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o cli.out $(LIBS)

clean:
	rm -f *.out