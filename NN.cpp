#include "NN.h"

NN::NN(int inSize, int outSize){
    this->inSize = inSize;
    this->outSize = outSize;
    layers = {Layer(outSize, inSize)};

}

float* NN::input(float* input){

    float output[outSize];
    return output;
}

void NN::addLayer(int layerSize, int hiddenNo){
    
}

int NN::getInSize(){
    return inSize;
}

int NN::getOutSize(){
    return outSize;
}