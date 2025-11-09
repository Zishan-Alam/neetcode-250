class WordDictionary {
public:

    // Each trieNode represents a single character in the word
    struct trieNode {
        bool isEndOfWord;          // Marks if this node completes a word
        trieNode* children[26];    // Each index corresponds to 'a' - 'z'
    };

    // Helper to create a new node
    trieNode* getNode() {
        trieNode* trie = new trieNode();
        trie->isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            trie->children[i] = nullptr;
        }
        return trie;
    }

    trieNode* root;

    // Constructor initializes root node
    WordDictionary() {
        root = getNode();
    }
    
    // Insert a word into the Trie
    void addWord(string word) {     // Example: "bad"
        trieNode* crawler = root;

        for(char ch : word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == nullptr) {
                crawler->children[idx] = getNode(); // create new node if missing
            }
            crawler = crawler->children[idx];       // move forward
        }
        crawler->isEndOfWord = true;                // mark word end
    }

    // Recursive helper function for search (handles '.')
    bool searchUtil(trieNode* root, string word) {  // Example: "b.ets"
        trieNode* crawler = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            // Case 1: wildcard '.' → can match any letter
            if(ch == '.') {
                for(int j = 0; j < 26; j++) {
                    if(crawler->children[j] != nullptr) {
                        // Try all possible children recursively
                        if(searchUtil(crawler->children[j], word.substr(i + 1)))
                            return true;
                    }
                }
                return false; // if none match
            }

            // Case 2: normal character but no child → no match
            else if(crawler->children[idx] == nullptr)
                return false;

            // Move to next character
            crawler = crawler->children[idx];
        }

        // Word found only if this node marks end of a valid word
        return crawler != nullptr && crawler->isEndOfWord;
    }
    
    // Public search function
    bool search(string word) {
        return searchUtil(root, word);
    }
};


/*
🧠 INTUITION (Roman Hindi me):
-----------------------------------
Trie ek tree jaisa structure hai jisme har node ek character represent karta hai.
Normal case me har letter ke liye direct child pointer follow karte hain.
Lekin agar word me '.' aaye to iska matlab hai — koi bhi character match ho sakta hai.
To hum '.' ke case me 26 possible branches (a-z) me recursively search karte hain.
Agar kisi ek branch se valid word mil gaya, to hum true return kar dete hain.

🪄 DRY RUN EXAMPLE:
-----------------------------------
addWord("bad")
addWord("bat")
Trie structure:
  root
   └── b
        └── a
             ├── d (end)
             └── t (end)

search("b.t"):
- 'b' → 'a' → '.' (dot mila)
- '.' ke liye dono children try karte hain: 'd' aur 't'
- 'b' → 'a' → 't' matches and isEndOfWord = true ✅ → return true

search("ba."):
- 'b' → 'a' → '.' (dot mila)
- '.' ke liye 'd' aur 't' dono paths valid, 'bad' aur 'bat' dono exist ✅

🕒 TIME COMPLEXITY:
-----------------------------------
addWord() → O(L), where L = word length
search()  → 
    • Without '.' → O(L)
    • With '.' → Worst case O(26^d), d = number of '.' in word
because each '.' may branch into 26 recursive calls

💾 SPACE COMPLEXITY:
-----------------------------------
O(L * N) for Trie storage (N = number of words, L = avg length)
O(L) recursion stack during search with '.'
*/
