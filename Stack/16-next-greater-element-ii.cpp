class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices (monotonic decreasing stack)

        // traverse twice to simulate circular array
        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];

            // jab tak current num bada hai stack ke top index ke element se
            while (!st.empty() && num > nums[st.top()]) {
                ans[st.top()] = num;
                st.pop();
            }

            // first pass me hi push karo indices
            if (i < n) st.push(i);
        }

        return ans;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Normal NGE me hum har element ka next greater find karte hain.
Is question me array circular hai — matlab agar end tak nahi mila to 
hum starting elements bhi consider kar sakte hain.

To hum array ko 2 times traverse karte hain (2*n):
- Current element = nums[i % n] (ye circular traversal hai)
- Stack decreasing order me rakhta hai (indices)
- Jab current element bada hota hai → wo stack ke top ka next greater hota hai
- Sirf first pass me push karte hain, taaki duplicate computation na ho

📊 Dry Run:
nums = [1, 2, 1]
n = 3

i=0 → num=1 → push(0)
i=1 → num=2 → 2>1 → ans[0]=2 → pop(0) → push(1)
i=2 → num=1 → push(2)
i=3 → num=1 → 1>1? no
i=4 → num=2 → 2>1 → ans[2]=2 → pop(2)
✅ ans = [2, -1, 2]

⏱️ Time Complexity: O(N)
👉 Each element pushed and popped at most once.

💾 Space Complexity: O(N)
👉 Stack stores at most N indices.
*/
