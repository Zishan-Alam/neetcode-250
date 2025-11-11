class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {}

    void push(int x) {
        // Step 1️⃣: Move all elements of st1 → st2
        // Taki hum new element ko bottom me daal sake (queue ke end me)
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Step 2️⃣: Push new element to st1
        st1.push(x);   // Yeh queue ke end me jaata hai

        // Step 3️⃣: Move all elements back from st2 → st1
        // Ab sab kuch waapas order me hai
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        // Top element of st1 is the front of the queue
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        // Return front element (top of st1)
        return st1.top();
    }
    
    bool empty() {
        // Queue empty if st1 has no elements
        return st1.empty();
    }
};

/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Queue FIFO (First In First Out) hota hai,
jabki Stack LIFO (Last In First Out).

Toh stack se queue banane ke liye, hum element ko hamesha
bottom me daalte hain taaki pehle daale hue elements pehle nikle.

👉 Isliye har push ke time:
1️⃣ Purane sab elements ko st2 me daal diya.
2️⃣ Naya element st1 me push kiya.
3️⃣ Fir st2 ke sab elements ko waapas st1 me daal diya.

Ab st1 ke top pe hamesha queue ka **front** hoga.

------------------------------------------------------------
🔍 DRY RUN:
------------------------------------------------------------
Input:
["MyQueue","push","push","peek","pop","empty"]
[[],[1],[2],[],[],[]]

Step 1️⃣ → push(1)
st1 = [1]   (1 front)

Step 2️⃣ → push(2)
→ st1→st2 = [1]
→ st1.push(2) → [2]
→ st2→st1 = [2,1]
(front = 1, rear = 2)

Step 3️⃣ → peek()
return st1.top() → 1 ✅

Step 4️⃣ → pop()
pop st1.top() = 1
now st1 = [2]

Step 5️⃣ → empty()
false ✅

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
push() → O(N) (because all elements are moved twice)
pop(), peek(), empty() → O(1)

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(N) → for two stacks (st1 + st2)
------------------------------------------------------------
*/
