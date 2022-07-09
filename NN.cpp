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

    // Limit final output
    int floatIndex = 0;
    for (float value : output){
        if (value > 1.0f){
            output.at(floatIndex) = 1.0f;
        }
        floatIndex++;
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
    // Validation for input and output size
    if (in.size() != inSize){
        throw invalid_argument("Incorrect size for input, expected "+inSize);
    } else if (desiredOut.size() != outSize){
        throw invalid_argument("Incorrect size for output, expected "+outSize);
    }

    // Error functions from https://brilliant.org/wiki/backpropagation/#:~:text=%E2%88%82ajk%E2%80%8B,1%20%CE%B4%20l%20k%20%2B%201%20.
    vector<vector<float>> outputs;
    vector<vector<float>> errors;

    vector<float> output = in;

    for (Layer &layer : layers){
        output = layer.input(output);
        outputs.push_back(output);
    }

    vector<float> limitedOut = outputs.at(outputs.size()-1);

    // Limit final output
    int floatIndex = 0;
    for (float value : limitedOut){
        if (value > 1.0f){
            limitedOut.at(floatIndex) = 1.0f;
        }
        floatIndex++;
    }

    vector<float> outErrors;

    // Calculate error for outputs
    for (unsigned int i = 0; i < outSize; i++){
        float diff = limitedOut.at(i) - desiredOut.at(i);
        float error = diff*diff/2;
        outErrors.push_back(error);
    }
    errors.push_back(outErrors);

    // For each layer from the last
    for (int layerNo = layers.size()-2; layerNo >= 0; layerNo--){
        Layer layer = layers.at(layerNo);
        vector<float> layerErrors;

        int neuronNo = 0;
        for (Neuron neuron : *layer.getNeurons()){
            float error;

            float wErrorSum = 0;
            Layer nextLayer = layers.at(layerNo+1);
            int nextNeuronNo = 0;
            // For each neuron in the next layer
            for (Neuron neuron : *nextLayer.getNeurons()){
                wErrorSum += neuron.getWeights().at(neuronNo) * errors.at(0).at(nextNeuronNo);
                nextNeuronNo++;
            }
            float nOut = outputs.at(layerNo).at(neuronNo);
            error = wErrorSum * nOut * (1 - nOut);
            // printf("%f %f\n",error,nOut);
            // layerErrors.push_back(error);
            layerErrors.push_back(error);
            neuronNo++;
        }

        errors.insert(errors.begin(),layerErrors);
    }

    for (vector<float> vec : outputs){
        printVector(vec);
    }
    printf("\n");
    for (vector<float> vec : errors){
        printVector(vec);
    }

    // printVector(outErrors);
    

    // printVector(output);
    // printVector(desiredOut);
    // printVector(difference);
    
    
    // vector<Neuron> *outputNeurons = layers.at(layers.size()-1).getNeurons();
    // for (Neuron n : *outputNeurons){
    //     printVector(n.getWeights());
    // }


    // printf("\n");


    // for (long unsigned int neuronIndex = 0; neuronIndex < outputNeurons->size(); neuronIndex++){
    //     vector<float> newWeights;
    //     for (float f : outputNeurons->at(neuronIndex).getWeights()){
    //         printf("origin: %f , diff: %f, res: %f\n",f,difference.at(neuronIndex),difference.at(neuronIndex)/10-f);
    //         float newWeight = difference.at(neuronIndex)/10-f; //TODO: change
    //         newWeights.push_back(newWeight);
    //     }
    //     printVector(newWeights);
    //     // layers.at(layers.size()-1).getNeurons()->at(neuronIndex).setWeights(newWeights);
    //     outputNeurons->at(neuronIndex).setWeights(newWeights);
        
    //     printVector(outputNeurons->at(neuronIndex).getWeights());
    // }

    // printf("\n");

    // // outputNeurons = layers.at(layers.size()-1).getNeurons();
    // for (Neuron n : *outputNeurons){
    //     printVector(n.getWeights());
    // }


    
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