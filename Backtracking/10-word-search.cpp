// ✅ WORD SEARCH (Backtracking + DFS)
// ------------------------------------------------------------
// Approach: DFS traversal from each cell matching the first char.
// If character matches, explore in 4 directions (up, down, left, right).
// Mark visited cells temporarily as '$' to avoid revisiting.
// ------------------------------------------------------------

class Solution {
public:
    int m, n;
    // Directions represent movement in 4 possible ways:
    // ↓ Down  → {+1,  0}
    // ↑ Up    → {-1,  0}
    // → Right → { 0, +1}
    // ← Left  → { 0, -1}
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};


    // DFS function to search the word
    bool find(vector<vector<char>> &board, string word, int i, int j, int idx) {
        // ✅ Base case: all characters matched
        if (idx == word.length()) return true;

        // ❌ Out of bounds or visited or mismatch
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
            return false;

        // Temporarily mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 directions
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (find(board, word, new_i, new_j, idx + 1))
                return true;
        }

        // Backtrack → unmark visited cell
        board[i][j] = temp;
        return false;
    }

    // Main function: start search from each cell that matches first character
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

/*
------------------------------------------------------------
🧠 DRY RUN (Example):
------------------------------------------------------------
board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED"

→ Start from (0,0) = 'A'
   - Go right → 'B'
     - Go right → 'C'
       - Go down → 'C'
         - Go left → 'E'
           - Go down → 'D' ✅ Found word

Backtracking ensures we revert visited cells after exploring each path.

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
O(m * n * 4^L)
→ m*n = total cells
→ L = length of word
→ In worst case, from each cell we explore 4 directions recursively.

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(L)
→ recursion depth up to length of word.
→ plus O(1) extra (since we modify board in-place).
------------------------------------------------------------
*/
