// using two queues

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {}

    void push(int x) {
        // Step 1: Push new element into que2
        que2.push(x);

        // Step 2: Move all elements from que1 -> que2
        while(!que1.empty()) {
            que2.push(que1.front()); que1.pop();
        }

        // Step 3: Swap que1 and que2
        // So that que1 always has newest element at the front
        while(!que2.empty()) {
            que1.push(que2.front()); que2.pop();
        }
    }

    int pop() {
        int ans = que1.front();
        que1.pop();
        return ans;
    }

    int top() {
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};

/*
🧠 Intuition:
Normal queue works as FIFO (First In First Out),
but we need stack behavior (LIFO - Last In First Out).
To achieve this using 2 queues:
  - Jab bhi naya element push karte hain, usse pehle purane sab elements ko peeche shift kar dete hain.
  - Isse queue ka front hamesha stack ke top jaisa ban jaata hai.

🪜 Dry Run:
operations = ["push(1)", "push(2)", "top()", "pop()", "empty()"]

Step 1: push(1)
 que1 = [1]

Step 2: push(2)
 que2 = [2]
 move que1 -> que2 ⇒ que2 = [2,1]
 swap ⇒ que1 = [2,1]

Step 3: top() ⇒ returns 2 (front of que1)
Step 4: pop() ⇒ removes 2, que1 = [1]
Step 5: empty() ⇒ false

✅ Output = [null, null, null, 2, 2, false]

⏱️ Time Complexity:
- push(): O(n)  (har push pe purane elements shift hote hain)
- pop(): O(1)
- top(): O(1)

💾 Space Complexity:
O(n)  (kyunki hum 2 queues store kar rahe hain)
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {}

    void push(int x) {
        // Step 1️⃣: Move all elements of que1 → que2
        // So we can insert the new element at front position later
        while(!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }

        // Step 2️⃣: Push the new element (x) into que1
        que1.push(x);

        // Step 3️⃣: Move everything back from que2 → que1
        // so that new element stays at front (acting as stack top)
        while(!que2.empty()) {
            que1.push(que2.front());
            que2.pop();
        }
    }
    
    int pop() {
        // Top element (front of queue) removed
        int ans = que1.front();
        que1.pop();
        return ans;
    }
    
    int top() {
        // Front element is the current stack top
        return que1.front();
    }
    
    bool empty() {
        // Stack is empty if que1 has no elements
        return que1.empty();
    }
};

/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Stack LIFO (Last In First Out) hota hai, jabki Queue FIFO (First In First Out).
Toh queue se stack banana hai, toh hume naya element hamesha "front" pe laana hoga.

Isliye:
1️⃣ Pehle purane sab elements ko que2 me daal diya.
2️⃣ Naya element x ko que1 me push kiya.
3️⃣ Fir que2 ke sab elements ko waapas que1 me daal diya.
Ab naya element front pe aa gaya — jaise stack ka top.

------------------------------------------------------------
🔍 DRY RUN:
------------------------------------------------------------
Input:
["MyStack","push","push","top","pop","empty"]
[[],[1],[2],[],[],[]]

Step 1️⃣ → push(1)
que1 = [1]
que2 = []
top = 1

Step 2️⃣ → push(2)
→ move que1 → que2 → que2 = [1]
→ que1 = [2]
→ move que2 → que1 → que1 = [2,1]
top = 2

Step 3️⃣ → top()
return que1.front() → 2 ✅

Step 4️⃣ → pop()
return que1.front() = 2
after pop → que1 = [1]

Step 5️⃣ → empty()
que1 not empty → false ✅

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
push() → O(N) (har baar saare elements move karne padte hain)
pop(), top(), empty() → O(1)

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(N) → 2 queues use ho rahe hain (que1 + que2)
------------------------------------------------------------
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
