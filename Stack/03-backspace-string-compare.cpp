class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        // Process first string
        for (auto &ch : s) {
            if (ch == '#') {
                if (!st1.empty()) st1.pop();  // Remove last character
            } else {
                st1.push(ch);                 // Add current character
            }
        }

        // Process second string
        for (auto &ch : t) {
            if (ch == '#') {
                if (!st2.empty()) st2.pop();  // Remove last character
            } else {
                st2.push(ch);                 // Add current character
            }
        }

        // Convert both stacks into strings (in correct order)
        string res1 = ""; 
        string res2 = "";
        while (!st1.empty()) {
            res1 = st1.top() + res1;  // ✅ Add to front to maintain order
            st1.pop();
        }
        while (!st2.empty()) {
            res2 = st2.top() + res2;  // ✅ Add to front to maintain order
            st2.pop();
        }

        return res1 == res2;
    }
};

/*
🧠 INTUITION:
Backspace '#' ka matlab hai pichla character delete karna.
Stack ek perfect data structure hai iske liye:
- Jab normal character mile → push karo
- Jab '#' mile → pop karo (agar stack empty nahi hai)

Dono strings ko process karke final form nikalo,
phir compare kar lo.

------------------------------------------------
🔍 DRY RUN:
s = "ab#c", t = "ad#c"

Process s:
'a' → [a]
'b' → [a,b]
'#' → pop b → [a]
'c' → [a,c] → final = "ac"

Process t:
'a' → [a]
'd' → [a,d]
'#' → pop d → [a]
'c' → [a,c] → final = "ac"

✅ Both equal → return true

------------------------------------------------
⏱️ TIME COMPLEXITY: O(N + M)
- Har string ke characters ek baar process ho rahe hain.

💾 SPACE COMPLEXITY: O(N + M)
- Stacks store kar rahe hain characters of s and t.
*/
