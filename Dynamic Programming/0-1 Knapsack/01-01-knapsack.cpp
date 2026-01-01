// Bottom-Up (Tabulation)
class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int n = wt.size();

        // DP table: t[i][j] = first i items se capacity j me max profit
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {

                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        val[i-1] + t[i-1][j - wt[i-1]], // item lo
                        t[i-1][j]                       // item skip
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
INTUITION:
t[i][j] represent karta hai → pehle i items se capacity j me max profit.
Initialization t[0][j] = 0 kyunki 0 items ke saath profit possible hi nahi.
Initialization t[i][0] = 0 kyunki bag ki capacity 0 hai to kuch le hi nahi sakte.
Baaki table fill karte waqt har cell me wahi 2 choice hai → lo ya skip.
Ye exactly recursion ka bottom-up version hai.

TIME COMPLEXITY:
O(n * W)

SPACE COMPLEXITY:
O(n * W)
*/

// 🔴 Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(int W, vector<int>& val, vector<int>& wt, int n) {

        // Base case
        if(n == 0 || W == 0) return 0;

        // Memoization check
        if(t[n][W] != -1) return t[n][W];

        if(wt[n-1] <= W) {
            return t[n][W] = max(
                val[n-1] + solve(W - wt[n-1], val, wt, n-1), // item lo
                solve(W, val, wt, n-1)                      // item skip
            );
        }

        return t[n][W] = solve(W, val, wt, n-1);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        t.assign(n+1, vector<int>(W+1, -1));
        return solve(W, val, wt, n);
    }
};

/*
INTUITION:
Recursive soch: har item ke paas 2 choice hoti hai → lo ya skip.
Base case wahi hai jo tabulation ke initialization me tha
(n==0 ya W==0 → answer 0).
Memoization ensure karta hai ki har (n,W) state sirf ek baar solve ho.

TIME COMPLEXITY:
O(n * W)

SPACE COMPLEXITY:
O(n * W) DP table
O(n) recursion stack
*/
