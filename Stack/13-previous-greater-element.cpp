class Solution {
public:
    vector<int> pge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Har element ka previous greater store karega
        stack<int> st;            // Index stack

        // Right to Left traversal
        for(int i = n - 1; i >= 0; i--) {
            // Agar current element bada hai stack ke top wale se
            // to iska matlab ye hi uska Previous Greater hai
            while(!st.empty() && nums[i] > nums[st.top()]) {
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
Hum har element ke liye uske pehle aane wala bada number (Previous Greater) dhundhna chahte hain.
Isliye hum array ko right se left traverse karte hain.
Stack me indexes store karte hain — jab bhi koi current element bada milta hai,
to iska matlab ye current element hi stack ke top wale element ka Previous Greater hai.

📊 Dry Run:
Input: nums = [4, 5, 2, 10, 8]

Start from right:
i=4 → st=[] → push(4)
i=3 → nums[3]=10 > nums[4]=8 → ans[4]=10, pop(4) → push(3)
i=2 → nums[2]=2 < nums[3]=10 → push(2)
i=1 → nums[1]=5 > nums[2]=2 → ans[2]=5, pop(2)
       nums[1]=5 < nums[3]=10 → push(1)
i=0 → nums[0]=4 < nums[1]=5 → push(0)

✅ Final ans = [-1, -1, 5, -1, 10]

⏱️ Time Complexity: O(N)
👉 Har element ek baar stack me push aur ek baar pop hota hai.

💾 Space Complexity: O(N)
👉 Stack aur ans vector dono ke liye linear space lagta hai.
*/

