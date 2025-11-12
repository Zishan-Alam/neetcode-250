class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // store next greater for each num in nums2
        stack<int> st; // monotonic decreasing stack

        for (int num : nums2) {
            // jab tak current num bada hai stack ke top se
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num; // next greater mil gaya
                st.pop();
            }
            st.push(num);
        }

        // jo stack me bacha wo kisi se chhota nahi mila
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // prepare answer for nums1 based on map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Yahan hume har number ka "Next Greater Element" find karna hai — 
lekin nums1 ke numbers nums2 ke subset hote hain.
To hum pehle nums2 ke liye har element ka "next greater" map bana lete hain.
Monotonic decreasing stack use karte hain:
- Jab tak current element bada hai stack ke top se → pop karke map me store kar dete hain.
- Baad me bache hue elements ka -1 hota hai.

Finally, nums1 ke liye answer map se directly nikal lete hain.

📊 Dry Run:
nums1 = [4,1,2]
nums2 = [1,3,4,2]

Iterate nums2:
num=1 → push(1)
num=3 → 3>1 → nextGreater[1]=3 → pop(1) → push(3)
num=4 → 4>3 → nextGreater[3]=4 → pop(3) → push(4)
num=2 → push(2)
end → nextGreater[4]=-1, nextGreater[2]=-1

map = {1:3, 3:4, 4:-1, 2:-1}

nums1 ke liye:
4→-1, 1→3, 2→-1 → ans = [-1,3,-1]

✅ Output: [-1, 3, -1]

⏱️ Time Complexity: O(N + M)
👉 nums2 traverse O(M), nums1 traverse O(N)

💾 Space Complexity: O(M)
👉 Stack + Map dono me nums2 ke elements store hote hain.
*/
