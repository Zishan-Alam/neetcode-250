class Solution {
public:
    void deleteNode(ListNode* node) {
        // Important condition: node should not be tail
        if(node && node->next) {

            // Copy next node's value into current node
            node->val = node->next->val;

            // Skip over the next node → delete it logically
            node->next = node->next->next;
        }
    }
};


/*
=========================================
🔥 Intuition (Roman Hindi)
=========================================
Bhai is problem me ek twist hai:
Hume **delete karna wo node hai jis ka pointer diya hua hai, 
par uske previous node ka pointer nahi diya**.

Normal delete me hum previous node se link todte.
Par yaha previous access nahi hai.

⚡ Trick:
- next node ka value current node me copy kar do
- current->next ko next->next se connect kar do

Isse next node delete ho jati hai,
aur current node logically "replace" ho jata hai.
Is tarah se aisa lagta hai ki current node delete ho gaya.

=========================================
🧪 Dry Run Example
List: 4 → 5 → 1 → 9  
Given node = 5 (isko delete karna hai)

Step 1: node->val = node->next->val  
         5 → 1 बन गया  

List: 4 → 1 → 1 → 9

Step 2: node->next = node->next->next  
         1 → next = 9

Final list:
4 → 1 → 9

Middle node effectively delete ho gayi.

=========================================
⏱️ Time Complexity
=========================================
O(1) — sirf constant operations.

=========================================
💾 Space Complexity
=========================================
O(1) — koi extra space nahi.

*/

