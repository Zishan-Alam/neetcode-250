class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max-heap (default priority_queue) bana rahe hain
        // taaki hamesha sabse bade do stones top pe rahein
        priority_queue<int, vector<int>> pq;

        // saare stones ko heap me daal do
        for(int &num : stones) {
            pq.push(num);
        }

        // jab tak 1 se zyada stones bache hain
        while(pq.size() > 1) {
            // top ke do largest stones nikaal lo
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();

            // dono ko tod do (subtract kar do)
            // agar dono equal hue to result 0 hoga
            int ans = abs(num1 - num2);

            // ab naya stone (difference) heap me daal do
            pq.push(ans);
        }

        // agar ek stone bacha hai to uska weight return karo
        // (agar sab 0 ho gaye to top 0 return karega)
        return pq.top();
    }
};

/*
🧠 Intuition (Hinglish me):
Har step pe hume do sabse heavy stones todne hain.
Isliye max-heap use karte hain taaki hamesha top pe sabse bade do stones mil jaayein.
Unka difference nikalke wapas heap me daal dete hain.
End me jo ek stone bacha, wahi answer hai.

⚙️ Time Complexity:
→ O(n log n)
    - Har stone ko heap me daalne me O(log n) lagta hai.
    - Aur har operation (pop/push) bhi O(log n) hai.
    - Worst case me n-1 baar loop chalega.

💾 Space Complexity:
→ O(n)
    - Heap me maximum n stones store hote hain.
*/
