CXX = g++

INCLUDE_DIRS := $(shell find ../sources -type d)
CXXFLAGS = -std=c++17 $(addprefix -I, $(INCLUDE_DIRS))

SOURCES_DIR = ../sources
CREATE_FILE = createDB.cpp
INSERT_FILE = insertData.cpp
INSERT2_FILE = insertData2.cpp

LIBS = -lsqlite3
SOURCES = $(shell find $(SOURCES_DIR) -name "*.cpp")

CREATE_OBJS = $(SOURCES) $(CREATE_FILE)
INSERT_OBJS = $(SOURCES) $(INSERT_FILE)
INSERT2_OBJS = $(SOURCES) $(INSERT2_FILE)

all: CREATE INSERT INSERT2

CREATE: $(CREATE_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o create.out $(LIBS)

INSERT: $(INSERT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o insert.out $(LIBS)

INSERT2: $(INSERT2_OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o insert2.out $(LIBS)

clean:
	rm -f *.out
