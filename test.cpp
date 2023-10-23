#include<iostream>
// #include<xynap.h>
using namespace std;
class x{
    public:
        int a;
};
class y{
    public:
        x a1[2][2] = {{{1}, {2}} ,{{3}, {4}}};
        x a2[2][2] = {{{6}, {7}} ,{{8}, {9}}};
        x (*al[2]); // al is an array of pointers to 2D arrays

        y() {
            this->al = &this->a1; // Assign the address of a1 to the first element of al
            this->al = &this->a2; // Assign the address of a2 to the second element of al
        }
};

int main(){
    int a[3];
    y c;
    // c.a[0][1].a = 0;
    cout<<c.al[0][0][0]->a<<endl;


}
