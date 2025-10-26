class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // do pointer approach use kar rahe hain
        int i = 0;                // start pointer
        int j = nums.size() - 1;  // end pointer

        // loop tab tak chalayenge jab tak pointers cross nahi karte
        while(i < j) {
            int sum = nums[i] + nums[j]; // dono pointers ke elements ka sum

            if(sum < target)  i++;  // sum chhota hai, to start pointer ko aage badhao
            else if(sum > target) j--;  // sum bada hai, to end pointer ko piche le aao
            else return {i+1, j+1}; // sum target ke barabar → answer mil gaya (1-based index)
        }

        // agar loop khatam ho gaya aur pair nahi mila
        return {};
    }
};

/*
🧠 Intuition (Hinglish me):
Array sorted hone ki wajah se hum two pointers approach use kar sakte hain.
- Start se aur end se pointers leke sum check karte hain.
- Sum chhota → start++ 
- Sum bada → end--
- Sum exact → return indices

⚙️ Time Complexity:
→ O(n)
    - Har pointer ek hi baar traverse karta hai.
    - Total operations linear in array size.

💾 Space Complexity:
→ O(1)
    - Extra space ka use nahi ho raha, bas do pointers.
*/
