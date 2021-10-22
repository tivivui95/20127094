# Basic Info
Full Name: **Nguyen Minh Van**

Student ID: **20127094**
# Description
`main` function in `DynamicArray.cpp`.

The `DynamicArray` class also in `DynamicArray.cpp` due to template using.
# Finished functions included
1. Create a template for a dynamic array. 

2. Generate a dynamic array of Fractions and print out the final sum of all fractions.

3. Generate a dynamic array of Fullname and print out all the full names.
# How to use
## Declaration
Like vector, the `DynamicArray` has the same declare function.
``` C++
DynamicArray<int> IntArr; // Declare an integer array
DynamicArray<int> IntArr2(3, 1,2,3); // Declare an integer array with 3 input are 1, 2 and 3
DynamicArray<string> StrArr; // Declare a string array
```
## Add Item
Use `push_back` to add more variable to existed array.
``` C++
IntArr.push_back(12); // Add 12 to the array
StrArr.push_back("more"); // Add another string to the string array
```
## Size of array
To get the **current size** of the array, call the `size()` function.
``` C++
IntArr.size(); 
StrArr.size();
// return the size of array in integer number
```
## Compatible with class
You can create an array with your own type declared by class. Example of a fraction:
```C++
class Fraction {..}
// A Fraction class has been created

// in main function
    DynamicArray<Fraction> FracArray; // create an fraction array
```
