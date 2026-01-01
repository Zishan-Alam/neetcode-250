class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        // wt = rod lengths (1 to n)
        vector<int> wt(n);
        for(int i = 0; i < n; i++)
            wt[i] = i + 1;

        // DP table
        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        // Unbounded Knapsack DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        price[i-1] + t[i][j - wt[i-1]], // include (same row)
                        t[i-1][j]                       // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
};

/*
Rod cutting me har piece ko unlimited baar use kar sakte ho.
Isliye ye Unbounded Knapsack hai.

Rod length = capacity
Piece length = weight
Price = value

Include case me:
  price add hota hai
  rod length kam hoti hai
  item same rehta hai (unlimited)
*/

// Time Complexity: O(n * n)
// Space Complexity: O(n * n)
