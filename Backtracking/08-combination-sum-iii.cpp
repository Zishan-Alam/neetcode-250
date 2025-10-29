class Solution {
public:

    void solve(int start, int sum, vector<int> &temp, vector<vector<int>> &result, int target, int k) {
        if(temp.size() == k && sum == target) {
            result.push_back(temp);
            return;
        }

        for(int i=start; i<10; i++) {

            if(sum + i > target) continue;

            temp.push_back(i);
            sum += i;

            solve(i+1, sum, temp, result, target, k);

            temp.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        solve(1, sum, temp, result, target, k);
        return result;
    }
};

/*
🧠 Intuition:
----------------------------------------
Numbers 1–9 me se k numbers choose karne hain
jinka sum target ke barabar ho.

→ Har step par hum decide karte hain ki current number lena hai ya nahi.
→ Ek baar number lene ke baad firse use nahi kar sakte (isliye i+1 pass karte hain).
→ Jab size == k aur sum == target, to valid combination mil gaya.

----------------------------------------

⏱️ Time Complexity:
O(C(9, k))  — maximum 9 numbers me se k choose kar rahe hain.

📦 Space Complexity:
O(k) recursion stack + O(k) temp vector.
*/
