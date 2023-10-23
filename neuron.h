#ifndef NEURON_H
#define NEURON_H
#include<iostream>
// #include<dendrite.h>
#include<synap.h>
#include<omp.h>


class Neuron{

    private:  
        // unsigned int electronegativity;
        // unsigned int electropositivity;
        unsigned int Vth = 8;
        unsigned int stimulate_signal=0;
        unsigned int inhibit_signal=0;
        Synap synap[8];  

    public:
        bool input_mem[8];
        bool axon; //neuron is active or inhibited
        // unsigned int axon_terminal[4][2];
        // unsigned int same_level_receptor[4];
        // unsigned int deeper_level_receptor[4];
        Neuron();

        unsigned int voltage;
        unsigned int regulation;
        void dendrite(bool input_pulse[8]); //forwards 
        void regulatory(unsigned int regulate_signal[8]); //backwards

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

}



#endif
