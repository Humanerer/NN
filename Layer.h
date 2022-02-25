#include "Neuron.h"
#include <vector>
#include <stdio.h>

using std::vector;

class Layer {
    public:
        Layer();
        Layer(int size, int prevSize);
        void setInSize(int newSize);
        int getSize();
        int getPrevSize();
        vector<float> input(vector<float> input);
        vector<Neuron>* getNeurons();

    private:
        int size;
        int prevSize;
        vector<Neuron> neurons;
};