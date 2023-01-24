# flex-C-declarations

Simple Flex program producing the corresponding C code to display all the declarions of another C code file.
<br>
These include:
- System libraries
- User libraries
- Forward declarations
- Function definitions

Compilation and tests execution is streamline via a Makefile.
<br>
Two test C code files have been provided to play with.

# Usage
```
% make
```
Makefile can be configured to use a different test case set and/or files.

# Execution example
```
❯ make
flex -o flex_c_declarations.c flex_c_declarations.l
gcc flex_c_declarations.c -o flex_c_declarations -lfl
./flex_c_declarations test_file_0.c
System Library: #include <stdio.h>
User Library: #include "genlib.h"
User Library: #include "simpio.h"
Macro definition: #define N 10
Forward Function Declaration: bool IsLeapYear(int year);
Forward Function Declaration: int MonthDays(int month, int year);
Forward Function Declaration: bool valide_date(int dd, int mm, int yy);
Forward Function Declaration: long Read_and_Calculate(int curyear);
Function Definition: bool IsLeapYear(int year)
Function Definition: int MonthDays(int month, int year)
Function Definition: bool valide_date(int dd, int mm, int yy)
Function Definition: long Read_and_Calculate(int curyear)
3 Libraries are included in file.
There are 4 fw function declarations and 4 fun defs.
./flex_c_declarations test_file_1.c
System Library: #include <stdio.h>
System Library: #include <string.h>
System Library: #include <conio.h>
Forward Function Declaration: void read_data(char user_string[], int *L, int *X, int *Y);
Forward Function Declaration: void leftjust(char str[], int L, int X, int Y);
Forward Function Declaration: void rightjust(char str[], int L, int X, int Y);
Forward Function Declaration: void centerjust(char str[], int L, int X, int Y);
Function Definition: void read_data(char str[], int *L, int *X, int *Y)
Function Definition: void leftjust(char str[], int L, int X, int Y)
Function Definition: void rightjust(char str[], int L, int X, int Y)
Function Definition: void centerjust(char str[], int L, int X, int Y)
3 Libraries are included in file.
There are 4 fw function declarations and 4 fun defs.
```
