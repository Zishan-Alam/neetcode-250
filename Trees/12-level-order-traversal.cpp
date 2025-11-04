class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();  // Current level me kitne nodes hain
            vector<int> temp;

            while(n--) {  // Current level ke saare nodes process karo
                TreeNode* node = que.front(); que.pop();
                temp.push_back(node->val);

                // Agle level ke liye children ko queue me daal do
                if(node->left) que.push(node->left);      //ye line n-- vale loop ke inside hai because, isme har node process horaha ha
                if(node->right) que.push(node->right);    //dry run for better understanding
            }
            res.push_back(temp);
        }
        return res;
    }
};

/*
🧠 Intuition:
Hum BFS (Breadth First Search) approach use kar rahe hain.
Queue help karti hai har level ke nodes ko systematically traverse karne me.
Ek level ke saare nodes process karne ke baad hi agla level queue me aata hai.

⏱️ Time Complexity: O(N)
    - Har node ko ek baar visit karte hain.
    - N = total number of nodes in the tree.

💾 Space Complexity: O(N)
    - Queue me ek level ke nodes store hote hain at a time (worst case me O(N)).
    - Result vector bhi O(N) space leta hai.
*/
