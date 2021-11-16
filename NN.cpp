#include "NN.h"

NN::NN(int inSize, int outSize){
    this->inSize = inSize;
    this->outSize = outSize;
    layers.push_back(Layer(outSize, inSize));

}

vector<float> NN::input(vector<float> input){
    if (input.size() != inSize){
        throw invalid_argument("Incorrect size for input, expected "+inSize);
    }

    vector<float> output = input;

    for (Layer layer : layers){
        output = layer.input(output);
    }

    int i = 0;
    for (float f : output){
        printf("%d : %f\n",i,f);
        i++;
    }

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