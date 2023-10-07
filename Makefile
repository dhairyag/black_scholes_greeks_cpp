# Makefile

# compiler
CXX = g++

CXXFLAGS = -Wall -std=c++11

# the source files
SOURCES = main.cpp black_scholes.cpp greeks.cpp utils.cpp

# executable name
TARGET = exe_out

all: $(TARGET)

# Linking 
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

