// Bottom-Up DP (Tabulation)
class Solution {
public:
    int countSubsetsWithDiff(vector<int>& arr, int diff) {

        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;

        // Edge case: agar (sum + diff) odd hai to possible nahi
        if((sum + diff) % 2 != 0) return 0;

        int target = (sum + diff) / 2;

        vector<vector<int>> t(n+1, vector<int>(target+1));

        // Initialization (step-by-step)
        for(int j = 0; j <= target; j++)
            t[0][j] = 0;        // 0 elements se positive sum ke 0 ways

        for(int i = 0; i <= n; i++)
            t[i][0] = 1;        // sum = 0 banane ka 1 way (empty subset)

        // DP fill (Count Subset Sum)
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {

                if(arr[i-1] <= j) {
                    // element lo + element skip (count add hota hai)
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
                } else {
                    // element le hi nahi sakte
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
};

/*
INTUITION:
Array ko do subsets me baantna hai jinka difference = diff ho.
Let s1 - s2 = diff
Aur s1 + s2 = totalSum
Solve karne pe milta hai:
s1 = (totalSum + diff) / 2
Agar (sum + diff) odd ho, to integer s1 possible hi nahi.
Isliye problem reduce ho jaati hai:
"Count Subsets with Given Sum = s1".
Boolean OR ki jagah '+' use hota hai
kyunki hume existence nahi, number of ways chahiye.

TIME COMPLEXITY:
O(n * target)

SPACE COMPLEXITY:
O(n * target)
*/

// Top-Down DP (Recursion + Memoization)
class Solution {
public:
    vector<vector<int>> t;

    int solve(vector<int>& arr, int sum, int n) {

        // Base cases
        if(sum == 0) return 1;    // sum 0 banane ka 1 way
        if(n == 0) return 0;      // items khatam, sum positive → 0 ways

        // Memoization check
        if(t[n][sum] != -1) return t[n][sum];

        if(arr[n-1] <= sum) {
            return t[n][sum] =
                solve(arr, sum - arr[n-1], n-1) + // element lo
                solve(arr, sum, n-1);              // element skip
        }

        return t[n][sum] = solve(arr, sum, n-1);
    }

    int countSubsetsWithDiff(vector<int>& arr, int diff) {

        int n = arr.size();
        int totalSum = 0;
        for(int x : arr) totalSum += x;

        if((totalSum + diff) % 2 != 0) return 0;

        int target = (totalSum + diff) / 2;
        t.assign(n+1, vector<int>(target+1, -1));

        return solve(arr, target, n);
    }
};

/*
INTUITION:
Recursive soch me har element ke paas 2 choice hoti hai → lo ya skip.
Har valid path jo target sum banata hai,
uska count add hota jaata hai.
Memoization ensure karta hai ki
har (n,sum) state sirf ek baar solve ho.

TIME COMPLEXITY:
O(n * target)

SPACE COMPLEXITY:
O(n * target) DP table
O(n) recursion stack
*/
