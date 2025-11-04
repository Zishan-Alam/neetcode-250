class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;

        bool toReverse = false;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            vector<int> temp;

            while(n--) {
                TreeNode* node = que.front(); que.pop();
                temp.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
          
            if(toReverse) {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            }
            else res.push_back(temp);
            
            toReverse = !toReverse;    // toggle the pattern
        }
        return res;
    }
};

/*
🧠 Intuition:
Ye problem Level Order Traversal (BFS) ka hi ek variant hai.
Bas fark itna hai ki:
- Pehla level left-to-right hota hai.
- Dusra level right-to-left hota hai.
- Fir alternate karte rehte hain (zigzag pattern).
Hum ek boolean flag (toReverse) se ye decide karte hain har level ke baad
ki next level ko reverse karna hai ya nahi.

⏱️ Time Complexity: O(N)
    - Har node ek baar visit hota hai.
    - Reverse operation har level pe O(k) hai (jahan k us level ke nodes hain),
      par total mila ke O(N) hi hota hai.

💾 Space Complexity: O(N)
    - Queue BFS traversal ke liye O(N) space leti hai.
    - Result vector bhi O(N) elements store karta hai.
*/
