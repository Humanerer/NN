#include <vector>
#include <cmath>
#include <random>

using std::exp;
using std::vector;
using std::uniform_real_distribution;
using std::default_random_engine;

class Neuron {
    public:
        Neuron(int inSize);
        void setInSize(int inSize);
        float input(vector<float> input);
        void setWeights(vector<float> weights);
        vector<float> getWeights();
        void setBias(float bias);
        float getBias();

    private:
        int inSize;
        float bias;
        vector<float> weights;
        
};