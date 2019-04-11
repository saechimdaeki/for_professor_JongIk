#include<iostream>
using namespace std;



int count(0);


int partition(int arr[], int from, int to){
    int x = arr[to];
    int i = from-1;
    
    for(int j = from; j<=to-1; j++)
        if(arr[j]<=x){i++; swap(arr[i], arr[j]); count++;}    
    
    swap(arr[i+1], arr[to]); count++;
    return i+1;   
}

void Quick_sort(int arr[], int from, int to){
    int result = 0;
    if(from<to){
        result = partition(arr, from, to);
        Quick_sort(arr, from, result-1);
        Quick_sort(arr, result+1, to);
    }
}

int main(){
    int size;
    cin>>size;
    
    int arr[size];
        
        
    for(int i=0; i<size; i++){
      cin>>  arr[i];
    }
    
    //sort
    Quick_sort(arr, 0, size-1);
    
    //output
    cout<<count;
    
    
    return 0;
}
