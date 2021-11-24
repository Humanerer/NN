#include "Neuron.h"

Neuron::Neuron(int inSize){
    this->inSize = inSize;

    // Add weights
    for (int i = 0; i < inSize; i++){
        float weight = (float) rand()/RAND_MAX;
        weights.push_back(weight);
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
        float weight = (float) rand()/RAND_MAX;
        weights.push_back(weight);
    }
}

float Neuron::input(vector<float> input){
    float sumW = 0.0f;

    // Sum inputs multiplied by weights
    for (int i = 0; i < inSize; i++){
        sumW += input.at(i) * weights.at(i);
    }

    float wb = sumW + bias;

    // Sigmoid
    // float ex = exp(wb);
    // float sigmoid = ex / (ex + 1.0f);

    // RELU
    if (wb < 0) wb = 0;

    return wb;
}

vector<float> Neuron::getWeights(){
    return weights;
}

void Neuron::setWeights(vector<float> weights){
    this->weights = weights;
}