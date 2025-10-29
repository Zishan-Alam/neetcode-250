class Solution {
public:

    void solve(int start, vector<int> &candidates, int target, int sum, vector<int> &temp, vector<vector<int>> &result) {
        if(sum == target) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++) {
            if(sum + candidates[i] > target) continue;

            temp.push_back(candidates[i]);
            sum += candidates[i];
            solve(i, candidates, target, sum, temp, result);
            temp.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        solve(0, candidates, target, sum, temp, result);
        return result;
    }
};

/*
🧠 Intuition:
----------------------------------------
Har element ke liye hum do choice rakhte hain —
→ include karo (aur same index se fir se try karo, kyunki repetition allowed hai)
→ ya skip karke next element pe jao.

Jab tak sum < target hai, hum explore karte hain.
Jab sum == target, ek valid combination mil gaya.
Jab sum > target, aage explore karne ka koi fayda nahi (pruning).

Ye process har path ke liye backtrack hota hai,
taaki sab possible combinations mil sake.

----------------------------------------

⏱️ Time Complexity:
O(2^t) approx — jahan 't' combinations ki total depth hai.
Worst case me har element multiple times include ho sakta hai
(DFS tree exponential grow karta hai).

📦 Space Complexity:
O(t) recursion stack + O(k) temp vector (where k is avg combination length).
So overall ~ O(target / min_element(candidates)) stack depth.
*/
