CXX = g++

INCLUDE_DIR = /opt/homebrew/Cellar/sfml/2.6.1/include
LIB_DIR = /opt/homebrew/Cellar/sfml/2.6.1/lib

CXXFLAGS = -std=c++11 -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system

TARGET = saveKitty

SRCS = main.cpp game.cpp kisu.cpp map.cpp players.cpp movement.cpp whyinamedthemballs.cpp gamemecanics.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
