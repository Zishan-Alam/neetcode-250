/*
==============================
Longest Common Subsequence (LCS)
==============================

Problem Statement:
Tumhe do strings di gayi hain:
text1 aur text2.

Tumhe longest length find karni hai
aise sequence ki jo:
- dono strings me common ho
- order same rahe
- BUT continuous hona zaroori nahi hai

Subsequence ka matlab:
characters skip ho sakte hain,
par order maintain rehna chahiye.

Input:
text1 = "abcde"
text2 = "ace"

Output:
3

Explanation:
Common subsequence = "ace"
Length = 3
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        // Agar ek bhi string empty ho,
        // to LCS length = 0
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        for(int j = 0; j <= m; j++)
            t[0][j] = 0;

        // DP filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    // characters match
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    // characters mismatch
                    t[i][j] = max(
                        t[i-1][j],   // text1 ka char skip
                        t[i][j-1]    // text2 ka char skip
                    );
                }
            }
        }
        return t[n][m];
    }
};

/*
INTUITION (Aditya Verma style):
Socho tum dono strings ko left se right compare kar rahe ho.

Har character pe 2 cases:
1) Match ho gaya:
   → dono strings ka character use kar lo
   → answer +1
2) Match nahi hua:
   → ek string ka character skip karo
   → jo maximum LCS de, wahi lo

Initialization kyu aisi hai?
- Agar ek string hi empty hai,
  to common subsequence possible hi nahi
  isliye answer = 0

Dry Run (short):
text1 = "abc", text2 = "ac"
a == a → 1
b != c → max(skip b, skip c)
c == c → +1
Answer = 2

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(string &s1, string &s2, int n, int m) {
        // Base case
        if(n == 0 || m == 0)
            return 0;

        // Memoization check
        if(t[n][m] != -1)
            return t[n][m];

        // Choice diagram
        if(s1[n-1] == s2[m-1]) {
            return t[n][m] =
                1 + solve(s1, s2, n-1, m-1);
        } else {
            return t[n][m] = max(
                solve(s1, s2, n-1, m),
                solve(s1, s2, n, m-1)
            );
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        t.assign(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, n, m);
    }
};

/*
INTUITION:
Recursion me hum last characters ko compare karte hain.

Agar last characters same hain:
→ dono ko include karo
→ n-1, m-1 pe chale jao

Agar different hain:
→ ya to first string ka last char skip
→ ya second string ka last char skip
→ jo maximum answer de, wahi lo

Base case:
Jaise hi koi string empty ho jaaye,
LCS possible nahi → return 0

Dry Run (short):
"abc" & "ac"
solve(3,2):
c == c → 1 + solve(2,1)
b != a → max(solve(1,1), solve(2,0))
Answer = 2

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/
