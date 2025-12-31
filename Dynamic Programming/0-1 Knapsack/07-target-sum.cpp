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

        // DP table
        vector<vector<int>> t(n+1, vector<int>(s1+1, 0));

        // Initialization
        t[0][0] = 1;

        // Count Subset Sum DP
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= s1; j++) {
                if(nums[i-1] <= j) {
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
Har number ke aage + ya - lagana hai.
Iska matlab array ko do subsets me baant rahe ho.

Math se nikalta hai:
s1 = (target + totalSum) / 2

Ab sirf ye count karna hai:
kitne subsets ka sum exactly s1 ban raha hai.

DP me:
t[i][j] = first i elements se
          sum j banane ke total ways
*/


// Time Complexity: O(n * s1)
// Space Complexity: O(n * s1)
