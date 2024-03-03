# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall


# Exec names for targets
HELLO_WORLD = HelloWorld
MONTECARLO = Ch1/MonteCarlo
#Source files
HELLO_SRCS = HelloWorld.cpp
MONTECARLO_SRCS = Ch1/MonteCarlo.cpp


# Make All
all: $(HELLO_WORLD) $(MONTECARLO)


# Specific Makes
# Make HelloWorld
$(HELLO_WORLD): $(HELLO_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(HELLO_SRCS)
# Make Montecarlo
$(MONTECARLO): $(MONTECARLO_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(MONTECARLO_SRCS)
