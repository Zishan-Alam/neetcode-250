class Solution {
public:
    // 🔹 Helper function: height nikalta hai
    int height(TreeNode* root) {
        // Agar node null hai → height = 0
        return (!root) ? 0 : 1 + max(height(root->left), height(root->right));
    }

    // 🔹 Main function: diameter nikalta hai
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        // ✅ Step 1: Left subtree ka diameter
        int leftDia  = diameterOfBinaryTree(root->left);

        // ✅ Step 2: Right subtree ka diameter
        int rightDia = diameterOfBinaryTree(root->right);

        // ✅ Step 3: Diameter passing through current node
        // (Longest path that goes from left subtree → root → right subtree)
        int currDia  = height(root->left) + height(root->right);

        // ✅ Step 4: Final answer = max of all three
        return max(currDia, max(leftDia, rightDia));
    }
};

/*
🧠 Intuition:
- Diameter ka matlab hai → longest path between any two nodes.
- Har node par hum ye check karte hain:
    🔹 Kya longest path left subtree me hai?
    🔹 Ya right subtree me?
    🔹 Ya phir current node se guzarta hai (leftHeight + rightHeight)?
- Ye tino me se jo max hoga, wahi diameter.

⚙️ But dikkat:
- Har node par height() function recursively call hota hai,
  jisse har level par puri subtree dobara traverse hoti hai.
  👉 Is wajah se ye O(n²) ban jaata hai.

⏱️ Time Complexity: O(n²)
→ Har node par height() call O(n) time leti hai.

💾 Space Complexity: O(h)
→ Recursion stack (tree height).

💡 Optimized version (O(n)):
- Height aur diameter ko ek hi pass me return karo.
- Ek helper function banao jo pair<int,int> (height, diameter) return kare.

💬 Bhai-style yaad rakhne ka shortcut:
"Diameter = left + right height ka max,
Par height baar-baar mat nikal, nahi to n² lag jaayega!" ⚡
*/

````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Solution {
public:

    // Helper function to calculate height and simultaneously update diameter
    int height(TreeNode* root, int& dia) {
        if(!root) return 0;  // base case: agar node NULL hai to height 0

        // Left subtree ka height nikaal lo
        int lh = height(root->left, dia);

        // Right subtree ka height nikaal lo
        int rh = height(root->right, dia);

        // Diameter ka matlab hai: kisi node ke through jane wala
        // longest path between two leaf nodes = left height + right height
        dia = max(dia, lh + rh);

        // Current node ka height return karo
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;               // global variable to store max diameter
        height(root, dia);         // helper function call
        return dia;                // final diameter return
    }
};

/*
🧠 Intuition:
Har node ke liye hum do kaam karte hain —
1️⃣ Uske left aur right subtree ke heights nikaalte hain.
2️⃣ Fir check karte hain ki leftHeight + rightHeight kya ab tak ka maximum diameter banata hai.

Isse hum ek hi DFS traversal me har node se guzarne wale longest path (diameter) ko track kar lete hain.
Height function recursion ke saath height return karta hai aur diameter ko reference se update karta hai.

⏱️ Time Complexity:  O(N)
Har node ek baar visit hota hai, aur har call me constant time kaam hota hai.

💾 Space Complexity: O(H)
Recursion stack depth jitni space lagegi, jaha H = height of the tree.
(Worst case: skewed tree → O(N), Best case: balanced tree → O(log N))
*/

  `````````````````````````````````````````````````
