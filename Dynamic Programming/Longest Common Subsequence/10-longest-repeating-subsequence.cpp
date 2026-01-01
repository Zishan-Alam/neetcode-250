/*LRS = LCS(s, s) with i != j

=========================================
Longest Repeating Subsequence (LRS)
=========================================

Problem Statement:
Tumhe ek string s di gayi hai.

Tumhe:
- us string ki Longest Repeating Subsequence
  ki LENGTH nikalni hai.

Repeating Subsequence:
- same subsequence kam se kam 2 baar aaye
- same index use nahi kar sakte

Input:
s = "aabebcdd"

Output:
3

Explanation:
Longest Repeating Subsequence = "abd"
Length = 3
*/
// Bottom-Up (Tabulation)
class Solution {
public:
    int LongestRepeatingSubsequence(string s) {
        int n = s.size();

        vector<vector<int>> t(n+1, vector<int>(n+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= n; j++)
            t[0][j] = 0;

        // LCS logic with index check (i != j)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == s[j-1] && i != j) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[n][n];
    }
};

/*
INTUITION (Aditya Verma style):
Repeating subsequence ka matlab:
same pattern do baar aaye
but same index reuse na ho.

Trick:
- String ko khud ke saath LCS me daal do
- Bas ek condition add karo: i != j

Agar:
s[i-1] == s[j-1] AND i != j
→ character repeat ho sakta hai

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row & column = 0

Dry Run (idea):
s = "aabebcdd"
LCS(s, s) with i!=j → "abd"
length = 3

Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/


// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[1001][1001];

    int solve(string &s, int i, int j) {
        if(i == 0 || j == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i-1] == s[j-1] && i != j) {
            return dp[i][j] = 1 + solve(s, i-1, j-1);
        } else {
            return dp[i][j] = max(
                solve(s, i-1, j),
                solve(s, i, j-1)
            );
        }
    }

    int LongestRepeatingSubsequence(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, s.size(), s.size());
    }
};

/*
INTUITION:
Top-Down me hum same string ke
do pointers (i, j) se LCS nikaalte hain.

Extra condition:
i != j
taaki same index reuse na ho.

Jo longest common part milta hai,
wahi longest repeating subsequence hoti hai.

Time Complexity: O(n * n)
Space Complexity: O(n * n) + recursion stack
*/
