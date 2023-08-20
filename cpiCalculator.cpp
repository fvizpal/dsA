#include<iostream>
using namespace std;

int main(){
    cout << "Enter the semseter \n";
    int n ; cin >> n;

    float c1 = 24, c2 = 26, c3 = 30, c4 = 28, c5 =27 , c6= 27;
    float s4, s5, s6;
    if( n==4){

        cout <<"CPI: \t" << 7.06 << endl;

    }
    if(n==5){

        cout << "Enter spi of 5 th semester ";
        cin >> s5;
        cout <<"CPI: \t" << ((8.29*c1 + 6.5*c2 + 7*c3 + 6.57*c4 + s5*c5)/(c1 +c2+c3+c4 + c5)) << endl;

    }
    if(n==6){

        cout << "Enter spi of 5 th semester ";
        cin >> s5;
        cout << "Enter spi of 6 th semester ";
        cin >> s6;
        cout <<"CPI: \t" << ((8.29*c1 + 6.5*c2 + 7*c3 + 6.57*c4 + s5*c5 + s6*c6)/(c1 +c2+c3+c4 + c5 + c6)) << endl;

    }
    return 0;
}