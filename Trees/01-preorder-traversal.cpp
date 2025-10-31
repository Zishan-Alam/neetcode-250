class Solution {
public:

    void preOrder(TreeNode* root, vector<int> &result) {
        if(!root) return;

        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preOrder(root, result);
        return result;
    }
};

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        if(!root) return {};  // Base case: agar tree empty hai, to empty vector return

        vector<int> res;        // Output vector to store preorder traversal
        stack<TreeNode*> st;    // Stack to simulate recursive calls
        st.push(root);          // Step 1️⃣: Push root node into stack

        while(!st.empty()) {
            TreeNode* node = st.top();  // Step 2️⃣: Take top element
            st.pop();                   // Pop it since we are processing it

            res.push_back(node->val);   // Step 3️⃣: Process current node (Node)

            // ⚡ Step 4️⃣: Push children
            // Preorder = Node → Left → Right
            // But stack LIFO hai, so Right ko pehle push karte hain
            // taki Left next iteration me pehle nikle aur process ho.
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }

        return res;  // ✅ Final preorder traversal stored in res
    }
};


/*
------------------------------------------
🧩 INTUITION :
------------------------------------------
1️⃣ Preorder = Node → Left → Right
2️⃣ Recursion ke jagah stack use karke manually traversal kar rahe hain
3️⃣ Stack me Right pehle aur Left baad me push karte hain
    → taaki Left subtree pehle process ho jaaye
4️⃣ Har node ko ek hi baar visit karte hain

------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------
O(N) → Har node ko exactly ek baar visit karte hain
       (N = number of nodes in the tree)

------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------
O(H) → Stack ke andar maximum H nodes ja sakte hain
       (H = height of tree)
👉 Worst case (skewed tree): O(N)
👉 Best case (balanced tree): O(log N)

------------------------------------------
*/
