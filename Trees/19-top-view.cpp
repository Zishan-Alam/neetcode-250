// ✅ BFS
class Solution {
public:
    // Helper function to find leftmost and rightmost horizontal distance
    void find(TreeNode* root, int pos, int &l, int &r) {
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<int> getTopView(TreeNode* root) {
        if(!root) return {};

        // Step 1️⃣: Find the leftmost and rightmost horizontal distance
        int l = 0, r = 0;
        find(root, 0, l, r);

        int width = r - l + 1;
        vector<int> res(width);
        vector<bool> visited(width, false);

        // Step 2️⃣: BFS traversal with horizontal distance
        queue<pair<TreeNode*, int>> que;  // {node, horizontal distance index}
        que.push({root, -l});

        while(!que.empty()) {
            auto [node, pos] = que.front(); 
            que.pop();

            // Step 3️⃣: Record first node seen at this position (top view)
            if(!visited[pos]) {
                visited[pos] = true;
                res[pos] = node->data;
            }

            // Step 4️⃣: Move left and right in horizontal distance
            if(node->left)  que.push({node->left, pos - 1});
            if(node->right) que.push({node->right, pos + 1});
        }

        return res;
    }
};

/*
🧠 Intuition:
Each node in a binary tree can be assigned a **horizontal distance (HD)**:
- Root = 0
- Left child = HD - 1
- Right child = HD + 1

Top view = first node visible at each horizontal distance (from top).
We perform BFS to ensure topmost nodes are seen first for each HD.

📘 Approach:
1️⃣ Use DFS to find how far left and right the tree goes (min and max HD).
2️⃣ Use BFS to traverse level by level, tracking HD.
3️⃣ For each HD, record the first node encountered (topmost).
4️⃣ Return nodes in order from leftmost to rightmost HD.

🧩 Dry Run Example:
Tree:
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6

HD map:
1(0), 2(-1), 3(+1), 4(0), 5(+1), 6(+2)

Top view → [2, 1, 3, 6]

⏱️ Time Complexity: O(N)
Each node is processed once.

💾 Space Complexity: O(N)
For queue + result storage.
*/
