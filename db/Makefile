CXX = g++
CXXFLAGS = -std=c++17 -I../sources

SOURCES_DIR = ../sources
CREATE_FILE = createDB.cpp
INSERT_FILE = insertData.cpp
INSERT2_FILE = insertData2.cpp

LIBS = -lsqlite3
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)

CREATE_OBJS = $(SOURCES) $(CREATE_FILE)
INSERT_OBJS = $(SOURCES) $(INSERT_FILE)
INSERT2_OBJS = $(SOURCES) $(INSERT2_FILE)

all: create insert insert2

create: $(CREATE_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o create.out $(LIBS)

insert: $(INSERT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o insert.out $(LIBS)

insert2: $(INSERT2_OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o insert2.out $(LIBS)

clean:
	rm -f *.out
