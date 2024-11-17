#include "Heap.h"

MinHeap::MinHeap() 
{ 
	heap_size = 0; 
} 

void MinHeap::MinHeapify(int i) 
{ 
	int l = (i*2) + 1; 
	int r = (i*2) + 2; 
	int smallest = i; 
	if (l < heap_size && taskList.at(l) < taskList.at(smallest)) {
		smallest = l; 
    }
	if (r < heap_size && taskList.at(r) < taskList.at(smallest)) {
		smallest = r;
    }
	if (smallest != i) 
	{ 
		swap(&taskList.at(i), &taskList.at(smallest)); 
		MinHeapify(smallest); 
	} 
} 

void MinHeap::HeapSort() {
    for (int i = (heap_size/2)-1; i > 0; i--){
        MinHeapify(i);
    }
  /*  for (int i = heap_size-1; i > 0; i--){
        swap(&taskList.at(0), &taskList.at(i)); 
        MinHeapify(i);
    }*/
}

//IMPLEMENT BST CONDITIONS
void MinHeap::insertKey(int k) 
{ 
	/*if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} */
	heap_size++; 
	taskList.push_back(k);
} 

int MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return taskList.at(0); 
	} 
	int root = taskList.at(0); 
	taskList.at(0) = taskList.at(heap_size-1); 
	heap_size--; 
	MinHeapify(0); 
	return root; 
} 

void MinHeap::deleteKey(int i) 
{ 
    taskList.at(i) = INT_MIN; 
	while (i != 0 && taskList.at((i-1)/2) > taskList.at(i)) 
	{ 
	swap(&taskList.at(i), &taskList.at((i-1)/2)); 
	i = (i-1)/2; 
	} 
	extractMin(); 
} 

void MinHeap::printPreorder()
{
    cout << "PREORDER: ";
    preorder(0);
    cout << endl;
}

void MinHeap::preorder(int i)
{
    if (i < heap_size){
    cout <<i<<": " << taskList.at(i) << " ";  // Deal with the node
    preorder(((i*2)+1));// Recur on left subtree
    preorder(((i*2)+2));// Recur on right subtree
    }
}

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 