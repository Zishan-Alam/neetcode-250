class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        bool cycle = false;

        // Phase 1: Detect cycle using Floyd’s algorithm
        while(fast && fast->next) {
            slow = slow->next;          // slow = +1
            fast = fast->next->next;    // fast = +2

            if(slow == fast) {          // meeting point
                cycle = true;
                break;
            }
        }

        // If no cycle found → return null
        if(cycle == false) return nullptr;

        // Phase 2: Find cycle start
        ListNode* temp = head;
        while(temp != slow) {
            slow = slow->next;
            temp = temp->next;
        }

        return slow;  // cycle starting point
    }
};

/*
🧠 Intuition (Roman Hindi):
Slow ek step, fast do step chalta hai.  
Agar cycle hogi to dono ek point par milenge.  
Meeting point milne ke baad:
  - ek pointer head se start karo
  - doosra meeting point se
Dono 1-1 step chalenge  
Jaha par milte hain → wahi cycle ka start hota hai.

🔎 Dry Run:
List: 1 → 2 → 3 → 4 → 5 → 3 (cycle)
slow-fast meet at node 4  
temp = head (1), slow = 4  
1→2→3  
4→5→3  
Meet at 3 → answer.

⏱ Time Complexity: O(N)
💾 Space Complexity: O(1)
*/
