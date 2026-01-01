/*
===================================
Longest Palindromic Subsequence (LPS)
===================================

Problem Statement:
Tumhe ek string s di gayi hai.

Tumhe:
- us string ki Longest Palindromic Subsequence
  ki LENGTH nikalni hai.

Palindrome:
- jo aage se aur peeche se same ho

Subsequence:
- characters delete ho sakte hain
- order same rehna chahiye

Input:
s = "bbabcbcab"

Output:
7

Explanation:
Longest Palindromic Subsequence = "babcbab"
Length = 7
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> t(n+1, vector<int>(n+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= n; j++)
            t[0][j] = 0;

        // LCS of s and reverse(s)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == rev[j-1]) {
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
Palindrome ka matlab:
string aage se aur peeche se same ho.

Trick:
- string ka reverse le lo
- LCS(s, reverse(s)) nikaal lo

Jo characters dono me common subsequence banate hain,
wahi longest palindromic subsequence hoti hai.

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row & column = 0

Dry Run (idea):
s   = bbabcbcab
rev = bacbcbabb
LCS length = 7

Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[1001][1001];

    int LCS(string &s, string &rev, int n, int m) {
        if(n == 0 || m == 0)
            return 0;

        if(dp[n][m] != -1)
            return dp[n][m];

        if(s[n-1] == rev[m-1]) {
            return dp[n][m] = 1 + LCS(s, rev, n-1, m-1);
        } else {
            return dp[n][m] = max(
                LCS(s, rev, n-1, m),
                LCS(s, rev, n, m-1)
            );
        }
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        memset(dp, -1, sizeof(dp));
        return LCS(s, rev, s.size(), rev.size());
    }
};

/*
INTUITION:
Top-Down me hum recursion se LCS nikaalte hain
string aur uske reverse ke beech.

Har (n, m) state ko memoize kar lete hain
taaki repeat calculation na ho.

Palindrome ka logic same:
LPS = LCS(s, reverse(s))

Time Complexity: O(n * n)
Space Complexity: O(n * n) + recursion stack
*/
