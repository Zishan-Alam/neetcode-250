class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map bana rahe hain jisme value -> index store karenge
        unordered_map<int, int> mp;

        // poore array pe loop chalayenge
        for(int i = 0; i < nums.size(); i++) {
            // har element ke liye difference nikalte hain (target - nums[i])
            int diff = target - nums[i];

            // check karte hain kya ye difference map me already exist karta hai
            // agar karta hai, to iska matlab hume dono numbers mil gaye
            if(mp.find(diff) != mp.end())
                return {mp[diff], i};  // dono indices return kar do

            // agar nahi mila, to current element ko map me daal do
            // taaki future elements ke liye check kar sakein
            mp[nums[i]] = i;
        }

        // agar koi pair nahi mila (edge case), empty vector return kar do
        return {};
    }
};

/*
🧠 Intuition (Hinglish me):
Target sum banane ke liye har number ke liye check karte hain
ki kya "target - current_number" pehle se array me aaya tha.
Agar aaya tha, to wahi do numbers answer hain.
Nahi to current number ko map me store kar lete hain future ke liye.

⚙️ Time Complexity:
→ O(n)
    - Har element ko ek hi baar process kar rahe hain.
    - Map me lookup aur insertion average O(1) me hoti hai.

💾 Space Complexity:
→ O(n)
    - Worst case me, har element map me store ho sakta hai.
    - Isliye auxiliary space O(n) lagta hai.
*/
