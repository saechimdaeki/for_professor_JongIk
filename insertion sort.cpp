#include<iostream>
using namespace std;
int count=0;
int item=0;
int loc=0;
 
void Insert_Sort(int arr[], int growth, int size){
    if(growth==size) return;
     
    //find out location of item
    loc = growth-1;
    item = arr[growth];
    while(loc>=0 && item < arr[loc]){
        arr[loc+1] = arr[loc];
        loc--;
        count++;
    }
    arr[loc+1] = item;
    count++;
     
    //increase
    growth++;
     
    //recursion
    Insert_Sort(arr, growth, size); 
}
 
int main(){
    int size;
    
         
    //input
    cin>>size;
    int arr[size];
     
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
     
    //sort
    Insert_Sort(arr, 1, size);
     
    //output
     
     
    cout<<count;
     
     
     
    
     
    return 0;
}
