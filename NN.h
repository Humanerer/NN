#include <list>
#include "Layer.h"
#include "Neuron.h"

using std::list;

class NN {
    public:
        NN();
        int getInSize();
        int getOutSize();

    private:
        Layer input;
        List<Layer> hidden;
        Layer output;
        
};