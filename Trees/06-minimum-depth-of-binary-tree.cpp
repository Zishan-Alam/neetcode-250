class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;  // Agar tree empty hai, depth = 0

        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;  // Level counter

        while(!que.empty()) {
            int n = que.size();
            depth++; // Ek level complete hone par depth badh jaati hai

            while(n--) {
                TreeNode* node = que.front(); 
                que.pop();

                // ✅ Agar leaf node mil gaya → wahi minimum depth hogi
                if(!node->left && !node->right) 
                    return depth;

                // Next level ke nodes queue me daal do
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth; // (Although loop se pehle hi return ho jaata hai)
    }
};

/*
🧠 Intuition:
BFS traversal level by level karta hai.
Minimum depth wahi level hogi jahan pehla leaf node mile.
Jab tak koi leaf nahi milta, hum queue ke next level tak traverse karte hain.

⏱️ Time Complexity: O(n)
→ Har node ek baar process hota hai (worst case jab leaf last level par ho).

💾 Space Complexity: O(n)
→ Queue me ek level ke nodes store hote hain (worst case me complete tree).

💡 Bhai-style yaad rakhne ka shortcut:
"Max depth me queue exhaust hone tak jaate hain,
Min depth me pehla leaf milte hi ruk jaate hain."
*/

```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;  // Base case: agar root hi null hai

        // ✅ Agar root khud leaf node hai → depth = 1
        if(!root->left && !root->right) return 1;

        // ⚙️ Left subtree ka depth nikalte hain (agar exist karta hai)
        int left = (root->left) ? minDepth(root->left) : INT_MAX;

        // ⚙️ Right subtree ka depth nikalte hain (agar exist karta hai)
        int right = (root->right) ? minDepth(root->right) : INT_MAX;

        // 🧩 Minimum depth hamesha chhoti subtree ki hoti hai + current level (1)
        return 1 + min(left, right);
    }

};

/*
🧠 Intuition:
- Hum recursively har node ke liye left aur right subtree ki minimum depth nikalte hain.
- Agar koi subtree exist nahi karta (NULL hai), to usse ignore karte hain (INT_MAX use karke).
- Jab leaf milta hai, to waha depth = 1 hoti hai.
- Final answer = 1 (current node) + min(leftDepth, rightDepth)

⚠️ Important:
Directly `min(minDepth(left), minDepth(right))` likhne se dikkat hoti hai 
agar ek subtree NULL ho — kyunki NULL subtree ki depth 0 hoti hai,
aur hum use ignore karna chahte hain, na ki minimum lena chahte.

⏱️ Time Complexity: O(n)
→ Har node ek baar visit hota hai.

💾 Space Complexity: O(h)
→ Recursion stack height = tree ki height (O(log n) for balanced, O(n) for skewed tree).

💡 Bhai-style yaad rakhne ka shortcut:
"Min depth me null subtree ko ignore karo,
Leaf milte hi 1 return karo." 🚀
*/
