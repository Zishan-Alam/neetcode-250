class MinStack {
public:
    stack<pair<int, int>> st; // {value, current_min}

    MinStack() {}

    void push(int val) {
        // agar stack empty hai, min value khud hi hai
        if(st.empty()) {
            st.push({val, val});
        } 
        else {
            int currMin = min(val, st.top().second);
            st.push({val, currMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Bhai, har element ke saath us tak ka minimum bhi store kar lete hain.
Jab bhi naya element aata hai, usse compare kar lete hain purane min se.
Isse har step par current minimum pata hota hai bina pura stack traverse kiye.

🧩 Dry Run:
push(5) → st = [(5,5)]
push(3) → st = [(5,5), (3,3)]
push(7) → st = [(5,5), (3,3), (7,3)]
getMin() → 3 ✅
pop() → st = [(5,5), (3,3)]
getMin() → 3 ✅
pop() → st = [(5,5)]
getMin() → 5 ✅

⏱️ Time Complexity:
push()    → O(1)
pop()     → O(1)
top()     → O(1)
getMin()  → O(1)

💾 Space Complexity:
O(2*n) → har element ke saath uska min store kar rahe hain
*/

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// Encoded Minimum value Approach

class MinStack {
public:
    stack<long long> st;   // Stores encoded values
    long long minVal;      // Current minimum

    MinStack() {
        minVal = LLONG_MAX; //  Proper initialization
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minVal = val;
        }
        else {
            if(val < minVal) {
                // Encode previous min to recover later  (2LL -> long long 2, typecasting to long long)
                st.push(2LL * val - minVal);
                minVal = val;
            } 
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long topVal = st.top();
        st.pop();

        // If top was encoded, recover previous min
        if(topVal < minVal) {
            minVal = 2LL * minVal - topVal;
        }
    }
    
    int top() {
        long long topVal = st.top();
        if(topVal < minVal)
            return minVal;  // Encoded case: real top = minVal
        else
            return topVal;
    }
    
    int getMin() {
        return (int)minVal;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Bhai, jab bhi naya element chhota hota hai, hum usse "encode" kar dete hain
(2*val - prevMin) formula se, taaki hum previous min ko trace kar sakein.
Jab pop karte hain aur encoded number milta hai, hum purana min nikaal lete hain.

⚙️ Dry Run:
push(5) → st=[5], min=5
push(2) → st=[5, (2*2-5)=-1], min=2
push(8) → st=[5, -1, 8], min=2
pop()   → 8 remove, min=2
pop()   → top=-1 < min(2) → newMin = 2*2 - (-1)=5 ✅
Now min=5, st=[5]
getMin() → 5 ✅

⏱️ Time Complexity:
push()  → O(1)
pop()   → O(1)
top()   → O(1)
getMin()→ O(1)

💾 Space Complexity:
O(n) → sirf ek stack use kar rahe hain
*/
