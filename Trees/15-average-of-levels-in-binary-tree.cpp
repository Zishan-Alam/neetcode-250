class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            double temp = 0;      // To store sum of nodes at current level
            int size = n;         // Keep original size for average calculation

            while(n--) {
                TreeNode* node = que.front(); que.pop();
                temp += node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(temp/size);
        }
        return res;
    }
};

/*
🧠 Intuition:
Level Order Traversal (BFS) ka use karke har level ke nodes ka sum nikalte hain.
Phir us level ka average = (sum / number_of_nodes_in_that_level).

Process:
1️⃣ Queue me initially root daalte hain.
2️⃣ Har level ke liye:
    - Queue ka size nikalte hain (that many nodes in this level).
    - Un sabka sum nikalte hain.
    - Average calculate karke result vector me daal dete hain.
3️⃣ Ye process tab tak chalta hai jab tak queue empty nahi hoti.

⏱️ Time Complexity: O(N)
   Har node ek baar visit hota hai (sum + queue operations).

💾 Space Complexity: O(N)
   BFS queue maximum ek level ke nodes ko hold karti hai (worst case N/2 ≈ O(N)).
*/
