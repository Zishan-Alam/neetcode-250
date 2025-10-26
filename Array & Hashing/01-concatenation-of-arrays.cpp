class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // pehle hum input vector 'nums' ka size n me store kar rahe hain
        int n = nums.size();

        // ab ek naya vector 'ans' bana rahe hain jiska size 2 * n hai
        // kyunki hume array ko do baar repeat karna hai (concatenate karna hai)
        vector<int> ans(2 * n);

        // loop chalayenge 0 se n tak
        for(int i = 0; i < n; i++) {
            // pehli half me same nums ke elements daal rahe hain
            ans[i] = nums[i];

            // dusri half (i + n) index par bhi wahi element daal rahe hain
            // taaki array concatenate ho jaye
            ans[i + n] = nums[i];
        }

        // final concatenated array return kar rahe hain
        return ans;
    }
};
