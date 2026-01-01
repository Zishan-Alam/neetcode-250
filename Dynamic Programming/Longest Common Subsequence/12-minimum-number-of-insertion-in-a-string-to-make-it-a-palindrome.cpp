/*
====================================================
Minimum Insertions to Make a String Palindrome
====================================================

Problem Statement:
Tumhe ek string s di gayi hai.

Tumhe:
- minimum number of INSERTIONS nikalni hain
  jisse string palindrome ban jaaye.

Allowed operation:
- Sirf insertion (deletion / replace allowed nahi)

Input:
s = "abcd"

Output:
3

Explanation:
Ek palindrome ho sakti hai: "abcdcba"
Minimum insertions = 3
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> t(n+1, vector<int>(n+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++) t[i][0] = 0;
        for(int j = 0; j <= n; j++) t[0][j] = 0;

        // LCS DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == rev[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int lps = t[n][n];
        return n - lps;
    }
};

/*
INTUITION (Aditya Verma style):
Palindrome banane ke liye
string ka sabse lamba palindromic part rakhna best hota hai.

Longest Palindromic Subsequence (LPS):
- jo already palindrome hai
- usko insert karne ki zarurat nahi
- this question is same as minimum number of deletions to make a string palindrome

Baaki characters ke mirror insert kar do.

Formula:
Min Insertions = len(s) - LPS

Aur:
LPS = LCS(s, reverse(s))

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row aur column = 0

Dry Run:
s = "abcd"
LPS = "a" (length = 1)
Insertions = 4 - 1 = 3

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

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        memset(dp, -1, sizeof(dp));
        int lps = LCS(s, rev, s.size(), rev.size());
        return s.size() - lps;
    }
};

/*
INTUITION:
Top-Down me hum recursion se LCS nikaalte hain
string aur uske reverse ke beech.

Jo LCS milta hai wahi LPS hota hai.

Baaki characters ke liye mirror insertions chahiye,
isliye answer = len(s) - LPS

Time Complexity: O(n * n)
Space Complexity: O(n * n) + recursion stack
*/

