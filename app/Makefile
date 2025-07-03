CXX = g++
CXXFLAGS = -std=c++17 -I../sources

SOURCES_DIR = ../sources
APP_FILE = main.cpp

LIBS = -lsqlite3
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)

APP_OBJS = $(SOURCES) $(APP_FILE)

all: app

app: $(APP_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o skill-tree.out $(LIBS)

clean:
	rm -f *.out
