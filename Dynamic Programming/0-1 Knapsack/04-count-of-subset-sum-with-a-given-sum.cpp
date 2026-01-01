// Bottom-Up DP (Tabulation)
class Solution {
public:
    int countSum(vector<int>& nums, int sum) {

        int n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1));

        // Initialization (step-by-step)
        for(int j = 0; j <= sum; j++)
            t[0][j] = 0;      // 0 elements se positive sum banane ke 0 ways

        for(int i = 0; i <= n; i++)
            t[i][0] = 1;      // sum = 0 banane ka 1 way (empty subset)

        // DP fill
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {

                if(nums[i-1] <= j) {
                    // element lo (ways add karo) + element skip
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                } else {
                    // element le hi nahi sakte
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};

/*
INTUITION:
Ye Subset Sum ka counting version hai.
t[i][j] batata hai ki first i elements se sum j
kitne tareeko (ways) se ban sakta hai.
Boolean OR ki jagah '+' isliye use hota hai
kyunki hume existence nahi, total count chahiye.
Initialization:
t[0][j]=0 → 0 elements se positive sum ke 0 ways.
t[i][0]=1 → sum 0 ka sirf 1 way (empty subset).

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum)
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
                solve(nums, sum - nums[n-1], n-1) + // element lo
                solve(nums, sum, n-1);               // element skip
        }

        return t[n][sum] = solve(nums, sum, n-1);
    }

    int countSum(vector<int>& nums, int sum) {
        int n = nums.size();
        t.assign(n+1, vector<int>(sum+1, -1));
        return solve(nums, sum, n);
    }
};

/*
INTUITION:
Recursive soch: har element ke paas 2 choice → lo ya skip.
Difference sirf itna hai ki yaha boolean nahi,
har valid path ka count add kar rahe hain.
Base case wahi hai jo bottom-up initialization
me logically represent hota hai.

TIME COMPLEXITY:
O(n * sum)

SPACE COMPLEXITY:
O(n * sum) DP table
O(n) recursion stack
*/
