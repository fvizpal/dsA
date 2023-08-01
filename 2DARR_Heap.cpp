#include<bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    cin >> n;
    
    //crating 2D array

    int **arr = new int *[n];
    for( int i = 0; i < n; i++ ){
        arr[i] = new int[n];
    }

    //taking input
    for (int i = 0; i< n; i++){
        for (int j = 0; j< n; j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    // printing output
    for(int i = 0; i < n; i++){
        for (int j = 0; j< n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // releasing memory
    for (int i =0; i <n ;i++){
        delete []arr[i];
    }
    delete []arr;

    return 0;
}