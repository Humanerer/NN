#include <vector>

using std::vector;

class Neuron {
    public:
        Neuron(int inSize);
        void setInSize(int inSize);
        float input(vector<float> input);

    private:
        int inSize;
        float bias = 0;
        vector<float> weights;
        
};