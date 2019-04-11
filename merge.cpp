
#include<iostream>
using namespace std;
int count(0);

void Merge(int arr[], int F, int M, int L){
    int first1= F;
    int middle = M+1;
    int index = 0;
    
    int temp[L-F+1];
    
    while((first1 <= M) && (middle <= L)){
        if(arr[first1] < arr[middle])
            temp[index++] = arr[first1++];
        else
            temp[index++] = arr[middle++];
        count++;
    }
    
    while(first1 <= M)
        temp[index++]= arr[first1++];
    while(middle <= L)
        temp[index++]= arr[middle++];
    
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
    //input
    

    for(int i=0; i<size; i++){
    	
        cin>>arr[i]; 
    }
    
    //sort
    Merge_sort(arr, 0, size-1);
    
    //output
    cout<<count;
    
    
    return 0;
}
