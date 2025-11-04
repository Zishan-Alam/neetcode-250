// Maximum Depth -> Height of Binary Tree

return (!root)? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;  // Base case: null node → depth 0

        // Recursively calculate the depth of left and right subtrees
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);

        // Add 1 for the current node and return the maximum of both sides
        return 1 + max(left, right);
    }
};

/*
🧠 Intuition:
We calculate the maximum depth of a binary tree using recursion.  
For every node, we find the depth of its left and right subtrees and take the maximum.  
Each recursive call goes one level deeper, so when the recursion unwinds,  
we get the total height of the tree.

⏱️ Time Complexity: O(n)
Each node is visited exactly once.

💾 Space Complexity: O(h)
Where h is the height of the tree (O(n) in worst case for skewed tree, O(log n) for balanced tree).
*/

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0; // Agar tree empty hai → depth = 0

        queue<TreeNode*> que; 
        que.push(root); // Root node se traversal start
        int depth = 0;  // Height counter

        // Har iteration ek "level" represent karta hai
        while(!que.empty()) {
            int size = que.size(); // Current level ke total nodes
            depth++; // Har level complete hone par height badh jaati hai

            // Current level ke sabhi nodes process karo
            while(size--) {
                TreeNode* node = que.front(); 
                que.pop();

                // Next level ke nodes enqueue karo
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth; // Final height return karo
    }
};

/*
🧠 Intuition:
Level order traversal (BFS) use karke hum tree ko level by level traverse karte hain.
Har level complete hone par height (depth) ek se badha dete hain.
Jab tak queue khali nahi hoti, matlab aur levels baaki hain.

⏱️ Time Complexity: O(n)
→ Har node ek baar process hota hai.

💾 Space Complexity: O(n)
→ Queue me maximum ek level ke nodes store hote hain (worst case: complete binary tree).
*/


``````````````````````````````````````````````````````````
