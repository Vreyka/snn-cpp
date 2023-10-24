#include<iostream>
#include "neuronlib.h"
#include "snnlib.h"
using namespace std;
class x{
    public:
        int a;
};
class y{
    public:
        x *xx;
};

class z{
    public:
        x a[2][2] = {{1,2},{3,4}};
        x a2[3][2] = {{6, 7} ,{8, 9}, {10}};
        x * b[2];
        x *b3[2];
        x *bz;

        z(){
            int acc = 5;
            this->b[0] = *this->a;
            this->b[1] = *this->a2;
            this->b3[0] =  new x[acc];
            
            // this->b3[1] =  *new x[3][2] ;
        }
        z(x *k){
            this->bz = k;
        }

        x * b2[2] = {*this->a, *this->a2};
};
int main(){
    SNN snn;
    cout << snn.shadow_layers[0][0] << endl;


}
