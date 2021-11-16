#include "Neuron.h"

Neuron::Neuron(int inSize){
    this->inSize = inSize;

    // Add weights
    for (int i = 0; i < inSize; i++){
        weights.push_back(0.01f);
    }
}

void Neuron::setInSize(int inSize){
    // Reset weights
    for (int i = 0; i < inSize; i++){
        weights.pop_back();
    }

    this->inSize = inSize;

    // Add weights
    for (int i = 0; i < inSize; i++){
        weights.push_back(0.01f);
    }
}

float Neuron::input(vector<float> input){
    float sumW = 0.0f;

    // Sum inputs multiplied by weights
    for (int i = 0; i < inSize; i++){
        sumW += input.at(i) * weights.at(i);
    }

    float wb = sumW - bias;

    // RELU
    if (wb < 0) wb = 0;

    return wb;
}