CXX=g++
OUT=corridor
RM=rm -f
OBJ=player.o

all: corridor

corridor: $(OBJ)
	$(CXX) src/main.cpp -o bin/$(OUT) $^

$(OBJ):
	$(CXX) -c src/$*.cpp

clean:
	$(RM) bin/$(OUT) *.o
