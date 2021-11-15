#include "Neuron.h"

Neuron::Neuron(){
    inSize = 1;
    weights = new float(0.0f);
}

Neuron::Neuron(int inSize){
    this->inSize = inSize;
    weights = new float[inSize];
}

Neuron::~Neuron() {
    delete[] weights;
}

void Neuron::setInSize(int inSize){
    this->inSize = inSize;
}

float Neuron::input(float* input){
    float sumW = 0.0f;

    for (int i = 0; i < inSize; i++){
        sumW += input[i] * weights[i];
    }

    float wb = sumW - bias;

    if (wb < 0) wb = 0;

    return wb;
}