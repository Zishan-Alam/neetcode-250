// ✅ PALINDROME PARTITIONING (Backtracking Approach)
// ------------------------------------------------------------
// Author: Zishan Alam Khan
// Description: Generate all possible partitions of a string 
//              such that every substring is a palindrome.
// ------------------------------------------------------------

class Solution {
public:

    // ------------------------------------------------------------
    // Helper function: Check if substring s[start...end] is palindrome
    // ------------------------------------------------------------
    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;  // move forward
            end--;    // move backward
        }
        return true;
    }

    // ------------------------------------------------------------
    // Recursive DFS function to explore partitions
    // ------------------------------------------------------------
    void dfs(string &s, int idx, vector<string> &path, vector<vector<string>> &res) {
        // Base case: if we reach end of string, store current partition
        if(idx == s.length()) {
            res.push_back(path);
            return;
        }

        // Explore all possible substring partitions from idx to end
        for(int end = idx; end < s.length(); end++) {

            // If substring s[idx...end] is palindrome
            if(isPalindrome(s, idx, end)) {
                // Choose (include current substring)
                path.push_back(s.substr(idx, end - idx + 1));

                // Recurse for remaining string
                dfs(s, end + 1, path, res);

                // Backtrack (undo the choice)
                path.pop_back();
            }
        }
    }

    // ------------------------------------------------------------
    // Main function
    // ------------------------------------------------------------
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};

        vector<vector<string>> res;
        vector<string> path;

        dfs(s, 0, path, res);
        return res;
    }
};


/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Har index se hum possible substrings check karte hain.
Agar substring palindrome hai, to usse current partition me leke 
aage ke part par recursion chala dete hain.

Backtracking ke through sab possible combinations explore karte hain.

------------------------------------------------------------
🔍 DRY RUN EXAMPLE:
------------------------------------------------------------
Input: "aab"

Step-by-step:
1️⃣ Start at idx = 0
   "a" (palindrome) -> path = ["a"]
   Recurse from idx = 1

2️⃣ From idx = 1
   "a" (palindrome) -> path = ["a", "a"]
   Recurse from idx = 2

3️⃣ From idx = 2
   "b" (palindrome) -> path = ["a", "a", "b"]
   Recurse from idx = 3 → push ["a","a","b"] to res

   Backtrack -> path = ["a", "a"]

4️⃣ Backtrack to idx = 0
   "aa" (palindrome) -> path = ["aa"]
   Recurse from idx = 2

5️⃣ From idx = 2
   "b" (palindrome) -> path = ["aa", "b"]
   push ["aa","b"] to res

✅ Final Output:
[["a","a","b"], ["aa","b"]]

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
O(2^n * n)
- 2^n combinations (each character has split/no-split choice)
- Each substring palindrome check takes O(n)

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(n) (recursion depth + current path storage)
------------------------------------------------------------
*/
