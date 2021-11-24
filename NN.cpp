#include "NN.h"

NN::NN(int inSize, int outSize){
    srand(time(NULL));
    this->inSize = inSize;
    this->outSize = outSize;
    layers.push_back(Layer(outSize, inSize));

}

vector<float> NN::input(vector<float> input){
    // Throw error if the size of the input is too small or roo large
    if (input.size() != inSize){
        throw invalid_argument("Incorrect size for input, expected "+inSize);
    }

    vector<float> output = input;

    // Input the output of the previous layer to the next
    for (Layer layer : layers){
        output = layer.input(output);
    }

    // Return the output of the output layer
    return output;
}

void NN::addLayer(int layerSize, int hiddenIndex){
    // Make a new layer with the given layerSize and make its input size the same as the previous layer
    Layer newLayer = Layer(layerSize, layers.at(hiddenIndex).getPrevSize());

    // Add the new layer to layers at the given hiddenIndex
    layers.insert(layers.begin()+hiddenIndex, newLayer);

    // Change the input size of the next layer to match the size of the new layer
    layers.at(hiddenIndex+1).setInSize(layerSize);
}

void NN::backProp(vector<float> in, vector<float> desiredOut){
    if (in.size() != inSize){
        throw invalid_argument("Incorrect size for input, expected "+inSize);
    } else if (desiredOut.size() != outSize){
        throw invalid_argument("Incorrect size for output, expected "+outSize);
    }

    vector<float> output = input(in);

    vector<float> difference;

    // A measure of how wrong the output is
    float MSE = 0;

    for (unsigned int i = 0; i < outSize; i++){
        float diff = output.at(i) - desiredOut.at(i);
        MSE += diff*diff/outSize;
        difference.push_back(diff);
    }

    printVector(output);
    printVector(desiredOut);
    printVector(difference);
    
    for (unsigned int i = 0; i < outSize; i++){
        
    }
}

void NN::save(){
    string meta = "";
    // TODO: implement
}

int NN::getInSize(){
    return inSize;
}

int NN::getOutSize(){
    return outSize;
}

void NN::printLayers(){
    int i = 0;
    for (Layer l : layers){
        printf("%d : %d,%d\n",i,l.getPrevSize(),l.getSize());
        i++;
    }
}

void NN::printVector(vector<float> vec){
    bool first = true;
    for (float f : vec){
        if (!first){
            printf(" %f", f);

        } else {
            printf("[ %f", f);
            first = false;
        }
    }
    printf(" ]\n");
}