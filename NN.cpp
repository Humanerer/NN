#include "NN.h"

NN::NN(){

    for (float weight : weights) {
        weight = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    
}

int NN::getInSize(){

}

int NN::getOutSize(){

}

Layer NN::input{

}

List<Layer> NN::hidden{

}

Layer NN::output{

}
