class Solution {
public:
    int hammingWeight(int n) {
        // __builtin_popcount(n) ek built-in GCC function hai
        // Ye function 'n' ke binary representation me kitne bits 1 (set bits) hain, wo count karta hai.
        // Example: n = 11 (binary: 1011) → output = 3
        return __builtin_popcount(n);
    }
};

/*
🧠 Intuition:
Ye problem me hume given integer ke binary form me kitne bits 1 hain, wo count karna hai.
Instead of manually checking each bit, hum GCC ke built-in function __builtin_popcount() ka use karte hain,
jo internally har bit check karke total set bits return karta hai — fast aur optimized tarike se.

⚙️ Time Complexity: O(1)
__builtin_popcount hardware-level instruction ka use karta hai (constant time me kaam karta hai),
toh ye operation fix time me complete hota hai.

💾 Space Complexity: O(1)
Koi extra space ya data structure use nahi hua — sirf ek integer return hota hai.
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;  
        // count variable rakha gaya hai total set bits (1s) track karne ke liye

        while (n != 0) {
            // Jab tak n zero nahi hota, loop chalta rahega

            n = n & (n - 1);
            // Ye step sabse powerful hai 💡
            // Har iteration me n ke least significant set bit (1) ko remove kar deta hai
            // Example:
            // n = 1011 → n-1 = 1010 → n & (n-1) = 1010
            // Is tarah har baar ek set bit kam ho jati hai

            count++;  
            // Har baar ek bit remove hoti hai, to count badha do
        }

        return count;  
        // total number of set bits (1s) return karo
    }
};

/*
🧠 Intuition:
Yaha hum Brian Kernighan’s Algorithm use kar rahe hain — My favorite technique
jab bhi hum n = n & (n-1) karte hain, tab current number ka sabse rightmost set bit (1) remove ho jata hai.
Is process ko repeat karke hum count kar lete hain ki total kitne set bits (1s) the.
Yeh method __builtin_popcount se bhi efficient hota hai jab hume manually implement karna ho.

⚙️ Time Complexity: O(k)
Yaha k = number of set bits in n.
Har iteration ek set bit remove karta hai, to loop utni baar chalega jitni 1s hain.

💾 Space Complexity: O(1)
Koi extra data structure use nahi hua, sirf constant variables (count aur n) lag rahe hain.
*/

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        // count rakhta hai kitne bits 1 (set) hain

        for (int k = 0; k < 32; k++) {
            int mask = (1 << k);
            // mask ek bit ko 1 set karta hai aur baaki sab 0 rehte hain

            if ((n & mask) != 0)
                count++;
            // agar (n & mask) non-zero hai to matlab wo bit set (1) hai
        }

        return count;
    }
};

/*
🧠 Intuition:
Har bit position (0 se 31) tak check karte hain ki wo bit 1 hai ya nahi.
Agar (n & mask) non-zero aata hai, iska matlab us position par bit set hai.
Aise sab bits count karte hain jaha 1 hai.

⚙️ Time Complexity: O(32) → O(1)
Hum fixed 32 bits ke liye loop chala rahe hain, to time constant rahta hai.

💾 Space Complexity: O(1)
Koi extra space use nahi hota, sirf count aur mask variables lagte hain.
*/

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int hammingWeight(int n) {  // unsigned int used to avoid sign issues
        int count = 0;

        while (n) {
            count += (n % 2);  // agar last bit 1 hai to +1
            n = n / 2;         // n ko ek bit right shift karne jaisa hai
        }

        return count;
    }
};

/*
🧠 Intuition:
Har iteration me hum last bit check karte hain (n % 2 se).
Agar wo 1 hai to count badhate hain.
Phir n ko 2 se divide karte hain taaki next bit check ho.

⚙️ Time Complexity: O(log n) ≈ O(32)
Har step me n half hota hai, max 32 steps for 32-bit number.

💾 Space Complexity: O(1)
Sirf count variable lagta hai.

⚠️ Note:
Is approach me signed integer par mat chalana, warna infinite loop ho sakta hai.
Unsigned integer (uint32_t) use karna best hai.
*/




