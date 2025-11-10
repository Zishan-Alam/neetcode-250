class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (auto &log : logs) {
            if (log == "../") {
                if (!st.empty()) st.pop(); // ✅ only pop if stack not empty
            } 
            else if (log == "./") {
                continue; // current folder, ignore
            } 
            else {
                st.push(log); // move into new folder
            }
        }

        return st.size(); // ✅ directly return stack size
    }
};

/*
🧠 Intuition:
- Each folder push hota hai stack me.
- "../" → ek folder back jaane ka matlab pop.
- "./" → current folder, kuch nahi karna.
At the end, stack size = depth of current folder.

🧩 Dry Run:
logs = ["d1/","d2/","../","d21/","./"]
→ push d1 → [d1]
→ push d2 → [d1, d2]
→ "../" → pop d2 → [d1]
→ push d21 → [d1, d21]
→ "./" → ignore
Final stack = [d1, d21]
Answer = 2 ✅

⏱️ Time Complexity: O(N)
💾 Space Complexity: O(N)
*/
