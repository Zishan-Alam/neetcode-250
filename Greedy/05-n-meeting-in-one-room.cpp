// ===================== PROBLEM EXPLANATION =====================
/*
Problem: N Meetings in One Room

- Tumhe N meetings ke start[] aur end[] time diye gaye hain
- Ek hi room available hai
- Ek time pe sirf ek meeting ho sakti hai

Goal:
- Maximum number of meetings select karni hain
- Aisi meetings jinki timings overlap na kare

Rule:
- Meeting i tab select ho sakti hai jab
  uska start time >= last selected meeting ka end time

Return:
- Maximum number of meetings
*/
// ===============================================================


// -------------------- GREEDY APPROACH --------------------
// Best strategy: meetings ko unke end time ke according sort karo

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end, int n) {

        vector<pair<int,int>> meetings;

        // Step 1: Combine start & end
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Step 2: Sort by end time
        sort(meetings.begin(), meetings.end());

        int cnt = 1;                     // pehli meeting select
        int lastEnd = meetings[0].first;

        // Step 3: Select meetings greedily
        for (int i = 1; i < n; i++) {
            if (meetings[i].second >= lastEnd) {
                cnt++;
                lastEnd = meetings[i].first;
            }
        }

        return cnt;
    }
};

/*
====================== INTUITION ======================

Intuition (Roman Hindi):

- Agar hum late khatam hone wali meeting le lenge,
  toh aage ke liye kam time bachega
- Isliye hum hamesha woh meeting lenge
  jo sabse pehle khatam hoti hai

Greedy Choice Property:
- Har step pe earliest finishing meeting lena
- Future ke liye maximum space chhodta hai
- Isse total meetings count maximize hota hai

Dry Run:
start = {1, 3, 0, 5, 8, 5}
end   = {2, 4, 6, 7, 9, 9}

Meetings (end, start) after sort:
(2,1), (4,3), (6,0), (7,5), (9,8), (9,5)

Select:
(2,1) → lastEnd = 2
(4,3) → select → lastEnd = 4
(6,0) → skip (0 < 4)
(7,5) → select → lastEnd = 7
(9,8) → select → lastEnd = 9
(9,5) → skip (5 < 9)

Answer = 4 meetings

Time Complexity:
- Sorting: O(n log n)
- Traversal: O(n)

Space Complexity:
- O(n) extra space
======================================================
*/
