#include "Task.h"
#include "TaskList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Menu Function
void menu(int x, TaskList &tasks) {
    if (x == 1) { // Add a new task
        string name;
        int p, d;
        cout << "Enter task name: ";
        cin >> name;
        cout << "Enter task priority (1 is low, 5 is high): ";
        cin >> p;
        cout << "Enter task deadline: ";
        cin >> d;
        Task temptask(name, p, d);
        tasks.addTask(temptask);
    }

    if (x == 2) { // Print all tasks
        tasks.printall();
    }

    if (x == 3) { // Remove a task by index
        tasks.printall();
        int index;
        cout << "Enter task number to remove: ";
        cin >> index;
        tasks.removeTask(index - 1); // Convert to 0-based index
    }
    if (x == 4) {
        tasks.sort();
        tasks.printall();
    }
}

// Main Function
int main() {
    TaskList allTasks;

    int x = 0;cout << "************************* MENU ***************************" << endl;
        cout << "1: Add Task\n2: View Task List\n3: Remove Task\n4: Sort Tasks\n-1: Quit\n";
        cout << "Enter your choice: ";
        
    while (x != -1) {
        cin >> x;
        if (x != -1) menu(x, allTasks);
        cout << "enter menu option:";
    }

    cout << "\nExiting program. Goodbye!" << endl;
    return 0;
}
