class Solution {
public:
    vector<int> nse(vector<int>& nums) { 
        int n = nums.size();
        vector<int> ans(n, -1);    // Har element ka Next Smaller store karega
        stack<int> st;             // Stack me index rakhenge

        for(int i = 0; i < n; i++) {
            // Jab current element chhota hai stack ke top se,
            // to iska matlab current element hi uska Next Smaller hai
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
Hum stack ka use karke har element ka agla chhota number (Next Smaller) dhundhte hain.
Stack me elements ke indexes store karte hain.
Jab bhi koi naya element nums[i] aata hai aur wo stack ke top wale element se chhota hota hai,
iska matlab nums[i] hi uska Next Smaller hai.
To ans[top] = nums[i] karte hain aur top index ko stack se hata dete hain.
Agar chhota nahi hai to index ko stack me daal dete hain.

📊 Dry Run:
Input: nums = [4, 8, 5, 2, 25]

Step-by-step:
i=0 → st=[] → push(0) → st=[0]
i=1 → nums[1]=8>nums[0]=4 → push(1) → st=[0,1]
i=2 → nums[2]=5<nums[1]=8 → ans[1]=5, pop(1) → st=[0] → 5>4 → push(2)
i=3 → nums[3]=2<nums[2]=5 → ans[2]=2, pop(2)
       nums[3]=2<nums[0]=4 → ans[0]=2, pop(0)
       push(3)
i=4 → nums[4]=25>nums[3]=2 → push(4)
End → ans=[2,5,2,-1,-1]

✅ Final ans = [2, 5, 2, -1, -1]

⏱️ Time Complexity: O(N)
👉 Har element stack me ek baar push aur ek baar pop hota hai.

💾 Space Complexity: O(N)
👉 Stack aur ans vector dono ke liye linear space lagta hai.
*/
