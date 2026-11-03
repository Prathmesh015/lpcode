#include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col) {
    int i, j;

    // Check the same column above
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "Enter the value of N (1-20): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Please enter N between 1 and 20.";
        return 0;
    }

    if (solveNQueens(0)) {
        cout << "\nN-Queens Matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "No solution exists.";
    }

    return 0;
}

