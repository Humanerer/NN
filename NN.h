#include <list>
#include "Layer.h"
#include <random>
#include <stdexcept>

using std::list;
using std::invalid_argument;

class NN {
    public:
        NN(int inSize, int outSize);
        void addLayer(int layerSize, int hiddenNo);
        float* input(float* input);
        int getInSize();
        int getOutSize();

    private:
        int inSize;
        static int outSize;
        list<Layer> layers;
        
};