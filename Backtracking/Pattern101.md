# 🧠 BACKTRACKING PATTERN CHEATSHEET (by Zishan 💥)

Master the difference between Subsets, Permutations, and Combinations —  
ek baar ye samajh gaya to koi bhi recursion/backtracking problem phod dega ⚙️

---

## ⚙️ QUICK 5-POINT SUMMARY (yaad karne ke liye bhai-style)

- **`i = start`** → jab elements **sorted order ya unique combination** banana ho.  
  ➤ *Used in:* Subsets, Combinations, Combination Sum variants

- **`i = 0`** → jab **order matter kare (Permutation type)**.  
  ➤ *Used in:* Permutations, Permutations-II

- **`solve(i)`** → jab **same element dobara use kar sakte ho**.  
  ➤ *Used in:* Combination Sum

- **`solve(i+1)`** → jab **next element lena ho (no reuse)**.  
  ➤ *Used in:* Subsets, Combinations, Combination Sum-II, Combination Sum-III

- **`used[i]`** → sirf **Permutations wale case** me (kyunki order aur repeat dono control karna hota hai).

---

## 🌿 PUSH CONDITIONS (result.push_back(temp) kab lagta hai)

- **Subsets** → Har recursive call ke start me  
  🧩 *Logic:* Har path ek valid subset hota hai (empty se full tak sab allowed)

- **Permutations** → Jab `temp.size() == nums.size()`  
  🧩 *Logic:* Jab poore elements use ho gaye, tabhi valid permutation banta hai

- **Combinations** → Jab condition (sum ya size) match kare  
  🧩 *Logic:* Fixed size ya target sum milte hi answer valid hota hai

- **Reuse allowed** → same index se call  
- **Reuse not allowed** → next index se call  
- **Duplicates skip** → sorted + `continue`
- **Used array** → jab loop `i = 0` se start hota hai (Permutation type)

---

## ⚙️ BONUS (Loop logic shortcut)

| Case | Loop start | Reuse allowed? | Duplicate handle |
|------|-------------|----------------|------------------|
| Subsets | `i = start` | ✅ Yes | Optional |
| Subsets-II | `i = start` | ✅ Yes | `if(i > start && nums[i]==nums[i-1]) continue;` |
| Permutations | `i = 0` | ❌ No | Use `used[i]` |
| Permutations-II | `i = 0` | ❌ No | Use `used[i]` + skip duplicates |
| Combination Sum | `i = start` | ✅ Yes | No duplicate skip |
| Combination Sum-II | `i = start` | ❌ No | Skip duplicates |
| Combination Sum-III | `i = start` | ❌ No | No duplicates, fixed 1–9 |

---

## 🧩 BACKTRACKING MASTER SUMMARY

### 1️⃣ Subsets  
**When to push:** Har recursive call ke start me  
**Logic:** Har path ek valid subset hota hai (0 se n tak length allowed)  
**Memory Trick:** “Har step ek subset hai”

---

### 2️⃣ Subsets-II  
**When to push:** Har recursive call ke start me  
**Logic:** Same as subsets, bas duplicates skip karte hain  
**Memory Trick:** “Har step + skip duplicates”

---

### 3️⃣ Permutations  
**When to push:** Jab `temp.size() == nums.size()`  
**Logic:** Order matter karta hai, sab fill hone par hi valid  
**Memory Trick:** “Full length = valid”

---

### 4️⃣ Permutations-II  
**When to push:** Jab `temp.size() == nums.size()`  
**Logic:** Same as permutation, but duplicates avoid  
**Memory Trick:** “Full + unique only”

---

### 5️⃣ Combinations (LC 77)  
**When to push:** Jab `temp.size() == k`  
**Logic:** Fixed size ke combinations chahiye  
**Memory Trick:** “Size == k”

---

### 6️⃣ Combination Sum (LC 39)  
**When to push:** Jab `sum == target`  
**Logic:** Sum match kar gaya → valid combination  
**Memory Trick:** “Sum == target”

---

### 7️⃣ Combination Sum-II (LC 40)  
**When to push:** Jab `sum == target`  
**Logic:** Same as above, duplicates skip + reuse nahi  
**Memory Trick:** “Sum == target, no reuse”

---

### 8️⃣ Combination Sum-III (LC 216)  
**When to push:** Jab `temp.size() == k && sum == target`  
**Logic:** Dono condition match hone chahiye  
**Memory Trick:** “Fix k + Fix sum”

---

## 🔥 FINAL TAKEAWAYS

- **Subsets →** Har step ek answer  
- **Permutations →** Full length hone par answer  
- **Combinations →** Fixed condition match hone par answer  
- **Reuse allowed →** `solve(i, …)`  
- **Reuse not allowed →** `solve(i+1, …)`  
- **Duplicates skip →** Sort + skip logic  
- **Used array →** Sirf permutation types me  

---

### 💬 Pro Tip
> Backtracking = pick → explore → unpick  
> Jab ye teen step samajh gaye, to koi bhi recursion problem impossible nahi lagti.

---

⭐ Made by **Zishan Alam Khan**  
_For Leetcode mastery & product-based interview prep_
