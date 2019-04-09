
#include<stdlib.h>
#include<iostream>
using namespace std;
int count(0);
 
void Merge(int arr[], int F, int M, int L){
    int first1= F;
    int first2 = M+1;
    int index = 0;
     int temp[L-F+1];
    while((first1 <= M) && (first2 <= L)){
        if(arr[first1] < arr[first2])
            temp[index++] = arr[first1++];
        else
            temp[index++] = arr[first2++];
        count++;
    }
    while(first1 <= M)
        temp[index++]= arr[first1++];
    while(first2 <= L)
        temp[index++]= arr[first2++];
    index = 0;
    while(F<=L)
        arr[F++] = temp[index++];
         
    
}
 
void Merge_sort(int arr[], int first, int last){
    if(first < last){
        int middle = (first + last)/2;
        Merge_sort(arr, first, middle);
        Merge_sort(arr, middle+1, last);
        Merge(arr, first, middle, last);
    }
}
 
int main(){
    int size;
    cin>>size;
   	int arr[size];
     
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    Merge_sort(arr, 0, size-1);

    cout<<count;

    return 0;
}

