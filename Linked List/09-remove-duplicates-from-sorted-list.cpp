class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* a = head;     
        ListNode* b = a->next;   

        while (b != nullptr) {

            // Skip all nodes having same value as a
            while (b != nullptr && b->val == a->val) 
                b = b->next;

            // Link next distinct element
            a->next = b;

            // Move both pointers ahead
            a = b;
            if (b) b = b->next;
        }
        return head;
    }
};

/*
🧠 Intuition (Roman Hindi):
List sorted hai, toh duplicates hamesha side-by-side honge.
Isliye do pointer use karte:
a = current valid node,
b = next node.
Jab tak b ka value a ke equal hota hai, b ko aage badhate jao.
Jab new distinct value mile, a->next = b kar do.
Isse duplicate nodes skip ho jaate hain without extra space.

🔎 Dry Run:
Input: 1 → 1 → 2 → 3 → 3
a = 1, b = 1
b matches → b = 2
a->next = 2
a = 2, b = 3
b=3 matches → b = null
a->next = null

Output: 1 → 2 → 3

⏱ Time Complexity: O(N)
Har node ko max 2 baar touch karte ho (a + b pointers)

💾 Space Complexity: O(1)
Koi extra array/set/list nahi use hota.
*/
