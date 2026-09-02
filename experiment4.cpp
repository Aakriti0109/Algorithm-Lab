//To implement the 0/1 Knapsack problem using Dynamic Programming and determine the maximum total value that can be obtained without exceeding the given knapsack capacity, where each item can be selected at most once.

#include <bits/stdc++.h> 

using namespace std; 

 

int knapsack(int W, vector<int>& weight, vector<int>& value) { 

 

    int n = weight.size(); 

 

    // dp[i][w] = maximum value using first i items 

    // with capacity w 

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); 

 

    for (int i = 1; i <= n; i++) { 

 

        for (int w = 0; w <= W; w++) { 

 

            // Don't take the current item 

            dp[i][w] = dp[i - 1][w]; 

 

            // Take the current item if it fits 

            if (weight[i - 1] <= w) { 

 

                dp[i][w] = max( 

                    dp[i][w], 

                    value[i - 1] + 

                    dp[i - 1][w - weight[i - 1]] 

                ); 

            } 

        } 

    } 

 

    return dp[n][W]; 

} 

 

int main() { 

 

    vector<int> weight = {1, 3, 4, 5}; 

    vector<int> value = {1, 4, 5, 7}; 

 

    int W = 7; 

 

    cout << knapsack(W, weight, value) << endl; 

 

    return 0; 

} 