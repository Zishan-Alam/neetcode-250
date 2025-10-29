class Solution {
public:
    vector<vector<int>> result;  // to store all possible subsets

    // Backtracking function
    void solve(vector<int>& nums, int start, vector<int>& temp) {
        result.push_back(temp);  // har recursive call pe ek valid subset milta hai

        // i loop ensures we include each element one by one
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);      // include current element
            solve(nums, i + 1, temp);     // recursive call for next elements
            temp.pop_back();              // backtrack (remove last element)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // temporary subset container
        solve(nums, 0, temp);
        return result;
    }
};

/*
🧠 Intuition:
Yahan hum har element ke liye do choices lete hain —
ya to element ko subset me include karo, ya skip karo.
Har recursive call ek path explore karti hai (include ya exclude).
Jab recursion poora ho jaata hai, sab possible combinations (subsets) mil jaate hain.

Example:
nums = [1,2,3]
Subsets -> [], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]

⚙️ Time Complexity: O(2^n * n)
- 2^n subsets bante hain (include/exclude pattern)
- Har subset ko copy karne me O(n) lagta hai

💾 Space Complexity: O(n)
- Recursive stack + temporary subset (`temp`) size max n
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    vector<vector<int>> result;  // final answer store karne ke liye

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        // base case: agar hum array ke end tak pahunch gaye
        if(i >= nums.size()) {
            result.push_back(temp);  // current subset store kar lo
            return;
        }

        // 🔹 Choice 1: current element ko include karo
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);   // next index ke liye call
        temp.pop_back();            // backtrack (remove element)

        // 🔹 Choice 2: current element ko exclude karo
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // temporary subset container
        solve(nums, 0, temp);
        return result;
    }
};

/*
🧠 Intuition:
Yahan har element ke liye hum do decision lete hain —
➡️ Ya to element ko include karo subset me
➡️ Ya fir exclude kar do

Iss se har level pe recursion 2 branches me divide hoti hai.
End me total 2^n subsets ban jaate hain.
Example:
nums = [1,2,3]
Subsets -> [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

⚙️ Time Complexity: O(2^n * n)
- 2^n possible subsets bante hain
- Har subset ko copy karne me O(n) lagta hai

💾 Space Complexity: O(n)
- Recursive stack + temporary vector (max depth n)
*/

