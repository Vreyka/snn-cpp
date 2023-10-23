#ifndef NEURON_H
#define NEURON_H
#include<iostream>
// #include<dendrite.h>
#include<xynap.h>
#include<omp.h>


class Neuron{

    private:  
        unsigned int electronegativity;
        unsigned int electropositivity;
        unsigned int Vth = 8;
        unsigned int stimulate_signal=0;
        unsigned int inhibit_signal=0;

    public:
        Xynap xynap[8];
        bool axon; //neuron is active or inhibited
        // unsigned int axon_terminal[4][2];
        unsigned int same_level_receptor[4];
        unsigned int deeper_level_receptor[4];
        Neuron();

        unsigned int voltage;
        bool state;
        void dendrite(unsigned int input_pulse[8]); //forwards 
        void regulatory(unsigned int regulate_signal[8]); //backwards

        void consolidate(); //return 0 or 1 to higher level
        void stimulation(); //return 3 to higher level
        void inhibition(); //return 2 to higher level



};

Neuron::Neuron(){   
    this->voltage = 0; 
    this->state = 0;
    this->axon = 0;
    this->electronegativity = 0;
    this->electropositivity = 0;
    this->stimulate_signal = 0;
    this->inhibit_signal = 0;

}

void Neuron::dendrite(unsigned int input_pulse[8]){

    for(int i=0;i<8;i++)
    {
        input_pulse[i] = input_pulse[i] * this->xynap[i].sensitive;
        this->voltage += input_pulse[i];
    }
    if(this->voltage > this->Vth){
        this->axon = 1;
    }
    else{
        this->state = 0;
    }

} 

void Neuron::regulatory(unsigned int regulate_signal[8]){

    /* 
        regulate_signal[i] = [0, 1, 2, 3]
        regulate_signal is the return signal via exitation or inhibition back from the output
        can be understood as a homeostatic regulatory signal against excessive or inactive neurons
    */
    /*
        may be confuse here:
        if the signal backward received is 01 or 00 but the axon in this neuron is 00 or 01
        what does it mean?
        it means that the in the lower layer, the neuron is activate/inactivate 
        and in this layer, the neuron is inactivate/activate
        and then there is no connection between them
        and more: the neuron is working fine and no need to be regulated
    */
    for(int i=0;i<8;i++)
    {
        if(regulate_signal[i]==2){
            this->inhibit_signal += 1;
        }
        else if(regulate_signal[i]==3){
            this->stimulate_signal += 1;
        }
    }

    if (this->inhibit_signal > this->stimulate_signal){
        this->inhibition();
    }
    else if (this->inhibit_signal < this->stimulate_signal){
        this->stimulation();
    }
    else{
        this->consolidate();
    }
    // if(regulate_signal == this->axon){ // regulate_signal = axon = 1 or 0: in binary : 01 or 00
    //     this->consolidate();
    // }
    // else{
    //     if(regulate_signal == 2){ // regulate_signal = 2: in binary : 10
    //         this->stimulation();
    //     }
    //     else if (regulate_signal == 3){ // regulate_signal = 3: in binary : 11
    //         this->inhibition();
    //     }
    // }
    
}

void Neuron::consolidate(){
    if (this->axon){
        
    }
}

#endif
