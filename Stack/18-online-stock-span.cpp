class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, span}

    StockSpanner() {
        // Constructor — initialize empty stack
    }
    
    int next(int price) {
        int span = 1; // Every day counts as 1

        // Jab tak previous prices current se chhote ya equal hain,
        // unka span add kar lo aur unhe hata do (merge logic)
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Current price with its total span
        st.push({price, span});

        return span;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Har din ka "stock span" matlab — current din ke price ke liye,
peeche kitne consecutive din tak stock ka price <= current price tha.

👉 Isme hum decreasing stack rakhte hain:
   - Stack me (price, span) store karte hain.
   - Jab naya price aata hai:
       • Agar wo bada hai top se → matlab previous din uske andar include ho sakte hain.
       • Unke span ko add karte jao aur pop kar do.
   - Phir current {price, total_span} ko push kar do.

Example:
Input: [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]

Dry Run:
price = 100 → span=1 → stack=[{100,1}]
price = 80  → span=1 → stack=[{100,1},{80,1}]
price = 60  → span=1 → stack=[{100,1},{80,1},{60,1}]
price = 70  → 70>60 pop(60,1) span=2 → push(70,2)
              stack=[{100,1},{80,1},{70,2}]
price = 60  → span=1 → stack=[{100,1},{80,1},{70,2},{60,1}]
price = 75  → 75>60 pop(60,1)
              75>70 pop(70,2)
              75>80? no → span=4 → push(75,4)
price = 85  → 85>75 pop(75,4)
              85>80 pop(80,1)
              85>100? no → span=6 → push(85,6)

⏱️ Time Complexity: O(N) (Amortized — each element pushed & popped once)
💾 Space Complexity: O(N)
*/
