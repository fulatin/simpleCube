
SRC = src/
all:
	g++ -I./include/ -L./lib/ $(SRC)main.cxx $(SRC)plane.cxx $(SRC)glad.c -lglfw3 -lX11 -lpthread  -ldl -lm -g -S main 
clean:
	rm ./main ./*.s