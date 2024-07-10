#include<iostream>
using namespace std;

int main(){
    cout << "Enter the semseter 5 \n";

    float c1 = 4, c2 = 4, c3 = 4, c4 = 4, c5 = 3 , c6= 2, c7 = 2, c8 = 2, c9 = 2;
    float s1, s2, s3, s4, s5, l1, l2, l3, l4;

    cin >> s1 >> s2 >> s3>> s4>> s5 >>l1 >> l2 >> l3 >> l4;

    cout << "spi is" << endl;
    cout << (c1*s1 + c2*s2 + c3*s3 + c4*s4 + c5*s5 + c6*l1 + c7*l2 + c8*l3 + c9*l4) / (c1+ c2+ c3+c4+c5+c6+c7+c8+c9) << endl;

    return 0;
}