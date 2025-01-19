#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " [";
        cout << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed!\n";
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully!\n";
}

