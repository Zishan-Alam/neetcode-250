class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // If the tree is empty, return an empty list
        if(!root) return {};
        vector<int> res;

        // Standard BFS using queue
        queue<TreeNode*> que;
        que.push(root);

        // Traverse level by level
        while(!que.empty()) {
            int n = que.size();       // Number of nodes in current level
            TreeNode* node = nullptr; // To keep track of the last node in each level

            // Process all nodes of the current level
            while(n--) {
                node = que.front(); 
                que.pop();

                // Push left and right children in queue
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            // The last popped node of each level is the rightmost one
            res.push_back(node->val);
        }
        return res;
    }
};

/*
🔹 Intuition:
We need to find which nodes are visible from the right side.
When we perform a level order traversal (BFS), the last node of each level 
will always be the rightmost visible node.
So, for every level, we just record the value of the last node we processed.

🔹 Dry Run Example:
Tree:
        1
       / \
      2   3
       \   \
        5   4

Level 1 → [1] → rightmost = 1  
Level 2 → [2, 3] → rightmost = 3  
Level 3 → [5, 4] → rightmost = 4  
Output → [1, 3, 4]

🔹 Time Complexity: O(N)
We visit every node exactly once in the BFS traversal.

🔹 Space Complexity: O(W)
Where W = maximum width of the tree (worst case O(N) when the tree is complete).
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    // Helper DFS function
    void dfs(TreeNode* root, int level, vector<int> &res) {
        if(!root) return;

        // 🧠 If this level is being visited for the first time,
        // it means this node is the *rightmost* node for that level
        if(res.size() < level) {
            res.push_back(root->val);
        }

        // ⚙️ Traverse right subtree first, then left
        // (so that rightmost nodes are visited first)
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        // 🌳 Start DFS traversal from root at level 1
        dfs(root, 1, res);

        return res;
    }
};


/*
--------------------------------------------
🧠 Intuition:
We want to see the nodes that are visible from the *right side* of the tree.
Using DFS, we go *right first*, because the rightmost node at each level
is the first one visible from the right side.

So for each level, if we haven’t added any node yet,
that means this is the first (rightmost) node of that level.

--------------------------------------------
🔍 Dry Run Example:
Input Tree:
        1
       / \
      2   3
       \   \
        5   4

DFS traversal order:
1 → 3 → 4 → 2 → 5

Step-by-step:
Level 1: add(1)
Level 2: add(3)
Level 3: add(4)
Final result = [1, 3, 4]

--------------------------------------------
⏱️ Time Complexity:  O(N)
👉 Each node is visited exactly once.

💾 Space Complexity: O(H)
👉 H = height of the tree (due to recursion stack)
    - Balanced tree: O(log N)
    - Skewed tree:  O(N)
--------------------------------------------
*/

