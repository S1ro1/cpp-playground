CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJS = main.o fraction.o

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS): fraction.hpp
