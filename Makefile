NN: Main.cpp NN.cpp NN.h Layer.cpp Layer.h Neuron.cpp Neuron.h
	g++ -Wall -pedantic -pthread -std=c++17 -g -O -o $@ $^

clean:
	rm NN