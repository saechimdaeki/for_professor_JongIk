#include<iostream>

using namespace std;
int t =0;


void Radix_sort(int A[], int size, int maxpos){
  int bts[size];
  int digit = 1;
  int i=0;
	 	for(int j = 0; j<t; j++){
	 		int bucket[10]={0};
        for (i = 0; i < size; i++) 
		bucket[(A[i] / digit)%10]++;
        for ( i = 1; i < 10; i++) 
		bucket[i] += bucket[i - 1];
        for ( i = size - 1; i >= 0; i--) 
		bts[--bucket[(A[i] / digit) % 10]] = A[i];
        for ( i = 0; i < size; i++) 
		A[i] = bts[i];
        digit *= 10;
  }
  
  for(int i=0; i<size; i++) 
  cout<<A[i]<<" ";
}

int Getpos(int data){
    int l = 0;
    for(int i=1; data > i; i*=10, l++);
    return l;
    if(data==0)
    return 0;
}

int main(){
    int size;
    int maximum=0;
    cin>>size>>t;
    int A[size];
    for(int i=0; i<size; i++){
        cin>>A[i];
    }
    int pos = 0;
    for(int i=0; i<size; i++){
        pos = Getpos(A[i]);
        if(maximum < pos) maximum = pos;
    }
    Radix_sort(A, size, maximum);
    return 0;
}
