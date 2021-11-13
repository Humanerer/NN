#include "Layer.h"

Layer::Layer(int size){
    neurons = Neuron[size];
    for (Neuron neuron : neurons) {
        neuron = Neuron();
    }
}