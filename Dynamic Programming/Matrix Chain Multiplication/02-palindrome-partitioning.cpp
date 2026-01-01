/* Palindrome Partitioning = Matrix Chain Multiplication + Palindrome Check

====================================================
Palindrome Partitioning (Minimum Cuts)
====================================================

Problem Statement:
Tumhe ek string s di gayi hai.

Tumhe string ko aise parts me todna hai
taaki har part ek PALINDROME ho.

Tumhara task:
- minimum number of cuts find karna
- jisse poori string palindrome substrings me split ho jaye.

Input:
s = "aab"

Output:
1

Explanation:
"aab" → "aa" | "b"
Sirf 1 cut chahiye.

Notes:
- Cut sirf characters ke beech lagta hai
- Already palindrome substring pe cut ki zarurat nahi
*/
// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[2001][2001];

    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int solve(string &s, int i, int j) {
        if(i >= j) return 0;

        if(isPalindrome(s, i, j)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int k = i; k < j; k++) {
            int temp =
                solve(s, i, k) +
                solve(s, k+1, j) +
                1;

            ans = min(ans, temp);
        }

        return dp[i][j] = ans;
    }

    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.length()-1);
    }
};

/*
INTUITION:
Same Matrix Chain Multiplication logic.

Decision:
"Last cut kahan lagana hai?"

Agar substring palindrome hai:
→ no cut needed

dp[i][j] = minimum cuts for s[i..j]

Base Case:
i >= j → 0 cuts

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.length();

        // dp[i] = minimum cuts needed for substring s[0..i]
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++) {
            if(isPalindrome(s, 0, i)) {
                dp[i] = 0;
            } else {
                int mini = INT_MAX;
                for(int j = 0; j < i; j++) {
                    if(isPalindrome(s, j+1, i)) {
                        mini = min(mini, dp[j] + 1);
                    }
                }
                dp[i] = mini;
            }
        }
        return dp[n-1];
    }
};

/*
INTUITION (Aditya Verma style):
Har index i pe socho:
"Last cut kahan laga?"

Agar s[j+1..i] palindrome hai,
toh cut j ke baad lag sakta hai.

dp[i] = min cuts to make s[0..i] palindrome parts

Base Case:
Agar s[0..i] already palindrome hai → 0 cuts

Time Complexity:
- Palindrome check: O(n)
- DP: O(n^2)
Total: O(n^3)

Space Complexity:
O(n)
*/
