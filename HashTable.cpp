#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int count = 0;

int nearPrimeNum(int n){
    for(int i = 2; i < n/2; i++)
            if(!(n%i)) return nearPrimeNum(n+1);
    return n;
}

int h_i(const int H[], int index, int size){
    int i = (index + 1) % size;
    if(H[i] == INT_MIN) return i;
    else{
         count++;
         return h_i(H, i, size);
    }
}

int main(){
        
    /* Get N */
    int N;
    cin>>N;
    int size = nearPrimeNum(N*2);
    
    /* HashTable */
    int* H = (int*) malloc(size*sizeof(int));
    for(int i=0; i<size; i++) H[i] = INT_MIN;
    
    /* Get keys */
    int index;
    int key;
    for(int i=0; i<N; i++){            
            cin>>key;
            index = key%size;
            
            if(H[index] == INT_MIN) H[index] = key;
            else {
                 count++;
                 index = h_i(H, index, size);
                 H[index] = key;
                 }
    }
    
    
    cout<<count<<endl;
    
    
    return 0;
}   
