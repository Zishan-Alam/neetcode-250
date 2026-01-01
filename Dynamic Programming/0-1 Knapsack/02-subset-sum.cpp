// Bottom-Up DP (Tabulation)
class Solution {
public:
    bool SubsetSum(vector<int>& nums, int sum) {

        int n = nums.size();
        vector<vector<bool>> t(n+1, vector<bool>(sum+1));

        // Initialization
        for(int j = 0; j <= sum; j++)
            t[0][j] = false;

        for(int i = 0; i <= n; i++)
            t[i][0] = true;

        // DP fill
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {

                if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
};

/*
INTUITION:
DP table ko hum logically fill kar rahe hain.
Row 0 & Column 0 base cases ko represent karte hain.
Uske baad har cell me 2 choice hoti hai → element lo ya skip.

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
        if(sum == 0) return true;     // sum mil gaya
        if(n == 0) return false;      // items khatam

        // Memoization check
        if(t[n][sum] != -1) return t[n][sum];

        if(nums[n-1] <= sum) {
            return t[n][sum] =
                solve(nums, sum - nums[n-1], n-1) || // item lo
                solve(nums, sum, n-1);                // item skip
        }

        return t[n][sum] = solve(nums, sum, n-1);
    }

    bool SubsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        t.assign(n+1, vector<int>(sum+1, -1));
        return solve(nums, sum, n);
    }
};

/*
INTUITION:
Recursive soch: har element ke paas 2 choice → lo ya skip.
Agar sum 0 ho gaya → answer true (valid subset mil gaya).
Memoization ensure karta hai ki har (n,sum) state ek hi baar solve ho.

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum) DP table
O(n) recursion stack
*/
