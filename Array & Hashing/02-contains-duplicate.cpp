class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map bana rahe hain jisme har number ki frequency count karenge
        unordered_map<int, int> freq;

        // har element ke liye loop chalayenge
        for (int num : nums) {
            // us number ki frequency badha do
            freq[num]++;

            // agar frequency 2 ya usse zyada ho gayi,
            // matlab duplicate mil gaya
            if (freq[num] >= 2)
                return true;
        }

        // agar poora array traverse karne ke baad koi duplicate nahi mila
        return false;
    }
};
