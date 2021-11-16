#include "Layer.h"

Layer::Layer(){

}

Layer::Layer(int size, int prevSize){
    this->size = size;
    for (int i = 0; i < size; i++){
        neurons.push_back(Neuron(prevSize));
    }
    printf("Layer with size %d and input of size %d made\n",size,prevSize);
}

void Layer::setInSize(int newSize){
    for (int i = 0; i < size; i++){
        neurons.at(i).setInSize(newSize);
    }
}

int Layer::getSize(){
    return size;
}

vector<float> Layer::input(vector<float> input){
    vector<float> output;

    for (int i = 0; i < size; i++){
        output.push_back(neurons.at(i).input(input));
    }

    return output;
}