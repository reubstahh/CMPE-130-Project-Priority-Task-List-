#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// Task Class Definition
class Task {
private:
    string name;
    int priorityLevel;
    int deadline;

public:
    // Constructor
    Task(string taskName, int priority, int dueDate)
        : name(taskName), priorityLevel(priority), deadline(dueDate) {}

    // Getters
    string getName() const { return name; }
    int getPriorityLevel() const { return priorityLevel; }
    int getDeadline() const { return deadline; }

    // Setters
    void setName(string taskName) { name = taskName; }
    void setPriorityLevel(int priority) { priorityLevel = priority; }
    void setDeadline(int dueDate) { deadline = dueDate; }

    // Comparison operator for sorting by deadline first, then priority
    bool operator<(const Task &other) const {
        if (deadline == other.deadline) {
            return priorityLevel < other.priorityLevel;
        }
        return deadline > other.deadline; // Max-heap requires reverse order
    }

    // Print Task
    void printTask() const {
        cout << "Task: " << name << ", Priority: " << priorityLevel
             << ", Deadline: " << deadline << endl;
    }
};

// TaskList Class Definition
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
};

#endif // TASK_H

