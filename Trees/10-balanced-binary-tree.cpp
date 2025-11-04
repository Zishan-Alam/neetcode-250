class Solution {
public:
    // Helper function returns height if balanced, else -1
    int height(TreeNode* root) {
        if(!root) return 0;

        int left = height(root->left);
        if(left == -1) return -1; // left subtree unbalanced

        int right = height(root->right);
        if(right == -1) return -1; // right subtree unbalanced

        if(abs(left - right) > 1) return -1; // current node unbalanced

        return 1 + max(left, right); // return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

/*
🧠 Intuition:
Each recursive call returns either:
   - Height of subtree (if balanced)
   - Or -1 (if unbalanced)

We combine height-calculation and balance-check in one traversal.
If any subtree unbalanced milta hai → propagate -1 upwards immediately.

⏱️ Time Complexity: O(N)
Each node is visited exactly once.

💾 Space Complexity: O(H)
Recursion stack space = height of tree (H).
Balanced tree → O(log N), Skewed → O(N)
*/
