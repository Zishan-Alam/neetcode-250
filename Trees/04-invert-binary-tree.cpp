class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;  // Base case: if the node is NULL, simply return

        // Recursively invert the left and right subtrees
        TreeNode* left  = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // Swap the left and right pointers of the current node
        root->left  = right;
        root->right = left;

        return root;  // Return the current node after inversion
    }
};

/*
🧠 Intuition:
The idea is simple — for every node, we just swap its left and right child.
Then we recursively repeat this process for both subtrees. 
Ultimately, the entire tree gets mirrored (left ↔ right).

⏱️ Time Complexity: O(n)
Because we visit each node exactly once during recursion.

💾 Space Complexity: O(h)
Where h is the height of the tree (O(log n) for balanced tree, O(n) for skewed tree)
due to the recursion call stack.
*/

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = que.front(); que.pop();

            swap(node->left, node->right);

            //TreeNode* temp = node->left;
            //node->left = node->right;
            //node->right = temp;

            if(node->left)  que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return root;
    }
};

/*
🧠 Intuition:
Instead of recursion, we use a queue (BFS) to traverse the tree level by level.  
At each node, we swap its left and right child. 
This ensures every node in the tree gets inverted iteratively.

⏱️ Time Complexity: O(n)
Every node is visited exactly once and swapped once.

💾 Space Complexity: O(n)
In the worst case (a completely filled tree), the queue can hold all nodes of the last level.
*/
