// ===================== PROBLEM EXPLANATION =====================
/*
Problem: Minimum Rotation to Unlock a Circular Lock

- Tumhe circular lock ke current digits ka string diya hai
- Tumhe target digits ka string diya hai
- Lock circular hai (0 ke baad 9, 9 ke baad 0)

Rules:
- Har digit ko independently rotate kar sakte ho
- Clockwise ya Anti-clockwise dono allowed
- 1 rotation = digit ko +1 ya -1 karna (circular)

Goal:
- Lock ko current se target tak le jane ke liye
  minimum total rotations nikalni hain

Assumption:
- current.length == target.length
*/
// ===============================================================


// -------------------- GREEDY APPROACH --------------------
// Har digit ke liye independently minimum circular distance lo

class Solution {
public:
    int minRotation(string current, string target) {

        int n = current.size();
        int totalRotations = 0;

        for (int i = 0; i < n; i++) {

            int cur = current[i] - '0';
            int tar = target[i] - '0';

            int clockwise = abs(cur - tar);
            int anticlockwise = 10 - clockwise;

            // Greedy choice: minimum of both directions
            totalRotations += min(clockwise, anticlockwise);
        }

        return totalRotations;
    }
};

/*
====================== INTUITION ======================

Intuition (Roman Hindi):

- Har digit independent hai, ek digit ki rotation
  doosri digit ko affect nahi karti
- Circular hone ki wajah se do raaste hote hain:
    1) Seedha ghoomna (clockwise)
    2) Ulta ghoomna (anti-clockwise)
- Jo bhi kam rotations me target tak le jaye,
  wahi best choice hoti hai

Greedy Choice Property:
- Har digit ke liye locally minimum rotation lena
- Global minimum total rotations deta hai
- Kyunki digits independent hain

Dry Run:
current = "039"
target  = "914"

Digit 0 → 9:
|0 - 9| = 9
10 - 9 = 1
take = 1

Digit 3 → 1:
|3 - 1| = 2
10 - 2 = 8
take = 2

Digit 9 → 4:
|9 - 4| = 5
10 - 5 = 5
take = 5

Total Rotations = 1 + 2 + 5 = 8

Time Complexity:
- O(n)

Space Complexity:
- O(1) extra space
======================================================
*/
