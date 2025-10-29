class Solution {
public:

    void solve(int start, vector<int> &candidates, int remaining, vector<int> &temp, vector<vector<int>> &result) {
        if(remaining < 0) return;
        else if(remaining == 0) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(i+1, candidates, remaining - candidates[i], temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, temp, result);
        return result;
    }
};

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    void solve(int start, vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &result, int sum) {
        if(sum == target) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] > target) continue;

            temp.push_back(candidates[i]);
            sum += candidates[i];
            solve(i+1, candidates, target, temp, result, sum);
            temp.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, temp, result, sum);
        return result;
    }
};

/*
🧠 Intuition:
----------------------------------------
Yahaan har number ek hi baar use ho sakta hai.
Isliye recursive call me hum `i+1` pass karte hain.

→ Duplicate avoid karne ke liye: 
   "if (i > start && candidates[i] == candidates[i-1]) continue" 
   ensures ki ek level pe same number baar baar na aaye.

→ Pruning (sum + candidates[i] > target) se
   unnecessary recursive calls avoid hoti hain.

----------------------------------------

⏱️ Time Complexity:
O(2^n) in worst case (each element include/exclude)  
with pruning reduces calls drastically.

📦 Space Complexity:
O(n) recursion stack + O(n) temp vector.
*/
