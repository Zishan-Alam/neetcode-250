class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        // DP table
        vector<vector<int>> t(n+1, vector<int>(amount+1, INF));

        // Initialization
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;   // 0 coins needed to make sum 0

        // DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(
                        1 + t[i][j - coins[i-1]], // include (same row)
                        t[i-1][j]                  // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return (t[n][amount] >= INF) ? -1 : t[n][amount];
    }
};

/*
Har coin unlimited times use kar sakte ho,
isliye ye Unbounded Knapsack hai.

t[i][j] = minimum coins required
          j sum banane ke liye
          first i coins use karke

Include:
  1 coin add karo
  amount kam karo (j - coin)
  i same rahega

Exclude:
  coin skip karo → i-1

Minimum lena hai, isliye min() use hota hai
*/


// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)
