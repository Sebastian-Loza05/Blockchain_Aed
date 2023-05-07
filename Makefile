CXX = g++
CXXFLAGS = `wx-config --cxxflags`
LIBS = `wx-config --libs`

main: main.cpp
		$(C>>) $(C>>FLAGS) -o main main.cpp $(LIBS)

