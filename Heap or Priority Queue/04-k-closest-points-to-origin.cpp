class Solution {
public:

    typedef pair<int, pair<int,int>> P;  // (distance, (x, y))

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap bana rahe hain (default comparator se)
        // taaki sabse bade distance wala top pe aaye
        priority_queue<P> pq;

        vector<vector<int>> res;

        for(auto &point : points) {
            int a = point[0];
            int b = point[1];

            // distance squared (square root lene ki zarurat nahi)
            int dist = a*a + b*b;

            // distance aur coordinate heap me daal do
            pq.push({dist, {a, b}});

            // agar heap me k se zyada points ho gaye to sabse door wala hata do
            if(pq.size() > k) pq.pop();
        }

        // ab heap me sirf k closest points bache hain
        while(!pq.empty()) {
            auto top = pq.top();
            int x = top.second.first;
            int y = top.second.second;

            res.push_back({x, y});
            pq.pop();
        }

        return res;
    }
};

/*
🧠 Intuition (Hinglish me):
- Har point ka distance origin se nikalte hain (x² + y²).
- Max-heap me rakhte hain taaki sabse door point top pe ho.
- Agar heap size k se bada ho gaya → top ko pop kar do.
- End me heap me bache hue points hi k closest hain.

⚙️ Time Complexity:
→ O(n log k)
    - Har point ke liye insertion O(log k) me hoti hai.
💾 Space Complexity:
→ O(k)
    - Heap me max k elements store hote hain.
*/
