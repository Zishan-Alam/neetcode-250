// ===================== PROBLEM EXPLANATION =====================
/*
Problem: Assign Mice to Holes

- Tumhe mice ke positions ka array diya hai
- Tumhe holes ke positions ka array diya hai
- Har mouse ko exactly ek hole assign karna hai
- Har hole me sirf ek mouse ja sakta hai

Goal:
- Maximum time minimize karna hai jisme sabhi mice apne holes tak pahunch jaye

Movement Rule:
- Mouse left ya right move kar sakta hai
- Time = |mouse_position - hole_position|

Return:
- Minimum possible maximum time

Note:
- Agar mice aur holes ki count same nahi hai → assignment possible nahi
*/
// ===============================================================


// -------------------- GREEDY APPROACH --------------------
// Best strategy: sort both arrays and pair them index-wise

class Solution {
public:
    int assignMiceToHoles(vector<int>& mice, vector<int>& holes) {

        int n = mice.size();
        if (n != holes.size()) return -1;

        // Step 1: Sort both arrays
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());

        int ans = 0;

        // Step 2: Assign i-th mouse to i-th hole
        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(mice[i] - holes[i]));
        }

        return ans;
    }
};

/*
====================== INTUITION ======================

Intuition (Roman Hindi):

- Agar hum mice aur holes ko random assign kare,
  toh koi mouse bahut door ka hole pa sakta hai
- Isse maximum time badh jayega

Greedy Idea:
- Mice aur holes dono ko sort kar do
- Jo mouse left me hai, use left wala hole do
- Jo mouse right me hai, use right wala hole do

Why Greedy Works:
- Agar hum crossing assignments karte hain
  (left mouse ko right hole aur right mouse ko left hole),
  toh maximum distance hamesha badhegi
- Isliye sorted order me pair karna optimal hai

Dry Run:
mice  = {4, -4, 2}
holes = {4, 0, 5}

Sorted mice  = {-4, 2, 4}
Sorted holes = {0, 4, 5}

Pairs:
(-4 → 0) = 4
( 2 → 4) = 2
( 4 → 5) = 1

Maximum time = max(4,2,1) = 4

Time Complexity:
- Sorting: O(n log n)
- Traversal: O(n)

Space Complexity:
- O(1) extra space (sorting in-place)
======================================================
*/
