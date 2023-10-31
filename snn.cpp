#include "snn.h"

SNN::SNN(){

    for(int i=0; i<8; i++){
        this->mem_forward[i] = 0;
        this->mem_backward[i] = 0;
    }
    for (int i=0; i<6; i++){
        this->layers[i] = new Neuron[this->row_scheduler[i]*this->col_scheduler[i]]; 
        this->shadow_layers[i] = new bool[this->row_scheduler[i]*this->col_scheduler[i]];
    }
}

void SNN::forward(bool *input,int lenth_input){ //array[28*28]
    int row_lenth, col_lenth, expain_lenth;
    // this->working_mem = input;
    for (int layer = 0; layer<5; layer++){

        row_lenth = this->row_scheduler[layer];
        col_lenth = this->col_scheduler[layer];
        expain_lenth = this->expain_scheduler[layer];

        //data to model
        if (layer == 0){
            this->data_in(input, lenth_input, layer, row_lenth, col_lenth, expain_lenth);
        }

        //fully connected layer
        else if (layer < this->last_layer-1){
            this->connect(lenth_input, layer, row_lenth, col_lenth, expain_lenth);
        }

        //classification layer
        else if (layer == this->last_layer-1)
        {
            this->classify();
        }
        
        // this->connect(this->working_mem, lenth_input, layer, row_lenth, col_lenth, expain_lenth);
        // lenth_input = col_lenth;



    }

}

void SNN::data_in(bool *input, int lenth_input, int layer, int row, int col, int expain){

    //voltage summary for the input data
    //data in input to the nn
    for(int i=0; i<lenth_input-expain; i++){
        for(int j= 0; j<lenth_input-expain; j++){
            //each 2x2 grid
            for(int h = 0; h<2; h++){
                for(int w = 0; w<2; w++){
                    //put data to mem_forward
                    this->mem_forward[h*2+w] = input[(i+h)*lenth_input+(j+w)];
                }
            }
            //y = f(x)
            this->layers[layer][i*col+j].dendrite(this->mem_forward);
        }
    }

    //voltage summary for the same lever layer
    for (int time= 0; time< this->stable_time; time++){
        for(int i=0; i<row; i++){
            for(int j= 0; j<col; j++){
                
                if (i>0){
                    this->mem_forward[4] = this->layers[layer][(i-1)*col+j].axon;
                }
                if (j>0){
                    this->mem_forward[5] = this->layers[layer][i*col+(j-1)].axon;
                }
                this->mem_forward[6] = this->layers[layer][(i+1)*col+j].axon;
                this->mem_forward[7] = this->layers[layer][i*col+(j+1)].axon;
                //y = f(x)
                this->layers[layer][i*col+j].dendrite(this->mem_forward);
            }
        }
    }
}

void SNN::connect(int lenth_input, int layer, int row, int col, int expain){
    
}

void SNN::classify(){
    
}