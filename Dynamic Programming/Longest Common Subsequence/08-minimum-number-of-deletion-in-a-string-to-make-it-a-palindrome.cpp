/*
====================================================
Minimum Deletions to Make a String Palindrome
====================================================

Problem Statement:
Tumhe ek string s di gayi hai.

Tumhe:
- minimum number of DELETIONS nikalni hain
  jisse string palindrome ban jaaye.

Allowed operation:
- Sirf deletion (insert / replace allowed nahi)

Input:
s = "agbcbda"

Output:
2

Explanation:
Longest Palindromic Subsequence = "abcba" (length = 5)
Original length = 7

Deletions = 7 - 5 = 2
*/
// Bottom-Up (Tabulation)
class Solution {
public:
    int minDeletions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> t(n+1, vector<int>(n+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= n; j++)
            t[0][j] = 0;

        // LCS DP (s vs reverse(s))
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
- usko delete nahi karna

Baaki characters delete kar do.

Formula:
Min Deletions = len(s) - LPS

Aur:
LPS = LCS(s, reverse(s))

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row aur column = 0

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

    int minDeletions(string s) {
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

Baaki characters delete kar dena hi
minimum deletions hota hai.

Time Complexity: O(n * n)
Space Complexity: O(n * n) + recursion stack
*/
