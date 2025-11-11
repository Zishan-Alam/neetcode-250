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
