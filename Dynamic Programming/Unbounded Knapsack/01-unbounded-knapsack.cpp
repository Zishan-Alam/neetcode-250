/*
==============================
Unbounded Knapsack Problem
==============================

Problem Statement:
Tumhe do arrays diye gaye hain:
1) wt[]  → items ke weights
2) val[] → items ke values
Aur ek integer W → knapsack ki capacity

Har item ko tum:
- include kar sakte ho
- ya exclude kar sakte ho
- aur IMPORTANT: ek item ko unlimited times use kar sakte ho

Task:
Maximum total value find karo
aise ki total weight <= W rahe.

Input:
wt  = [2, 4, 6]
val = [5, 11, 13]
W   = 10

Output:
27

Explanation:
2 weight wala item 5 value ka hai.
Isko 5 baar le sakte ho:
5 + 5 + 5 + 5 + 5 = 25
Better combination ban sakta hai using others → max = 27
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();

        vector<vector<int>> t(n+1, vector<int>(W+1));

        // Initialization (step-by-step)
        // i = 0 → no items → profit = 0
        for(int j = 0; j <= W; j++)
            t[0][j] = 0;

        // j = 0 → capacity 0 → profit = 0
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        // Table filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j) {
                    t[i][j] = max(
                        val[i-1] + t[i][j - wt[i-1]], // include (same item again)
                        t[i-1][j]                    // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
};

/*
INTUITION (Aditya Verma style):
Socho tum shop me ho aur items unlimited stock me hain.
Har item ke saamne choice hai:
1) Le lo → value add hogi, capacity kam hogi
           BUT item wahi rahega (unbounded)
2) Mat lo → pichle items pe chale jao

Isliye include case me:
  t[i][j - wt[i-1]]  (same row)

Initialization kyu aise hai?
- 0 items se koi bhi capacity ho → profit 0
- 0 capacity me kitne bhi items ho → profit 0
Ye recursion ke base cases ko table me convert karta hai.

Dry Run (short):
wt = [2], val = [5], W = 4
t[1][2] = max(5 + t[1][0], 0) = 5
t[1][4] = max(5 + t[1][2], 0) = 10

Time Complexity: O(n * W)
Space Complexity: O(n * W)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(int W, vector<int>& val, vector<int>& wt, int n) {
        // Base case
        if(n == 0 || W == 0) return 0;

        // Memoization check
        if(t[n][W] != -1) return t[n][W];

        // Choice diagram
        if(wt[n-1] <= W) {
            return t[n][W] = max(
                val[n-1] + solve(W - wt[n-1], val, wt, n), // include (n same)
                solve(W, val, wt, n-1)                     // exclude
            );
        } else {
            return t[n][W] = solve(W, val, wt, n-1);
        }
    }

    int unboundedKnapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        t.assign(n+1, vector<int>(W+1, -1));
        return solve(W, val, wt, n);
    }
};

/*
INTUITION:
Har item ke liye do choice:
- Include → capacity kam hoti hai, item same rehta hai
- Exclude → item count kam hota hai

Ye hi difference hai 0/1 aur Unbounded me:
Include case me n same rehta hai.

Dry Run (short):
wt = [2], val = [5], W = 4
solve(4,1):
 include → 5 + solve(2,1)
 include → 5 + solve(0,1) = 10
 exclude → solve(4,0) = 0

Time Complexity: O(n * W)
Space Complexity: O(n * W) + recursion stack
*/
