/*
==============================
Print Longest Common Substring
==============================

Problem Statement:
Tumhe do strings di gayi hain:
s1 aur s2.

Tumhe:
1) Longest Common Substring ki length
2) Aur us actual substring ko PRINT karna hai

Substring ka matlab:
- dono strings me common ho
- order same ho
- CONTIGUOUS (continuous) ho

Input:
s1 = "abcde"
s2 = "abfce"

Output:
Length = 2
Substring = "ab"
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    string printLongestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        // Initialization (step-by-step)
        for(int i = 0; i <= n; i++) t[i][0] = 0;
        for(int j = 0; j <= m; j++) t[0][j] = 0;

        int maxLen = 0;
        int endIndex = -1; // s1 me substring ka end index

        // DP filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];

                    // max update
                    if(t[i][j] > maxLen) {
                        maxLen = t[i][j];
                        endIndex = i - 1; // s1 ka index
                    }
                } else {
                    // mismatch → substring break
                    t[i][j] = 0;
                }
            }
        }

        // substring extract
        if(maxLen == 0) return "";

        return s1.substr(endIndex - maxLen + 1, maxLen);
    }
};

/*
INTUITION (Aditya Verma style):
Substring continuous hota hai,
jaise hi mismatch aaya → chain toot jaati hai.

Isliye:
- Match → diagonal se +1
- Mismatch → 0 se reset

Printing ka logic:
Jab bhi naya maximum mile:
- us time ka end index store kar lo
Baad me:
endIndex se peeche maxLen characters uthao

Initialization kyu aisi hai?
- Empty string ke saath substring possible nahi
- First row & column = 0

Dry Run (short):
s1 = "abcd", s2 = "abxd"
a == a → 1
b == b → 2 (max)
c != x → reset
Substring = "ab"

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

/*
Top-Down (Recursion + Memoization) approach
Longest Common Substring ke liye recommended nahi hai.

Reason:
- Substring me mismatch aate hi value 0 ho jaati hai
- Recursion naturally overlapping subproblems
  efficiently reuse nahi kar paata
- Printing ke liye end-index tracking messy ho jaata hai

Isliye interview + practice dono me:
👉 Bottom-Up approach hi preferred hai
*/
