class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;  
        // final answer store karne ke liye variable — ye XOR ka combined result hoga

        for (int bit = 0; bit < 32; bit++) {  
            // har bit position (0 se 31 tak) check karenge
            // int me total 32 bits hoti hain

            int temp = (1 << bit);  
            // 'temp' ek mask hai — jisse hum check karenge ki current bit set (1) hai ya nahi

            int countZero = 0;  
            int countOne = 0;  
            // ye dono counters har bit position par 0s aur 1s ko count karne ke liye

            for (int &num : nums) {  
                // har number ke liye check karenge ki us bit par kya value hai

                if ((num & temp) == 0)  
                    countZero++;   // agar us bit par 0 hai
                else  
                    countOne++;    // agar us bit par 1 hai
            }

            if (countOne % 2 == 1)  
                result = result | temp;  
            // agar kisi bit position par 1s ki count odd hai,
            // iska matlab XOR result me wo bit set honi chahiye
        }

        return result;  
        // final XOR result — ye wahi number hoga jo sirf ek baar aaya hai
    }
};

/* 🧠 Intuition (Roman Hindi me):

Yaha hum bit-by-bit check karte hain ki har position par kitne numbers me bit 1 hai.
Agar kisi bit position pe 1 ki count odd hai, to wo bit final answer me set hogi —
kyunki XOR ka rule kehta hai:

even times 1 → 0 ban jaata hai,
odd times 1 → 1 ban jaata hai.

Is tarah har bit ke liye ye logic apply karke hum unique number nikal lete hain jo sirf ek baar aaya ho.

⏱️ Time Complexity:

O(32 × n) → ≈ O(n)
(kyunki hum 32 bits ke liye har element traverse karte hain)

💾 Space Complexity:

O(1)
(sirf kuch constant variables use hue hain) */



