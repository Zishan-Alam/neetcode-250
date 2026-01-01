/*
===================================
Sequence Pattern Matching
===================================

Problem Statement:
Tumhe do strings di gayi hain:
string a (pattern)
string b (text).

Tumhe check karna hai:
- kya string a, string b ki SUBSEQUENCE hai ya nahi.

Subsequence:
- characters delete ho sakte hain
- order same rehna chahiye

Input:
a = "axy"
b = "adxcpy"

Output:
true

Explanation:
"axy" ko
a d x c p y
me se order maintain karke bana sakte hain.
*/
// Bottom-Up (Tabulation)
class Solution {
public:
    bool isSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++) t[i][0] = 0;
        for(int j = 0; j <= m; j++) t[0][j] = 0;

        // LCS DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[n][m] == n;
    }
};

/*
INTUITION (Aditya Verma style):
Sequence Pattern Matching ka matlab:
choti string poori ki poori
badi string ke andar order me milni chahiye.

Trick:
- LCS(a, b) nikaal lo
- Agar LCS length == len(a)
  → a subsequence hai b ki

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row & column = 0

Dry Run:
a = "axy", b = "adxcpy"
LCS = "axy"
Length = 3 → match

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[1001][1001];

    int LCS(string &a, string &b, int n, int m) {
        if(n == 0 || m == 0)
            return 0;

        if(dp[n][m] != -1)
            return dp[n][m];

        if(a[n-1] == b[m-1]) {
            return dp[n][m] = 1 + LCS(a, b, n-1, m-1);
        } else {
            return dp[n][m] = max(
                LCS(a, b, n-1, m),
                LCS(a, b, n, m-1)
            );
        }
    }

    bool isSubsequence(string a, string b) {
        memset(dp, -1, sizeof(dp));
        int lcs = LCS(a, b, a.size(), b.size());
        return lcs == a.size();
    }
};

/*
INTUITION:
Top-Down me hum LCS recursion se nikaalte hain
pattern aur text ke beech.

Agar poora pattern LCS me aa gaya
toh pattern subsequence hai.

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/

