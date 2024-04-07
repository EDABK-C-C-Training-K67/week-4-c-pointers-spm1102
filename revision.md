# C Programming Revision Tasks

## Task Overview
You are required to write two C programs that demonstrate basic pointer usage. Your code should be written in `.c` files and placed in the `src` directory.

### Task 1: String Length Calculator
**File**: `src/task1_0.c`

**Objective**: Write a program that takes a string of characters as input and prints the length of the string. ***Do not use library to calculate the length***.

**Input**: A string of characters

**Output**: The length of the string

**Example**:  
Input
```c
Hello World!
```
Output  
```c
12
```

### Task 2: Binary Representation Display
**Objective**: Create two functions within this program:
1. One that displays the binary form of an integer.
2. Another that displays the binary form of a real number.

#### 2a. Binary Form of an Integer
**File**: `src/task2_1.c`

**Input**: An 32-bit integer

**Output**: The binary representation of the integer (full 32 bit)

**Example**:
Input
```c
12
```
Output
```c
00000000000000000000000000001100
```

#### 2b. Binary Form of a Real Number
**File**: `src/task2_2.c`

**Input**: A real number type `float`

**Output**: The binary representation of the real number (type `float`) in IEEE 754 format (Note: You will need to use bitwise operators and pointers to achieve this.)

**Example**:
Input
```c
3.5
```
Output
```c
01000000011000000000000000000000
```
(Note: The actual binary representation will depend on the system's implementation of floating-point numbers.)

**Instructions**:
- Use bitwise operators to manipulate bits and pointers to access the binary representation.
- Ensure your code is well-commented to explain your logic.
- Test your program with various inputs to ensure accuracy.

### Task 3: Dynamic Allocation for String Arrays
**File**: `src/task3_0.c`

**Objective**: Write a C program that dynamically allocates a two-dimensional array to receive strings separated by newline characters and prints those strings.

**Instructions**:
- Allocate memory dynamically for an array of strings.
- Read strings from the user input, separated by newline characters. Each line has maximum of 30 characters.
- Print each string on a separate line.
- Ensure you free the allocated memory at the end of the program.
- Do not create separate functions; write all code in the `main` function.

**Example**:
Input
```c
Hello
World
Goodbye
```
Output
```c
Hello
World
Goodbye
```

### Task 4: Pointer Arrays of Strings Allocated by Function
**File**: `src/task4_0.c`

**Objective**: Similar to Task 3, but create a function to allocate memory for the strings with three parameters: `void allocate(char ***array, int num_lines, int line_length)`.

**Instructions**:
- Define the `allocate` function to dynamically allocate memory for a two-dimensional array of strings.
- Use the `allocate` function in the `main` function to allocate memory for the array of strings.
- Read strings from the user input, separated by newline characters. Each line has maximum of 30 characters.
- Print each string on a separate line using the allocated memory.
- Ensure you free the allocated memory at the end of the program.

**Example**:
Input
```c
Hello
World
Goodbye
```
Output
```c
Hello
World
Goodbye
```

Please implement these tasks in your C programs, following the provided examples and instructions. Make sure to handle memory allocation and deallocation properly to avoid memory leaks.

**Submission**:
After completing the tasks, push your `.c` files to the `src` directory in your repository. Make sure to test your code thoroughly before submission.

Good luck, and happy coding!