class Solution {
public:

    void solve(int start, int &k, int &n, vector<int> &temp, vector<vector<int>> &result) {
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<=n; i++) {
            temp.push_back(i);
            solve(i+1, k, n, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1, k, n, temp, result);
        return result;
    }
};

/*
💡 Intuition:
-----------------
Ye ek classic BACKTRACKING problem hai.
Hum har step par decide karte hain:
    - Current number include karein ya skip karein.

Recursion tree "combination generation" jaisa hota hai.
Jaise hi temp.size() == k hota hai, ek valid combination milta hai.

Example:
n = 4, k = 2
Tree ke levels:
[1] → [1,2], [1,3], [1,4]
[2] → [2,3], [2,4]
[3] → [3,4]

→ Ye saare combinations milte hain.

⏱ Time Complexity: O(C(n, k) * k)
   - C(n, k) total combinations bante hain.
   - Har combination banane me O(k) time lagta hai.

🧠 Space Complexity: O(k)
   - Recursion stack + temp vector (maximum depth k tak).
*/
