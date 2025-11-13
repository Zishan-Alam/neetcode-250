class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Brute Force: check every bar as potential smallest height
        for(int i = 0; i < n; i++) {
            int minHeight = heights[i];
            for(int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]); // current window ka min height
                int width = j - i + 1;
                int area = minHeight * width;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

/*
🧠 Intuition (Roman Hindi):
Is approach mein hum har ek bar ko ek starting point maante hain.
Phir uske baad ke sabhi bars ko leke dekhte hain ki sabse chhoti height kya ban rahi hai.
Har step par area = minHeight * width nikalte hain aur maximum area ko update karte hain.

Basically hum brute force kar rahe hain ki har possible rectangle check ho jaaye.

🧮 Dry Run Example:
heights = [2,1,5,6,2,3]

i=0 → j=0: min=2 → area=2x1=2  
       j=1: min=1 → area=1x2=2  
       j=2: min=1 → area=1x3=3  
       ...
       maxArea=3
i=1 → j=1: min=1 → area=1x1=1  
       j=2: min=1 → area=1x2=2  
       j=3: min=1 → area=1x3=3  
       j=4: min=1 → area=1x4=4  
       maxArea=4
i=2 → j=2: min=5 → area=5x1=5  
       j=3: min=5 → area=5x2=10 ✅  
       j=4: min=2 → area=2x3=6  
       maxArea=10
i=3 → j=3: min=6 → area=6x1=6  
       j=4: min=2 → area=2x2=4  
       maxArea=10
...final = 10

✅ Final Answer: 10

⏱️ Time Complexity: O(n²)
   → Har element ke liye hum n tak loop chala rahe hain.

💾 Space Complexity: O(1)
   → Koi extra data structure nahi use hua.
*/

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);   // index of previous smaller element
        vector<int> right(n, n);   // index of next smaller element
        stack<int> st;

        // Next Smaller Element (right boundary)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Smaller Element (left boundary)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int largestArea = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            largestArea = max(largestArea, currArea);
        }
        return largestArea;
    }
};

/*
🧠 Intuition (Roman Hindi):
Har bar ke liye hum dekhte hain — 
uske left aur right mein kitna area expand kar sakta hai bina chhote bar ke milne tak.
Isliye hum "Previous Smaller" aur "Next Smaller" index nikalte hain.
Phir width = (right - left - 1) aur area = height * width.

🧮 Dry Run Example:
heights = [2,1,5,6,2,3]
left  = [-1,-1,1,2,1,4]
right = [1,6,4,4,6,6]

i=2 (height=5): width=4-1-1=2 → area=10  
i=3 (height=6): width=4-2-1=1 → area=6  
i=1 (height=1): width=6-(-1)-1=6 → area=6  
✅ maxArea=10

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)
*/
