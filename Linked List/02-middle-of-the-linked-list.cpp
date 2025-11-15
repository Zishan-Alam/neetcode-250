class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;   // moves 1 step
        ListNode* fast = head;   // moves 2 steps

        // Jab tak fast end tak nahi pahunchta
        while(fast && fast->next) {
            slow = slow->next;         // slow ek step
            fast = fast->next->next;   // fast do step
        }

        return slow;   // slow middle par hoga
    }
};


/*
==================================
🔥 Intuition (Roman Hindi)
==================================
Bhai, hum fast–slow pointer technique use karte hain.

- fast pointer 2 step chalta hai
- slow pointer 1 step chalta hai

Jab fast pointer end tak pahunchta hai,
tab tak slow pointer exactly linked list ke middle par hota hai.

Agar list even length ki ho:
→ slow second middle par rukta hai (LC ka requirement).

==================================
🧪 Dry Run Example
List: 1 → 2 → 3 → 4 → 5

slow = 1, fast = 1

Loop 1:
slow = 2  
fast = 3  

Loop 2:
slow = 3  
fast = 5  

Loop 3:
fast->next = NULL → loop stop  
Return slow = 3  
✔ middle = 3

Even list example:
1 → 2 → 3 → 4 → 5 → 6

slow = 4 return hota hai (2nd middle)

==================================
⏱️ Time Complexity
==================================
O(n) — poora list ek baar traverse hota hai.

==================================
💾 Space Complexity
==================================
O(1) — sirf 2 pointers lagte hain.

*/
