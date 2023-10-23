#ifndef SNN_H
#define SNN_H
#include<neuronlib.h>
#include<omp.h>

class Layer{
    public:
        Neuron *neuron_matrix;
};

class SNN{
    public:

        Neuron layer0[27][27];
        Neuron layer1[20][20];
        Neuron layer2[12][12];
        Neuron layer3[4][4];
        // ... can be more layers
        Neuron spine[10][1]; //classification

        Neuron * layer[5];

        // Neuron * layer[5] = {*this->layer0, *this->layer1, *this->layer2, *this->layer3, *this->spine};
        

        unsigned int expain_scheduler[5] = {1, 7, 8, 8, 1};
        unsigned int row_scheduler[5] = {27, 20, 12, 4, 10};
        unsigned int col_scheduler[5] = {27, 20, 12, 4, 1};

        bool mem_forward_higher[4];
        bool mem_forward_counterpart[4];
        unsigned int mem_backward_lower[4];
        unsigned int mem_backward_counterpart[4];
        

        SNN();

        SNN(
            unsigned int num_of_class, 
            unsigned int num_of_layer,
            unsigned int *expain_scheduler
        );

        void forward(bool input[28][28]);
        void backward(unsigned int regulate_signal[10][4]);

        void connect(int row, int col, int expain);

};

SNN::SNN(){
    this->layer[0] = *this->layer0;
//     this->layer->neuron_matrix = {this->layer0, this->layer1, this->layer2, this->layer3, this->spine};
}

#endif