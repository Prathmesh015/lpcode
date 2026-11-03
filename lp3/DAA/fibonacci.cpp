
#include <iostream>
using namespace std;

// Non-Recursive (Iterative) Fibonacci
int fibonacciIterative(int n)
{
    int a = 0, b = 1, c;

    if (n == 0)
        return a;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Recursive Fibonacci
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Enter a non-negative number.";
        return 0;
    }

    cout << "\nNon-Recursive Fibonacci:\n";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciIterative(i) << " ";
    }

    cout << "\n\nRecursive Fibonacci:\n";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciRecursive(i) << " ";
    }

    cout << endl;

    return 0;
}

