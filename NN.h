#include "Layer.h"
#include <random>
#include <stdexcept>
#include <vector>

using std::invalid_argument;
using std::vector;

class NN {
    public:
        NN(int inSize, int outSize);
        void addLayer(int layerSize, int hiddenNo);
        vector<float> input(vector<float> input);
        int getInSize();
        int getOutSize();
        void printLayers();

    private:
        long unsigned int inSize;
        long unsigned int outSize;
        vector<Layer> layers;
        
};