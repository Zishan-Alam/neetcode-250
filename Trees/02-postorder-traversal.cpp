class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &res) {
        if(!root) return;

        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
      
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            res.push_back(node->val);   // Process the node

            // ⚡ Postorder = Left → Right → Node
            // But hum reverse logic use kar rahe hain: Node → Right → Left
            // Aur baad me reverse(res) karke final postorder milta hai
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        reverse(res.begin(), res.end());  // ✅ Reverse to get Left → Right → Node
        return res;
    }
};

/*
------------------------------------------
🧩 INTUITION SUMMARY:
------------------------------------------
1️⃣ Postorder = Left → Right → Node
2️⃣ Hum reverse logic lagate hain: Node → Right → Left
3️⃣ Stack me Left pehle aur Right baad me push karte hain
    taki reverse ke baad correct order mil jaaye
4️⃣ Last me res ko reverse kar dete hain

------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------
O(N) — Har node ek baar process hoti hai

------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------
O(H) — Stack ke andar maximum height ke nodes aate hain
      (H = height of tree)
------------------------------------------
*/
