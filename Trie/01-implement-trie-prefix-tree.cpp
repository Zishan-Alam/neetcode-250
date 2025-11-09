// ✅ IMPLEMENT TRIE (Prefix Tree)
// ------------------------------------------------------------
// Author: Zishan Alam Khan
// Description: Trie (Prefix Tree) implementation supporting
//              insert(), search(), and startsWith() operations.
// ------------------------------------------------------------

class Trie {
public:

    // ------------------------------------------------------------
    // Structure for each Trie Node
    // ------------------------------------------------------------
    struct trieNode {
        bool isEndOfWord;          // Marks end of a complete word
        trieNode* children[26];    // Each node can have 26 children (a-z)
    };

    trieNode* root; // Root node of the Trie

    // ------------------------------------------------------------
    // Helper: Create and initialize a new Trie node
    // ------------------------------------------------------------
    trieNode* getNode() {
        trieNode* trie = new trieNode();
        trie->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            trie->children[i] = nullptr;
        }
        return trie;
    }

    // ------------------------------------------------------------
    // Constructor: Initialize root node
    // ------------------------------------------------------------
    Trie() {
        root = getNode();
    }

    // ------------------------------------------------------------
    // Insert a word into the Trie
    // ------------------------------------------------------------
    void insert(string word) {  // Example: "apple"
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';   // Map 'a'..'z' → 0..25

            // If path doesn't exist, create a new node
            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true; // Mark end of the word
    }

    // ------------------------------------------------------------
    // Search for a complete word in the Trie
    // ------------------------------------------------------------
    bool search(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            // If path breaks, word not found
            if (crawler->children[idx] == nullptr) return false;

            crawler = crawler->children[idx];
        }
        // Return true only if word is complete (not just prefix)
        return crawler->isEndOfWord == true;
    }

    // ------------------------------------------------------------
    // Check if any word in Trie starts with given prefix
    // ------------------------------------------------------------
    bool startsWith(string prefix) {  // Example: "app"
        trieNode* crawler = root;

        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';

            // If prefix path breaks, return false
            if (crawler->children[idx] == nullptr) return false;

            crawler = crawler->children[idx];
        }
        // Successfully traversed entire prefix
        return true;
    }
};


/*
------------------------------------------------------------
🧠 INTUITION (Roman Hindi):
------------------------------------------------------------
Trie ek prefix-based tree hai jahan har node ek character ko represent karta hai.
- Har node ke paas 26 possible branches hoti hain (a-z ke liye).
- Jab hum ek word insert karte hain, hum letter by letter tree me jaate hain.
- Agar node nahi milta to naya node bana dete hain.
- Last letter ke node pe `isEndOfWord = true` kar dete hain.

Search me hum same path follow karte hain:
- Agar beech me path break ho gaya → word nahi hai.
- Agar last tak gaya aur `isEndOfWord == true` hai → word present hai.

Prefix check (`startsWith`) me bas itna dekhte hain ki prefix tak path exist karta hai ya nahi.

------------------------------------------------------------
🔍 DRY RUN EXAMPLE:
------------------------------------------------------------
Insert("apple"):

root
 └── a
      └── p
           └── p
                └── l
                     └── e (endOfWord = true)

search("apple") → true  
search("app")   → false (prefix hai, pura word nahi)

startsWith("app") → true  
startsWith("bat") → false

------------------------------------------------------------
⏱️ TIME COMPLEXITY:
------------------------------------------------------------
- insert(word): O(L)
- search(word): O(L)
- startsWith(prefix): O(P)
  where L = word length, P = prefix length

------------------------------------------------------------
💾 SPACE COMPLEXITY:
------------------------------------------------------------
O(26 * N * L)
- Har node me 26 pointers hote hain
- N = number of inserted words
- L = average length of each word

------------------------------------------------------------
*/
