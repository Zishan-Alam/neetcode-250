class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // 💥 Jab tak stack non-empty ho aur current asteroid left jaa raha ho (a < 0)
            // aur top of stack right jaa raha ho (st.top() > 0)
            // tab tak collision check karte rahenge
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop(); // top chhota hai → destroy ho gaya
                    continue;
                } 
                else if (st.top() == -a) {
                    st.pop(); // dono equal → dono destroy
                }
                destroyed = true; // current destroy ho gaya
                break;
            }

            if (!destroyed) st.push(a);
        }

        // ✅ Stack me bache sab safe asteroids hain
        vector<int> res(st.size());
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

/*
🧠 Intuition (Roman Hindi me):
Socho asteroid ek line me move kar rahe hain.
- Positive number → right side jaa raha hai 🚀
- Negative number → left side jaa raha hai 💥

Agar ek right moving asteroid (positive) aur ek left moving (negative) takraate hain,
tabhi collision hota hai.
→ Agar dono opposite direction me hain, to bada asteroid bacha rahta hai.

Stack use karte hain:
- Har asteroid ko stack me daal do.
- Agar current left jaa raha hai (a < 0) aur top right jaa raha hai (st.top() > 0), 
  to check karo kiski magnitude badi hai:
    - Agar |a| > top → top destroy, current bacha rahega → check next
    - Agar |a| == top → dono destroy
    - Agar |a| < top → current destroy

Agar koi collision nahi, to current asteroid ko push karo.

📘 Dry Run:
Input: [5, 10, -5]

Step1: push(5)
Stack: [5]
Step2: push(10)
Stack: [5, 10]
Step3: a = -5
→ top = 10 > 0, a < 0 → collision
→ |a| = 5 < 10 → current destroy
Stack: [5, 10]
✅ Output: [5, 10]

⏱️ Time Complexity: O(n)
(Each asteroid ek baar push/pop hota hai)

💾 Space Complexity: O(n)
(Stack store karta hai surviving asteroids)
*/
