class Solution {
public:
    void inorder(TreeNode* root, vector<int> &res) {
        if(!root) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;

        // Jab tak ya to stack me element hai ya current node exist karti hai
        while(!st.empty() || node) {

            // 🔹 Step 1: Go to the extreme left
            // (Inorder traversal: Left → Node → Right)
            while(node) {
                st.push(node);
                node = node->left;
            }

            // 🔹 Step 2: Process the top node (Leftmost element)
            node = st.top(); st.pop();

            // Visit / store current node
            res.push_back(node->val);

            // 🔹 Step 3: Move to the right subtree
            node = node->right;
        }
        return res;
    }
};

/*
------------------------------------------
🧠 INTUITION (Inorder Traversal - Iterative)
------------------------------------------
Inorder traversal order: Left → Node → Right

Recursive way me:
    inorder(root->left)
    process(root)
    inorder(root->right)

Iterative way me:
    🔹 Stack simulate karta hai recursion call stack ko.
    🔹 Pehle leftmost tak jaate hain (push karte hue).
    🔹 Jab left NULL mil jaaye, top element process karte hain (ye "Node" hai).
    🔹 Fir uske right subtree me jaate hain.
    🔹 Ye process tab tak repeat hota hai jab tak stack aur node dono empty na ho jaayein.

------------------------------------------
⚙️ STEP FLOW (Example):
------------------------------------------
Input: [1, null, 2, 3]

1️⃣ Start at root = 1 → push(1) → move left → NULL
2️⃣ Pop 1 → add to result → move right → node = 2
3️⃣ Push(2) → move left → node = 3
4️⃣ Push(3) → move left → NULL
5️⃣ Pop(3) → add to result
6️⃣ Pop(2) → add to result → right = NULL
✅ Done → [1, 3, 2]

------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------
O(N) — Har node ek hi baar visit hoti hai.

------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------
O(H) — Stack me max tree height tak nodes aa sakte hain.
(H = height of the binary tree)

------------------------------------------
*/

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        TreeNode* curr = root;

        while(curr) {

            if(curr->left) {
                TreeNode* leftChild = curr->left;

                while(leftChild->right) leftChild = leftChild->right;
          
                leftChild->right = curr;

                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
            else{
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};
