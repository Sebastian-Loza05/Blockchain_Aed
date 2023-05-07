CXX = g++
CXXFLAGS = `wx-config --cxxflags`
LIBS = `wx-config --libs`

main: main.cpp
		$(CXX) $(CXXFLAGS) -o main main.cpp $(LIBS)

