/*
==============================
Coin Change – Number of Ways
==============================

Problem Statement:
Tumhe ek integer array "coins[]" diya gaya hai,
jisme har coin ki value di hoti hai.
Aur ek integer "amount" diya gaya hai.

Har coin ko tum:
- unlimited times use kar sakte ho

Task:
Batana hai total kitne different ways hain
jinse tum "amount" bana sakte ho.

Order matter nahi karta
(1+2 aur 2+1 same way maana jayega).

Input:
coins = [1, 2, 5]
amount = 5

Output:
4

Explanation:
Possible ways:
1+1+1+1+1
1+1+1+2
1+2+2
5
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> t(n+1, vector<int>(amount+1));

        // Initialization (step-by-step)
        // Sum = 0 banane ka 1 hi way hota hai → kuch mat lo
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;

        // 0 coins se positive sum nahi ban sakta
        for(int j = 1; j <= amount; j++)
            t[0][j] = 0;

        // DP filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] =
                        t[i][j - coins[i-1]]   // include (same coin again)
                      + t[i-1][j];              // exclude
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
};

/*
INTUITION (Aditya Verma style):
Yahan goal MAX ya MIN nahi hai,
yahan bas COUNT karna hai → kitne tareeke possible hain.

Har coin ke saamne 2 choice:
1) Coin use karo:
   sum kam ho jaayega,
   coin same rahega (unbounded)
2) Coin skip karo:
   pichle coins pe chale jao

Isliye + use hota hai (ways add hote hain),
max nahi.

Initialization kyu aisi hai?
- Sum = 0 hamesha 1 way se banta hai (empty set)
- 0 coins se koi positive sum nahi ban sakta

Dry Run (short):
coins = [1,2], amount = 3
Ways:
1+1+1
1+2
Total = 2

Time Complexity: O(n * amount)
Space Complexity: O(n * amount)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(int amount, vector<int>& coins, int n) {
        // Base cases
        if(amount == 0) return 1;   // ek valid way mil gaya
        if(n == 0) return 0;        // coins khatam, sum abhi baaki

        // Memoization check
        if(t[n][amount] != -1) return t[n][amount];

        // Choice diagram
        if(coins[n-1] <= amount) {
            return t[n][amount] =
                solve(amount - coins[n-1], coins, n)   // include (same coin)
              + solve(amount, coins, n-1);              // exclude
        } else {
            return t[n][amount] = solve(amount, coins, n-1);
        }
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        t.assign(n+1, vector<int>(amount+1, -1));
        return solve(amount, coins, n);
    }
};

/*
INTUITION:
Recursion me har coin ke liye sochte hain:
- Coin use karo → amount kam, coin same
- Coin mat use karo → next coin pe move

amount == 0 ka matlab:
ek valid combination ban chuki hai → return 1

Yahi difference hai:
0/1 knapsack vs Coin Change
Include case me n same rehta hai (unbounded).

Dry Run (short):
coins = [1,2], amount = 3
solve(3):
 include 1 → solve(2)
 include 2 → solve(1)
 exclude → etc
Total ways = 2

Time Complexity: O(n * amount)
Space Complexity: O(n * amount) + recursion stack
*/
