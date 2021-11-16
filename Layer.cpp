#include "Layer.h"

Layer::Layer(){

}

Layer::Layer(int size, int prevSize){
    this->size = size;
    this->prevSize = prevSize;

    // Add neurons with input of size prevSize to the layer
    for (int i = 0; i < size; i++){
        neurons.push_back(Neuron(prevSize));
    }
}

void Layer::setInSize(int newSize){
    prevSize = newSize;

    // Change input size for all Neurons in this Layer
    for (int i = 0; i < size; i++){
        neurons.at(i).setInSize(newSize);
    }
}

int Layer::getSize(){
    return size;
}

int Layer::getPrevSize(){
    return prevSize;
}

vector<float> Layer::input(vector<float> input){
    vector<float> output;

    // Get all outputs for each Neuron in this Layer
    for (int i = 0; i < size; i++){
        output.push_back(neurons.at(i).input(input));
    }

    return output;
}