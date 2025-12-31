// Same as subset sum bas isme BITWISE OR ki jagah "+" use hua hai, and change of return type from bool to int.

class Solution {
public:
    int countSum(vector<int>& nums, int sum) {
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(sum+1));

        //Initializing 
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<sum+1; j++) {
                if(i == 0) t[i][j] = 0;
                if(j == 0) t[i][j] = 1;
            }
        }

        for(int i=1; i<n+1; i++) {
            for(int j=1; j<sum+1; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};

// Time: O(n * sum)
// Space: O(n * sum)

