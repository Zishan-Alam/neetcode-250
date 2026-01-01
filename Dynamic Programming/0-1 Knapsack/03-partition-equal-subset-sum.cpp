// Bottom-Up DP (Tabulation)
class Solution {
public:
    bool SubsetSum(vector<int>& nums, int sum) {

        int n = nums.size();
        vector<vector<bool>> t(n+1, vector<bool>(sum+1));

        // Initialization (step-by-step)
        for(int j = 0; j <= sum; j++)
            t[0][j] = false;   // 0 elements se positive sum possible nahi

        for(int i = 0; i <= n; i++)
            t[i][0] = true;    // sum = 0 hamesha possible (empty subset)

        // DP fill
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {

                if(nums[i-1] <= j) {
                    // element lo ya skip
                    t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
                } else {
                    // element le hi nahi sakte
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        for(int x : nums) totalSum += x;

        // Agar total sum odd hai to equal partition possible hi nahi
        if(totalSum % 2 != 0) return false;

        // Ab problem subset sum ban jaati hai (sum = totalSum/2)
        return SubsetSum(nums, totalSum / 2);
    }
};

/*
INTUITION:
Equal Sum Partition ka matlab hai array ko 2 subsets me baantna
jinka sum equal ho. Agar total sum odd hai to ye possible hi nahi.
Agar even hai, to sirf ye check karna hai ki kya koi subset
(totalSum/2) bana sakta hai.
Isliye ye problem direct Subset Sum pe reduce ho jaati hai.
Initialization:
t[0][j]=false → 0 elements se positive sum nahi ban sakta.
t[i][0]=true  → sum 0 empty subset se ban jaata hai.

TIME COMPLEXITY:
O(n * sum)  (yaha sum = totalSum/2)

SPACE COMPLEXITY:
O(n * sum)
*/

// Top-Down DP (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    bool solve(vector<int>& nums, int sum, int n) {

        // Base cases
        if(sum == 0) return true;   // subset mil gaya
        if(n == 0) return false;   // items khatam

        // Memoization check
        if(t[n][sum] != -1) return t[n][sum];

        if(nums[n-1] <= sum) {
            return t[n][sum] =
                solve(nums, sum - nums[n-1], n-1) || // element lo
                solve(nums, sum, n-1);                // element skip
        }

        return t[n][sum] = solve(nums, sum, n-1);
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        for(int x : nums) totalSum += x;

        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        t.assign(n+1, vector<int>(target+1, -1));
        return solve(nums, target, n);
    }
};

/*
INTUITION:
Recursive soch: har element ke paas 2 choice → lo ya skip.
Goal ye dekhna hai ki kya target = totalSum/2 ban sakta hai.
Base case aur memoization wahi hai jo bottom-up initialization
me logically dikh raha tha.

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum) DP table
O(n) recursion stack
*/
