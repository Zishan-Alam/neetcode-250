/*
========================================
Shortest Common Supersequence (SCS) Length
========================================

Problem Statement:
Tumhe do strings di gayi hain:
s1 aur s2.

Tumhe:
- unki Shortest Common Supersequence ki LENGTH nikalni hai.

Supersequence:
- s1 aur s2 dono iske subsequence hone chahiye
- order same rehna chahiye

Input:
s1 = "abac"
s2 = "cab"

Output:
5

Explanation:
Ek SCS ho sakti hai: "cabac"
length = 5
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int shortestCommonSupersequenceLength(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= m; j++)
            t[0][j] = 0;

        // LCS DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int lcs = t[n][m];
        return n + m - lcs;
    }
};

/*
INTUITION (Aditya Verma style):
Direct SCS banana mushkil hai,
isliye pehle LCS nikaalte hain.

Observation:
- Jo characters LCS me common hain → ek hi baar aayenge
- Baaki characters dono strings se add honge

Isliye:
SCS Length = len(s1) + len(s2) - LCS

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row aur column = 0

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[1001][1001];

    int LCS(string &s1, string &s2, int n, int m) {
        if(n == 0 || m == 0)
            return 0;

        if(dp[n][m] != -1)
            return dp[n][m];

        if(s1[n-1] == s2[m-1]) {
            return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1);
        } else {
            return dp[n][m] = max(
                LCS(s1, s2, n-1, m),
                LCS(s1, s2, n, m-1)
            );
        }
    }

    int shortestCommonSupersequenceLength(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int lcs = LCS(s1, s2, s1.size(), s2.size());
        return s1.size() + s2.size() - lcs;
    }
};

/*
INTUITION:
Top-Down me hum LCS recursion se nikaalte hain,
phir wahi same formula use hota hai.

SCS Length = n + m - LCS

Recursion ka fayda:
- Jo states repeat ho rahi hain unko memo me store kar liya

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/
