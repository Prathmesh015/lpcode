
#include <iostream>
using namespace std;

int main()
{
    int n, r;

    cout << "Enter value of n: ";
    cin >> n;

    cout << "Enter value of r: ";
    cin >> r;

    if (n < 0 || r < 0 || r > n) {
        cout << "Invalid input!";
        return 0;
    }

    int dp[n + 1][r + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r && j <= i; j++)
        {
            // Base conditions
            if (j == 0 || j == i)
                dp[i][j] = 1;

            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << "Binomial Coefficient C("
         << n << "," << r << ") = " << dp[n][r];

    return 0;
}
