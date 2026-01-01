class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();

        // DP table
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));

        // Build table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        val[i-1] + t[i][j - wt[i-1]], // include (same row)
                        t[i-1][j]                    // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
};

/*
Unbounded knapsack me har item ko
kitni bhi baar use kar sakte ho.

Isliye jab include karte hain:
  capacity kam hoti hai
  BUT item count same rehta hai

Isliye DP transition:
t[i][j] = max(
   val[i-1] + t[i][j - wt[i-1]],   // same row
   t[i-1][j]
)
*/


// Time Complexity: O(n * W)
// Space Complexity: O(n * W)
