class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;  
        // final answer store karne ke liye variable — ye wahi number hoga jo sirf 1 baar aaya ho

        for (int bit = 0; bit < 32; bit++) {
            // har bit position (0 se 31 tak) check karenge
            // int me total 32 bits hoti hain

            int mask = (1 << bit);
            // mask banaya — jisse check kar sake ki current bit set (1) hai ya nahi

            int countZero = 0;
            int countOne = 0;
            // har bit position par 0 aur 1 ke occurrences count karne ke liye

            for (int &num : nums) {
                // har element ke liye check karenge ki current bit 0 hai ya 1

                if ((num & mask) == 0)
                    countZero++;      // agar us bit par 0 hai
                else
                    countOne++;       // agar us bit par 1 hai
            }

            if (countOne % 3 == 1)
                result = result | mask;
            // agar is bit position pe 1 ka count %3 karne ke baad 1 bacha,
            // to iska matlab ye bit unique element me set hai
        }

        return result;  
        // ye final number hoga jo sirf ek baar aaya hai
    }
};


/* 🧠 Intuition (Roman Hindi me):

Is problem me har number 3 times repeat hota hai, sirf ek number alag hai.
To har bit position ke liye dekhte hain —
kitne numbers me wo bit set hai (count of 1).
Agar koi bit position pe 1 ki count 3 ka multiple nahi hai
(i.e. countOne % 3 == 1),
to wo bit sirf unique element ke wajah se aayi hai.

Isliye hum us bit ko result me set kar dete hain.
End me result hi wo number hota hai jo exactly once aaya tha 💡

⏱️ Time Complexity:

O(32 × n) ≈ O(n)
(har bit ke liye poora array traverse karte hain)

💾 Space Complexity:

O(1)
(sirf kuch variables use hue hain) */


