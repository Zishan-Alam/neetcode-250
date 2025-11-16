class Solution {
public:
    int length(ListNode* head) {
        int n = 0;
        while(head) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        int n = length(head);

        ListNode* first = head;
        ListNode* second = head;

        // move first to kth node (1-based)
        for(int i = 1; i < k; i++)
            first = first->next;

        // move second to (n-k+1)-th node (1-based)
        for(int i = 1; i < n - k + 1; i++)
            second = second->next;

        // swap values
        swap(first->val, second->val);

        return head;
    }
};


/*
=====================================================
🔥 Intuition (Roman Hindi)
=====================================================
Bhai hume:
- start se k-th node
- end se k-th node
ko swap karna hai.

Approach:
1️⃣ Pehle list ka length n nikaal lo.  
2️⃣ 'first' pointer ko k-1 steps move karo → kth node mil jayegi.  
3️⃣ 'second' pointer ko (n-k) steps move karo → end se kth node mil jayegi.  
4️⃣ Dono nodes ke values ko swap kar do.  
=====================================================
🧪 Dry Run
List: 1 → 2 → 3 → 4 → 5, k = 2

Length = 5

first:
move 1 time → first = 2

second:
move (5-2) = 3 times → second = 4

swap(2,4)

Result: 1 → 4 → 3 → 2 → 5
=====================================================
⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)
=====================================================
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head->next) return head; // 1-node list → nothing to swap

        ListNode* first = head;
        ListNode* second = head;
        
        ListNode* fast = head;

        // 1️⃣ Move fast to kth node (from start)
        for(int i=1; i<k; i++) fast = fast->next;
        first = fast;   // this is kth from start

        // 2️⃣ Move fast to end + move second accordingly
        while(fast->next) {
            fast = fast->next;
            second = second->next;
        }
        // second is kth from end

        // 3️⃣ Swap values
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};


/*
=========================================
🔥 Intuition (Roman Hindi)
=========================================
Bhai problem simple hai:

- Hume **start se kth node** aur  
- **end se kth node** ko swap karna hai.

Approach:
1️⃣ Pehle fast ko k-1 step aage le jao → ye kth node hoga → isko "first" bol do  
2️⃣ Ab fast ko end tak le jao, aur sath me second ko move karao  
   → second last se kth node pe pahunch jayega  
3️⃣ Dono nodes ke values ko swap kar do.

=========================================
🧪 Dry Run
List: 1 → 2 → 3 → 4 → 5, k = 2

Step1:
fast moves 1 time → fast = 2
first = 2

Step2:
Move fast to end + move second:
fast=3, second=2
fast=4, second=3
fast=5, second=4

second = 4 (kth from end)

Step3:
swap(2,4)

Result: 1 → 4 → 3 → 2 → 5

=========================================
⏱️ Time Complexity
O(n)

💾 Space Complexity
O(1)
=========================================
*/
