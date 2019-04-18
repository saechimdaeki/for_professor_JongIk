#include<iostream>
using namespace std;
void counting_sort(int A[], int size){
    int max = A[0];
    int min = A[0]; 
    for (int i = 0; i<size; i++){
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    
    int k = max-min+1;//김종익교수님 항상수업시간강조하며 한숨쉰 제일중요파트 2019.04.04 
    int c[k];

    for(int i=0; i<k; i++) 
	c[i] = 0;
    for(int j=0; j<size; j++) 
	c[A[j]-min]++;
    for(int i=1; i<k; i++) 
	c[i] = c[i]+c[i-1];
    for(int i=0; i<k; i++) 
	cout<<c[i]<<" ";
}
    
int main(){
    int size;
    
    cin>>size;
    int arr[size];
    
    for(int i=0; i<size; i++)
        cin>>arr[i];
    
    //sort
    counting_sort(arr, size);
    return 0;
}
