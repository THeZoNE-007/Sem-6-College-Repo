Certainly! Below is the solution to all the questions from the uploaded file, written in markdown format.

---

# **Assignment-II Solutions**

## **1. Absolute Minimum Value of a Function Subject to a Constraint**
**Problem:**  
Find the absolute minimum value of the function $ f(x, y) = x^2 + y^2 $ subject to the constraint $ x^2 + 2y^2 = 1 $.

### **Solution:**
We use the **method of Lagrange multipliers**. Let:
$$
f(x, y) = x^2 + y^2 \quad \text{and} \quad g(x, y) = x^2 + 2y^2 - 1 = 0.
$$

The gradients are:
$$
\nabla f = (2x, 2y), \quad \nabla g = (2x, 4y).
$$

Equating $\nabla f = \lambda \nabla g$, we get:
$$
2x = \lambda(2x), \quad 2y = \lambda(4y).
$$

From the first equation:
$$
\lambda = 1 \quad \text{(if $x \neq 0$)}.
$$

From the second equation:
$$
\lambda = \frac{1}{2} \quad \text{(if $y \neq 0$)}.
$$

Case 1: $x = 0$:  
Substitute into the constraint $x^2 + 2y^2 = 1$:
$$
2y^2 = 1 \implies y = \pm \frac{1}{\sqrt{2}}.
$$
Thus, $(x, y) = (0, \pm \frac{1}{\sqrt{2}})$.

Case 2: $y = 0$:  
Substitute into the constraint $x^2 + 2y^2 = 1$:
$$
x^2 = 1 \implies x = \pm 1.
$$
Thus, $(x, y) = (\pm 1, 0)$.

Evaluate $f(x, y) = x^2 + y^2$ at these points:
- At $(0, \pm \frac{1}{\sqrt{2}})$: $f(0, \pm \frac{1}{\sqrt{2}}) = 0^2 + \left(\frac{1}{\sqrt{2}}\right)^2 = \frac{1}{2}$.
- At $(\pm 1, 0)$: $f(\pm 1, 0) = (\pm 1)^2 + 0^2 = 1$.

The **absolute minimum value** is:
$$
\boxed{\frac{1}{2}}
$$

---

## **2. Minimizing Production Costs**
**Problem:**  
A firm manufactures a commodity at two factories. The total cost of manufacturing depends on the quantities supplied by each factory and is expressed by the joint cost function:
$$
C(p, q) = 2pq^2 + pq + 22q + 500.
$$
The company’s objective is to produce 200 units while minimizing production costs. How many units should be supplied by each factory?

### **Solution:**
Let $p$ and $q$ represent the quantities produced by the two factories. We have the constraint:
$$
p + q = 200.
$$

Substitute $q = 200 - p$ into the cost function:
$$
C(p) = 2p(200 - p)^2 + p(200 - p) + 22(200 - p) + 500.
$$

Simplify:
$$
C(p) = 2p(40000 - 400p + p^2) + 200p - p^2 + 4400 - 22p + 500.
$$
$$
C(p) = 80000p - 800p^2 + 2p^3 + 200p - p^2 + 4400 - 22p + 500.
$$
$$
C(p) = 2p^3 - 801p^2 + 8178p + 4900.
$$

To minimize $C(p)$, take the derivative and set it to zero:
$$
C'(p) = 6p^2 - 1602p + 8178 = 0.
$$

Solve this quadratic equation using the quadratic formula:
$$
p = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}, \quad a = 6, \, b = -1602, \, c = 8178.
$$
$$
p = \frac{1602 \pm \sqrt{(-1602)^2 - 4(6)(8178)}}{12}.
$$
$$
p = \frac{1602 \pm \sqrt{2566404 - 196272}}{12}.
$$
$$
p = \frac{1602 \pm \sqrt{2370132}}{12}.
$$
$$
p = \frac{1602 \pm 1539.5}{12}.
$$

Two solutions:
$$
p_1 = \frac{1602 + 1539.5}{12} \approx 261.8, \quad p_2 = \frac{1602 - 1539.5}{12} \approx 5.2.
$$

Since $p + q = 200$, the feasible solution is:
$$
p \approx 5.2, \quad q \approx 194.8.
$$

Thus, the optimal production quantities are:
$$
\boxed{p \approx 5.2, \, q \approx 194.8.}
$$

---

## **3. Maximum Possible Weight of Minimum Spanning Tree**
**Problem:**  
Find the maximum possible weight of the minimum spanning tree of a graph with four vertices and six edges having weights $6, 7, 4, 8, 11, 9$.

### **Solution:**
A graph with 4 vertices will have a minimum spanning tree with $4 - 1 = 3$ edges. To maximize the weight of the minimum spanning tree, we select the three largest edge weights that do not form a cycle.

Sort the edge weights in descending order: $11, 9, 8, 7, 6, 4$.

Select the largest three weights ($11, 9, 8$) such that they do not form a cycle. Since there are only 4 vertices, any three edges can form a spanning tree.

The total weight is:
$$
11 + 9 + 8 = 28.
$$

Thus, the maximum possible weight of the minimum spanning tree is:
$$
\boxed{28.}
$$

---

## **4. Maximizing Profit Using Graphical Method**
**Problem:**  
Maximize the profit $Z = 2x + 3y$ subject to the constraints:
$$
x + 3y \leq 40, \quad 3x + y \leq 24, \quad x + y \leq 10, \quad x > 0, \, y > 0.
$$

### **Solution:**
Plot the constraints on a graph:

1. $x + 3y = 40$: Intercepts are $(40, 0)$ and $(0, \frac{40}{3})$.
2. $3x + y = 24$: Intercepts are $(8, 0)$ and $(0, 24)$.
3. $x + y = 10$: Intercepts are $(10, 0)$ and $(0, 10)$.

The feasible region is the intersection of these constraints. Evaluate $Z = 2x + 3y$ at the corner points of the feasible region.

Corner points:
- $(0, 0)$: $Z = 2(0) + 3(0) = 0$.
- $(8, 0)$: $Z = 2(8) + 3(0) = 16$.
- $(6, 4)$: $Z = 2(6) + 3(4) = 12 + 12 = 24$.
- $(0, 10)$: $Z = 2(0) + 3(10) = 30$.

The maximum profit is:
$$
\boxed{30.}
$$

---

## **5. Solving LPP Using Graphical Method**
**Problem:**  
Maximize $Z = 3x + 2y$ subject to:
$$
5x + y \geq 10, \quad x + y \geq 6, \quad x + 4y \geq 12, \quad x, y \geq 0.
$$

### **Solution:**
Plot the constraints on a graph:

1. $5x + y = 10$: Intercepts are $(2, 0)$ and $(0, 10)$.
2. $x + y = 6$: Intercepts are $(6, 0)$ and $(0, 6)$.
3. $x + 4y = 12$: Intercepts are $(12, 0)$ and $(0, 3)$.

The feasible region is the intersection of these constraints. Evaluate $Z = 3x + 2y$ at the corner points of the feasible region.

Corner points:
- $(2, 4)$: $Z = 3(2) + 2(4) = 6 + 8 = 14$.
- $(4, 2)$: $Z = 3(4) + 2(2) = 12 + 4 = 16$.
- $(0, 6)$: $Z = 3(0) + 2(6) = 12$.

The maximum value of $Z$ is:
$$
\boxed{16.}
$$

---

## **6. Solving LPP Using Graphical Method**
**Problem:**  
Maximize $Z = x + y$ subject to:
$$
x + y \leq 10, \quad x + y \geq 3, \quad x, y \geq 0.
$$

### **Solution:**
Plot the constraints on a graph:

1. $x + y = 10$: Intercepts are $(10, 0)$ and $(0, 10)$.
2. $x + y = 3$: Intercepts are $(3, 0)$ and $(0, 3)$.

The feasible region is the area between these two lines. Evaluate $Z = x + y$ at the corner points of the feasible region.

Corner points:
- $(3, 0)$: $Z = 3 + 0 = 3$.
- $(0, 3)$: $Z = 0 + 3 = 3$.
- $(10, 0)$: $Z = 10 + 0 = 10$.
- $(0, 10)$: $Z = 0 + 10 = 10$.

The maximum value of $Z$ is:
$$
\boxed{10.}
$$

---

## **7. Solving LPP Using Simplex Method**
**Problem:**  
Maximize $Z = 3x + 2y$ subject to:
$$
x + 3y \leq 40, \quad 3x + y \leq 24, \quad x + y \leq 10, \quad x, y \geq 0.
$$

### **Solution:**
Using the simplex method, convert inequalities to equalities by introducing slack variables $s_1, s_2, s_3$. The initial tableau is:

| Basis | $x$ | $y$ | $s_1$ | $s_2$ | $s_3$ | RHS |
|-------|-----|-----|--------|--------|--------|-----|
| $s_1$ | 1   | 3   | 1      | 0      | 0      | 40  |
| $s_2$ | 3   | 1   | 0      | 1      | 0      | 24  |
| $s_3$ | 1   | 1   | 0      | 0      | 1      | 10  |
| $Z$   | -3  | -2  | 0      | 0      | 0      | 0   |

Perform iterations until all coefficients in the $Z$-row are non-negative. After solving, the optimal solution is:
$$
x = 6, \, y = 4, \, Z = 26.
$$

Thus, the maximum value of $Z$ is:
$$
\boxed{26.}
$$

---

## **8. Probability of Vanilla Cookie from Bowl 1**
**Problem:**  
Suppose there are two bowls of cookies. Bowl 1 contains 30 vanilla cookies and 10 chocolate cookies. Bowl 2 contains 20 of each. A cookie is selected at random and is vanilla. What is the probability that it came from Bowl 1?

### **Solution:**
Let $B_1$ and $B_2$ denote selecting Bowl 1 and Bowl 2, respectively. Let $V$ denote selecting a vanilla cookie.

Using Bayes' theorem:
$$
P(B_1 | V) = \frac{P(V | B_1) P(B_1)}{P(V)}.
$$

Calculate each term:
- $P(B_1) = P(B_2) = 0.5$ (random selection of bowl).
- $P(V | B_1) = \frac{30}{40} = 0.75$.
- $P(V | B_2) = \frac{20}{40} = 0.5$.
- $P(V) = P(V | B_1)P(B_1) + P(V | B_2)P(B_2) = (0.75)(0.5) + (0.5)(0.5) = 0.375 + 0.25 = 0.625$.

Now calculate $P(B_1 | V)$:
$$
P(B_1 | V) = \frac{(0.75)(0.5)}{0.625} = \frac{0.375}{0.625} = 0.6.
$$

Thus, the probability that the vanilla cookie came from Bowl 1 is:
$$
\boxed{0.6.}
$$

---

## **9. Prisoner's Chance of Being Pardoned**
**Problem:**  
Three prisoners, A, B, and C, are in separate cells and sentenced to death. One prisoner is pardoned randomly. The warden knows who is pardoned but cannot reveal it directly. If A asks for the name of one of the two who will be executed, what is the probability of A being pardoned after the warden says "B"?

### **Solution:**
Initially, each prisoner has an equal chance of being pardoned:
$$
P(A) = P(B) = P(C) = \frac{1}{3}.
$$

If A is pardoned, the warden flips a coin to decide whether to say "B" or "C". Thus:
$$
P(\text{Warden says "B"} | A \text{ pardoned}) = \frac{1}{2}.
$$

If B is pardoned, the warden must say "C":
$$
P(\text{Warden says "B"} | B \text{ pardoned}) = 0.
$$

If C is pardoned, the warden must say "B":
$$
P(\text{Warden says "B"} | C \text{ pardoned}) = 1.
$$

Now, calculate $P(A | \text{Warden says "B"})$ using Bayes' theorem:
$$
P(A | \text{Warden says "B"}) = \frac{P(\text{Warden says "B"} | A)P(A)}{P(\text{Warden says "B"})}.
$$

Calculate $P(\text{Warden says "B"})$:
$$
P(\text{Warden says "B"}) = P(\text{Warden says "B"} | A)P(A) + P(\text{Warden says "B"} | B)P(B) + P(\text{Warden says "B"} | C)P(C).
$$
$$
P(\text{Warden says "B"}) = \left(\frac{1}{2}\right)\left(\frac{1}{3}\right) + (0)\left(\frac{1}{3}\right) + (1)\left(\frac{1}{3}\right) = \frac{1}{6} + \frac{1}{3} = \frac{1}{2}.
$$

Now calculate $P(A | \text{Warden says "B"})$:
$$
P(A | \text{Warden says "B"}) = \frac{\left(\frac{1}{2}\right)\left(\frac{1}{3}\right)}{\frac{1}{2}} = \frac{\frac{1}{6}}{\frac{1}{2}} = \frac{1}{3}.
$$

Similarly, calculate $P(C | \text{Warden says "B"})$:
$$
P(C | \text{Warden says "B"}) = \frac{\left(1\right)\left(\frac{1}{3}\right)}{\frac{1}{2}} = \frac{\frac{1}{3}}{\frac{1}{2}} = \frac{2}{3}.
$$

Thus:
$$
\boxed{P(A \text{ pardoned}) = \frac{1}{3}, \, P(C \text{ pardoned}) = \frac{2}{3}.}
$$

---

## **10. Transition Matrix for Weather**
**Problem:**  
If it’s sunny today, there is a 70% chance it will be sunny tomorrow and a 30% chance it will rain. If it’s rainy today, there is a 60% chance it will be sunny tomorrow and a 40% chance it will continue to rain. Represent the situation as a transition matrix. Also, if it is sunny today, calculate the probability that it will be sunny after two days.

### **Solution:**
The transition matrix is:
$$
P = \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix}.
$$

To find the probability of being sunny after two days, compute $P^2$:
$$
P^2 = P \cdot P = \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix} \cdot \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
(0.7)(0.7) + (0.3)(0.6) & (0.7)(0.3) + (0.3)(0.4) \\
(0.6)(0.7) + (0.4)(0.6) & (0.6)(0.3) + (0.4)(0.4)
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
0.49 + 0.18 & 0.21 + 0.12 \\
0.42 + 0.24 & 0.18 + 0.16
\end{bmatrix} = \begin{bmatrix}
0.67 & 0.33 \\
0.66 & 0.34
\end{bmatrix}.
$$

The probability of being sunny after two days, starting from sunny today, is:
$$
P(\text{Sunny after 2 days}) = 0.67.
$$

Thus:
$$
\boxed{P^2 = \begin{bmatrix}
0.67 & 0.33 \\
0.66 & 0.34
\end{bmatrix}, \, P(\text{Sunny after 2 days}) = 0.67.}
$$

---

## **11. Transition Matrix for Company State**
**Problem:**  
A company has two states: Good (G) and Bad (B). If the company is in a Good state today, there is an 80% chance it will remain in the Good state tomorrow and a 20% chance it will move to the Bad state. If the company is in a Bad state today, there is a 50% chance it will remain in the Bad state and a 50% chance it will move to the Good state. Derive the transition matrix and calculate the probability that if the company is in the Good state today, it will be in the Good state after two days.

### **Solution:**
The transition matrix is:
$$
P = \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix}.
$$

Compute $P^2$:
$$
P^2 = P \cdot P = \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix} \cdot \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
(0.8)(0.8) + (0.2)(0.5) & (0.8)(0.2) + (0.2)(0.5) \\
(0.5)(0.8) + (0.5)(0.5) & (0.5)(0.2) + (0.5)(0.5)
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
0.64 + 0.1 & 0.16 + 0.1 \\
0.4 + 0.25 & 0.1 + 0.25
\end{bmatrix} = \begin{bmatrix}
0.74 & 0.26 \\
0.65 & 0.35
\end{bmatrix}.
$$

The probability of being in the Good state after two days, starting from Good today, is:
$$
P(\text{Good after 2 days}) = 0.74.
$$

Thus:
$$
\boxed{P^2 = \begin{bmatrix}
0.74 & 0.26 \\
0.65 & 0.35
\end{bmatrix}, \, P(\text{Good after 2 days}) = 0.74.}
$$

---

Apologies for the oversight! Let me complete the solutions for **Questions 12 and 13** from the uploaded PDF. Here's the continuation:

---

## **12. Transition Matrix for Weather**
**Problem:**  
If it’s sunny today, there is a **70% chance** it will be sunny tomorrow and a **30% chance** it will rain. If it’s rainy today, there is a **60% chance** it will be sunny tomorrow and a **40% chance** it will continue to rain. Represent the situation as a transition matrix. Also, if it is sunny today, calculate the probability that it will be sunny after two days.

### **Solution:**

The states are:
- $ S $: Sunny
- $ R $: Rainy

The transition probabilities are:
- $ P(S \to S) = 0.7 $, $ P(S \to R) = 0.3 $
- $ P(R \to S) = 0.6 $, $ P(R \to R) = 0.4 $

The **transition matrix** is:
$$
P = \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix}.
$$

To find the probability of being sunny after two days, compute $ P^2 $ (the square of the transition matrix):
$$
P^2 = P \cdot P = \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix} \cdot \begin{bmatrix}
0.7 & 0.3 \\
0.6 & 0.4
\end{bmatrix}.
$$

Perform the matrix multiplication:
$$
P^2 = \begin{bmatrix}
(0.7)(0.7) + (0.3)(0.6) & (0.7)(0.3) + (0.3)(0.4) \\
(0.6)(0.7) + (0.4)(0.6) & (0.6)(0.3) + (0.4)(0.4)
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
0.49 + 0.18 & 0.21 + 0.12 \\
0.42 + 0.24 & 0.18 + 0.16
\end{bmatrix} = \begin{bmatrix}
0.67 & 0.33 \\
0.66 & 0.34
\end{bmatrix}.
$$

The probability of being sunny after two days, starting from sunny today, is given by the $(1,1)$ entry of $P^2$:
$$
P(\text{Sunny after 2 days}) = 0.67.
$$

Thus:
$$
\boxed{P^2 = \begin{bmatrix}
0.67 & 0.33 \\
0.66 & 0.34
\end{bmatrix}, \, P(\text{Sunny after 2 days}) = 0.67.}
$$

---

## **13. Transition Matrix for Company State**
**Problem:**  
A company has two states:
- **Good (G)**: The company is profitable.
- **Bad (B)**: The company is making a loss.

If the company is in a **Good state today**, there is an **80% chance** it will remain in the Good state tomorrow and a **20% chance** it will move to the Bad state. If the company is in a **Bad state today**, there is a **50% chance** it will remain in the Bad state and a **50% chance** it will move to the Good state. Derive the transition matrix for this system. Also, calculate the probability that if the company is in the Good state today, it will be in the Good state after two days.

### **Solution:**

The states are:
- $ G $: Good
- $ B $: Bad

The transition probabilities are:
- $ P(G \to G) = 0.8 $, $ P(G \to B) = 0.2 $
- $ P(B \to G) = 0.5 $, $ P(B \to B) = 0.5 $

The **transition matrix** is:
$$
P = \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix}.
$$

To find the probability of being in the Good state after two days, compute $ P^2 $:
$$
P^2 = P \cdot P = \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix} \cdot \begin{bmatrix}
0.8 & 0.2 \\
0.5 & 0.5
\end{bmatrix}.
$$

Perform the matrix multiplication:
$$
P^2 = \begin{bmatrix}
(0.8)(0.8) + (0.2)(0.5) & (0.8)(0.2) + (0.2)(0.5) \\
(0.5)(0.8) + (0.5)(0.5) & (0.5)(0.2) + (0.5)(0.5)
\end{bmatrix}.
$$
$$
P^2 = \begin{bmatrix}
0.64 + 0.1 & 0.16 + 0.1 \\
0.4 + 0.25 & 0.1 + 0.25
\end{bmatrix} = \begin{bmatrix}
0.74 & 0.26 \\
0.65 & 0.35
\end{bmatrix}.
$$

The probability of being in the Good state after two days, starting from Good today, is given by the $(1,1)$ entry of $P^2$:
$$
P(\text{Good after 2 days}) = 0.74.
$$

Thus:
$$
\boxed{P^2 = \begin{bmatrix}
0.74 & 0.26 \\
0.65 & 0.35
\end{bmatrix}, \, P(\text{Good after 2 days}) = 0.74.}
$$

---

This completes all the questions from the uploaded PDF. Let me know if you need further clarifications!
