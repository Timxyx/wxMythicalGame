# Compiler and linker
CXX = g++
LD = g++

# wxWidgets configuration
WX_CONFIG = wx-config

# Compiler and linker flags
CXXFLAGS = `$(WX_CONFIG) --cxxflags` -Wall -O2
LDFLAGS = `$(WX_CONFIG) --libs`

# Source and object files
SRCS = mainframe.cpp app.cpp unit.cpp weapon.cpp
OBJS = $(SRCS:.cpp=.o)

# Test source and object files
TEST_SRCS = tests.cpp catch_amalgamated.cpp someclass.cpp unit.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_EXEC = run_tests

# Target executable
TARGET = myapp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS)
	$(LD) -o $@ $(TEST_OBJS)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_EXEC)

.PHONY: all clean test
