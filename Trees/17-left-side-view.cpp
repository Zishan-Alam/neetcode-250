class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {    // BFS
        if(!root) return {};
        vector<int> res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();

            // 🧠 The first node of each level (front of queue)
            // is the leftmost node visible from the left side
            res.push_back(que.front()->val);

            while(n--) {
                TreeNode* node = que.front(); que.pop();

                // 👇 Push left child first so leftmost nodes appear early
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return res;
    }
};

/*
--------------------------------------------
🧠 Intuition:
We want to see the nodes that are visible from the *left side*.
So at each level, the **first node** we encounter in BFS 
is the leftmost node for that level.

BFS (level-order) naturally processes nodes level by level,
and `queue.front()` at the start of each level 
gives us the leftmost node.

--------------------------------------------
🔍 Dry Run Example:

Input Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

BFS Traversal by levels:
Level 1: [1] → leftmost = 1
Level 2: [2, 3] → leftmost = 2
Level 3: [4, 5, 6] → leftmost = 4

✅ Output = [1, 2, 4]

--------------------------------------------
⏱️ Time Complexity:  O(N)
→ Each node is visited once in BFS traversal.

💾 Space Complexity: O(W)
→ Queue stores at most one full level of nodes (W = max width of the tree).
In worst case (perfect binary tree) → O(N).
--------------------------------------------
*/

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& res) {    //DFS
        if(!root) return;

        // 🧠 If this is the first node we're visiting at this level,
        // then it's the leftmost node (since we go left first)
        if(res.size() == level) res.push_back(root->val);

        // 🔁 Explore left first, then right
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);
    }

    vector<int> leftSideView(TreeNode* root) { 
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

/*
--------------------------------------------
🧠 Intuition:
We want to find the nodes visible when looking at the tree from the left side.
If we always traverse the **left subtree first**, the first node encountered at 
each depth is the leftmost node visible from that side.

So, whenever we visit a new level for the first time
(`res.size() == level`), we record the current node’s value.

--------------------------------------------
🔍 Dry Run Example:

Input Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

DFS order (left-first):
1 → 2 → 4 → 5 → 3 → 6

Processing:
Level 0 → add 1  
Level 1 → add 2  
Level 2 → add 4  
Remaining nodes (5, 3, 6) ignored because those levels are already visited.

✅ Output = [1, 2, 4]

--------------------------------------------
⏱️ Time Complexity:  O(N)
→ Every node is visited once in DFS traversal.

💾 Space Complexity: O(H)
→ Recursion stack depth equals tree height.
Best case (balanced tree): O(log N)
Worst case (skewed tree):  O(N)
--------------------------------------------
*/


``````````````````````````````````````````````````````````````````````````````
