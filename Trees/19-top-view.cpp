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

    vector<int> topView(TreeNode* root) {
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

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    // Step 1️⃣ — Helper DFS to find leftmost & rightmost horizontal range
    void find(TreeNode* root, int pos, int &l, int &r) {
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    // Step 2️⃣ — Main DFS function to fill top view nodes
    void dfs(TreeNode* root, int pos, int currLevel, vector<int> &res, vector<int> &level) {
        if(!root) return;

        // Agar current level smaller hai (means ye node upar hai), update top view
        if(level[pos] > currLevel) {
            res[pos] = root->val;
            level[pos] = currLevel;
        }

        // Left subtree ke liye position -1 aur right ke liye +1
        dfs(root->left, pos - 1, currLevel + 1, res, level);
        dfs(root->right, pos + 1, currLevel + 1, res, level);
    }

    vector<int> topView(TreeNode* root) {
        if(!root) return {};

        // Step 3️⃣ — Find horizontal limits (leftmost, rightmost)
        int l = 0, r = 0;
        find(root, 0, l, r);
        int width = r - l + 1;

        // Step 4️⃣ — Prepare result and level arrays
        vector<int> res(width);
        vector<int> level(width, INT_MAX);   // store smallest level (closest to top)

        // Step 5️⃣ — DFS call starting from root
        dfs(root, -l, 0, res, level);

        return res;
    }
};

/*
🧠 INTUITION (Roman Hindi + English mix):

1️⃣  Top view ka matlab — tree ko upar se dekhte hue har vertical line me 
     jo sabse upar (smallest level) wala node dikhta hai, wahi answer me aayega.

2️⃣  Har node ka ek "horizontal distance" (pos) hota hai:
     - Root → pos = 0
     - Left child → pos = parent_pos - 1
     - Right child → pos = parent_pos + 1

3️⃣  Hum ek DFS karte hain jisme:
     - pos track karte hain (kitna left/right gaya)
     - level track karte hain (depth of node)
     - Agar kisi horizontal line pe current node ka level < existing level hai,
       iska matlab ye node pehle wale se upar hai → update kar dete hain.

4️⃣  find() function se pehle width nikalte hain (leftmost aur rightmost pos),
     taaki indexing me dikkat na ho.

🧩 DRY RUN:

           1
          / \
         2   3
          \   \
           4   5

Horizontal positions:
    2 → -1
    1 →  0
    3 → +1
    4 →  0
    5 → +2

DFS traversal order (Root → Left → Right):
    pos=0 → 1 at level 0
    pos=-1 → 2 at level 1
    pos=0 → 4 at level 2 → ignore (already have smaller level)
    pos=+1 → 3 at level 1
    pos=+2 → 5 at level 2

✅ Result → [2, 1, 3, 5]


⏱️ Time Complexity → O(N)
   Har node ek baar visit hota hai (DFS traversal).

💾 Space Complexity → O(H)
   DFS recursion stack ke liye space (H = height of tree).

📌 NOTE:
   - Ye approach BFS se thoda different hai.
   - BFS naturally top nodes pehle leta hai, jabki DFS me manually level check karna padta hai.
   - Advantage → DFS is cleaner, aur recursion se easily handle hota hai.
*/

