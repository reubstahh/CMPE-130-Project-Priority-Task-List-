#include "Task.h"
#include<iostream> 
#include<climits> 
#include <vector>
using namespace std; 

void swap(int *x, int *y); 
 
class MinHeap 
{  
    public:
	MinHeap(); // Constructor 
	void MinHeapify(int i); // to heapify a subtree with the root at given index 
    void HeapSort();

	int extractMin(); // to extract the root which is the minimum element 
	void deleteKey(int i); // Deletes a key stored at index i 
	void insertKey(int k); 

    void printPreorder();
    void preorder(int i);

	vector<int> taskList; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap
}; 