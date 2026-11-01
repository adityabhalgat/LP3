#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W, int n,
             vector<vector<int>>& dp) {

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n-1] <= W) {
        return dp[n][W] = max(
            val[n-1] + knapsack(wt, val, W-wt[n-1], n-1, dp),
            knapsack(wt, val, W, n-1, dp)
        );
    }

    return dp[n][W] = knapsack(wt, val, W, n-1, dp);
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    cout << "Maximum Profit = "
         << knapsack(wt, val, W, n, dp);

    return 0;
}


// #include <iostream>
// using namespace std;

// int main() {
//     int n, W;
//     cin >> n >> W;

//     int wt[100], val[100], dp[100][100];

//     for (int i = 0; i < n; i++)
//         cin >> wt[i] >> val[i];

//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {

//             if (i == 0 || w == 0)
//                 dp[i][w] = 0;

//             else if (wt[i-1] <= w)
//                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],
//                                dp[i-1][w]);

//             else
//                 dp[i][w] = dp[i-1][w];
//         }
//     }

//     cout << "Maximum Profit = " << dp[n][W];

//     return 0;
// }