class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {    // same as left side view but pushing right first
        if(!root) return {};
        vector<int> res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            res.push_back(que.front()->val);

            while(n--) {
                TreeNode* node = que.front(); que.pop();

                // You are pushing right before left,
                // so the queue will have the *rightmost* nodes earlier next time.
                if(node->right) que.push(node->right);
                if(node->left) que.push(node->left);
            }
            
        }
        return res;
    }
};

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// 🔥 Leetcode 199: Binary Tree Right Side View  
// ✅ BFS (Level Order Traversal) Approach

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {}; 
        vector<int> res; 

        queue<TreeNode*> que;
        que.push(root); 

        while(!que.empty()) {
            int n = que.size();
            TreeNode* node; // to store the last node at this level

            // process all nodes of the current level
            while(n--) {
                node = que.front(); que.pop();

                // push children in normal order (left first, then right)
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            // after the level ends, 'node' will store the last node of that level
            res.push_back(node->val);
        }
        return res;
    }
};

/*
🧠 Intuition:
- We need the nodes visible from the right side.
- So, for each level of the tree, we only need the **last node**.
- Using level-order traversal (BFS), we can process all nodes level by level.
- The last node processed in each level is the one visible from the right side.

📘 Dry Run:
Example:
        1
       / \
      2   3
       \   \
        5   4

Queue process:
Level 1: [1] → last = 1 → res = [1]
Level 2: [2,3] → last = 3 → res = [1,3]
Level 3: [5,4] → last = 4 → res = [1,3,4]

✅ Final Output: [1,3,4]

⏱️ Time Complexity: O(N)
- Each node is visited exactly once.

💾 Space Complexity: O(N)
- Queue can hold up to N/2 nodes in the worst case (for the last level).
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// ✅ Leetcode 199: Binary Tree Right Side View (DFS Solution)

class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& res) {
        if(!root) return;

        // If this is the first node we’re visiting at this level,
        // it means it’s the rightmost (since we visit right first)
        if(res.size() == level) 
            res.push_back(root->val);

        // First explore right subtree to capture rightmost nodes first
        dfs(root->right, level + 1, res);
        // Then explore left subtree
        dfs(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

/*
🧠 Intuition:
We perform a **right-first DFS traversal** of the tree.
For every level, we only record the **first node** we visit,
because when we go right first, that’s the rightmost node visible from that level.

📘 Approach:
1️⃣ Start DFS from root at level 0.  
2️⃣ For every recursive call:
   - If `res.size() == level`, it means no node has been added for this level yet.
     So, we add the current node’s value as the visible rightmost node.
3️⃣ Recurse to right subtree first (rightmost view), then left.

💡 This guarantees that the first time we visit a level,
   we’re seeing its rightmost node.

🧩 Dry Run Example:
Tree:
        1
       / \
      2   3
       \   \
        5   4

DFS traversal order → 1 → 3 → 4 → 2 → 5

- Level 0: res = [1]  (first node)
- Level 1: res = [1, 3]  (first node at level 1 is 3)
- Level 2: res = [1, 3, 4]  (first node at level 2 is 4)
✅ Output → [1, 3, 4]

⏱️ Time Complexity: O(N)
Every node is visited once.

💾 Space Complexity: O(H)
Due to recursion stack, where H = height of the tree.
→ O(log N) for balanced tree  
→ O(N) for skewed tree
*/
