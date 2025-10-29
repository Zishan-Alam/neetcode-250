class Solution {
public:

    void solve(vector<int> &temp, vector<vector<int>> &result, vector<bool> &used, vector<int>& nums) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {

            // agar element already use ho chuka hai → skip
            // ya agar current element previous ke barabar hai 
            // aur previous element use nahi hua → skip (to avoid duplicate sequence)
            if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]) ) continue; 

            temp.push_back(nums[i]);
            used[i] = true;
            solve(temp, result, used, nums);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        sort(begin(nums), end(nums));
        solve(temp, result, used, nums);
        return result;
    }
};

/*

💡 Why?

used[i] → agar current element already use ho chuka hai, to skip kar.

(i > 0 && nums[i] == nums[i-1] && !used[i-1]) → agar current element duplicate hai
aur uska previous duplicate use nahi hua hai, to skip kar (taaki duplicate permutations avoid ho).

Agar dono ko && se jod diya, to ye condition sirf tab chalegi jab dono ek sath true ho,
lekin hume skip karna chahiye agar koi bhi ek true ho —
isliye || (OR) use karna chahiye.

🧠 Intuition:
Ye problem “Permutation I” jaise hi hai, bas difference ye hai ki 
nums me duplicate elements ho sakte hain.

➡️ Pehle array ko sort kar lete hain taaki duplicate elements ek saath ho.
➡️ Fir har recursion step pe:
   - Agar current element already use ho chuka hai → skip
   - Agar current element same hai as previous aur previous use nahi hua → skip
   Ye dono condition ensure karte hain ki duplicate permutations avoid ho jaayein.

Example:
nums = [1,1,2]
Unique permutations:
[1,1,2], [1,2,1], [2,1,1]

⚙️ Time Complexity: O(n * n!)
- Total roughly n! permutations possible hote hain
- Har permutation banate time O(n) lagta hai

💾 Space Complexity: O(n)
- Recursion stack aur “used” array dono O(n) lete hain
*/
