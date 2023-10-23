#include<neuron.h>

void Neuron::dendrite(bool input_pulse[8]){
    this->voltage = 0;

    for(int i=0;i<8;i++){
        this->input_mem[i] = input_pulse[i];
        this->input_mem[i] = this->input_mem[i] * this->synap[i].sensitive;
        this->voltage += input_pulse[i];
    }
    if(this->voltage > this->Vth){
        this->axon = 1;
    }
    else{
        this->regulation = 0;
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
        and then there have no connection between them yet
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

    if ((this->inhibit_signal > this->stimulate_signal) and (this->axon)){
        this->inhibition();
    }
    else if ((this->inhibit_signal < this->stimulate_signal) and (this->axon==0)){
        this->stimulation();
    }
    else{
        this->stimulate_signal = 0;
        this->inhibit_signal = 0;
        this->consolidate();
    }
    
}

void Neuron::consolidate(){
    if (this->axon){
        this->regulation = 1;
        for(int i=0;i<8;i++){
            if((this->input_mem[i]) and (this->synap[i].sensitive)<15){
                this->synap[i].sensitive += 1;
            }
            else if((this->input_mem[i]==0) and (this->synap[i].sensitive)>0){
                this->synap[i].sensitive -= 1;
            }
        }
        
    }
    else if (this->axon==0){
        this->regulation = 0;
        for(int i=0;i<8;i++){
            if (this->synap[i].sensitive>0){
                this->synap[i].sensitive -= 1;
            }
        }
    }
}

void Neuron::stimulation(){
    // occur when the neuron is inactivated and received a stimulation signal from lower layer
    
    // this->electropositivity += 1; // increase the electropositivity
    if(this->Vth > 0){
        // this->Vth = this->Vth - this->electropositivity;
        // this->electronegativity = 0; 
        this->Vth -= 1;
    }
    if (this->voltage > this->Vth){ 
        // the regulation is not necessary because the neuron is already activated
        if (this->axon){
            this->regulation = 1;
        }
        else if (this->axon==0){
            this->regulation = 0;
        }
    }
    else{ //increase the sensitivity of the synap
        this->voltage = 0;
        for(int i=0;i<8;i++){
            if (this->synap[i].sensitive<15){
                this->synap[i].sensitive += 1;
                this->voltage += this->synap[i].sensitive*this->input_mem[i];
            }
        }
        
        if (this->voltage > this->Vth){
            if (this->axon){
                this->regulation = 1;
            }
            else if (this->axon==0){
                this->regulation = 0;
            }
        }
        else{ // stimulate the higher layer
            this->regulation = 3;
        }
    }
}

void Neuron::inhibition(){
    // occur when the neuron is activated and received a inhibition signal from lower layer    
    
    if(this->Vth < 128){
        this->Vth += 1;
    }
    if (this->voltage < this->Vth){
        if (this->axon){
            this->regulation = 1;
        }
        else if (this->axon==0){
            this->regulation = 0;
        }
    }
    else{ //decrease the sensitivity of the synap
        this->voltage = 0;
        for(int i=0;i<8;i++){
            if (this->synap[i].sensitive>0){
                this->synap[i].sensitive -= 1;
                this->voltage += this->synap[i].sensitive*this->input_mem[i];
            }
        }
        
        if (this->voltage < this->Vth){
            if (this->axon){
                this->regulation = 1;
            }
            else if (this->axon==0){
                this->regulation = 0;
            }
        }
        else{ // inhibit the higher layer
            this->regulation = 2;
        }
    }
}