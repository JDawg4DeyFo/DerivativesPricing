#Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Exec names for targets
HELLO_WORLD = HelloWorld
MONTECARLO = Ch1/MonteCarlo

#Source files
HELLO_SRCS = HelloWorld.cpp
MONTECARLO_SRCS = MonteCarlo.cpp

#Make All
all: $(HELLO_WORLD) $(MONTECARLO)

# Make HelloWorld
$(HELLO_WORLD): $(HELLO_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(HELLO_SRCS)

$(MONTECARLO): $(MONTECARLO_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(MONTECARLO_SRCS)
