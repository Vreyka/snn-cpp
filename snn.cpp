#include<snn.h>

SNN::SNN(){
    for(int i=0; i<4; i++){
        this->mem_forward_counterpart[i] = 0;
        this->mem_forward_higher[i] = 0;
        this->mem_backward_counterpart[i] = 0;
        this->mem_backward_lower[i] = 0;
    }
}

void SNN::forward(bool input[28][28]){
    int row_lenth, col_lenth, expain_lenth;
    for (int layer = 0; layer<5; layer++){

        row_lenth = this->row_scheduler[layer];
        col_lenth = this->col_scheduler[layer];
        expain_lenth = this->expain_scheduler[layer];

        this->connect(row_lenth, col_lenth, expain_lenth);


    }

}

void SNN::connect(int row, int col, int expain){
    for(int i=0; i<row; i++){

        for(int j=0; j<col; j++){
            
        }
    }
}