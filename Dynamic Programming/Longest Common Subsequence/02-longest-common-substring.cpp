/*
==============================
Longest Common Substring
==============================

Problem Statement:
Tumhe do strings di gayi hain:
s1 aur s2.

Tumhe longest length find karni hai
aise substring ki jo:
- dono strings me common ho
- order same ho
- aur CONTIGUOUS (continuous) ho

Substring ka matlab:
characters lagataar hone chahiye,
beech me gap allowed nahi hai.

Input:
s1 = "abcde"
s2 = "abfce"

Output:
2

Explanation:
Longest common substring = "ab"
Length = 2
*/
// Bottom-Up (Tabulation)
class Solution {
public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        // Agar koi bhi string empty ho,
        // to common substring possible nahi
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        for(int j = 0; j <= m; j++)
            t[0][j] = 0;

        int ans = 0;

        // DP filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    // characters match → extend substring
                    t[i][j] = 1 + t[i-1][j-1];
                    ans = max(ans, t[i][j]);
                } else {
                    // mismatch → substring break ho jata hai
                    t[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

/*
INTUITION (Aditya Verma style):
Substring ka rule strict hota hai:
jaise hi mismatch hua,
current substring turant break ho jaata hai.

Isliye:
- Match → diagonal se +1
- Mismatch → 0 se reset

Initialization kyu aisi hai?
- Empty string ke saath koi substring possible nahi
- Isliye pehli row aur column = 0

Dry Run (short):
s1 = "abc", s2 = "ab"
a == a → 1
b == b → 2
c != ? → reset to 0
Answer = 2

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/
// Top-Down (Recursion + Memoization - Conceptual)
class Solution {
public:
    int ans = 0;
    vector<vector<int>> t;

    int solve(string &s1, string &s2, int i, int j) {
        if(i == 0 || j == 0)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        if(s1[i-1] == s2[j-1]) {
            t[i][j] = 1 + solve(s1, s2, i-1, j-1);
            ans = max(ans, t[i][j]);
        } else {
            t[i][j] = 0; // mismatch → reset
        }

        // Important:
        // baaki combinations explore karne ke liye
        solve(s1, s2, i-1, j);
        solve(s1, s2, i, j-1);

        return t[i][j];
    }

    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        t.assign(n+1, vector<int>(m+1, -1));
        solve(s1, s2, n, m);
        return ans;
    }
};

/*
INTUITION:
Substring continuous hona chahiye,
isliye mismatch pe turant chain toot jaati hai → 0.

Unlike LCS:
- yahan max(t[i-1][j], t[i][j-1]) nahi le sakte
- kyunki continuity break ho chuki hoti hai

Isi wajah se:
Bottom-Up approach sabse clean aur preferred hai.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/


//⚠️ Important Note
//Longest Common Substring Top-Down recursion se naturally suit nahi karta,
//kyunki mismatch pe hume substring ko reset (0) karna padta hai
//aur recursion overlapping states effectively reuse nahi kar paata.
