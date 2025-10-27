class KthLargest {
public:

    // min-heap (priority_queue with greater<int>) banaya hai
    // ye hamesha smallest element ko top pe rakhega
    priority_queue<int, vector<int>, greater<int>> pq;

    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k; // K ko store kar liya

        // har number ko heap me daalte hain
        for(auto num : nums) {
            pq.push(num);

            // agar heap ka size K se zyada ho gaya to smallest element hata dete hain
            // taaki heap me hamesha top K largest elements hi bachein
            if(pq.size() > k) pq.pop();
        }
    }
    
    // add() function har naye value ko stream me add karega
    int add(int val) {
        pq.push(val);  // naya element heap me daal do

        // agar heap size K se zyada ho gaya, to chhota element hata do
        if(pq.size() > K) pq.pop();

        // heap ke top me ab Kth largest element hoga
        return pq.top();
    }
};

/*
🧠 Intuition (Hinglish me):
Hum ek min-heap maintain karte hain jisme hamesha top K largest elements hote hain.
Heap ka top element hamesha Kth largest hota hai.
- Agar naya element bada hua, to wo heap me daal dete hain aur smallest ko nikal dete hain.
- Isse heap ka size fixed (K) rehta hai aur efficiency high hoti hai.

⚙️ Time Complexity:
→ O(n log K) for constructor
    - Initial nums ko heap me daalte waqt har insertion O(log K) lagta hai.
→ O(log K) for add() operation
    - Har nayi entry insert/pop me O(log K) lagta hai.

💾 Space Complexity:
→ O(K)
    - Heap me maximum K elements store hote hain.
*/
