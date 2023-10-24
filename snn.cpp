#include "snn.h"

SNN::SNN(){

    for(int i=0; i<4; i++){
        this->mem_forward_counterpart[i] = 0;
        this->mem_forward_higher[i] = 0;
        this->mem_backward_counterpart[i] = 0;
        this->mem_backward_lower[i] = 0;
    }
    for (int i=0; i<5; i++){
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
            /* code */
        }
        
        // this->connect(this->working_mem, lenth_input, layer, row_lenth, col_lenth, expain_lenth);
        // lenth_input = col_lenth;



    }

}

void SNN::data_in(bool *input, int lenth_input, int layer, int row, int col, int expain){
    //voltage summary for the input data
    //each neuron in layer
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){

            //each data in input
            for(int ipr=0; ipr<lenth_input-expain; ipr++){
                for(int ipc= 0; ipc<lenth_input-expain; ipc++){

                    //each 2x2 grid
                    for(int k = 0; k<4; k++){
                        this->mem_forward_higher[k] = input[(i*expain+ipr)*lenth_input+j*expain+ipc];   
                    }
                }
            }
            // this->layers[layer][i*col+j].dendrite(input);
        }
    }
}

void SNN::connect(int lenth_input, int layer, int row, int col, int expain){
    
}

void SNN::classify(){
    
}