class Solution {
public:

    void solve(int start, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result, unordered_set<int> &st) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {

            if(st.find(nums[i]) != st.end()) continue;

            temp.push_back(nums[i]);
            st.insert(nums[i]);

            solve(i+1, nums, temp, result, st);

            temp.pop_back();
            st.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<int> st;
        solve(0, nums, temp, result, st);
        return result;
    }
};

/*
🧠 Intuition:
Permutation me hum har element ko ek position pe rakh kar
baaki ke elements ke liye recursion chala dete hain.
Har element ek baar use hota hai, isliye hum unordered_set se track karte hain
ki kaunsa element already choose ho chuka hai.

Example:
nums = [1, 2, 3]
Permutations -> [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]

⚙️ Time Complexity: O(n * n!)
- Total n! permutations bante hain
- Har permutation ko banana me O(n) lagta hai

💾 Space Complexity: O(n)
- temp vector aur recursion stack ke liye O(n) space lagta hai
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    void solve(int start, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result, vector<bool> &used) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {

            if(used[i]) continue;

            temp.push_back(nums[i]);
            used[i] = true;

            solve(i+1, nums, temp, result, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        solve(0, nums, temp, result, used);
        return result;
    }
};

111111111```````
