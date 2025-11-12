class Solution {
public:
    vector<int> ngr(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);   // har element ka NGE store karega
        stack<int> st;            // stack me index store karenge

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
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
Hum stack ka use karke "Next Greater Element" find karte hain.
Stack me hum elements ke index store karte hain.
Jab bhi koi naya element nums[i] aata hai aur wo stack ke top wale element se bada hota hai,
iska matlab ye element hi uska "Next Greater" hai.
To hum ans[top] = nums[i] karte hain aur top ko stack se nikaal dete hain.
Agar bada nahi hai to index ko stack me daal dete hain.

📊 Dry Run:
Input: nums = [2, 1, 3]

Step-by-step:
i = 0 → nums[0]=2 → stack = [0]
i = 1 → nums[1]=1 → stack = [0,1]
i = 2 → nums[2]=3 → 3 > nums[1] → ans[1]=3, pop(1)
                     3 > nums[0] → ans[0]=3, pop(0)
                     stack = [] → push(2)
Final ans = [3, 3, -1]

⏱️ Time Complexity: O(N)
👉 Har element sirf ek baar push aur ek baar pop hota hai.

💾 Space Complexity: O(N)
👉 Stack aur answer vector dono ke liye linear space lagta hai.
*/
