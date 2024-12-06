# C++ Implementation of Graph Algorithms

---

## 1. Task Description

You are required to solve the following puzzle using **C++**.

### **Puzzle Description**

The problem involves redesigning the road system of an imaginary country to:

1. Ensure exactly **one path** exists between every pair of cities.
2. Minimize the **total cost** of reconstruction, which includes:
   - **Building new roads.**
   - **Destroying existing roads.**

The graph is **undirected**, and the task involves:

1. **Input:**  
   Three 2D arrays:
   - `country[i][j]`:  
     - `1`: There is a road between city `i` and `j`.  
     - `0`: No road exists.
   - `build[i][j]`: Cost to build a road between `i` and `j`, encoded as:
     - `A-Z`: Costs 0-25.
     - `a-z`: Costs 26-51.
   - `destroy[i][j]`: Cost to destroy a road between `i` and `j`, encoded similarly.

2. **Output:**  
   The **minimal cost** to reconstruct the road system.

---

## 2. Input and Output Specifications

### **Input Format**

1. The input consists of three strings separated by spaces:
   - First string: Represents the `country` array.
   - Second string: Represents the `build` array.
   - Third string: Represents the `destroy` array.
2. Each string contains `N` parts separated by commas.
   - Each part contains `N` characters.

### **Output Format**

1. A single integer representing the **minimal cost** of reconstruction.

---

### **Examples**

#### **Sample Input 1**:
```text
000,000,000 ABD,BAC,DCA ABD,BAC,DCA
```

**Sample Output 1**:
```text
3
```

**Explanation**:  
- Three disconnected cities.  
- Build roads to connect them (total cost = 3).

---

#### **Sample Input 2**:
```text
011,101,110 ABD,BAC,DCA ABD,BAC,DCA
```

**Sample Output 2**:
```text
1
```

**Explanation**:  
- Three cities form a triangle.  
- Destroy one road (optimal: 0-1 with cost = 1).

---

#### **Sample Input 3**:
```text
011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA
```

**Sample Output 3**:
```text
7
```

**Explanation**:  
- Six cities forming two triangles.  
- Destroy one road in each triangle (cost = 1 each).  
- Build one road to connect the triangles (cost = 5).  
- Total cost = 7.

---

#### **Sample Input 4**:
```text
0 A A
```

**Sample Output 4**:
```text
0
```

**Explanation**:  
- Single city, no reconstruction needed.

---

#### **Sample Input 5**:
```text
0001,0001,0001,1110 AfOj,fAcC,OcAP,jCPA AWFH,WAxU,FxAV,HUVA
```

**Sample Output 5**:
```text
0
```

**Explanation**:  
- Four cities already satisfy the conditions.  
- No reconstruction needed.

---

## 3. Implementation Details

### **Steps**

1. Parse input strings into 2D arrays for `country`, `build`, and `destroy`.
2. Represent the graph using adjacency lists/matrices.
3. Solve the problem using **graph algorithms**:
   - Use **Kruskal's MST algorithm** to minimize the cost of building and destroying roads.
   - Treat "destroying a road" as a negative weight edge to ensure efficient removal.
4. Compute the total minimal cost of reconstruction.

---

## 4. Marking Scheme

- **Total Marks**: 10
  - 1 mark for successful compilation.
  - 9 marks for passing 9 test cases.

---

## 5. Submission Guidelines

1. Submit **exactly one file** named `main.cpp`.
2. Follow the input/output format precisely.
3. Ensure your code compiles on the university system:
   ```bash
   g++ -o main.out -std=c++11 -O2 -Wall main.cpp
   ```
4. Submit via [Websubmission](https://cs.adelaide.edu.au/services/websubmission/):
   - Select the correct semester, course, and assignment.
   - You can resubmit as many times as needed before the deadline.

---

### **Notes**

- Debug your code on lab computers or via SSH to the university system.
- Ensure compatibility with `g++` used on the university system.

```