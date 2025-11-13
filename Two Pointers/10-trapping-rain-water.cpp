class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        // For every index, calculate left max and right max, then find trapped water
        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;

            // Find maximum height on the left of i
            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, height[j]);
            }

            // Find maximum height on the right of i
            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            // Water trapped at index i = min(leftMax, rightMax) - height[i]
            totalWater += min(leftMax, rightMax) - height[i];
        }

        return totalWater;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Har ek building ke upar kitna paani ruk sakta hai ye dekhne ke liye,
uske left aur right dono side ka sabse bada tower dhoondo.
Agar leftMax aur rightMax dono height jyada hain current se,
to paani = min(leftMax, rightMax) - currentHeight itna ruk sakta hai.

Example dry run:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

i = 2 (height=0):
  leftMax = 1
  rightMax = 3
  trapped = min(1,3) - 0 = 1 unit
i = 5 (height=0):
  leftMax = 2
  rightMax = 3
  trapped = min(2,3) - 0 = 2 units
...
Total = 6 units

⏱️ Time Complexity: O(N²)  // For each element, we scan left and right sides
💾 Space Complexity: O(1)  // No extra space used

Brute Force Method — works fine for small inputs but slow for large N.
*/

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        vector<int> left(n,0);
        vector<int> right(n,0);

        left[0] = height[0];
        right[n-1] = height[n-1];

        // Precompute the max height to the left of each index
        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1], height[i]);
        }

        // Precompute the max height to the right of each index
        for(int i=n-2; i>=0; i--) {
            right[i] = max(right[i+1], height[i]);
        }

        // Water trapped = min(leftMax, rightMax) - height[i]
        for(int i=0; i<n; i++) {
            totalWater += min(left[i], right[i]) - height[i];
        }
        return totalWater;
    }
};

/*
🧠 Intuition:
Har index ke upar paani tabhi ruk sakta hai jab uske left aur right dono taraf badi walls ho.
Toh har index ke liye:
- leftMax = us index ke left tak ka sabse bada height
- rightMax = us index ke right tak ka sabse bada height
- trappedWater[i] = min(leftMax, rightMax) - height[i]

Agar koi side open hai (like first or last index), min(left,right) usi side ka height dega, 
aur difference 0 ho jaayega — matlab paani waha nahi rukta.

💧 Example dry run (height = [4,2,0,3,2,5]):

i | height | leftMax | rightMax | trapped
0 |   4    |   4     |   5      | 0
1 |   2    |   4     |   5      | 2
2 |   0    |   4     |   5      | 4
3 |   3    |   4     |   5      | 1
4 |   2    |   4     |   5      | 2
5 |   5    |   5     |   5      | 0

✅ Total trapped water = 9 units

⏱️ Time Complexity: O(3n)
   - 3 linear passes → build left[], right[] and compute trapped water.

💾 Space Complexity: O(2n)
   - Extra space for left[] and right[] arrays.
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        int l = 0;             // Left pointer
        int r = n - 1;         // Right pointer
        int leftMax = 0;       // Max height seen so far from left
        int rightMax = 0;      // Max height seen so far from right

        while(l < r) {
            // Update running maximums
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            // Decide which side to process
            if(leftMax < rightMax) {
                totalWater += leftMax - height[l];  // Water trapped on left side
                l++;
            } 
            else {
                totalWater += rightMax - height[r]; // Water trapped on right side
                r--;
            }
        }
        return totalWater;
    }
};

/*
🧠 Intuition (Roman Hindi):
Isme hum two-pointer approach use karte hain.
Idea ye hai ki water trap hone ka depend karta hai choti wall pe — 
jo side choti hogi (leftMax < rightMax), waha paani ka amount fix ho chuka hai.

Toh agar leftMax chhota hai → right side se koi aur badi wall mil bhi jaaye,
usse paani ka level leftMax se zyada nahi badhega.
Isliye us side ka contribution abhi add kar dete hain.

💧 Example dry run (height = [4,2,0,3,2,5]):

Initial: l=0, r=5, leftMax=0, rightMax=0

Iter 1 → leftMax=4, rightMax=5 → leftMax<rightMax → add(4-4)=0 → l=1  
Iter 2 → leftMax=4, rightMax=5 → add(4-2)=2 → l=2  
Iter 3 → leftMax=4, rightMax=5 → add(4-0)=4 → l=3  
Iter 4 → leftMax=4, rightMax=5 → add(4-3)=1 → l=4  
Iter 5 → leftMax=4, rightMax=5 → add(4-2)=2 → l=5 stop

✅ Total trapped water = 9 units

⏱️ Time Complexity: O(n)
   → Har element ek baar process hota hai (no extra arrays)

💾 Space Complexity: O(1)
   → Sirf constant space for pointers and max trackers.
*/

