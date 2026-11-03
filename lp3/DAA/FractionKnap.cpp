
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    double capacity, totalProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of items must be positive.";
        return 0;
    }

    Item items[100];

    if (n > 100) {
        cout << "Maximum 100 items allowed.";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item "
             << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;

        if (items[i].weight <= 0 || items[i].profit < 0) {
            cout << "Invalid weight or profit.";
            return 0;
        }

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Capacity cannot be negative.";
        return 0;
    }

    sort(items, items + n, compare);

    cout << fixed << setprecision(2);
    cout << "\nSelected items:\n";

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            cout << "Weight: " << items[i].weight
                 << ", Profit: " << items[i].profit
                 << ", Fraction: 1.00\n";
        }
        else {
            double fraction =
                capacity / items[i].weight;

            totalProfit += items[i].profit * fraction;

            cout << "Weight taken: " << capacity
                 << ", Profit gained: "
                 << items[i].profit * fraction
                 << ", Fraction: " << fraction << endl;

            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}

