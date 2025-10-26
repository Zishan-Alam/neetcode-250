class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map bana rahe hain jisme har element ka last index store karenge
        unordered_map<int, int> mp;

        // poore nums vector pe loop chalayenge
        for(int i = 0; i < nums.size(); i++) {

            // check karte hain kya current element pehle se map me exist karta hai
            // agar karta hai aur current index aur previous index ka difference <= k hai
            // to iska matlab duplicate mil gaya within range k
            if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k)
                return true; // to true return kar denge

            // agar duplicate nahi mila ya range exceed kar gayi
            // to us element ka latest index update kar do
            else
                mp[nums[i]] = i;
        }

        // agar pura loop chal gaya aur koi duplicate nearby nahi mila
        return false;
    }
};
