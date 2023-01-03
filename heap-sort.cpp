//PROBLEM STATEMENT
/*
Assignment 10: Read the marks obtained by students of 
second year in an online examination of particular subject.
 Find out maximum and minimum marks obtained in that subject. 
 Use heap data structure. 
 Analyze the algorithm.
*/
//CODE
#include<iostream>
using namespace std;

class Heap_sort
{
 public:
 void heapify(int[], int, int);  
};

void Heap_sort:: heapify(int arr[], int n, int i)
{
   int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
 
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
 
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
 
        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
 
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
}

int main()
{
   Heap_sort ob;
   int n;
   cout<<"Enter the number of students:"<<endl;
   cin>>n;
   int arr[n];
   cout<<"Enter marks of DSA:"<<endl;
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
   for (int i = n / 2 - 1; i >= 0; i--)
            ob.heapify(arr, n, i);
 
        // One by one extract an element from heap
   for (int i = n - 1; i > 0; i--) 
   {
            // Move current root to end
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
 
      // call max heapify on the reduced heap
       ob.heapify(arr, i, 0);
   }
   cout<<"Maximum Marks:"<<arr[n-1]<<endl;
   cout<<"Minimum Marks:"<<arr[0]<<endl;         
   return 0;
}