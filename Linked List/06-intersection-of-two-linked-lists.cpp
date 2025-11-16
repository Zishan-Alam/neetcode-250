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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int diff = abs(lenA - lenB);

        // Move longer list pointer ahead
        if(lenA > lenB) {
            for(int i=0; i<diff; i++) tempA = tempA->next;
        }
        else {
            for(int i=0; i<diff; i++) tempB = tempB->next;
        }

        // Move both pointers together
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;        
    }
};

/*
=====================================================================
🔥 Intuition (Roman Hindi)
=====================================================================
Do linked lists alag length ki ho sakti hain.  
Agar intersection hoga, to last ke kuch nodes dono lists me SAME honge.

Problem:
Dono pointers agar start se chalaoge to wo kabhi saath-saath intersection pe 
nahi pahunchte—kyunki lengths different hain.

Solution Intuition:
1️⃣ Pehle dono lists ka length nikaal lo.  
2️⃣ Jo list LAMBI hai, uska pointer 'diff' steps aage badha do.  
   Ab dono pointers end se SAME distance pe khade hain.  
3️⃣ Ab dono pointers ko same speed se move karo.  
4️⃣ Jis node par pehli baar tempA == tempB ho → wahi intersection hai.

=====================================================================
🧪 Dry Run
List A: 1 → 3 → 5 → 7 → 9 → 11  
List B:       2 → 4 → 7 → 9 → 11  
Intersection = 7

lenA = 6  
lenB = 5  
diff = 1  

A pointer ko 1 step aage badhao:
tempA = 3 → 5 → 7 → 9 → 11  
tempB = 2 → 4 → 7 → 9 → 11

Ab dono move saath-saath:
5 != 4  
7 == 7  → intersection found

=====================================================================
⏱️ Time Complexity: O(n + m)
💾 Space Complexity: O(1)
=====================================================================
*/
