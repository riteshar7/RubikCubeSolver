# RubikCubeSolver

This project is a C++ implementation of a **Rubik's Cube (3x3)** solver that supports multiple ways of representing the cube's state and offers three different algorithms to solve it. The project aims to efficiently model and solve the Rubik's Cube using standard data structures and search algorithms.

## Features

- Three different ways to represent the Rubik's Cube:
  - **3D Array Representation**
  - **1D Array Representation**
  - **Bitboard Representation**
  
- Solving the cube using three graph traversal algorithms:
  - **DFS (Depth-First Search)**
  - **BFS (Breadth-First Search)**
  - **IDDFS (Iterative Deepening Depth-First Search)**
    

## Cube Representations

### 1. 3D Array Representation

The cube is represented as a **3D array** consisting of six **3x3 matrices**, each representing one face of the cube. Every element of the matrix stores the color of that facelet, allowing for an intuitive way to model the cube's physical structure.

- **Index Calculation Formula**:
    ```
    cube[face][row][col]
    ```
    where `face` ranges from 0 to 5, `row` and `col` range from 0 to 2.

### 2. 1D Array Representation

In this form, the cube's state is stored in a **1D array of size 54**. The colors and faces can be accessed using the following formula:
    
- **Index Calculation Formula**:
    ```
    index = 6 * face + 3 * row + column
    ```
  - `face`: ranges from 0 to 5
  - `row`: ranges from 0 to 2
  - `column`: ranges from 0 to 2

This allows for efficient indexing and storage of the cube's state in a linear form.

### 3. Bitboard Representation

The most compact representation is the **bitboard**. Here, each face of the cube is represented using **8 bits**, with one bit representing each facelet color. Since only **8 out of 9** facelets need to be stored for any face (as one is implied by the rest), this allows for a **64-bit** representation of each cube face, stored in a clockwise fashion.

- **Bit Storage**:
  - 8 bits per face, each face storing facelet colors in a clockwise direction.
  - This results in 64 bits per face for all 6 faces.
    

## Solving Algorithms

The Rubik's Cube is modeled as a **graph** where:
- **Each node** represents a specific cube state.
- **Each edge** represents a valid move that connects one cube state to another.

### 1. Depth-First Search (DFS)

DFS explores the cube's possible states by going as deep as possible along each branch before backtracking (maximum limit of 25 as any cube can be solved in less than or equal to 20). It is not guaranteed to find the shortest solution but may be faster in some cases due to its depth-driven approach.

### 2. Breadth-First Search (BFS)

BFS explores all possible moves at the current level before moving deeper into the cube's state tree. This ensures that the shortest solution is found (in terms of moves) but may take longer in terms of memory and time complexity compared to DFS. This method is good for the cube state cases which is near to the solved cube state.

### 3. Iterative Deepening Depth-First Search (IDDFS)

IDDFS combines the benefits of both DFS and BFS. It performs DFS but with a **depth limit**. If no solution is found within that depth, the limit is increased, and the search is restarted. This allows IDDFS to find the shortest solution without the memory overhead of BFS.

### Options:
- You can choose to use either 3D array, 1D array, or Bitboard representation by specifying the desired representation of the object (Rubik's Cube). The code will generate the cube in readable format for any representation selected.
- You can choose to use either DFS, BFS, or IDDFS by specifying the desired algorithm in the code (depending on your implementation).



## Future Work

- Implement **Korf's IDA*** algorithm to further optimize the solution search.
- Allow users to give input of an unsolved cube which can be solved by algorithm.
- Add a UI/CLI interface for user-friendly interaction with the solver.


## References

- [Korf’s Research Paper](https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf)

