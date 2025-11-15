class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // If only one node → delete it (middle is itself)
        if(!head->next) return nullptr;

        ListNode* prevSlow = head;   // slow ka previous track karega
        ListNode* slow = head;       // middle ko find karega
        ListNode* fast = head;       // 2-step pointer

        // Fast 2 step, slow 1 step → slow middle par aayega
        while(fast && fast->next) {
            prevSlow = slow;           
            slow = slow->next;        
            fast = fast->next->next;  
        }

        // slow = middle node
        // prevSlow middle ke ek pehle
        prevSlow->next = slow->next;   // middle ko skip kiya

        return head;
    }
};


/*
=========================================
🔥 Intuition (Roman Hindi)
=========================================
Bhai, hum same slow–fast pointer technique use karte hain:

- fast 2 step chalti hai
- slow 1 step

Jab fast end tak pahunchti hai,
slow bilkul middle node par hota hai.

Ab middle ko delete karna hai:
- prevSlow slow se ek node pehle hota hai
- bas prevSlow->next = slow->next kar diya

Isse slow wala middle node list se remove ho jata hai.

=========================================
🧪 Dry Run Example
List: 1 → 2 → 3 → 4 → 5

slow = 1  
fast = 1  
prevSlow = 1

Loop 1:
slow = 2  
fast = 3  
prevSlow = 1

Loop 2:
slow = 3  
fast = 5  
prevSlow = 2

Loop stops.

Middle = 3  
prevSlow = 2  

Delete:
2 → next = 4

Final list:
1 → 2 → 4 → 5

=========================================
⏱️ Time Complexity
=========================================
O(n) — linked list ek hi pass me traverse hota hai.

=========================================
💾 Space Complexity
=========================================
O(1) — sirf 3 pointers use ho rahe hain.

*/
