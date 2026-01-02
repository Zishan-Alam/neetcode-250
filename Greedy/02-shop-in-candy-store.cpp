// ===================== PROBLEM EXPLANATION =====================
/*
Problem: Shop in Candy Store

- Tumhe candies ke prices ka array diya hai
- Ek integer K diya hai
- Rule:
    Jab tum 1 candy kharidte ho,
    tumhe FREE me K candies mil sakti hain (jo bhi available ho)

Goal:
- Minimum amount spent to buy all candies
- Maximum amount spent to buy all candies

Return Format:
- result[0] = minimum amount
- result[1] = maximum amount

Note:
- Har candy sirf ek baar use hogi
*/
// ===============================================================


// -------------------- GREEDY APPROACH --------------------
// Minimum ke liye: sasti candy kharido, mehngi free lo
// Maximum ke liye: mehngi candy kharido, sasti free lo

class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {

        sort(candies, candies + N);

        int minCost = 0, maxCost = 0;

        // ---------- MINIMUM COST ----------
        int buy = 0;
        int free = N - 1;

        while (buy <= free) {
            minCost += candies[buy];   // sasti candy buy
            buy++;
            free -= K;                 // K mehngi free
        }

        // ---------- MAXIMUM COST ----------
        buy = N - 1;
        free = 0;

        while (free <= buy) {
            maxCost += candies[buy];   // mehngi candy buy
            buy--;
            free += K;                 // K sasti free
        }

        return {minCost, maxCost};
    }
};

/*
====================== INTUITION ======================

Intuition (Roman Hindi):

Minimum Amount:
- Hume kam paisa kharch karna hai
- Isliye sabse sasti candy kharidte hain
- Aur rule ka use karke sabse mehngi candies free le lete hain

Maximum Amount:
- Hume zyada paisa kharch karna hai
- Isliye sabse mehngi candy kharidte hain
- Free me sabse sasti candies le lete hain

Greedy Choice Property:
- Har step pe local best decision
- (min ke liye cheapest buy, max ke liye costliest buy)
- Global optimal result deta hai

Dry Run:
candies = {3, 2, 1, 4}, K = 2

Sorted = {1, 2, 3, 4}

MIN:
Buy 1 → free {4,3}
Buy 2 → done
minCost = 3

MAX:
Buy 4 → free {1,2}
Buy 3 → done
maxCost = 7

Returned Array = {3, 7}

Time Complexity:
- Sorting: O(N log N)
- Traversal: O(N)

Space Complexity:
- O(1) extra space
======================================================
*/
