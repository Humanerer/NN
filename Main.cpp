#include "NN.h"
#include <vector>

int main(){
    NN nn = NN(9,4);

    /* input for testing
    example input with the given display:

    # - -
    # - -
    # - -

    */
    vector<float> in = {1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f};
    vector<float> desout = {1.0f,0.0f,0.0f,0.0f};

    // Used to test NN::addLayers()
    // nn.printLayers();
    nn.addLayer(7,0);
    // nn.printLayers();
    nn.addLayer(3,1);
    // nn.printLayers();
    // nn.addLayer(6,0);
    // nn.printLayers();

    nn.printLayers();

    // Test output of NN
    // vector<float> out = nn.input(in);
    // for (float f : out){
    //     printf("%f\n",f);
    // }

    nn.backProp(in, desout);

    return 0;
}