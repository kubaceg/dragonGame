OUT = dragon
CXX = g++
SDL = `sdl-config --cflags --libs`
LIBS =  -lSDL_ttf -lSDL_image -std=c++11
SRC = src/*.cpp src/*.h 

all: $(OUT)
$(OUT): $(SRC)
	$(CXX) $(SRC) $(SDL) $(LIBS) -o $(OUT)

clean: 
	rm $(OUT)
