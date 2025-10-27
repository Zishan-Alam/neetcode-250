class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        return nums[n-k];
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------

  class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min-heap bana rahe hain (smallest element top pe rahega)
        priority_queue<int, vector<int>, greater<int>> pq;

        // har element ko heap me daalenge
        for(int &num : nums) {
            pq.push(num);

            // agar heap ka size K se bada ho gaya to smallest element hata denge
            // taaki heap me hamesha top K largest elements hi rahein
            if(pq.size() > k) pq.pop();
        }

        // ab heap ke top me Kth largest element hoga
        return pq.top();
    }
};

/*
🧠 Intuition (Hinglish me):
Hum min-heap use kar rahe hain taaki hum sirf K largest elements track kar sakein.
- Har number ko heap me daal do.
- Jab heap ka size K se bada ho jaye, to sabse chhota number nikaal do.
Aakhir me heap ke top pe bacha element hi Kth largest hoga.

⚙️ Time Complexity:
→ O(n log K)
    - Har insertion aur deletion O(log K) me hota hai.
    - Ye process n elements ke liye chalti hai.

💾 Space Complexity:
→ O(K)
    - Heap me maximum K elements store hote hain.
*/
