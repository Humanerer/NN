#include "Neuron.h"

Neuron::Neuron(int inSize){
    this->inSize = inSize;

    // Add weights
    for (int i = 0; i < inSize; i++){
        // Random float between -1.0 and 1.0
        float weight = (float) (rand() - RAND_MAX/2) * 2 / RAND_MAX;
        weights.push_back(weight);
    }

    // Random float between -1.0 and 1.0
    bias = (float) (rand() - RAND_MAX/2) * 2 / RAND_MAX;
}

void Neuron::setInSize(int inSize){
    // Reset weights
    while (!weights.empty()){
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

void Neuron::setWeights(vector<float> weights){
    if (weights.size() == this->weights.size()){
        this->weights = weights;
    }
}

vector<float> Neuron::getWeights(){
    return weights;
}

void Neuron::setBias(float bias){
    this->bias = bias;
}

float Neuron::getBias(){
    return bias;
}