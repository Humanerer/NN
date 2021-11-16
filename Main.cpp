#include "NN.h"
#include <vector>

int main(){
    NN nn = NN(9,4);
    vector<float> in = {1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f};
    nn.input(in);
    return 0;
}