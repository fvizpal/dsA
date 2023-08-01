#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n){

    for(int i = 1; i < n ;i++){
        for(int j = 0; j < n - i; j++){
            if ( arr[j] > arr[j + 1] )
                swap( arr[j] , arr[ j + 1]);
        }
    }
}

int main(){
    int array[50], size;
    cout<< "Enter number of elements : ";
    cin>> size;

    for( int i = 0 ; i < size; i++){
        cout<< i << "number is: ";
        cin>>array[i];
    }

    cout<<"The unsorted array is "<<endl;
    for( int i = 0; i < size; i++){
        cout<< array[i] << " ";
    }
    cout<< endl;
    
    bubbleSort(array , size);

    cout<< "The sorted array is : "<<endl;
    for( int i = 0; i < size; i++){
        cout<< array[i] << " ";
    }
    
    return 0;
}