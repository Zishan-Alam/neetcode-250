// Top-Down (Optimised)
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> pal;

    int solve(string &s, int i, int j) {
        if(i >= j) return 0;
        if(pal[i][j]) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            if(pal[i][k]) {
                ans = min(ans, 1 + solve(s, k+1, j));
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));
        pal.assign(n, vector<bool>(n, false));

        // Palindrome precomputation
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) pal[i][j] = true;
                else if(g == 1) pal[i][j] = (s[i] == s[j]);
                else pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
            }
        }

        return solve(s, 0, n-1);
    }
};

/*
INTUITION:
Same recursion as normal Palindrome Partitioning
BUT palindrome check precomputed hai.

Decision:
"Agar left part palindrome hai,
toh right part pe cut lagao"

Optimization:
Palindrome checking O(1)

Time Complexity:
O(n²)

Space Complexity:
O(n²)
*/
