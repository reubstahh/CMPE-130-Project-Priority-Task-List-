#include "Task.h"
#include "Heap.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main(){

    //testing heapsort
    MinHeap h;
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(220);
    h.insertKey(12);
    h.insertKey(1);
    h.insertKey(2);
    h.insertKey(320);
    h.insertKey(3);
    h.insertKey(420);


    h.printPreorder();
    cout << endl;
    h.HeapSort();
   // h.printPreorder();

}