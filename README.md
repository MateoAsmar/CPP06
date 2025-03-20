# CPP06
(C++ casts)
## Grade: 100/100
![cpp06](https://github.com/user-attachments/assets/1db12049-86dd-4861-afb5-5624fd7729fb)

## Overview

This project implements a series of advanced C++ utilities that showcase advanced type conversion, pointer serialization, and runtime type identification without using RTTI. It is divided into three main parts:

1. **ScalarConverter**:  
   A class with a single static method `convert` that takes a string representing a literal (in its most common form) and outputs its value as a `char`, `int`, `float`, and `double`. The class is designed to be non-instantiable.

2. **Serializer**:  
   A utility class that serializes a pointer to an unsigned integer type (`uintptr_t`) and deserializes it back to a pointer. This part demonstrates how to safely convert between pointers and integral types.

3. **Identify Real Type**:  
   A set of classes and functions that allow identification of the actual type of an object at runtime without using `std::typeinfo`.  
   - A base class `Base` (with a virtual destructor) is inherited by three empty classes: `A`, `B`, and `C`.  
   - Functions `generate()`, `identify(Base* p)`, and `identify(Base& p)` determine and print the real type of a given object.

## Features

### ScalarConverter
- **Static Method**:  
  `ScalarConverter::convert(std::string literal)`  
  Converts the given string literal into its corresponding scalar types:
  - **char**: Displays the character if displayable; otherwise, an informative message.
  - **int**: Converts the string to an integer.
  - **float**: Converts to a float (handles literals like `42.0f`, `+inff`, `nanf`, etc.).
  - **double**: Converts to a double (handles literals like `42.0`, `+inf`, `nan`, etc.).
- **Non-instantiable**:  
  The class is not meant to be instantiated; it only provides a static interface.

### Serializer
- **Static Methods**:
  - `uintptr_t Serializer::serialize(Data* ptr)`:  
    Converts a pointer to a `uintptr_t`.
  - `Data* Serializer::deserialize(uintptr_t raw)`:  
    Converts a `uintptr_t` back to a pointer.
- **Data Structure**:  
  A simple `Data` structure (with at least one data member) is used to demonstrate the serialization/deserialization process.

### Identify Real Type
- **Class Hierarchy**:
  - **Base**: A base class with a public virtual destructor.
  - **A, B, C**: Empty classes that inherit publicly from `Base`.
- **Functions**:
  - `Base* generate(void)`:  
    Randomly instantiates one of `A`, `B`, or `C` and returns it as a `Base*`.
  - `void identify(Base* p)`:  
    Identifies and prints the real type of the object pointed to by `p`.
  - `void identify(Base& p)`:  
    Identifies and prints the real type of the object referenced by `p` (without using a pointer inside the function).
- **Restriction**:  
  The solution avoids the use of `std::typeinfo` and demonstrates manual runtime type identification.

## File Structure

- **Makefile**  
  Automates the build process.

- **ScalarConverter.hpp / ScalarConverter.cpp**  
  Implements the `ScalarConverter` class.

- **Serializer.hpp / Serializer.cpp**  
  Implements the `Serializer` class along with the `Data` structure.

- **Base.hpp, A.hpp, B.hpp, C.hpp (and corresponding .cpp files)**  
  Define the base class and its derived classes, as well as the functions for type identification (`generate`, `identify`).

- **main.cpp**  
  Contains comprehensive tests that demonstrate:
  - Converting string literals using `ScalarConverter::convert`
  - Serializing and deserializing pointers with `Serializer`
  - Generating random objects of type `A`, `B`, or `C` and identifying their actual types.

## Compilation

To compile the project, run:
```bash
cd ex00
make
./executable_filename
```

## What I Learned

**Scalar Conversion & Pseudo-literals:** How to interpret various literal formats and convert them between scalar types while handling edge cases (non-displayable characters, special floating-point values).

**Serialization:** Understanding pointer representation and how to safely convert between pointers and integral types using uintptr_t.

**Manual Type Identification:** Techniques for determining an object’s dynamic type without relying on RTTI, reinforcing the importance of polymorphism and virtual functions.

**Designing Utility Classes:** Creating non-instantiable classes that expose only static methods to perform useful tasks.

**Robust Testing:** Implementing extensive tests to ensure that all conversion and identification cases are handled correctly.

## Conclusion
CPP06 pushed my understanding of advanced C++ features such as static member functions, pointer manipulation, and polymorphism. By implementing scalar conversion, serialization, and manual runtime type identification, I deepened my expertise in type systems and low-level programming in C++. This project not only reinforces best practices in C++ but also prepares me for more complex systems programming challenges.




















