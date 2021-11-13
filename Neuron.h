class Neuron {
    public:
        Neuron(int inSize);
        int getOut(List<int> ins);

    private:
        float weight = 0;
        int[] biases;
        
};