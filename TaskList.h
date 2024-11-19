#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// TaskList Class Definition
class TaskList {
private:
    vector<Task> tasks;

public:
    // Constructor
    TaskList() {}

    // Add a Task
    void addTask(const Task &task) {
        tasks.push_back(task);
        cout << "Task \"" << task.getName() << "\" added!" << endl;
    }

    // Remove a Task by Index
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Removing task: " << tasks[index].getName() << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid index. Task not removed." << endl;
        }
    }

    // Print all tasks
    void printall() const {
        if (tasks.empty()) {
            cout << "--- Task List is Empty ---" << endl;
        } else {
            cout << "--- Task List ---" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << "Task #" << (i + 1) << ": ";
                tasks[i].printTask();
            }
        }
    }
};

#endif // TASKLIST_H

