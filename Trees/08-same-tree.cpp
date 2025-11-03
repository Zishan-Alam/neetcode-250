class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case 1: dono null hai -> same tree
        if(!p && !q) return true;

        // Base Case 2: ek null hai, dusra nahi -> not same
        if(!p || !q) return false;

        // Base Case 3: current node values differ -> not same
        if(p->val != q->val) return false;

        // Recursive Case:
        // dono ke left aur right subtree check karo
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
🧠 Intuition:
Do trees same hone ke liye har node par 3 condition match karni hoti hai:
1️⃣ Value same honi chahiye.
2️⃣ Left subtree same hona chahiye.
3️⃣ Right subtree same hona chahiye.

Agar kisi bhi point par mismatch milta hai (null check ya value mismatch),
to recursion turant false return kar deta hai.
Isse har node ke pair ko top-down compare karke full tree verify hota hai.

⏱️ Time Complexity:  O(N)
Har node ek baar visit hota hai (where N = min(nodes in p, q)).

💾 Space Complexity: O(H)
Recursion stack ka height jitni space lagti hai (H = height of the tree).
Best case → O(log N) (balanced), Worst case → O(N) (skewed tree)
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Agar dono null hain -> same tree
        if(!p && !q) return true;
        // Agar ek null aur dusra nahi -> not same
        if(!p || !q) return false;

        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});

        while(!que.empty()) {
            auto [node1, node2] = que.front();
            que.pop();

            // Values different -> not same
            if(node1->val != node2->val) return false;

            // Left child check karo
            if(node1->left && node2->left) que.push({node1->left, node2->left});
            else if(node1->left || node2->left) return false;

            // Right child check karo
            if(node1->right && node2->right) que.push({node1->right, node2->right});
            else if(node1->right || node2->right) return false;
        }
        return true;
    }
};

/*
🧠 Intuition:
Recursive DFS ke jagah hum BFS (queue) use kar rahe hain.
Har step par dono trees ke same-level nodes ko ek pair me compare karte hain:
  1️⃣ Agar dono nodes null -> skip
  2️⃣ Agar ek null aur dusra non-null -> not same
  3️⃣ Agar values different -> not same
  4️⃣ Agar dono same -> unke left aur right child queue me daal do

Ye process level-by-level comparison karta hai.

⏱️ Time Complexity:  O(N)
Har node ek baar visit hota hai.

💾 Space Complexity: O(N)
Queue me worst case me N/2 nodes (last level) ho sakte hain.
*/


