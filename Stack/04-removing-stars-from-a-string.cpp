// ✅ Leetcode 2390 – Removing Stars From a String
// ------------------------------------------------------------
// Author: Zishan Alam Khan
// Approach: Stack-based simulation of removing characters before '*'
// ------------------------------------------------------------

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        // Traverse each character in the string
        for (auto &ch : s) {
            if (ch == '*' && !st.empty()) 
                st.pop();        // '*' means remove previous character
            else 
                st.push(ch);     // otherwise, push current character
        }

        // Build the final string from stack (reverse order)
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;  // maintain correct order
            st.pop();
        }
        return res;
    }
};

/*
🧠 INTUITION (Roman Hindi):
----------------------------------------------
'*' ka matlab hai — pichla character hata do.
Stack se easy tarika milta hai:
- Normal character aaye → stack me daal do.
- '*' aaye → top character hata do (pop).

End me stack me wahi characters bache rahenge
jo remove nahi hue, unhe ulta padhkar final string banate hain.

----------------------------------------------
🔍 DRY RUN EXAMPLE:
----------------------------------------------
Input: s = "leet**cod*e"

Step-by-step:
'l' → [l]
'e' → [l,e]
'e' → [l,e,e]
't' → [l,e,e,t]
'*' → remove 't' → [l,e,e]
'*' → remove 'e' → [l,e]
'c' → [l,e,c]
'o' → [l,e,c,o]
'd' → [l,e,c,o,d]
'*' → remove 'd' → [l,e,c,o]
'e' → [l,e,c,o,e]

✅ Final stack = [l,e,c,o,e]
Final string = "lecoe"

----------------------------------------------
⏱️ TIME COMPLEXITY: O(N)
→ Har character ek baar process hota hai.

💾 SPACE COMPLEXITY: O(N)
→ Stack me maximum N characters store ho sakte hain.
----------------------------------------------
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// ✅ Leetcode 2390 – Removing Stars From a String
// ------------------------------------------------------------
// Author: Zishan Alam Khan
// Approach: Optimized in-place string building (no stack used)
// ------------------------------------------------------------

class Solution {
public:
    string removeStars(string s) {
        string res = "";

        // Traverse each character of the input
        for (auto &ch : s) {
            if (ch == '*' && !res.empty()) res.pop_back();  // remove last added character
            else res.push_back(ch);  // add normal characters
        }
        return res;
    }
};

/*
🧠 INTUITION (Roman Hindi):
----------------------------------------------
'*' ka matlab hai — pichla character hata do.
Stack use karne ki jagah hum ek hi string `res` me
push aur pop karte hain, jaise stack behave karta hai.

Isse memory bachti hai kyunki hum koi extra data structure
nahi use kar rahe (sirf ek string hi).

----------------------------------------------
🔍 DRY RUN EXAMPLE:
----------------------------------------------
Input: s = "leet**cod*e"

res = ""
'l' → "l"
'e' → "le"
'e' → "lee"
't' → "leet"
'*' → remove 't' → "lee"
'*' → remove 'e' → "le"
'c' → "lec"
'o' → "leco"
'd' → "lecod"
'*' → remove 'd' → "leco"
'e' → "lecoe"

✅ Final Answer = "lecoe"

----------------------------------------------
⏱️ TIME COMPLEXITY: O(N)
→ Har character ek baar process hota hai.

💾 SPACE COMPLEXITY: O(1) extra space
→ Sirf ek string `res` use kar rahe hain, jo output hi hai.
----------------------------------------------
*/

