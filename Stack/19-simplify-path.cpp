class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token = "";
        stringstream ss(path);

        // Split the path by '/'
        while(getline(ss, token, '/')) {
            if(token == "" || token == ".") continue;  // Ignore empty or '.'

            if(token == "..") {
                if(!st.empty()) st.pop(); // Move one directory up
            } 
            else {
                st.push(token); // Valid directory name
            }
        }

        if(st.empty()) return "/";

        // Construct the canonical path
        string res = "";
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Unix-style file path simplification karni hai.
Path me "." ka matlab current directory aur ".." ka matlab ek level upar.
Jo bhi normal names hain unhe stack me daal lo.
Agar ".." mila to ek element pop kar do (agar stack khaali nahi hai).

Example:
Input: "/home//foo/../bar/"
Tokens → ["home", "foo", "..", "bar"]
Stack dry run:
- "home" → push
- "foo"  → push
- ".."   → pop("foo")
- "bar"  → push
Stack = ["home","bar"]
Final path = "/home/bar"

⏱️ Time Complexity: O(N)
💾 Space Complexity: O(N)
*/
