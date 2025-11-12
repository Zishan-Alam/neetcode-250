class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Next Greater Element variation (for temperature difference)
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices of days

        for(int i = 0; i < n; i++) {
            // jab tak current temp > previous (stack top) temp hai
            // tab tak difference nikalte jao
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[idx] = i - st.top(); // difference of days
                st.pop();
            }
            st.push(i); // current day ko stack me daal do
        }
        return ans;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Har din ke liye hume ye dekhna hai ki agla din kab zyada garam hoga.
Yaani "Next Greater Element" (temperature) ka distance chahiye.
Stack me indices store karte hain.
Jab bhi koi naya din aata hai jiska temperature zyada hai,
to pichle thande din ka answer (i - idx) mil jaata hai.

📊 Dry Run:
temperatures = [73, 74, 75, 71, 69, 72, 76, 73]

i=0 → st=[] → push(0)
i=1 → 74>73 → ans[0]=1-0=1 → pop(0) → push(1)
i=2 → 75>74 → ans[1]=2-1=1 → pop(1) → push(2)
i=3 → 71<75 → push(3)
i=4 → 69<71 → push(4)
i=5 → 72>69 → ans[4]=5-4=1 → pop(4)
           → 72>71 → ans[3]=5-3=2 → pop(3)
           → push(5)
i=6 → 76>72 → ans[5]=6-5=1 → pop(5)
           → 76>75 → ans[2]=6-2=4 → pop(2)
           → push(6)
i=7 → 73<76 → push(7)

✅ Final ans = [1, 1, 4, 2, 1, 1, 0, 0]

⏱️ Time Complexity: O(N)
👉 Har element ek baar push aur ek baar pop hota hai.

💾 Space Complexity: O(N)
👉 Stack aur ans vector dono ke liye linear space lagta hai.
*/
