#include "Layer.h"

Layer::Layer(){

}

Layer::~Layer(){
    delete neurons;
}

Layer::Layer(int size, int prevSize){
    this->size = size;
    neurons = new Neuron[size];
    for (int i = 0; i < size; i++) {
        neurons[i] = Neuron(prevSize);
    }
}

void Layer::setInSize(int newSize){
    for (int i = 0; i < size; i++){
        neurons[i].setInSize(newSize);
    }
}

int Layer::getSize(){
    return size;
}

float* Layer::input(float* input){
    float output[size];

    for (int i = 0; i < size; i++){
        output[i] = neurons[i].input(input);
    }

    return output;
}