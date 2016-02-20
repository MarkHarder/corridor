CXX=g++
OUT=corridor
RM=rm -f

all: corridor

corridor:
	$(CXX) src/main.cpp -o bin/$(OUT)

clean:
	$(RM) bin/$(OUT)
