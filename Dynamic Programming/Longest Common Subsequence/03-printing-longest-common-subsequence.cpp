/*
==============================
Print Longest Common Subsequence
==============================

Problem Statement:
Tumhe do strings di gayi hain:
s1 aur s2.

Tumhe:
1) Longest Common Subsequence ki length nikalni hai
2) Aur us actual LCS string ko PRINT karna hai

Subsequence:
- order same rahega
- continuous hona zaroori nahi

Input:
s1 = "abcde"
s2 = "ace"

Output:
LCS Length = 3
LCS String = "ace"
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    string printLCS(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization
        for(int i = 0; i <= n; i++) t[i][0] = 0;
        for(int j = 0; j <= m; j++) t[0][j] = 0;

        // LCS length DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // Backtracking to print LCS
        int i = n, j = m;
        string lcs = "";

        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                lcs.push_back(s1[i-1]);
                i--; j--;
            } else if(t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

/*
INTUITION (Aditya Verma style):
Pehle normal LCS ka DP table banao (length).

Phir last cell se peeche chalo:
- Agar characters match → answer ka part hai → diagonal move
- Agar match nahi:
    → jahan se LCS length aayi ho, wahi direction lo

Initialization kyu aisi hai?
- Empty string ke saath LCS possible nahi
- Isliye first row & column = 0

Dry Run (short):
s1 = "abcde", s2 = "ace"
e == e → add 'e'
c == c → add 'c'
a == a → add 'a'
Reverse → "ace"

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/


// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int lcsLen(string &s1, string &s2, int n, int m) {
        if(n == 0 || m == 0) return 0;
        if(t[n][m] != -1) return t[n][m];

        if(s1[n-1] == s2[m-1]) {
            return t[n][m] = 1 + lcsLen(s1, s2, n-1, m-1);
        } else {
            return t[n][m] = max(
                lcsLen(s1, s2, n-1, m),
                lcsLen(s1, s2, n, m-1)
            );
        }
    }

    string printLCS(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        t.assign(n+1, vector<int>(m+1, -1));

        // First compute LCS length table
        lcsLen(s1, s2, n, m);

        // Backtracking (same as bottom-up)
        int i = n, j = m;
        string lcs = "";

        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                lcs.push_back(s1[i-1]);
                i--; j--;
            } else if(t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

/*
INTUITION:
Top-Down me pehle LCS length nikalte hain
using recursion + memoization.

Uske baad same DP table ko use karke
peeche se traverse karke LCS print karte hain.

Important:
Printing LCS hamesha DP table ke bina mushkil hota hai,
isliye Bottom-Up zyada preferred hota hai interview me.

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/
