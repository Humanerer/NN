#include "Neuron.h"

class Layer {
    public:
        Layer();
        ~Layer();
        Layer(int size, int prevSize);
        void setInSize(int newSize);
        int getSize();
        float* input(float* input);

    private:
        int size;
        Neuron* neurons;
};