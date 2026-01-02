// ===================== PROBLEM EXPLANATION =====================
/*
Problem:
- Tumhe coin denominations ka array diya hai
- Ek integer amount diya hai
- Tumhe SAME amount ke liye do values nikalni hain:
    1) Minimum number of coins
    2) Maximum number of coins

Return Format:
- Dono answers ko ek hi array / vector me return karna hai
  result[0] = minimum coins
  result[1] = maximum coins

Rules / Assumptions:
- Coin system canonical hai (jaise 1, 2, 5, 10)
- Har coin unlimited times use ho sakta hai
- Agar amount banana possible nahi ho → -1 return karo
*/
// ===============================================================


// -------------------- GREEDY APPROACH --------------------
// Canonical coin system ke liye Greedy valid hota hai

class Solution {
public:
    vector<int> minMaxCoins(vector<int>& coins, int amount) {

        int minCoins = 0, maxCoins = 0;
        int tempAmount;

        // ---------- MINIMUM COINS ----------
        sort(coins.rbegin(), coins.rend());   // largest first
        tempAmount = amount;

        for (int coin : coins) {
            if (tempAmount == 0) break;

            if (coin <= tempAmount) {
                int take = tempAmount / coin;
                minCoins += take;
                tempAmount -= take * coin;
            }
        }

        if (tempAmount != 0) minCoins = -1;


        // ---------- MAXIMUM COINS ----------
        sort(coins.begin(), coins.end());     // smallest first
        tempAmount = amount;

        for (int coin : coins) {
            if (tempAmount == 0) break;

            if (coin <= tempAmount) {
                int take = tempAmount / coin;
                maxCoins += take;
                tempAmount -= take * coin;
            }
        }

        if (tempAmount != 0) maxCoins = -1;

        // result[0] = min coins, result[1] = max coins
        return {minCoins, maxCoins};
    }
};

/*
====================== INTUITION ======================

Intuition (Roman Hindi):

Minimum Coins:
- Hume kam se kam coins chahiye
- Isliye har step pe sabse bada coin lete hain
- Bada coin lene se amount fast reduce hota hai

Maximum Coins:
- Hume zyada se zyada coins chahiye
- Isliye har step pe sabse chhota coin lete hain
- Chhota coin lene se coins count badhta hai

Greedy Choice Property:
- Local best choice (largest / smallest coin) se
  canonical systems me global optimal solution milta hai

Dry Run:
coins = {1, 2, 5}, amount = 11

MIN:
Sorted ↓ = {5, 2, 1}
5 → 2 coins → amount = 1
1 → 1 coin  → amount = 0
min = 3

MAX:
Sorted ↑ = {1, 2, 5}
1 → 11 coins → amount = 0
max = 11

Returned Array = {3, 11}

Time Complexity:
- Sorting twice: O(n log n)
- Loops: O(n)
- Overall: O(n log n)

Space Complexity:
- O(1) extra space (output vector excluded)
======================================================
*/
