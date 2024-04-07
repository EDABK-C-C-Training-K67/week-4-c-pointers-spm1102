# Weekly Task 4 Description - C Pointers

## Table of Contents
1. [Theory](#a-theory)
   - [Concepts](#i-concepts)
   - [Declaration](#ii-declaration)
   - [Data Types](#iii-data-types)
   - [Initialization](#iv-initialization)
   - [Pointer-related Calls](#v-pointer-related-calls)
2. [Pointer Operations](#b-pointer-operations)
   - [Essential Knowledge](#i-essential-knowledge)
   - [Pointer Arithmetic](#ii-pointer-arithmetic)
   - [Pointers with Arrays, Strings, and Dynamic Allocation](#iii-pointers-with-arrays-strings-and-dynamic-allocation)
   - [Pointers with Functions, Function Pointers](#iv-pointers-with-functions-function-pointers)
   - [Multi-level Pointers](#v-multi-level-pointers)
   - [Appendix](#vi-appendix)
   - [Notes](#vii-notes-read-only-no-need-to-delve-into)

## A. Theory
### I. Concepts
### II. Declaration
### III. Data Types
### IV. Initialization
### V. Pointer-related Calls
   1. Value of the pointer
   2. Address of the pointer
   3. Value of the variable the pointer is pointing to
   4. Address of the variable the pointer is pointing to

## B. Pointer Operations
### I. Essential Knowledge
   - Variable `a` has an address `&a`
   - The value of the variable that pointer `p` points to can be accessed by `*p`
     - The `*` operator is called the dereference operator
   - `*&p` is the same as `*(&p)` which is the same as `p`; `*&*p` is the same as `*p`
   - Always initialize pointers to `NULL` if not yet assigned
   - Always check if a pointer is `NULL` before using it

### II. Pointer Arithmetic
   1. Assignment
      - Assigning an address to a pointer
      - Assigning a value at the address the pointer points to
   2. Comparison
      - Meaning of comparison operations
      - Notes:
        - Comparison with 0?
        - When comparing two pointers or a pointer with a specific address?
        - Comparison with a void pointer?
   3. Addition, Subtraction, Increment, and Decrement: `+`, `+=`, `-`, `-=`, `++`, `--`
      - What is the essence of incrementing/decrementing pointer `p` by one unit?
      - Notes:
        - Is there addition, subtraction, increment, and decrement for:
          - void pointers?
          - function pointers?
          - two pointers with each other?
        - What does subtracting two pointers signify?
      - How does the data type of the pointer affect addition, subtraction, increment, and decrement operations?
   4. Write a C program applying basic pointer usage
      1) Enter a string of characters, print the length of the string
      2) a. Display the binary form of an integer: Traverse each bit of the integer and print the binary form on the screen (Hint: use bitwise operators)  
         b. Display the binary form of a real number: Print the binary form on the screen (Hint: combine bitwise operators and pointers)

### III. Pointers with Arrays, Strings, and Dynamic Allocation
   1. Const Pointer & Pointer to Const - Constant Pointer & Pointer to a Constant
      a. Constants
      b. Const Pointer - Constant Pointer
      c. Pointer to Const - Pointer to a Constant
      d. Combining const pointer with pointer to const - Constant pointer pointing to a constant
      e. Why use const pointer and pointer to const?
   2. Arrays and Pointers
      a. The relationship between arrays and pointers
         - What does declaring an array imply?
         - `int a[100];`
           - Knowing `a[0]`, `a[1]`,… are the values at index 0, 1,… of the array
             - Knowing `a` is a pointer
             - What kind of pointer is `a`?
           - Can operations be used to make `a` point to a different area (`++`, `--`, `=`)?
           - What do the following statements mean?
             - `a`
             - `a+i`
             - `*a`
             - `*(a+i)`
             - `a[-2]`
             - `-2[a]`
         - Compare `arr` and `&arr[0]`. Apply this in calculating the number of elements in an array
         - When passing an array into a function, the array is passed by reference (passing the value `arr`)
         - How to pass an array into a function?
      b. Two-dimensional arrays, their nature, and how they differ from one-dimensional arrays
   3. String Literals  
      a. What is a string literal  
      b. Common mistakes: Explain the following mistakes  
        - Mistake 1
            ```c
            char *xau;
            gets(xau);
            ```
        - Mistake 2
            ```c
            char *xau = "Hello World!";
            xau[6] = 'A';
            ```
         - Mistake 3
            ```c
            char xau[100];
            xau = "Hello World!";
            ```
         - Mistake 4
            ```c
            int main() {
                char xau[100] = "quangxeng";
                if (xau == "quangxeng") ...
            }
            ```
   4. Dynamic Allocation  
      a. Why is dynamic allocation necessary? Compare dynamic allocation with static allocation. Advantages and disadvantages of these two types of allocation  
      b. Dynamic allocation and notes on memory release  
      c. Memory handling functions in C: `malloc()`, `calloc()`, `realloc()`, `free()`  
        - Purpose of each function  
        - Explain how these functions work, what happens to the program when using these functions, and the return value of the function  
        - Knowing that these functions can be very dangerous if used carelessly, how are they dangerous and what are the precautions for effective use  
        - Write example code using each function

      d. Dynamic allocation of one-dimensional arrays  
      e. Dynamic allocation of two-dimensional arrays: explain the allocation and release methods, write illustrative code  
        - Method 1: Using a second-level pointer  
        - Method 2: Using a one-dimensional array to represent a two-dimensional array

### IV. Pointers with Functions, Function Pointers
   1. Do functions have addresses?
   2. Function pointers. Write example code using function pointers.
   3. Constant function pointers.
   4. Applications of function pointers.
   5. Using pointers as function parameters
      a. Changing variable values through functions? Write code to create a function that swaps two integers.
   6. Advanced topics on function pointers, array of function pointers, and problem-solving skills
      - Explain the meaning of the declaration `int(*)[10]`.
      - Distinguish between `(*ptr)[10]` and `*ptr[10]` in C.

### V. Multi-level Pointers
   1. What are multi-level pointers?
   2. Their purpose.
   3. Examples of common cases  
      - Handling pointer arrays of strings: Write a C program that dynamically allocates a two-dimensional array to receive strings separated by newline characters. Print those strings. (Code in main, do not create functions)  
      - Handling pointer arrays of strings allocated by function: Similar to the above task but create a function to allocate with three parameters `void allocate(array of lines, number of lines, line length)`. Input strings separated by newline characters, output print the strings to the screen.

### VI. Appendix
   1. What are `'\0'` and `NULL`? Are they different?

### VII. Notes (Read only, no need to delve into)
   - When calling `*p`, use `(*p)` to write clean code and avoid mistakes.  
     e.g.,  
      `a = b + (*p) * c;`   //clean code  
      `(*p)++;` instead of `*p++;`    //the `*` operator has lower precedence than `++`, so `*p++` means `*(p++)`  
   - Microsoft's coding style related to pointers:
     - In pointer declaration statements, write `*` close to the pointer name.
     - Write the data type, and place `*` close to the basic data type: specifically in the return type of functions, in titles, and in function prototypes.
     - In typecasting statements, manually adjust as desired, possibly spacing out for clearer code.
     - Look at the function `char* gets(char* str);` in the library to understand more about the writing style.