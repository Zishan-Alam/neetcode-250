class Solution {
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        val[i-1] + t[i-1][j - wt[i-1]],
                        t[i-1][j]
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
};

// Time: O(n * W)
// Space: O(n * W)


// Top Down
class Solution {
public:
    vector<vector<int>> t;

    int solve(int W, vector<int> &val, vector<int> &wt, int n) {
        // Base case
        if(n == 0 || W == 0) return 0;

        // Memoization check
        if(t[n][W] != -1) return t[n][W];

        // Choice diagram
        if(wt[n-1] <= W) {
            return t[n][W] = max(
                val[n-1] + solve(W - wt[n-1], val, wt, n-1),
                solve(W, val, wt, n-1)
            );
        } else {
            return t[n][W] = solve(W, val, wt, n-1);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        t.assign(n+1, vector<int>(W+1, -1));
        return solve(W, val, wt, n);
    }
};
