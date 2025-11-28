CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = sistema_manutencao

all: $(TARGET)

$(TARGET): $(SRC) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
