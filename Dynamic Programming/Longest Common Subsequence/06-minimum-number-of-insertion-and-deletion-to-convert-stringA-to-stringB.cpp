/*
=====================================================
Minimum Insertions & Deletions to Convert String A to B
=====================================================

Problem Statement:
Tumhe do strings di gayi hain:
string a aur string b.

Tumhe:
- minimum number of INSERTIONS
- minimum number of DELETIONS
batani hain jisse string a ko string b me convert kiya ja sake.

Allowed operations:
- Insertion
- Deletion
(Replacement allowed nahi hai)

Input:
a = "heap"
b = "pea"

Output:
Deletions = 2
Insertions = 1

Explanation:
"heap"
delete 'h' → "eap"
delete 'e' → "ap"
insert 'p' at start → "pea"
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    pair<int,int> minInsertDelete(string a, string b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= m; j++)
            t[0][j] = 0;

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

        int lcs = t[n][m];

        int deletions  = n - lcs;
        int insertions = m - lcs;

        return {insertions, deletions};
    }
};

/*
INTUITION (Aditya Verma style):
Direct convert karna mushkil hota hai,
isliye pehle common part (LCS) nikaalte hain.

- Jo characters LCS me hain → wahi common rahenge
- a me jo extra hain → DELETE karne padenge
- b me jo missing hain → INSERT karne padenge

Formula:
Deletions  = len(a) - LCS
Insertions = len(b) - LCS

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

    pair<int,int> minInsertDelete(string a, string b) {
        memset(dp, -1, sizeof(dp));
        int lcs = LCS(a, b, a.size(), b.size());

        int deletions  = a.size() - lcs;
        int insertions = b.size() - lcs;

        return {insertions, deletions};
    }
};

/*
INTUITION:
Top-Down me hum LCS recursion se nikaalte hain,
har state (n, m) ko memo me store kar lete hain.

LCS milne ke baad:
- a se extra characters delete
- b ke missing characters insert

Time Complexity: O(n * m)
Space Complexity: O(n * m) + recursion stack
*/
