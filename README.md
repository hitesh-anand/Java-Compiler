# Java-x86 Compiler
This repository contains our implementation of JAVA prototype compiler. 
This was implemented as project in the course CS335A : Compiler Design in the academic session 2022-23-II at IIT Kanpur.

## Features Supported

The following features are supported by our implementation of the compiler:

* Primitive Data types such as int, byte, long, short
* Multidimensional Arrays (upto 3 dimensions)
* Basic operators such as
*   Arithmetic Operators : `+,-,*,/,%`
*   Pre-Post Increment/Decrement
*   Relational Operators : `>,<,>=,<=,==,!=`
*   Bitwise Operators : `&, |, ^, ~, <<, >>, >>>`
*   Logical Operators : `&&, ||, !`
*   Assignment Operators (including shorthand notation)
*   Ternary Operator
* Control-flow via if-else statements, for loops, while loops
* Method Declarations and Invocations
* Recursion
* Printing functions such as `System.out.println() for integers`
* Classes and Objects

## Test Cases

We have include multiple test cases in the `tests/` folder 
to test different features. These test cases include:
* test1.java : simple test case for function calls and object creation
* test2.java : while loops, and if-else
* test3.java : use of `this` pointer
* test4.java : complex arithmetic operations
* test5.java : test for arrays
* test6.java : test for short-circuiting
* test7.java : if-else and while example
* test8.java : test for recursion
* test9.java : object creation from a separate call
* test10.java : test for printing numbers using `System.out.println()`

## Compilation

```console
cd milestone4/src
make
```


## Execution

### Generating the Intermediates

There are four possible options flags:
* `--input` : To specify the path of the input file (Required)
* `--output` : To specify the path of the output text file containing the 3AC (Required)
* `--verbose` : If used, the user can see the exact rules that are being used during the parsing (Optional)
* '--help' : can be used to see the available flags and their usage

For example:
`./parser --input=../tests/test_1.java --output=3ac.txt --verbose`

The resulting output will be the IR (in a 3AC format) stored in the
3ac.txt file in the folder named `temporary`

### Final Assembly code generation

`g++ asmgen.cpp`
./a.out --input=<input_file> --output=<output_file>`
`gcc <output_file> -o <executable_file>`
`./executable_file`

Here, the input should be the 3AC file generated above, and the
output should be the name of the x86 assembly file to 
be generated (in .s format)

For example:
`g++ asmgen.cpp`
`./a.out --input=3ac.txt --output=test.s`
'gcc test.s -o test`
`./test`

Here, `test.s` contains the assembly code for the IR
contained in the `3ac.txt` file. We compile the `test.s` file
to create the executable `test` and then simply run the
executable and observe the output

## Assembly Conventiona and Assumptions

* All the arrays and objects are allocated on heap as done by the real JAVA compiler
* 6 registers are used to transfer arguments to a function, and if there are more arguments, we push them onto the stack.
* First register is reserved for the `this` pointer
* We have assumed that the maximum dimension for the arrays is 3 and the word size is 8 to maintain the alignment property

