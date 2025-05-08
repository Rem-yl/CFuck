CXX = g++
CXXFLAGS = -std=c++11 
INCLUDES = -I ./include
TARGET = main
SRCS = main.cpp ./src/*

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)