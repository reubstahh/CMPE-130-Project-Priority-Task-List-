Project Goal:
Create a dynamic task list that sorts and prioritizes tasks based on urgency using a heap data structure. Users will be able to add, remove, or update tasks as needed, and the scheduler will adapt dynamically. Users will input tasks to complete with their priority level on a scale from 1 to 3 and a deadline. The program will sort the tasks by deadline first then priority to determine the order in which the tasks should be completed.

 Implementation:
A class called Task will have private member variables priorityLevel and deadline, both of which will be ints. A new object Task will be created every time a user inputs a new task. A priority queue will be used by implementing a max-heap called AllTasks. This priority queue will be sorted through heap-sort, using priorityLevel as the metric. Any tasks that have the same deadline will be sorted using quick sort.

This project implements data structures such as classes, priority queue, and heap as well as sort methods like heapsort and quick sort.


