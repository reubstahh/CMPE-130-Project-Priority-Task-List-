#include "Task.h"
#include "Heap.cpp"
#include "TaskList.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void menu(int x, TaskList tasks)
{

    if (x == 1) // add new task to list
    {
        string name;
        int p, d;
        cout << "\t enter task name:";
        cin >> name;
        cout << "\tenter task priority (1 is low, 5 is highest)";
        cin >> p;
        // assuming all tasks are due in the same month
        cout << "\tenter task deadline date ";
        cin >> d;
        Task temptask(name, p, d);
        tasks.addTask(temptask);
    }

    // ____ISSUE: new task does not print once added
    if (x == 2) // print tasks
    {
        tasks.printall();
    }

    //remove task at i
    if (x == 3)
    {
        tasks.printall();
        cout << "\t enter task number:";
        tasks.removeTask();
    }
    if (x == 4)
    {
        // do we wanna implement this
    }
    if (x == 5)
    {
        // tasks.sort();
        // tasks.printPreorder();
    }
}
int main()
{

    //  _______debugging
    Task t1("a", 3, 12);
    Task t2("b", 3, 10);

    TaskList allTasks;
    allTasks.addTask(t1);
    allTasks.addTask(t2);
    t1.printTask();// prints t1
    allTasks.printT(0); // prints t1
    allTasks.printall(); // should print tasks t1 and t2
    // ^^ this works!

    // _____main
    int x = 11;
    while (x == 11)
    {
        cout << "*************************   MENU   ***************************" << endl;
        cout << "1 for new task\n 2 to view tasklist\n 3 to delete a task\n 4 to edit a task\n 5 to sort\n -1 to quit";
        cin >> x;
        menu(x, allTasks);
        cout << " 11 to return to menu, -1 to quit: ";
        cin >> x;
    }
}