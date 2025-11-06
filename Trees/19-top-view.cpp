// ✅ TOP VIEW OF BINARY TREE
// -----------------------------------------------------------
// Author: Zishan Alam Khan
// Approach: Level Order (BFS) + Horizontal Distance Tracking
// -----------------------------------------------------------

class Solution {
public:

    // -----------------------------------------------------------
    // Helper Function:
    // Find leftmost (l) and rightmost (r) horizontal boundaries.
    // -----------------------------------------------------------
    void findBoundary(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        findBoundary(root->left, pos - 1, l, r);
        findBoundary(root->right, pos + 1, l, r);
    }

    // -----------------------------------------------------------
    // Main Function: Return Top View of Binary Tree
    // -----------------------------------------------------------
    vector<int> topView(TreeNode* root) {
        if (!root) return {};

        // Step 1️⃣: Find boundaries (horizontal distance range)
        int l = 0, r = 0;
        findBoundary(root, 0, l, r);

        int width = r - l + 1;
        vector<int> res(width, INT_MIN);

        // Step 2️⃣: BFS Traversal (Level Order)
        queue<pair<TreeNode*, int>> q;
        q.push({root, -l}); // Normalize so leftmost = 0

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            // Top View logic:
            // Fill only first time (top-most node)
            if (res[pos] == INT_MIN)
                res[pos] = node->val;

            if (node->left) q.push({node->left, pos - 1});
            if (node->right) q.push({node->right, pos + 1});
        }

        // Step 3️⃣: Return result
        return res;
    }
};


/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Top view ka matlab — agar tree ko upar se dekho,
to har vertical column me sabse upar ka node kaunsa dikhega.

Har node ko ek horizontal position (pos) assign karte hain:
→ Left child: pos - 1  
→ Right child: pos + 1  

Ab BFS (level order) traversal karte hain.
Kyuki BFS upar se neeche jaata hai, pehle level ka node
sabse upar hota hai.  
Isliye hum pehli baar `res[pos]` fill karte hain aur 
uske baad overwrite **nahi** karte.

------------------------------------------------------------
🔍 DRY RUN EXAMPLE:
------------------------------------------------------------
Tree:
        1
       / \
      2   3
       \   \
        5   4

Traversal:
1️⃣ Root(1, pos=0) → res[0]=1  
   Queue = [(2,-1), (3,1)]

2️⃣ Node(2, pos=-1) → res[-1-l]=res[0]=2  
   Queue = [(3,1), (5,0)]

3️⃣ Node(3, pos=1) → res[1-l]=res[2]=3  
   Queue = [(5,0), (4,2)]

4️⃣ Node(5, pos=0) → Already filled → skip  
   Queue = [(4,2)]

5️⃣ Node(4, pos=2) → res[3]=4

✅ Final Top View = [2, 1, 3, 4]

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
O(N) → Har node ek baar visit hoti hai (BFS traversal)

💾 SPACE COMPLEXITY:
O(W) → Queue + Result vector (W = tree ki width)
------------------------------------------------------------
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

