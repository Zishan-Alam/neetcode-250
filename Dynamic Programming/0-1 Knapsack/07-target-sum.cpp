/*
==============================
6) Target Sum
(LeetCode 494)
==============================

Problem Statement:
Tumhe ek array diya gaya hai.
Har element ke aage ya to '+' lagana hai
ya '-' lagana hai.

Batana hai kitne different ways me
expression ka result exactly "target" ban sakta hai.

Input:
nums = [1,1,1,1,1]
target = 3

Output:
5

Explanation:
+1 -1 +1 +1 +1 = 3
+1 +1 -1 +1 +1 = 3
+1 +1 +1 -1 +1 = 3
+1 +1 +1 +1 -1 = 3
-1 +1 +1 +1 +1 = 3
*/


// Bottom-Up DP (Tabulation)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;

        // Edge cases
        if(abs(target) > sum) return 0;
        if((sum + target) % 2 != 0) return 0;

        int s1 = (sum + target) / 2;

        vector<vector<int>> t(n+1, vector<int>(s1+1));

        // Initialization (step-by-step)
        for(int j = 0; j <= s1; j++)
            t[0][j] = 0;      // 0 elements se positive sum ke 0 ways

        for(int i = 0; i <= n; i++)
            t[i][0] = 1;      // sum = 0 ka 1 way (empty subset)

        // Count Subset Sum DP
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= s1; j++) {

                if(nums[i-1] <= j) {
                    // '+' group me lo + '-' group me bhejo (skip)
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][s1];
    }
};

/*
INTUITION:
Har number ke aage + ya - lagana hai.
Iska matlab array ko 2 subsets me baant rahe ho:
s1 - s2 = target
s1 + s2 = totalSum
Solve karne pe milta hai:
s1 = (totalSum + target) / 2
Agar abs(target) > totalSum ya (sum+target) odd ho,
to solution possible hi nahi.
Ab problem reduce ho jaati hai:
"Count Subset with Given Sum = s1".

TIME COMPLEXITY:
O(n * s1)

SPACE COMPLEXITY:
O(n * s1)
*/

// Top-Down DP (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(vector<int>& nums, int sum, int n) {

        // Base cases
        if(sum == 0) return 1;   // sum 0 banane ka 1 way
        if(n == 0) return 0;     // items khatam, sum positive → 0 ways

        // Memoization check
        if(t[n][sum] != -1) return t[n][sum];

        if(nums[n-1] <= sum) {
            return t[n][sum] =
                solve(nums, sum - nums[n-1], n-1) + // '+' group
                solve(nums, sum, n-1);               // '-' group
        }

        return t[n][sum] = solve(nums, sum, n-1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totalSum = 0;
        for(int x : nums) totalSum += x;

        if(abs(target) > totalSum) return 0;
        if((totalSum + target) % 2 != 0) return 0;

        int s1 = (totalSum + target) / 2;
        t.assign(n+1, vector<int>(s1+1, -1));

        return solve(nums, s1, n);
    }
};

/*
INTUITION:
Recursive soch: har element ke paas 2 choice → '+' ya '-'.
Math ke through problem Count Subset Sum me reduce hoti hai.
Har valid path jo target sum banata hai,
uska count add hota jaata hai.
Memoization overlapping states ko avoid karta hai.

TIME COMPLEXITY:
O(n * s1)

SPACE COMPLEXITY:
O(n * s1) DP table
O(n) recursion stack
*/
