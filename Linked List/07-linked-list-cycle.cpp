class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;         // 1 step
            fast = fast->next->next;   // 2 steps

            if(slow == fast) return true; // cycle mil gaya
        }
        return false; // fast null -> cycle nahi hai
    }
};

/*
🧠 Intuition (Roman Hindi):
Slow 1 step chalta hai, fast 2 steps. Agar linked list me cycle hoga to fast track ke andar slow ko kabhi na kabhi catch kar lega. 
Agar slow == fast ho gaya → cycle hai. Agar fast null tak pahunch gaya → cycle nahi.

🔎 Dry Run:
1 → 2 → 3 → 4 → 5 → 3 (cycle)
slow: 1→2→3→4
fast: 1→3→5→4
slow == fast at node 4 → cycle found.

⏱ Time Complexity: O(N)
💾 Space Complexity: O(1)
*/
