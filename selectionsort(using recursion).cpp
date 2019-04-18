#include<iostream>
using namespace std;
void selectionsort(int a[],int n)
{
	if(n==1)
	return; 
	
		int largest(0);
		for(int i=1;	i<n; i++)
		{
			if(a[largest]<a[i])
			largest=i;
		}
		swap(a[largest],a[n-1]);
		selectionsort(a,n-1);
	
}



int main()
{
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	selectionsort(arr,n);
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
}
