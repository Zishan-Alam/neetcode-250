class Solution {
public:

    // 🧮 Helper function: performs arithmetic operation
    int operate(int a, int b, string token) {
        if(token == "+") return a + b;
        else if(token == "-") return a - b;
        else if(token == "*") return a * b;
        else if(token == "/") return a / b;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        // 🔁 Iterate over each token
        for(string &token : tokens) {
            // If it's an operator, pop top two elements and compute result
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand
                int res = operate(a, b, token);
                st.push(res);
            }
            else {
                // Else convert string to integer and push
                st.push(stoi(token));
            }
        }

        // Final result will be the only element left in stack
        return st.top();
    }
};

/*
🧠 Intuition (Roman Hindi me):
Bhai yahan postfix expression (RPN) diya hota hai jisme operators operands ke baad likhe hote hain.
Hum stack use karke evaluate karte hain:
- Jab tak number mile → stack me push karte jao.
- Jab operator mile → top ke 2 numbers nikaalo, operation karo, aur result wapas stack me daal do.
End me stack ke top par hi final answer hota hai.

📘 Dry Run:
Input → ["2","1","+","3","*"]
Step 1: push(2)
Step 2: push(1)
Step 3: token = "+" → a=2, b=1 → res=3 → push(3)
Step 4: push(3)
Step 5: token = "*" → a=3, b=3 → res=9 → push(9)
✅ Output = 9

⏱️ Time Complexity:  O(n)
(Each token ek baar process hota hai)

💾 Space Complexity: O(n)
(Stack me max n/2 elements store ho sakte hain)
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// Using Unordered_map and Lambda

class Solution {
public:

    // 🔧 Map of operators with corresponding lambda functions
    unordered_map<string, function<int (int,int)>> mp = {
        {"+", [](int a, int b) {return a + b;}},
        {"-", [](int a, int b) {return a - b;}},
        {"*", [](int a, int b) {return a * b;}},
        {"/", [](int a, int b) {return a / b;}}
    };

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        // 🔁 Iterate over each token
        for(string &token : tokens) {
            if(mp.find(token) != mp.end()) { 
                // If it's an operator
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = mp[token](a, b); // call lambda function
                st.push(res);
            }
            else {
                // Otherwise it's a number → push to stack
                st.push(stoi(token));
            }
        }

        // Final result will be top element
        return st.top();
    }
};

/*
🧠 Intuition (Roman Hindi me):
Bhai postfix (RPN) expression me operands pehle aur operator baad me aata hai.
Stack ka use karke hum evaluate karte hain:
→ Jab tak number mile, stack me daalte jao.
→ Jab operator mile, top ke do elements nikaalo (a, b), unpe operation karo, aur result wapas push karo.
End me stack ke top pe final result hoga.

⚙️ Example Dry Run:
Input: ["2","1","+","3","*"]

Step 1: push(2)
Step 2: push(1)
Step 3: token = "+" → a=2, b=1 → res=3 → push(3)
Step 4: push(3)
Step 5: token = "*" → a=3, b=3 → res=9 → push(9)
✅ Output = 9

⏱️ Time Complexity:  O(n)
(Each token ek hi baar process hota hai)

💾 Space Complexity: O(n)
(Stack me max n/2 operands store ho sakte hain)
*/
