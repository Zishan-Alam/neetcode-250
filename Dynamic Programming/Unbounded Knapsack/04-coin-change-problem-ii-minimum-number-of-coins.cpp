/*
==============================
Coin Change – Minimum Coins
==============================

Problem Statement:
Tumhe ek integer array "coins[]" diya gaya hai,
jisme har coin ki value di hoti hai.
Aur ek integer "amount" diya gaya hai.

Har coin ko tum:
- unlimited times use kar sakte ho

Task:
Minimum number of coins find karo
jinse tum exactly "amount" bana sako.

Agar amount banana possible hi nahi ho,
to -1 return karo.

Input:
coins = [1, 2, 5]
amount = 11

Output:
3

Explanation:
Best way:
5 + 5 + 1 = 11
Total coins = 3
*/

// Bottom-Up (Tabulation)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9;

        vector<vector<int>> t(n+1, vector<int>(amount+1));

        // Initialization (step-by-step)
        // Sum = 0 banane ke liye 0 coins chahiye
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        // 0 coins se positive amount banana impossible
        for(int j = 1; j <= amount; j++)
            t[0][j] = INF;

        // DP filling
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(
                        1 + t[i][j - coins[i-1]], // include (same coin again)
                        t[i-1][j]                  // exclude
                    );
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return (t[n][amount] >= INF) ? -1 : t[n][amount];
    }
};

/*
INTUITION (Aditya Verma style):
Ye bhi Unbounded Knapsack hai,
par yahan MAX ya COUNT nahi,
yahan MIN chahiye.

Har coin ke liye choice:
1) Coin le lo:
   - 1 coin count add hoga
   - amount kam hoga
   - coin same rahega (unlimited)
2) Coin skip karo:
   - pichle coins pe chale jao

Isliye include case me:
1 + t[i][j - coins[i-1]]

Initialization kyu aisi hai?
- Amount = 0 → 0 coins chahiye
- 0 coins se positive amount → impossible (INF)
INF ka matlab: "ye state reachable nahi hai"

Dry Run (short):
coins = [1,2], amount = 3
Best:
1+1+1 → 3 coins
1+2   → 2 coins (minimum)

Time Complexity: O(n * amount)
Space Complexity: O(n * amount)
*/

// Top-Down (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;
    int INF = 1e9;

    int solve(int amount, vector<int>& coins, int n) {
        // Base cases
        if(amount == 0) return 0;   // 0 coins needed
        if(n == 0) return INF;      // coins khatam, amount abhi baaki

        // Memoization check
        if(t[n][amount] != -1) return t[n][amount];

        // Choice diagram
        if(coins[n-1] <= amount) {
            return t[n][amount] = min(
                1 + solve(amount - coins[n-1], coins, n), // include
                solve(amount, coins, n-1)                  // exclude
            );
        } else {
            return t[n][amount] = solve(amount, coins, n-1);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        t.assign(n+1, vector<int>(amount+1, -1));

        int ans = solve(amount, coins, n);
        return (ans >= INF) ? -1 : ans;
    }
};

/*
INTUITION:
Recursion me har coin ke liye sochte hain:
- Is coin ko use karun?
  → 1 coin add hoga
  → amount kam hoga
  → coin same rahega
- Ya is coin ko skip kar dun?

amount == 0 ka matlab:
exact amount ban chuka hai → return 0

n == 0 aur amount > 0:
possible nahi → INF return

Dry Run (short):
coins = [1,2], amount = 3
include 2 → 1 + solve(1)
include 1 → 1 + solve(0)
Total coins = 2

Time Complexity: O(n * amount)
Space Complexity: O(n * amount) + recursion stack
*/
