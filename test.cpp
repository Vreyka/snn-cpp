#include<iostream>
// #include<xynap.h>
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
        x a2[3][2] = {{6, 7} ,{8, 9}, {10, 11}};
        x * b[2];

        z(){
            this->b[0] = *this->a;
            this->b[1] = *this->a2;
        }

        x * b2[2] = {*this->a, *this->a2};
};
int main(){
    z c;
    cout << c.b[1][5].a << endl;


}
