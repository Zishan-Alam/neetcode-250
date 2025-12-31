class Solution {
public:
    int countSubsetsWithDiff(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;

        // Edge case
        if((sum + diff) % 2 != 0) return 0;

        int target = (sum + diff) / 2;

        // DP table
        vector<vector<int>> t(n+1, vector<int>(target+1, 0));

        // Initialization
        t[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
};


/*
Subset ko do parts me baantna hai jinka difference diff ho.

Math se humne prove kiya:
s1 = (sum + diff)/2

Ab bas ye count karna hai:
kitne subsets ka sum exactly s1 ban raha hai.

DP me:
t[i][j] = number of subsets using first i elements
          j sum banane ke liye
*/


// Time Complexity: O(n * target)
// Space Complexity: O(n * target)
