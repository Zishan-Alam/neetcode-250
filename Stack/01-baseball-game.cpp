class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;  // ✅ Use integer stack

        for(auto &op : operations) {
            if(op == "C") {
                st.pop(); // remove last score
            }
            else if(op == "D") {
                st.push(st.top() * 2); // double last score
            }
            else if(op == "+") {
                int a = st.top(); st.pop();
                int b = st.top();
                st.push(a);         // restore 'a'
                st.push(a + b);     // push sum of last two
            }
            else {
                st.push(stoi(op)); // ✅ convert string to int
            }
        }

        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

/*
🧠 Intuition:
Stack maintain karta hai valid scores.
- "C" → last score cancel
- "D" → double last score
- "+" → sum of last 2 valid scores
- number → normal push
At the end, sum of all stack elements gives final result.

🧩 Dry Run:
Input: ["5","2","C","D","+"]
Step-by-step:
Push 5 → [5]
Push 2 → [5,2]
"C" → remove 2 → [5]
"D" → double 5 → push 10 → [5,10]
"+" → 5+10=15 → [5,10,15]
Sum = 30 ✅

⏱️ Time: O(N)
💾 Space: O(N)
*/
