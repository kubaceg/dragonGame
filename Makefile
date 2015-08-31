OUT = dragon
CXX = g++
SDL = `sdl-config --cflags --libs`
LIBS =  -lSDL_ttf -lSDL_image -lSDL_gfx -std=c++11 -Wno-write-strings 
SRC = $(shell find src -name '*.cpp' -o -name '*.h')

all: $(OUT)
$(OUT): $(SRC)
	$(CXX) $(SRC) $(SDL) $(LIBS) -o $(OUT) -g

clean: 
	rm $(OUT) 