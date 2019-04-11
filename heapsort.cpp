#include <iostream>
 
using namespace std;
 
int count(0);
void heapify(int A[], int start, int end)
{
   int left = 2*start+1;
   int right = 2*start+2;
   int bigger = 0;
   if(right<=end)
   {
      if(A[left]>A[right])
         bigger=left;
         else
            bigger=right;
   }
      else if(left<=end)
         bigger=left;
         else return;
   if(A[bigger]>A[start])
   {
      swap(A[start], A[bigger]);
      count++;
      heapify(A, bigger, end);
   }
}
 
void buildHeap(int A[], int end)
{
   for(int i=end/2; i>=0; i--)
   {
      heapify(A, i, end);
   }
}
 
void heapSort(int A[], int end)
{
   buildHeap(A, end);
   count=0;
   for(int i=end; i>=1; i--)
   {
      swap(A[0], A[i]);
      heapify(A, 0, i-1);
   }
}
 
int main()
{
   int size;
   cin >> size;
   int A[size];
    
   for(int i = 0; i < size; i++)
   {
      cin >> A[i];
   }
  
   heapSort(A, size-1);
 
   cout << count << endl;
   return 0;
}
