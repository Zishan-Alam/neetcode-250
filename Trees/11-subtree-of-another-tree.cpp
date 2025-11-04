class Solution {
public:
    // Helper function to check if two trees are identical
    bool isSame(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;      // both null → same
        if(!p || !q) return false;     // one null → not same
        if(p->val != q->val) return false;  // value mismatch → not same

        // Check left and right subtrees
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Cases
        if(!root && !subRoot) return true;   // both empty → same
        if(!root || !subRoot) return false;  // one empty → can't be subtree

        // If current node matches subRoot root, check for identical trees
        if((root->val == subRoot->val) && isSame(root, subRoot))
            return true;

        // Otherwise, check in left or right subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/*
🧠 Intuition:
We recursively traverse the main tree (`root`) and check:
1️⃣ If current node value == subRoot value → check if both trees are identical using `isSame()`.
2️⃣ If not identical, recursively check in left and right subtrees.
3️⃣ As soon as we find one identical subtree, return true.

So this is a **tree matching problem** where each node of main tree acts as a possible root of subRoot.

⏱️ Time Complexity: O(M * N)
- For every node in main tree (`M`), we may compare up to `N` nodes in `subRoot`.
- Worst case (when tree values mostly same): O(M × N)

💾 Space Complexity: O(H)
- H = height of main tree (recursion stack)
- Balanced tree → O(log M)
- Skewed tree → O(M)
*/
