/*Matrix Chain Multiplication → "Last Cut kahan lagana hai?"

====================================================
Matrix Chain Multiplication (Minimum Cost)
====================================================

Problem Statement:
Tumhe matrices ki ek chain di gayi hai.

Agar:
A1 = p0 x p1
A2 = p1 x p2
A3 = p2 x p3
...
An = p(n-1) x pn

Toh tumhe ek array arr diya hoga:
arr[] = {p0, p1, p2, ..., pn}

Tumhara task:
- matrices ko aise parenthesize karna hai
- taaki total scalar multiplications MINIMUM ho.

NOTE:
Sirf multiplication order change kar sakte ho,
matrices ka order nahi.

Input:
arr = {40, 20, 30, 10, 30}

Output:
26000

Explanation:
Optimal parenthesization:
((A1 x (A2 x A3)) x A4)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, vector<int>& arr) {
        if(i >= j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k = i; k < j; k++) {
            int cost =
                solve(i, k, arr) +
                solve(k+1, j, arr) +
                arr[i-1] * arr[k] * arr[j];

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        return solve(1, n-1, arr);
    }
};

/*
INTUITION:
Har recursive call ek matrix chain ka answer deta hai.

Decision:
Last multiplication k kis point pe hogi?

Memoization:
Same (i, j) baar-baar calculate na ho,
isliye dp use kiya.

Base Case:
i >= j → single matrix → cost 0

Time Complexity: O(n^3)
Space Complexity: O(n^2) + recursion stack
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();

        // dp[i][j] = minimum cost to multiply matrices from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length = 2 se start (single matrix ka cost 0 hota hai)
        for(int len = 2; len < n; len++) {
            for(int i = 1; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for(int k = i; k < j; k++) {
                    int cost =
                        dp[i][k] +
                        dp[k+1][j] +
                        arr[i-1] * arr[k] * arr[j];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
    }
};

/*
INTUITION (Aditya Verma style):
Matrix chain me main decision hota hai:
"Last multiplication kahan karni hai?"

k ko try karte hain:
(i..k) x (k+1..j)

Cost = 
left part ka cost +
right part ka cost +
last multiplication cost

last multiplication:
(arr[i-1] x arr[k]) * (arr[k] x arr[j])
= arr[i-1] * arr[k] * arr[j]

Base Case:
Single matrix → cost = 0

DP Meaning:
dp[i][j] = min cost to multiply matrices i to j

Why Bottom-Up?
Chhote subproblems pehle solve,
phir bade windows.

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
