/*
==============================
Rod Cutting Problem
==============================

Problem Statement:
Tumhe ek rod diya gaya hai jiska length = n.
Tumhe ek array "price[]" diya gaya hai,
jahan price[i] batata hai:
length (i+1) ke rod piece ka price.

Tum rod ko chaaho utni baar cut kar sakte ho,
aur ek hi length ka piece multiple times use kar sakte ho.

Task:
Rod ko cut karke maximum profit nikalna hai.

Input:
price = [1, 5, 8, 9, 10, 17, 17, 20]
n = 8

Output:
22

Explanation:
Best cut:
2 + 6 → price[1] + price[5] = 5 + 17 = 22
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int cutRod(vector<int>& price, int n) {

        // wt array banaya: rod ke possible lengths (1 to n)
        vector<int> wt(n);
        for(int i = 0; i < n; i++)
            wt[i] = i + 1;

        vector<vector<int>> t(n+1, vector<int>(n+1));

        // Initialization (step-by-step)
        // 0 items → profit 0
        for(int j = 0; j <= n; j++)
            t[0][j] = 0;

        // 0 rod length → profit 0
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        // Unbounded Knapsack filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        price[i-1] + t[i][j - wt[i-1]], // include (same piece again)
                        t[i-1][j]                       // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
};

/*
INTUITION (Aditya Verma style):
Rod cutting asal me Unbounded Knapsack hi hai.

Mapping:
- Rod length → Capacity
- Piece length → Weight
- Price → Value

Har piece ke saamne 2 choice:
1) Piece kaat lo:
   profit add hoga,
   rod length kam hogi,
   BUT piece same rahega (unlimited)
2) Piece mat lo:
   pichle pieces pe move karo

Isliye include case me:
t[i][j - wt[i-1]]  (same row)

Initialization kyu aisi hai?
- 0 rod length me koi profit nahi
- 0 pieces se koi profit nahi
Ye recursion ke base case ka table version hai.

Dry Run (short):
price = [2,5], n = 4
Best: 2 + 2 → 5 + 5 = 10

Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(int n, vector<int>& price, vector<int>& wt, int len) {
        // Base case
        if(n == 0 || len == 0) return 0;

        // Memoization check
        if(t[n][len] != -1) return t[n][len];

        // Choice diagram
        if(wt[n-1] <= len) {
            return t[n][len] = max(
                price[n-1] + solve(n, price, wt, len - wt[n-1]), // include (same piece)
                solve(n-1, price, wt, len)                       // exclude
            );
        } else {
            return t[n][len] = solve(n-1, price, wt, len);
        }
    }

    int cutRod(vector<int>& price, int n) {
        vector<int> wt(n);
        for(int i = 0; i < n; i++)
            wt[i] = i + 1;

        t.assign(n+1, vector<int>(n+1, -1));
        return solve(n, price, wt, n);
    }
};

/*
INTUITION:
Recursion me har rod piece ke liye sochte hain:
- Is length ka piece kaatun?
  → profit milega
  → rod length kam hogi
  → piece same rahega (unbounded)
- Ya is piece ko skip kar dun?

0/1 Knapsack se sirf ek difference:
Include case me n same rehta hai.

Dry Run (short):
n = 2, price = [2,5], len = 4
include 2 → 5 + solve(2,2)
include 2 → 5 + solve(2,0) = 10

Time Complexity: O(n * n)
Space Complexity: O(n * n) + recursion stack
*/
