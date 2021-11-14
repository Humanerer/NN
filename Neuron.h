#include <list>

class Neuron {
    public:
        Neuron(int inSize);
        int getOut(List<int> ins);

    private:
        float bias = 0;
        int[] weights;
        
};