#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[] , int size){

    for(int i = 0; i < size; i++){
        int minInd = i;

        for(int j = i + 1 ; j < size; j++){
            if ( arr[minInd] > arr[j] )
                minInd = j;            
        }
        swap( arr[i] , arr[minInd] );
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
    selectionSort(array , size);

    cout<< "The sorted array is : "<<endl;
    for( int i = 0; i < size; i++){
        cout<< array[i] << " ";
    }
    
    return 0; 
}
