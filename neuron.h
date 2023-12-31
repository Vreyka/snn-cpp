#ifndef NEURON_H
#define NEURON_H
#include<iostream>
// #include<dendrite.h>
#include "synap.h"
#include<omp.h>


class Neuron{

    private:  
        unsigned int Vth = 8;
        unsigned int stimulate_signal=0;
        unsigned int inhibit_signal=0;
        Synap synap[13];  

    public:
        bool input_mem[13];
        bool axon; //neuron is active or inhibited
        
        Neuron();

        unsigned int voltage;
        unsigned int regulation;
        void dendrite(bool input_pulse[13]); //forwards 
        void regulatory(unsigned int regulate_signal[13]); //backwards

        void consolidate(); //return 0 or 1 to higher level
        void stimulation(); //return 3 to higher level
        void inhibition(); //return 2 to higher level



};

Neuron::Neuron(){   
    this->voltage = 0; 
    this->regulation = 0;
    this->axon = 0;
    // this->electronegativity = 0;
    // this->electropositivity = 0;
    this->stimulate_signal = 0;
    this->inhibit_signal = 0;
    for (int i=0; i<13; i++){
        this->input_mem[i] = 0;
    }

}



#endif
