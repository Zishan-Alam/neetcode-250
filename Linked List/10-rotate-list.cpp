class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if (!head || !head->next) return head;

        // STEP 1: Find length and tail
        int n = 0;
        ListNode* temp = head;
        ListNode* tail = head;

        while (temp) {
            n++;
            if (temp->next == nullptr) tail = temp;
            temp = temp->next;
        }

        // STEP 2: Effective rotation
        k = k % n;  
        if (k == 0) return head;

        // STEP 3: Find the break point (n-k-1)
        temp = head;
        for (int i = 0; i < n - k - 1; i++) {
            temp = temp->next;
        }

        // STEP 4: Rotate
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

/*
🧠 Intuition (Roman Hindi):
List ko right side rotate karne ka matlab:
Last ke k nodes ko aage le aao.

Example:
1 → 2 → 3 → 4 → 5, k = 2
Output:
4 → 5 → 1 → 2 → 3

Steps:
1. Length n find karo.
2. Rotation effective tab hota hai jab k = k % n.
3. New head hoga (n-k)th node ke baad wala node.
4. Tail ko head se jod do → circular list ban jaati hai.
5. Break point (n-k-1) par next = NULL kar do → rotated list mil jaati hai.

---

🧪 Dry Run:
Input: 1→2→3→4→5, k=2

n = 5  
k = 2 % 5 = 2  
Break point = n-k-1 = 5-2-1 = 2  
(temp stops at node with value 3)

Before:
1 → 2 → 3 → 4 → 5  
Tail = 5  

Step:
tail->next = head  → list becomes circular  
New head = temp->next = 4  
temp->next = NULL → break  

Result:
4 → 5 → 1 → 2 → 3

---

⏱ Time Complexity: O(N)
Ek hi traversal mein length + rotation.

💾 Space Complexity: O(1)
Koi extra DS use nahi hota.
*/
