#include<iostream> 
using namespace std;
int count(0);

void selectionSort(int arr[], int size)
{	
	int abc;
    for(int i = size-1 ; i>0  ; i--) 
	{            
     	abc=0;
		for (int j = 0  ; j <=i ; j++) 
        {
        		
            if(arr[j] > arr[abc])
            {
				abc=j;
             	count++;   
            }
        }
         swap(arr[i], arr[abc]);               
        }
    }    
 
/*
int largest(int arr[],int last)
{
     
}
 책보고 하다가 뻘짓한것입니다.  이함수는  
 */
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int size = sizeof(arr) / sizeof(arr[0]);
        selectionSort(arr, size);
        cout<<count;
     
}
