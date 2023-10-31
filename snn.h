#ifndef SNN_H
#define SNN_H
#include "neuronlib.h"
#include<omp.h>


class SNN{
    public:

        
        // ... can be more layers
        Neuron spine[10][1]; //classification

        Neuron * layers[6];
        bool *shadow_layers[6];

        // Neuron * layer[5] = {*this->layer0, *this->layer1, *this->layer2, *this->layer3, *this->spine};
        

        unsigned int expain_scheduler[5] = {1, 0, 3, 1, 1};
        unsigned int stride_scheduler[5] = {1, 1, 3, 2, 2};
        unsigned int col_scheduler[5] = {27, 55, 18, 9, 4};
        unsigned int row_scheduler[5] = {27, 55, 18, 9, 4};
        unsigned int last_layer = 5;

        // bool mem_forward_higher[4];
        // bool mem_forward_counterpart[4];
        // unsigned int mem_backward_lower[4];
        // unsigned int mem_backward_counterpart[4];

        bool mem_forward[13];
        unsigned int mem_backward[13];

        bool *working_mem;
        unsigned int stable_time = 3;
        

        SNN();

        SNN(
            unsigned int num_of_class, 
            unsigned int num_of_layer,
            unsigned int *expain_scheduler
        );

        void forward(bool *input, int lenth_input);
        void backward(unsigned int regulate_signal[10][4]);

        void data_in(bool *input, int lenth_input, int layer, int row, int col, int expain);
        void connect(int lenth_input, int layer, int row, int col, int expain);
        void classify();
        

};




#endif