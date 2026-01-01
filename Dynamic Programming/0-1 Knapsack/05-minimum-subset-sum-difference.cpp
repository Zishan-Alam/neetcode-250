/*
==============================
4) Minimum Subset Sum Difference
==============================

Problem Statement:
Tumhe ek integer array diya gaya hai.
Is array ko 2 subsets me divide karna hai
aise ki dono subsets ke sums ka
absolute difference minimum ho.

Input:
nums = [1, 6, 11, 5]

Output:
1

Explanation:
Possible partition:
Subset1 = {1, 5, 6} → sum = 12
Subset2 = {11}      → sum = 11
Difference = |12 - 11| = 1 (minimum)
*/


// Bottom-Up DP (Tabulation)
class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;

        vector<vector<bool>> t(n+1, vector<bool>(sum+1));

        // Initialization (step-by-step)
        for(int j = 0; j <= sum; j++)
            t[0][j] = false;     // 0 elements se positive sum possible nahi

        for(int i = 0; i <= n; i++)
            t[i][0] = true;      // sum = 0 empty subset se ban jaata hai

        // Subset Sum DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {

                if(nums[i-1] <= j) {
                    // element lo ya skip
                    t[i][j] = t[i-1][j] || t[i-1][j - nums[i-1]];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        // Minimum difference find karna
        int mini = INT_MAX;
        for(int s1 = 0; s1 <= sum/2; s1++) {
            if(t[n][s1]) {
                mini = min(mini, sum - 2*s1);
            }
        }
        return mini;
    }
};

/*
INTUITION:
Is problem ko pehle Subset Sum me convert karte hain.
DP batata hai kaun-kaun se subset sums possible hain.
Do subsets ka difference = |totalSum - 2*s1|.
Best balance hamesha sum/2 ke aas-paas milta hai,
isliye sirf sum/2 tak check karte hain.
Jo s1 closest ho, wahi minimum difference deta hai.

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum)
*/

// Top-Down DP (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    bool solve(vector<int>& nums, int sum, int n) {

        // Base cases
        if(sum == 0) return true;
        if(n == 0) return false;

        // Memoization check
        if(t[n][sum] != -1) return t[n][sum];

        if(nums[n-1] <= sum) {
            return t[n][sum] =
                solve(nums, sum - nums[n-1], n-1) || // element lo
                solve(nums, sum, n-1);                // element skip
        }

        return t[n][sum] = solve(nums, sum, n-1);
    }

    int minDifference(vector<int>& nums) {

        int n = nums.size();
        int totalSum = 0;
        for(int x : nums) totalSum += x;

        t.assign(n+1, vector<int>(totalSum+1, -1));

        int mini = INT_MAX;
        for(int s1 = 0; s1 <= totalSum/2; s1++) {
            if(solve(nums, s1, n)) {
                mini = min(mini, totalSum - 2*s1);
            }
        }
        return mini;
    }
};

/*
INTUITION:
Recursive approach me hum check karte hain
kaun-kaun se subset sums possible hain.
Har element ke paas 2 choice hoti hai → lo ya skip.
Jo subset sum totalSum/2 ke closest ho,
wahi minimum subset difference deta hai.

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum) DP table
O(n) recursion stack
*/
