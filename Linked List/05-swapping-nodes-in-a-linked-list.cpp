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

