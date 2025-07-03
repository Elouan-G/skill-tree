CXX = g++
CXXFLAGS = -std=c++17 -I../sources

SOURCES_DIR = ../sources
CREATE_FILE = createDB.cpp
INSERT_FILE = insertData.cpp

LIBS = -lsqlite3
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)

CREATE_OBJS = $(SOURCES) $(CREATE_FILE)
INSERT_OBJS = $(SOURCES) $(INSERT_FILE)

all: create insert

create: $(CREATE_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o create.out $(LIBS)

insert: $(INSERT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o insert.out $(LIBS)

clean:
	rm -f *.out
