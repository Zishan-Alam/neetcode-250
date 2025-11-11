class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char &ch : s) {

            // Opening bracket milta hai to stack me daal do
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } 
            else {
                // Agar closing bracket aaya lekin stack empty hai -> invalid
                if (st.empty()) return false;

                // Stack ke top ke hisaab se matching check karo
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop(); // Matching pair mil gaya -> remove
                } 
                else {
                    return false; // Mismatch -> invalid string
                }
            }
        }

        // Agar sab pair match ho gaye, to stack empty hoga
        return st.empty();
    }
};

/*
🧠 Intuition:
Har bracket ek pair ke form me hota hai. Jab bhi opening bracket mile, usse stack me daal do.
Aur jab closing bracket mile, to stack ke top se check karo ki kya woh matching opening bracket hai.
Agar match kare to pop kar do, warna invalid string. Agar end me stack empty hai -> valid string.

🪜 Dry Run:
Input: s = "{[()]}"
Stack = []

'{' -> push('{')       -> { '{' }
'[' -> push('[')       -> { '{', '[' }
'(' -> push('(')       -> { '{', '[', '(' }
')' -> top='(' match   -> pop() -> { '{', '[' }
']' -> top='[' match   -> pop() -> { '{' }
'}' -> top='{' match   -> pop() -> { }

Stack empty → ✅ Valid string

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)
*/
