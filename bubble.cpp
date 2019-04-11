#include<iostream>
using namespace std;

int count(0);
int temp;

void Bubble_Sort(int arr[], int size){
    if(size==1) return;
    
    //modification
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]) {
            count++;
            swap(arr[i], arr[i+1]);
        }
    }
    
    //reduction
    size--;
    
    //recursion
    Bubble_Sort(arr, size);  
}
        

int main(){
    int size;
    cin>>size;
    int arr[size];
   
    
    for(int i=0; i<size; i++){
        
        cin>>arr[i];
    }
    
    //sort
    Bubble_Sort(arr, size);
    
    //output
   cout<<count;
    
    
    return 0;
}
