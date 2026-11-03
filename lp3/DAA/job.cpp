
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];

    if (n <= 0 || n > 100) {
        cout << "Invalid number of jobs!";
        return 0;
    }

    // Accept job details
    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline and profit: ";
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;

        if (jobs[i].deadline <= 0 || jobs[i].profit < 0) {
            cout << "Invalid job details!";
            return 0;
        }
    }

    // Sort jobs by profit in descending order
    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create and initialize time slots
    int slot[101] = {0};
    int totalProfit = 0;

    cout << "\nSelected Jobs:\n";

    // Schedule jobs using Greedy Method
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (slot[j] == 0) {
                slot[j] = i + 1;

                cout << jobs[i].id << " ";

                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    cout << "\n\nFinal Job Schedule:\n";

    for (int j = 1; j <= maxDeadline && j <= 100; j++) {
        if (slot[j] != 0) {
            cout << "Slot " << j << ": "
                 << jobs[slot[j] - 1].id << endl;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
