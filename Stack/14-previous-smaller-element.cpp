class Solution {
public:
    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Har element ka previous smaller yahan store hoga
        stack<int> st;            // Stack indexes rakhega

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            // Agar current element chhota hai stack ke top wale se,
            // to iska matlab ye hi uska Previous Smaller hai
            while(!st.empty() && nums[i] < nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Har element ke liye uske pehle aane wala chhota number (Previous Smaller) chahiye.
Isliye hum right se left traverse karte hain.
Stack me indexes store karte hain — jab bhi koi chhota element milta hai,
to iska matlab ye current element hi stack ke top wale ka Previous Smaller hai.

📊 Dry Run:
nums = [4, 5, 2, 10, 8]

i=4 → st=[] → push(4)
i=3 → nums[3]=10 < nums[4]=8 ❌ → push(3)
i=2 → nums[2]=2 < nums[3]=10 ✅ ans[3]=2 pop(3)
        nums[2]=2 < nums[4]=8 ✅ ans[4]=2 pop(4)
        push(2)
i=1 → nums[1]=5 < nums[2]=2 ❌ → push(1)
i=0 → nums[0]=4 < nums[1]=5 ✅ ans[1]=4 pop(1)
        nums[0]=4 > nums[2]=2 ❌ push(0)

✅ Final ans = [-1, 4, -1, 2, 2]

⏱️ Time Complexity: O(N)
👉 Har element ek baar push aur ek baar pop hota hai.

💾 Space Complexity: O(N)
👉 Stack aur ans vector ke liye linear space lagta hai.
*/
