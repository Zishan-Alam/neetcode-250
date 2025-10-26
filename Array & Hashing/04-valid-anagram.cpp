class Solution {
public:
    bool isAnagram(string s, string t) {
        // dono strings ko sort kar rahe hain
        // taaki unke characters same order me aa jayein
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // agar dono sorted strings same nikli
        // to iska matlab dono anagram hain
        return s == t;
    }
};

/*
🧠 Intuition (Hinglish me):
Anagram matlab — dono strings me same characters hone chahiye, bas order matter nahi karta.
Agar hum dono strings ko sort kar dein aur compare karein,
to agar dono equal hain → iska matlab characters same hain → valid anagram.

⚙️ Time Complexity:
→ O(n log n)
    - Har string ko sort karne me O(n log n) lagta hai (n = string length).
    - Comparison O(n) me hota hai.
    - Overall: O(n log n)

💾 Space Complexity:
→ O(1) (agar in-place sort maan lein)
    - Humne koi extra data structure use nahi kiya,
      bas string ke andar hi sort hua hai.
*/

-----------------------------------------------------------------------------------------------------------------------------------------

  class Solution {
public:
    bool isAnagram(string s, string t) {
        // agar dono strings ka size alag hai to wo anagram kabhi nahi ho sakte
        if (s.size() != t.size()) return false;

        // ek frequency vector bana rahe hain jisme 26 letters (a-z) ke counts store honge
        vector<int> freq(26, 0);

        // pehle string 's' ke har character ke liye count badha rahe hain
        for(char &ch : s) freq[ch - 'a']++;

        // ab string 't' ke har character ke liye count ghata rahe hain
        for(char &ch : t) freq[ch - 'a']--;

        // agar sab characters ka final count 0 ho gaya,
        // to iska matlab dono strings me same characters the
        for(int i : freq) {
            if(i != 0)
                return false; // koi mismatch mila to anagram nahi hai
        }

        // agar koi mismatch nahi mila, to s aur t anagram hain
        return true;
    }
};

/*
🧠 Intuition (Hinglish me):
Anagram hone ke liye har character ka count dono strings me equal hona chahiye.
Isliye hum ek frequency array bana ke pehle string ke counts badhate hain aur
dusre string ke counts ghatate hain.
Agar end me sab counts 0 ho gaye → dono anagram hain.

⚙️ Time Complexity:
→ O(n)
    - Dono strings ke har character ko ek baar traverse kar rahe hain.
    - Total operations proportional to n (string length).

💾 Space Complexity:
→ O(1)
    - Fixed size vector (26) use kiya hai — constant space.
    - Input size se independent hai.
*/

