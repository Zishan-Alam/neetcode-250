class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // DP table
        vector<vector<int>> t(n+1, vector<int>(amount+1, 0));

        // Initialization
        // 1 way to make sum 0 (choose nothing)
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;

        // DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] =
                        t[i][j - coins[i-1]]   // include (same row → unbounded)
                      + t[i-1][j];              // exclude
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
};


/*
Har coin ko kitni bhi baar use kar sakte ho,
isliye ye Unbounded Knapsack hai.

t[i][j] = number of ways to make sum j
          using first i coins

Include:
  coin use karo → j - coin[i-1]
  i same rahega (unlimited)

Exclude:
  coin skip → i-1

Max nahi lena,
yahan COUNT karna hai isliye + use hota hai

coins = [1, 2, 5]
amount = 5

// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

*/


