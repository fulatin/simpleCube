
SRC = src/
all:
	g++ -I./include/ -L./lib/ $(SRC)main.cxx $(SRC)cube.cxx $(SRC)block.cxx $(SRC)plane.cxx $(SRC)glad.c -lglfw3 -lX11 -lpthread  -ldl -lm -o main 
clean:
	rm ./main ./*.s