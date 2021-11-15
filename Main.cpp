#include "NN.h"

int main(){
    NN nn = NN(9,1);
    float in[9] = {1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f};
    nn.input(in);
    return 0;
}