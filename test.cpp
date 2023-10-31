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
    x k[2][2];
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
            k[i][j].a = i+j;
            cout<< k[i][j].a << endl;
        }
    }
    // k[0][0].a = 1;
    z zz(*k);

    cout << zz.bz[3].a << endl;


}
