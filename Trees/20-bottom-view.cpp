// ✅ BOTTOM VIEW OF BINARY TREE
// -----------------------------------------------------------
// Author: Zishan Alam Khan
// Approach: Level Order (BFS) + Horizontal Distance Mapping
// -----------------------------------------------------------

class Solution {
public:

    // -----------------------------------------------------------
    // Helper Function:
    // Find the leftmost (l) and rightmost (r) horizontal distance
    // boundaries in the binary tree.
    // -----------------------------------------------------------
    void findBoundary(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        findBoundary(root->left, pos - 1, l, r);
        findBoundary(root->right, pos + 1, l, r);
    }

    // -----------------------------------------------------------
    // Main Function: Return Bottom View of Binary Tree
    // -----------------------------------------------------------
    vector<int> bottomView(TreeNode* root) {
        if (!root) return {};

        // Step 1️⃣: Find boundaries (horizontal distance range)
        int l = 0, r = 0;
        findBoundary(root, 0, l, r);

        int width = r - l + 1;
        vector<int> res(width, INT_MIN);

        // Step 2️⃣: BFS Traversal (Level Order)
        queue<pair<TreeNode*, int>> q;
        q.push({root, -l}); // normalize so leftmost = 0 index

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            // Overwrite -> ensures bottom-most node for each column
            res[pos] = node->val;

            if (node->left) q.push({node->left, pos - 1});
            if (node->right) q.push({node->right, pos + 1});
        }

        // Step 3️⃣: Return the result
        return res;
    }
};

/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Bottom view ka matlab — agar tree ko bilkul niche se dekho,
to har vertical column me sabse neeche ka node kaunsa dikhega.

Har node ko ek "horizontal position (pos)" assign karte hain:
→ Left child: pos - 1  
→ Right child: pos + 1  

Ab BFS (level order) traversal karte hain.
BFS level by level neeche jaata hai, isliye jab bhi hum
`res[pos] = node->val` likhte hain, to neeche vala (latest) node
overwrite karke bottom view banata hai.

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

2️⃣ Node(2, pos=-1) → res[-1 - l]=res[0]=2
   Queue = [(3,1), (5,0)]

3️⃣ Node(3, pos=1) → res[1 - l]=res[2]=3
   Queue = [(5,0), (4,2)]

4️⃣ Node(5, pos=0) → res[1]=5 (overwrite 1)
   Queue = [(4,2)]

5️⃣ Node(4, pos=2) → res[3]=4

✅ Final Bottom View: [2, 5, 4]

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
O(N) — Har node ek baar visit hoti hai (BFS traversal)

💾 SPACE COMPLEXITY:
O(W) — Queue + Result vector (W = tree ki width)
------------------------------------------------------------
*/

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

// ✅ Bottom View of Binary Tree (DFS Approach)
// Author: Zishan Alam Khan

class Solution {
public:
    // ------------------------------------------------------------
    // Helper: find leftmost (l) and rightmost (r) horizontal limits
    // ------------------------------------------------------------
    void find(TreeNode* root, int pos, int &l, int &r) {
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    // ------------------------------------------------------------
    // DFS traversal: updates bottom-most node at each column
    // ------------------------------------------------------------
    void dfs(TreeNode* root, int pos, int currLevel, 
             vector<int> &res, vector<int> &level) {
        if(!root) return;

        // Agar current node zyada depth par hai, overwrite karo
        if(level[pos] < currLevel) {
            res[pos] = root->val;
            level[pos] = currLevel;
        }

        // Traverse left and right subtree with updated positions
        dfs(root->left, pos - 1, currLevel + 1, res, level);
        dfs(root->right, pos + 1, currLevel + 1, res, level);
    }

    // ------------------------------------------------------------
    // Main Function
    // ------------------------------------------------------------
    vector<int> bottomView(TreeNode* root) {
        if(!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);  // Step 1: find left & right limits
        int width = r - l + 1;

        vector<int> res(width);
        vector<int> level(width, INT_MIN);

        // Step 2: start DFS with normalized position (-l)
        dfs(root, -l, 0, res, level);

        // Step 3: return final bottom view
        return res;
    }
};

/*
🧠 Intuition (Roman Hindi):
- Har node ko ek horizontal position (pos) assign karte hain.
  Left child -> pos - 1
  Right child -> pos + 1
- DFS se har path explore karte hain, aur jab bhi kisi column (pos)
  me koi node zyada depth (currLevel) pe milta hai, usse overwrite kar dete hain.
- Aise hi har column ka sabse neeche wala node final bottom view deta hai.

🧩 Dry Run Example:
Tree:
        1
       / \
      2   3
       \   \
        5   4

Traversal order (DFS):
1(pos=0, lvl=0) → res[0]=1
2(pos=-1,lvl=1) → res[-1+1=0]=2
5(pos=0,lvl=2) → res[0+1=1]=5 (overwrites 1)
3(pos=1,lvl=1) → res[1+1=2]=3
4(pos=2,lvl=2) → res[2+1=3]=4
✅ Bottom View = [2, 5, 4]

⏱️ Time:  O(N)   // Har node ek baar visit hota hai
💾 Space: O(H)   // DFS recursion stack (H = height of tree)
*/
