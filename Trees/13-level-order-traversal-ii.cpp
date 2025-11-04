class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;

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
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());      // just reverse the result to get the result upside down
        return res;
    }
};

/*
🧠 Intuition:
Ye problem normal Level Order Traversal jaisi hi hai (BFS se har level traverse karte hain).
Bas difference ye hai ki hume output bottom se top chahiye.

Approach:
1️⃣ Har level ke nodes ko ek temporary vector me store karo.
2️⃣ Us level ko result me daal do (res.push_back(temp)).
3️⃣ Jab saare levels process ho jaayein, poore result ko reverse kar do.
   Isse levels bottom-to-top order me aa jaayenge.

⏱️ Time Complexity: O(N)
    - Har node ek baar queue me aata hai aur ek baar pop hota hai.

💾 Space Complexity: O(N)
    - Queue BFS traversal ke liye O(N) space leti hai.
    - Result vector bhi O(N) elements store karta hai.
*/
