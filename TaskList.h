#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
// TaskList Class Definition
class TaskList : public Task
{
private:
    vector<Task> tasks; // Max-heap for tasks
    int size;

public:
    // Add a Task
    TaskList()
    {
        int size = 1;
    }
    void addTask(const Task &task)
    {
        size++;
        tasks.push_back(task);
        cout << "task " << task.getName() << " added!" << endl;
    }

    // Remove the top-priority task
    void removeTask()
    {
        if (!tasks.empty())
        {
            tasks.pop_back();
        }
        else
        {
            cout << "Task list is empty!" << endl;
        }
    }

    // Print all tasks
    void printT(int i)
    {
        cout << "task#" << i << ":\t";
        tasks.at(i).printTask();
    }
    void printall()
    {
        cout << "\t          --- TASK LIST ---          " << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            tasks.at(i).printTask();
        }
        cout << "\t                                     " << endl;
    }

    // Getter for the tasks queue
    Task getTask(int i) const
    {
        return tasks.at(i); // Returns a copy of the queue
    }

    // Setter for the tasks queue
    void setTasks(const vector<Task> &newTasks)
    {
        tasks = newTasks; // Replace the current queue with the new one
    }
};

/*// TaskList Class Definition
class TaskList {
private:
    priority_queue<Task> tasks; // Max-heap for tasks

public:
    // Add a Task
    void addTask(const Task &task) {
        tasks.push(task);
    }

    // Remove the top-priority task
    void removeTask() {
        if (!tasks.empty()) {
            tasks.pop();
        } else {
            cout << "Task list is empty!" << endl;
        }
    }

    // Print all tasks
    void printTasks() const {
        priority_queue<Task> temp = tasks; // Copy the heap for iteration
        while (!temp.empty()) {
            temp.top().printTask();
            temp.pop();
        }
    }

    // Getter for the tasks queue
    priority_queue<Task> getTasks() const {
        return tasks; // Returns a copy of the queue
    }

    // Setter for the tasks queue
    void setTasks(const priority_queue<Task> &newTasks) {
        tasks = newTasks; // Replace the current queue with the new one
    }
};*/

#endif // TASKLIST_H
