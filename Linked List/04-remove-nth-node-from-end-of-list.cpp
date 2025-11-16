class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast ahead by n+1 steps
        for(int i=0; i<n+1; i++) {
            // If fast null ho gaya → matlab hume head delete karna hoga
            if(fast == nullptr) return head->next;
            fast = fast->next;
        }

        // Move slow & fast together
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow is just before the target node
        slow->next = slow->next->next;

        return head;
    }
};


/*
=========================================
🔥 Intuition (Roman Hindi)
=========================================
Bhai yaha trick simple hai:
Hume last se Nth node delete karna hai,
to hum do pointer (fast & slow) use karenge.

1️⃣ Fast ko n+1 steps aage bhejo.
   - Why n+1?
     Taaki slow final me **delete karne wale node ke just pehle** ruk jaye.

2️⃣ Ab fast aur slow ko sath chalate raho.
   - Jab fast end pohonch jayega,
     slow exactly delete-target ke previous node par hoga.

3️⃣ slow->next ko skip kar do.
   - Bas delete ho gaya.

Special case:
- Agar fast n+1 move karte time NULL ho jaye → iska matlab head hi delete karna hai.

=========================================
🧪 Dry Run
List: 1 → 2 → 3 → 4 → 5  
n = 2 (last se 2nd = 4 delete karna hai)

Step 1: fast ko n+1 = 3 steps move:
- fast: 1 → 2 → 3 → 4
- slow: 1

Step 2: move together:
1) fast=5, slow=2
2) fast=null, slow=3

→ slow is at 3, which is just before 4.

Step 3:
slow->next = slow->next->next  
3 → 5

Final list:
1 → 2 → 3 → 5

=========================================
⏱️ Time Complexity
=========================================
O(n) — list ek baar traverse hoti hai.

=========================================
💾 Space Complexity
=========================================
O(1) — extra memory nahi.

*/
