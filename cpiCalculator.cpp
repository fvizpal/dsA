#include<iostream>
using namespace std;

int main(){
    cout << "Enter the semseter \n";
    int n ; cin >> n;

    float c1 = 24, c2 = 26, c3 = 30, c4 = 28, c5 =27 , c6= 27, c7 = 26, c8 = 21;
    float s7, s8;
    if( n==6){

        cout <<"CPI: \t" << 7.46 << endl;

    }
    if(n==7){

        cout << "Enter spi of 7 th semester ";
        cin >> s7;
        cout <<"CPI: \t" << ((8.29*c1 + 6.5*c2 + 7*c3 + 6.57*c4 + 8.37*c5 + 8.19*c6 + s7*c7)/(c1 +c2+c3+c4 + c5 + c6 + c7)) << endl;

    }
    if(n==8){

        cout << "Enter spi of 7 th semester ";
        cin >> s7;
        cout << "Enter spi of 8 th semester ";
        cin >> s8;
        cout <<"CPI: \t" << ((8.29*c1 + 6.5*c2 + 7*c3 + 6.57*c4 + 8.37*c5 + 8.19*c6 + s7*c7 + s8*c8)/(c1 +c2+c3+c4 + c5 + c6 + c7 + c8)) << endl;

    }
    return 0;
}