#include "Layer.h"
#include <random>
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>

using std::invalid_argument;
using std::string;
using std::vector;

class NN {
    public:
        NN(int inSize, int outSize);
        void addLayer(int layerSize, int hiddenNo);
        vector<float> input(vector<float> input);
        void backProp(vector<float> input, vector<float> desiredOut);
        void save();
        int getInSize();
        int getOutSize();
        void printLayers();

    private:
        void printVector(vector<float> vec);
        long unsigned int inSize;
        long unsigned int outSize;
        vector<Layer> layers;
        
};