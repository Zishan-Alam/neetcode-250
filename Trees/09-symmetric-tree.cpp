class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q) {
        // Base Case 1: dono null -> symmetric
        if(!p && !q) return true;

        // Base Case 2: ek null hai aur dusra nahi -> asymmetric
        if(!p || !q) return false;

        // Base Case 3: value mismatch -> asymmetric
        if(p->val != q->val) return false;

        // Recursive Case:
        // Mirror check — left of one vs right of other, and vice versa
        return isSame(p->left, q->right) && isSame(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        // Empty tree is symmetric by default
        if(!root) return true;

        return isSame(root->left, root->right);
    }
};

/*
🧠 Intuition:
A tree is symmetric if its left and right subtrees are mirror images of each other.

So instead of comparing both sides directly,
we recursively check these mirror pairs:
    1️⃣ Left subtree of p ↔ Right subtree of q
    2️⃣ Right subtree of p ↔ Left subtree of q

If all corresponding mirrored nodes match in value and structure,
the tree is perfectly symmetric.

For example:
        1
      /   \
     2     2
    / \   / \
   3  4  4  3
→ Left(3 ↔ 3) and Right(4 ↔ 4) match → symmetric ✅

⏱️ Time Complexity: O(N)
Every node is visited exactly once for comparison.

💾 Space Complexity: O(H)
Recursive stack uses space proportional to the height of the tree.
Best case: O(log N) (balanced tree)
Worst case: O(N) (skewed tree)
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // Empty tree is symmetric
        if(!root) return true;

        // Queue stores mirror node pairs
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({root->left, root->right});

        while(!que.empty()) {
            auto [node1, node2] = que.front();
            que.pop();

            // If both nodes are null → symmetric at this level, continue checking next pairs
            if(!node1 && !node2) continue;

            // If one is null and the other isn't → asymmetric
            if(!node1 || !node2) return false;

            // Values mismatch → asymmetric
            if(node1->val != node2->val) return false;

            // Mirror children push:
            // left of node1 ↔ right of node2
            que.push({node1->left, node2->right});
            // right of node1 ↔ left of node2
            que.push({node1->right, node2->left});
        }

        // All pairs checked → symmetric tree
        return true;
    }
};

/*
🧠 Intuition:
We check symmetry level-by-level using BFS (queue).  
At each step, we compare node pairs that should mirror each other:
    - Left subtree of one ↔ Right subtree of the other.
    - Right subtree of one ↔ Left subtree of the other.

If all mirrored pairs match (both null or equal values), the tree is symmetric.
If any mismatch occurs (one null, value differ), we return false immediately.

For example:
        1
      /   \
     2     2
    / \   / \
   3  4  4  3  ✅ → perfectly symmetric

⏱️ Time Complexity: O(N)
Every node is visited exactly once.

💾 Space Complexity: O(N)
Queue can hold up to N/2 pairs in the last level (worst case).
*/

