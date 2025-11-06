// ✅ GENERATE VALID PARENTHESIS (Brute Force Approach)
// -----------------------------------------------------------
// Author: Zishan Alam Khan
// Description: Generate all combinations of parentheses 
// and filter only valid ones using recursion + validation check.
// -----------------------------------------------------------

class Solution {
public:
    // -----------------------------------------------------------
    // Helper function to check if current string is valid
    // -----------------------------------------------------------
    bool isValid(string str) {
        int count = 0; // balance tracker

        for (char ch : str) {
            if (ch == '(') count++;   // open bracket adds 1
            else count--;             // close bracket subtracts 1

            if (count < 0) return false; // more ')' than '(' → invalid
        }
        return count == 0; // valid only if all '(' are matched
    }

    // -----------------------------------------------------------
    // Recursive function to generate all combinations
    // -----------------------------------------------------------
    void solve(int n, string &curr, vector<string> &res) {
        // Base case: if length reaches 2*n
        if (curr.length() == 2 * n) {
            if (isValid(curr)) res.push_back(curr); // store only if valid
            return;
        }

        // Choice 1️⃣: Add '(' and explore
        curr.push_back('(');
        solve(n, curr, res);
        curr.pop_back(); // backtrack

        // Choice 2️⃣: Add ')' and explore
        curr.push_back(')');
        solve(n, curr, res);
        curr.pop_back(); // backtrack
    }

    // -----------------------------------------------------------
    // Main Function: Generate all valid parentheses combinations
    // -----------------------------------------------------------
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(n, curr, res);
        return res;
    }
};


/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Yeh brute-force approach hai jisme har position par 
'(' aur ')' dono possibilities try karte hain.
Total 2^(2n) strings banengi.  
Phir har string ko 'isValid()' se check karte hain 
ki wo balanced parentheses hai ya nahi.

Agar valid hai → result me daal dete hain.

------------------------------------------------------------
🔍 DRY RUN EXAMPLE:
------------------------------------------------------------
n = 2 → total length = 4

Recursion Tree (partial):
""  
├─ "("  
│  ├─ "((" → "(())" ✅ valid  
│  └─ "()" → "()()" ✅ valid  
└─ ")" → invalid early due to imbalance

✅ Final Output = ["(())", "()()"]

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
O(2^(2n) * n)
→ 2 choices per position ( '(' or ')' )  
→ and O(n) to validate each string.

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(n) (recursion stack) + O(2^(2n)) (result storage)

------------------------------------------------------------
⚡ NOTE:
------------------------------------------------------------
Yeh brute-force version hai.
Optimized version me hum directly sirf valid strings generate karte hain
by tracking open and close count → O(4^n / √n) complexity.
------------------------------------------------------------
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// ✅ GENERATE VALID PARENTHESIS (Optimized Backtracking Approach)
// -----------------------------------------------------------
// Author: Zishan Alam Khan
// Description: Backtracking approach that directly builds only valid combinations
// by tracking counts of open and close parentheses.
// -----------------------------------------------------------

class Solution {
public:
    // -----------------------------------------------------------
    // Recursive function to generate valid parentheses
    // open  → number of '(' used so far
    // close → number of ')' used so far
    // -----------------------------------------------------------
    void solve(int n, string &curr, vector<string> &res, int open, int close) {
        // ✅ Base case: if length == 2*n, means one valid combination formed
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        // Choice 1️⃣: Add '(' if we still have open brackets left
        if (open < n) {
            curr.push_back('(');               // choose '('
            solve(n, curr, res, open + 1, close); // explore
            curr.pop_back();                   // backtrack
        }

        // Choice 2️⃣: Add ')' if we have unmatched '(' to close
        if (close < open) {
            curr.push_back(')');               // choose ')'
            solve(n, curr, res, open, close + 1); // explore
            curr.pop_back();                   // backtrack
        }
    }

    // -----------------------------------------------------------
    // Main Function
    // -----------------------------------------------------------
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(n, curr, res, 0, 0); // start recursion with 0 open and close
        return res;
    }
};


/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Brute force me hum sab combinations banate the aur baad me check karte the 
ki valid hain ya nahi.  
Yahaan hum **smartly backtracking** se sirf valid parentheses hi banate hain.

→ Agar '(' ka count n se kam hai to ek '(' add kar sakte hain.  
→ Agar ')' ka count open se kam hai to ek ')' add kar sakte hain.  
Isse kabhi bhi invalid string nahi banegi.

------------------------------------------------------------
🔍 DRY RUN EXAMPLE:
------------------------------------------------------------
n = 2

Start: curr = "", open=0, close=0

1️⃣ '(' add → curr="(", open=1, close=0  
   → '(' add → curr="((", open=2, close=0  
      → ')' add → curr="(()", open=2, close=1  
         → ')' add → curr="(())" ✅ valid  
   → backtrack  
   → ')' add → curr="()", open=1, close=1  
      → '(' add → curr="()(", open=2, close=1  
         → ')' add → curr="()()" ✅ valid  

✅ Final Output = ["(())", "()()"]

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
O(4^n / √n) → Catalan Number complexity  
(Same as number of valid parentheses combinations)

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(n) recursion stack (for curr path)

------------------------------------------------------------
⚡ NOTE:
------------------------------------------------------------
- Yeh optimized version hai (no need to check validity).
- Generates only valid strings → efficient & elegant.
------------------------------------------------------------
*/
