class Solution {
public:

    vector<vector<int>> result;  // final answer store karne ke liye

    void solve(int idx, vector<int> &nums, vector<int> &temp) {
        result.push_back(temp);  // har step par current subset ko result me daal do

        for(int i = idx; i < nums.size(); i++) {

            // agar same element repeat ho raha hai aur wo current recursion level ka pehla element nahi hai
            // to skip kar do — taaki duplicate subsets na bane
            if(i > idx && nums[i] == nums[i - 1]) continue;

            // current element include karo
            temp.push_back(nums[i]);

            // next index ke liye recursive call
            solve(i + 1, nums, temp);

            // backtrack karke element hatao (exclude)
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(begin(nums), end(nums));   // sort karna important hai duplicates detect karne ke liye
        solve(0, nums, temp);
        return result;
    }
};

/*
🧠 Intuition:
Yahan hum normal subsets jaisa hi backtracking kar rahe hain,
bas ek extra check lagaya hai duplicates avoid karne ke liye.

➡️ Pehle array ko sort karte hain, taaki duplicates ek saath aa jayein.
➡️ Jab hum for-loop me traverse karte hain, agar current element
   pehle wale ke equal hai (aur i > idx hai), to hum usko skip kar dete hain.
   Isse same subset baar-baar generate nahi hota.

Example:
nums = [1,2,2]
Subsets:
[], [1], [1,2], [1,2,2], [2], [2,2]

⚙️ Time Complexity: O(2^n)
- Har element ke liye include/exclude decision hota hai.
- Sorting O(n log n) hai, but recursion dominates.

💾 Space Complexity: O(n)
- Recursive stack + temp vector ke liye O(n) space lagta hai.
*/
