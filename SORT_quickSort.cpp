#include<bits/stdc++.h>
using namespace std;

int partition(int& arr[], int s , int e){
    //
    int pivot = arr[s];

    int cnt = 0;
    for ( int i = s+1; i <= e; i++ ){
        if ( arr[i] <= pivot){
            cnt++;
        }
    }

    // placing pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right part handling
    int i = s , j = e;
    while( i < pivotIndex && j > pivotIndex){

        while( arr[i] < pivot){
            i++;
        }
        while( arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);\
        }
    }

    return pivotIndex;
}

void quickSort(int& arr[], int start , int end){
    //nase case
    if (start >= end)
        return;
    // first partition - will give index in return
    int p = partition(arr, start ,end);

    //recursive call
    //solving left part
    quickSort(arr, start, p-1);
    // solving right part
    quickSort(arr, p+1 , end);
}


int main(){

    int arr[5]={2, 4, 1 , 6, 9};
    int n = 5;

    for (int i= 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    quickSort(arr, 0, n-1);

    cout << "Sorted array is "<< endl;
    for (int i= 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }cout << endl;



    return 0;
}