NN: Main.cpp NN.o Layer.o Neuron.o
	g++ -Wall -pedantic -pthread -std=c++17 -g -O -o $@ $^

NN.o: NN.cpp NN.h
	g++ -Wall -c -pedantic -pthread -std=c++11 -g -O NN.cpp -o NN.o

Layer.o: Layer.cpp Layer.h
	g++ -Wall -c -pedantic -pthread -std=c++11 -g -O Layer.cpp -o Layer.o

Neuron.o: Neuron.cpp Neuron.h
	g++ -Wall -c -pedantic -pthread -std=c++11 -g -O Neuron.cpp -o Neuron.o

clean:
	rm NN
	rm *.o