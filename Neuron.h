class Neuron {
    public:
        Neuron();
        Neuron(int inSize);
        ~Neuron();
        void setInSize(int inSize);
        float input(float* input);

    private:
        int inSize;
        float bias = 0;
        float* weights;
        
};