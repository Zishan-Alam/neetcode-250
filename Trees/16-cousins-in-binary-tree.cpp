class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return true;

        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({root, nullptr});    // pair = {node, parent}

        while(!que.empty()) {
            int n = que.size();

            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;

            while(n--) {
                auto [node, parent] = que.front(); que.pop();

                if(node->val == x) xParent = parent;
                if(node->val == y) yParent = parent;

                if(node->left) que.push({node->left, node});
                if(node->right) que.push({node->right, node});
            }

            // agar dono same level me mile
            if(xParent && yParent) return xParent != yParent; // same level but different parent → cousins ✅
            if( (!xParent && yParent) || (xParent && !yParent) ) return false;
        }
        return true;
    }
};

/*
🧠 Intuition:
We need to check if two nodes (x and y) are *cousins* → i.e., 
they must be on the same level but have different parents.

So we perform **Level Order Traversal (BFS)** just like in `levelOrder` or `averageOfLevels`.
But this time, we store `(node, parent)` pair in the queue.

At every level:
1️⃣ Track the parent of x and y.
2️⃣ If both found in the same level → return (xParent != yParent)
3️⃣ If only one found → not cousins.
4️⃣ Otherwise → move to next level.

This way we compare nodes level by level instead of recursive depth check.

🧩 Dry Run Example:
Tree:
        1
       / \
      2   3
       \  /
        4 5

x = 4, y = 5

Level 1 → (1, null)
  queue = [(2,1), (3,1)]

Level 2 → (2,1), (3,1)
  queue = [(4,2), (5,3)]

Level 3 → (4,2), (5,3)
  Found xParent=2, yParent=3 → Different parents ✅ → return true

⏱️ Time Complexity: O(N)
→ Each node is visited exactly once during BFS.

💾 Space Complexity: O(N)
→ Queue may store up to N/2 nodes (last level in worst case).
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    void dfs(TreeNode* root, TreeNode* parent, int level, int target, int &targetLevel, TreeNode* &targetParent) {
        if(!root) return;

        if(root->val == target) {
            targetParent = parent;
            targetLevel = level;
            return;
        }

        dfs(root->left, root, level+1, target, targetLevel, targetParent);
        dfs(root->right, root, level+1, target, targetLevel, targetParent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return true;

        //variables for level
        int xLevel = -1;
        int yLevel = -1;

        //variables for parent
        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;

        // Find depth & parent for both x and y
        dfs(root, nullptr, 0, x, xLevel, xParent);
        dfs(root, nullptr, 0, y, yLevel, yParent);

        // Cousins if at same level but different parents
        return (xLevel == yLevel) && (xParent != yParent);
    }
};

/*
🧠 Intuition:
Same goal — check if nodes x and y are *cousins* (same depth, different parents).
But instead of BFS (level-order), here we use **DFS (depth-first recursion)**.

During recursion:
- Pass the current depth (level count).
- Pass the parent node pointer.
- When we find target node (x or y), store its depth & parent.
Finally, if both nodes have same depth but different parent → they’re cousins ✅

📘 Pattern Match:
Yeh logic similar hai `maxDepth`, `diameterOfBinaryTree` ya `isSameTree` jese recursive traversal se.
Bas yahan recursion me extra info track kar rahe hain: `depth` aur `parent`.

🧩 Dry Run Example:
Tree:
        1
       / \
      2   3
       \  /
        4 5

x = 4, y = 5

DFS(root=1)
 → left = 2 (depth=1, parent=1)
   → right = 4 → x found → xDepth=2, xParent=2
 → right = 3 (depth=1, parent=1)
   → left = 5 → y found → yDepth=2, yParent=3

Compare:
xDepth == yDepth ✅
xParent != yParent ✅
→ return true

⏱️ Time Complexity: O(N)
Each node visited once in DFS traversal.

💾 Space Complexity: O(H)
Recursive stack space (H = height of tree)
→ Best case: O(log N) (balanced)
→ Worst case: O(N) (skewed)
*/
