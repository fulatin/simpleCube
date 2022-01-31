
SRC = src/
all:
	g++ -I./include/ -L./lib/ $(SRC)main.cxx $(SRC)plane.c $(SRC)utils.c $(SRC)glad.c -lglfw3 -lX11 -lpthread  -ldl -lm -g -o main 
clean:
	rm ./main