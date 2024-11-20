#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// TaskList Class Definition
class TaskList
{
private:
    vector<Task> tasks;

public:
    // Constructor
    TaskList() {}
    // getters
    string getName(int i)
    {
        return tasks.at(i).getName();
    }
    int getPriority(int i)
    {
        return tasks.at(i).getPriorityLevel();
    }
    int getDate(int i)

    {
        return tasks.at(i).getDeadline();
    }
    Task getTask(int i)
    {
        return tasks.at(i);
    }
    int getSize()
    {
        return tasks.size();
    }
    // Add a Task
    void addTask(const Task &task)
    {
        tasks.push_back(task);
        cout << "Task \"" << task.getName() << "\" added!" << endl;
    }

    // Remove a Task by Index
    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            cout << "\nRemoving task: " << tasks[index].getName() << endl;
            tasks.erase(tasks.begin() + index);
        }
        else
        {
            cout << "\nInvalid index. Task not removed." << endl;
        }
    }

    // Print all tasks
    void printall() const
    {
        if (tasks.empty())
        {
            cout << "\n--- Task List is Empty ---" << endl;
        }
        else
        {
            cout << "\n--- Task List ---" << endl;
            for (int i = 0; i < tasks.size(); ++i)
            {
                cout << "Task #" << (i + 1) << ": ";
                tasks[i].printTask();
            }
            cout << "\n----------------" << endl;
        }
    }
    void sort()
    {
        // merge sort by deadline
        // quick sort each subgroup before merging
        mergeSort(0, tasks.size() - 1);
         quicksort(0, tasks.size() - 1);
    }
    // 4 5 5 5 2 2 2 2 2

    void merge(int left,
               int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp vectors
        vector<Task> L(n1), R(n2);

        // Copy data to temp vectors L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = tasks.at(left + i);
        for (int j = 0; j < n2; j++)
            R[j] = tasks.at(mid + 1 + j);

        int i = 0, j = 0;
        int k = left;

        // Merge the temp vectors back
        // into arr[left..right]
        while (i < n1 && j < n2)
        {
            if (L[i].getDeadline() <= R[j].getDeadline())
            {
                tasks.at(k) = L[i];
                i++;
            }
            else
            {
                tasks.at(k) = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[],
        // if there are any
        while (i < n1)
        {
            tasks.at(k) = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[],
        // if there are any
        while (j < n2)
        {
            tasks.at(k) = R[j];
            j++;
            k++;
        }
    }

    // begin is for left index and end is right index
    // of the sub-array of arr to be sorted
    void mergeSort(int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void quicksort(int low, int high)
    {
        cout << "low:" << low << "\thigh:" << high << endl;
        if (low < high)
        {
            int p = pivot(low, high);
            cout << "pivot:" << p;
            quicksort(low, p - 1);
            quicksort(p + 1, high);
        }
    }
    int pivot(int low, int high)
    {
        int i = low - 1;
        int p = tasks.at(high).getPriorityLevel();
        for (int j = low; j < high; j++)
        {
            if (tasks.at(j).getPriorityLevel() < p)
            {
                cout << " hi!";
                cout << tasks.at(j).getPriorityLevel() << tasks.at(i).getPriorityLevel() << endl;
                i++;
                Task temp = tasks.at(j);
                tasks.at(j) = tasks.at(i);
                tasks.at(i) = temp;
            }
        }
        Task temp = tasks.at(i + 1);
        tasks.at(i + 1) = tasks.at(high);
        tasks.at(high) = temp;
        cout << "pivot: " << i << endl;
        return i + 1;
    }
};

#endif // TASKLIST_H
