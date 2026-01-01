/*
==========================================
Print Shortest Common Supersequence (SCS)
==========================================

Problem Statement:
Tumhe do strings di gayi hain:
string s1 aur string s2.

Tumhe:
- unki Shortest Common Supersequence PRINT karni hai.

Supersequence:
- s1 aur s2 dono iske subsequence hone chahiye
- order same rehna chahiye
- length minimum honi chahiye

Input:
s1 = "abac"
s2 = "cab"

Output:
"cabac"

Explanation:
"cabac" me:
- "abac" subsequence hai
- "cab" subsequence hai
aur length minimum hai.
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
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

        // Backtracking to build SCS
        int i = n, j = m;
        string ans = "";

        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            } 
            else if(t[i-1][j] > t[i][j-1]) {
                ans.push_back(s1[i-1]);
                i--;
            } 
            else {
                ans.push_back(s2[j-1]);
                j--;
            }
        }

        // Remaining characters
        while(i > 0) {
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j > 0) {
            ans.push_back(s2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
INTUITION (Aditya Verma style):
SCS directly banana mushkil hota hai,
isliye pehle LCS nikaalte hain.

Backtracking idea:
- Agar characters same hain → ek hi baar add karo
- Agar different hain:
    → jis side LCS bada ho, us side ka character add karo

End me:
- jo characters bach jaate hain, unko bhi add kar do

Initialization kyu?
- Empty string ke saath LCS = 0
- Isliye first row aur column = 0

Dry Run (idea):
s1 = "abac"
s2 = "cab"

LCS = "ab"
Backtracking se: "cabac"

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

    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        LCS(s1, s2, s1.size(), s2.size());

        int i = s1.size(), j = s2.size();
        string ans = "";

        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans.push_back(s1[i-1]);
                i--;
            }
            else {
                ans.push_back(s2[j-1]);
                j--;
            }
        }

        while(i > 0) {
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j > 0) {
            ans.push_back(s2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
INTUITION:
Top-Down me hum pehle LCS recursion se nikaalte hain
aur dp table fill ho jaata hai.

Phir same Bottom-Up jaisa backtracking karte hain
dp table ki help se SCS build karne ke liye.

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/
