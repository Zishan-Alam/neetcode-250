class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;

        // DP table: t[i][j] = can we form sum j using first i elements
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

        // Initialization
        for(int i = 0; i <= n; i++)
            t[i][0] = true;

        // Subset Sum DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j] || t[i-1][j - nums[i-1]];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        // Find minimum difference
        int mini = INT_MAX;
        for(int s1 = 0; s1 <= sum/2; s1++) {
            if(t[n][s1] == true) {            // last row of dp table
                mini = min(mini, sum - 2*s1);
            }
        }
        return mini;
    }
};


/*
Hum pehle Subset Sum DP bana lete hain.
DP batata hai kaun-kaun se subset sums possible hain.

Phir hum sirf sum/2 tak check karte hain,
kyunki wahi best balance point hota hai.

Jo s1 sum/2 ke sabse paas hota hai,
uska difference = |totalSum - 2*s1|
minimum ho jaata hai.
*/

// Time Complexity: O(n * sum)
// Space Complexity: O(n * sum)

