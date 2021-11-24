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
        vector<float> getWeights();
        void setWeights(vector<float> weights);

    private:
        int inSize;
        float bias = 0;
        vector<float> weights;
        
};