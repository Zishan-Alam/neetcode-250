class Solution {
public:
    void deleteNode(ListNode* node) {

        // prev pointer track karega second last node ko
        ListNode* prev = nullptr;

        // Jab tak next node exist karta hai,
        // current node ka value next wale node se copy karte jao
        while(node->next) {

            prev = node;                     // previous ko store karo
            node->val = node->next->val;     // next node ka value copy karo
            node = node->next;               // aage badho
        }

        // Ab hum last node par aagaye
        // prev second-last node par hai
        prev->next = nullptr;                // last node ko list se hatao
        delete(node);                         // last node ko free kar do
    }
};



/*
===========================
🔥 Intuition (Roman Hindi)
===========================
Bhai, yaha problem ye hai ki hum jis node ko delete karna chahte hain,
uska previous node nahi mil sakta. Isliye hum ek trick use karte hain:

- jis node ko delete karna hai, usme "next node ka value" copy kar do.
- phir pointer ko aage badhate jao aur value copy karte jao.
- jab last node par pahunch jao, usko simply prev->next = NULL karke delete kar do.

Is tarike se hum bina previous pointer ke node ko delete kar sakte hain.

====================================
🧪 Dry Run
List: 4 → 5 → 1 → 9
delete node = 5
====================================

Step 1:
node = 5
copy 1 → list becomes: 4 → 1 → 1 → 9

Step 2:
node = 1 (2nd)
copy 9 → list becomes: 4 → 1 → 9 → 9

Step 3:
node = 9 (3rd)
node->next = NULL → loop stops

prev = 2nd last node
prev->next = NULL
delete(last)

Final list: 4 → 1 → 9

===========================
⏱️ Time Complexity
===========================
O(n) — last node tak traverse karna padta hai.

===========================
💾 Space Complexity
===========================
O(1) — constant space only.

*/
