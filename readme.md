# C++ Examples Repository

This repository contains **hundreds of C++ examples** covering a wide range of topics. It is designed as a learning resource and reference for developers who want to explore modern C++ features and practical programming techniques.

---

## Topics Covered

The examples are organized into categories such as:

- **Error Handling**  
  Exception safety, `try`/`catch`, custom error classes, and RAII patterns.

- **Algorithms**  
  Standard Template Library (STL) algorithms, sorting, searching, and custom algorithm implementations.

- **File Streaming**  
  Reading and writing files with `fstream`, binary I/O, and serialization.

- **Move Semantics**  
  Rvalue references, `std::move`, and efficient resource management.

- **Multithreading**  
  Thread creation, synchronization primitives (`mutex`, `condition_variable`), thread pools, and parallel algorithms.

---

## Requirements

- Most examples are written for **C++17**.  
- A modern compiler such as:
  - GCC (MinGW-w64 on Windows)
  - Clang
  - MSVC (Visual Studio)

---

## Installing MinGW-w64 via MSYS2 on Windows

To compile and run the examples on Windows, we recommend installing **MinGW-w64** using **MSYS2**.

### Step 1: Download and Install MSYS2
- Go to [MSYS2 official website](https://www.msys2.org/).
- Download the installer and run it.
- Follow the installation instructions and update the system packages:
  ```bash
  pacman -Syu
  ```

### Step 2: Install MinGW-w64 Toolchain
Open the MSYS2 MinGW 64-bit terminal and run:
  ```bash
  pacman -S mingw-w64-x86_64-gcc
  ```

### Step 3: Verify Installation
Check the compiler version:
  ```bash
  gcc --version
  ```

### Step 4: Add to PATH (Optional)
To use gcc from any terminal (like PowerShell or CMD), add the following path to your Windows environment variables:
  ```bash
  C:\msys64\mingw64\bin
  ```
## How to Compile and Run Example
From the terminal:
  ```bash
  g++ -std=c++17 example.cpp -o example.exe
  ./example.exe
  ```
