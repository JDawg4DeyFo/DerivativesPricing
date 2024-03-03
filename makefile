#Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Exec names for targets
HELLO_WORLD = HelloWorld\

#Source files
HELLO_SRCS = HelloWorld.cpp

#Make All
all: $(HELLO_WORLD)

# Make HelloWorld
$(HELLO_WORLD): $(HELLO_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(HELLO_SRCS)
