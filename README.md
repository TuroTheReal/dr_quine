# DR_QUINE

## Table of Contents

* [About](#about)
* [Installation](#installation)
* [Usage](#usage)
* [Key Concepts Learned](#key-concepts-learned)
* [Skills Developed](#skills-developed)
* [Project Overview](#project-overview)
* [Programs Implemented](#programs-implemented)
* [Theoretical Foundation](#theoretical-foundation)
* [Testing](#testing)
* [42 School Standards](#42-school-standards)

## About

This repository contains my implementation of the **Dr. Quine** project.  
Dr. Quine explores the fascinating world of **self-reproducing programs** (quines) and illustrates **Kleene's recursion theorem**, a fundamental concept in computability theory and computer science philosophy.  
Implemented in **C**, **Python**, and **ASM (x86_64)**, this project demonstrates that programs can access and output their own source code without external file reading, using clever string manipulation, format specifiers, and self-referential techniques.

The project proves the theoretical possibility of self-replication in computation and provides practical implementations of various quine variants across multiple programming languages.

## Installation

### Prerequisites

* **C Compiler** (gcc/clang)
* **Python 3** interpreter
* **NASM** assembler (for ASM quines)
* **Make** utility
* **UNIX/Linux environment**

### Compilation

```bash
# Clone the repository
git clone https://github.com/TuroTheReal/dr_quine.git
cd dr_quine

# Compile all quines
make

# Compile specific language
make c        # C quines only
make python   # Python quines only
make asm      # ASM quines only

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## Usage

### Basic Quines (Colleen, Grace, Sully)

```bash
# C Quines
./Colleen > tmp_Colleen
diff Colleen.c tmp_Colleen

./Grace
./Sully

# Python Quines
python3 Colleen.py > tmp_Colleen.py
diff Colleen.py tmp_Colleen.py

python3 Grace.py
python3 Sully.py

# ASM Quines
./Colleen_asm > tmp_Colleen.s
diff Colleen.s tmp_Colleen.s

./Grace_asm
./Sully_asm
```

### Self-Replicating Programs

**Colleen**: Simple quine that outputs its own source code to stdout

```bash
./Colleen > output.c
diff Colleen.c output.c  # Should be identical
```

**Grace**: Quine that writes its source code to a file named `Grace_kid.c`

```bash
./Grace
diff Grace.c Grace_kid.c  # Should be identical
```

**Sully**: Recursive quine that creates decreasing generations until reaching 0

```bash
./Sully
# Creates: Sully_5.c, Sully_5, Sully_4.c, Sully_4, ..., Sully_0.c
```

## Key Concepts Learned

### Theoretical Computer Science

* **Kleene's Recursion Theorem**: Understanding self-referential computation and fixed-point theorem
* **Quine Philosophy**: Programs that produce their own source code without reading external files
* **Self-Reference in Computation**: How programs can "know" their own structure
* **Computability Theory**: Exploring limits and possibilities of computation

### String Manipulation Mastery

* **Format String Techniques**: Using printf format specifiers for self-replication
* **Escape Sequence Handling**: Managing quotes, newlines, backslashes in nested strings
* **Character Encoding**: Representing source code as data within the program
* **String Duplication**: Creating identical copies of complex string structures

### Multi-Language Programming

* **C String Literals**: Working with char arrays and printf formatting
* **Python String Formatting**: Using f-strings, .format(), and % operators
* **ASM Data Sections**: Storing strings in .data segment and outputting with syscalls
* **Cross-Language Patterns**: Identifying common quine patterns across languages

### Program Self-Awareness

* **Source as Data**: Treating program source code as manipulable data
* **Metacircular Evaluation**: Programs that reason about their own structure
* **Bootstrap Problem**: Solving chicken-and-egg initialization challenges
* **Reflection Techniques**: Programs examining their own code structure

## Skills Developed

* **Advanced String Manipulation**: Expert-level string formatting and escaping
* **Theoretical Understanding**: Deep grasp of computability and recursion theory
* **Multi-Language Proficiency**: Implementing identical logic across C, Python, ASM
* **Format Specifier Mastery**: Creative use of printf, sprintf, and format strings
* **Code Golf Techniques**: Writing minimal, elegant self-reproducing code
* **Pattern Recognition**: Identifying quine structure across different paradigms
* **Recursive Thinking**: Understanding self-referential and recursive program design

## Project Overview

Dr. Quine explores three fundamental quine patterns: simple self-replication (Colleen), file-writing quines (Grace), and recursive generation (Sully).
Each program must reproduce its complete source code without reading any external files, using only string manipulation and format specifiers to achieve self-reference.

### Core Quine Technique

All quines follow a fundamental pattern: define a string `s` containing the program's source code with a placeholder, then print the string twice—first as data (quoted), then as code (unquoted), filling the placeholder with `s` itself.

**Generic Quine Pattern**:
```c
char *s = "program source with %s placeholder";
printf(s, s);  // First outputs s as data, then executes with s
```

This creates a fixed point where the program's output exactly matches its source code.

## Programs Implemented

### Colleen (Simple Quine)

**Purpose**: Outputs its own source code to stdout  
**Technique**: Single printf with format string containing entire program  
**Key Challenge**: Properly escaping quotes, newlines, and backslashes

**Example Structure**:
```c
// This is a comment (required by subject)
#include <stdio.h>
int main() {
    char *s = "complex format string with %s";
    printf(s, s);
}
```

**Verification**:
```bash
./Colleen > tmp.c
diff Colleen.c tmp.c  # Exit code 0 = identical
```

### Grace (File-Writing Quine)

**Purpose**: Writes its own source code to file `Grace_kid.c`  
**Technique**: Uses fprintf to write to file instead of stdout  
**Key Challenge**: Opening file, writing source, proper cleanup

**Example Structure**:
```c
// Comment at start
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *f = fopen("Grace_kid.c", "w");
    char *s = "source code with %s placeholder";
    fprintf(f, s, s);
    fclose(f);
}
```

**Verification**:
```bash
./Grace
diff Grace.c Grace_kid.c  # Exit code 0 = identical
```

### Sully (Recursive Generation Quine)

**Purpose**: Creates decreasing generations of itself (Sully_5 → Sully_0)  
**Technique**: Embeds counter, writes source with decremented value, compiles and executes  
**Key Challenge**: System calls for compilation and execution, proper counter handling

**Example Flow**:
```bash
./Sully          # Counter = 5, creates Sully_5.c
./Sully_5        # Counter = 4, creates Sully_4.c
./Sully_4        # Counter = 3, creates Sully_3.c
...
./Sully_1        # Counter = 0, creates Sully_0.c (stops)
```

**Key Elements**:
- Filename generation: `sprintf(filename, "Sully_%d.c", i-1)`
- Source writing: `fprintf(f, source, i-1, source)`
- Compilation: `system("gcc -o Sully_X Sully_X.c")`
- Execution: `system("./Sully_X")`
- Base case: Stop when counter reaches 0

**Verification**:
```bash
./Sully
# Check file generation
ls Sully_*.c Sully_[0-5]
# Verify each source
diff Sully_5.c <(cat Sully.c | sed 's/5/4/')  # Simplified check
```

### Language Variants

Each quine (Colleen, Grace, Sully) is implemented in:
- **C**: Using printf/fprintf and char* strings
- **Python**: Using print() and f-strings or .format()
- **ASM (x86_64)**: Using syscall write with .data section strings

## Theoretical Foundation

### Kleene's Recursion Theorem

**Statement**: For any computable function f, there exists a program p such that p computes the same function as f(p), where p is the code of p itself.

**Implication**: Programs can "obtain" their own source code through pure computation without external file access.

**Practical Application**: Quines demonstrate that a program can reference its own code by encoding it as a string and using format specifiers to reproduce that encoding.

### Fixed-Point Theorem

A quine is a fixed point of the "evaluate and print" function:
```
eval(print(code)) = code
```

The program's execution produces its own source as output.

### Self-Reference Paradox Resolution

Quines resolve the apparent paradox: "How can a program reference itself without already existing?"

**Solution**: The program stores a partial representation of itself, then uses that representation to reconstruct the full source including the representation itself.

### Quine Variants

- **True Quine**: No input/output files, pure self-reproduction
- **Cheating Quine**: Reads its own source file (not a true quine)
- **Error Quine**: Produces itself through error messages
- **Polyglot Quine**: Valid in multiple programming languages simultaneously

## Testing

### Colleen Verification

```bash
# C version
./Colleen > tmp_Colleen.c
diff Colleen.c tmp_Colleen.c
echo $?  # Should be 0

# Python version
python3 Colleen.py > tmp_Colleen.py
diff Colleen.py tmp_Colleen.py
echo $?  # Should be 0

# ASM version
./Colleen_asm > tmp_Colleen.s
diff Colleen.s tmp_Colleen.s
echo $?  # Should be 0
```

### Grace Verification

```bash
# C version
./Grace
diff Grace.c Grace_kid.c
echo $?  # Should be 0

# Python version
python3 Grace.py
diff Grace.py Grace_kid.py
echo $?  # Should be 0

# ASM version
./Grace_asm
diff Grace.s Grace_kid.s
echo $?  # Should be 0
```

### Sully Verification

```bash
# C version
./Sully
ls Sully_{5,4,3,2,1,0}.c
ls Sully_{5,4,3,2,1}  # Executables
./Sully_0  # Should not create Sully_-1

# Python version
python3 Sully.py
ls Sully_{5,4,3,2,1,0}.py

# Verify generation chain
./Sully
./Sully_5
./Sully_4
# ... check each creates correct next generation
```

### Comprehensive Test Script

```bash
#!/bin/bash
# test_all_quines.sh

echo "Testing Colleen..."
./Colleen > tmp_Colleen.c && diff -q Colleen.c tmp_Colleen.c
python3 Colleen.py > tmp_Colleen.py && diff -q Colleen.py tmp_Colleen.py

echo "Testing Grace..."
./Grace && diff -q Grace.c Grace_kid.c
python3 Grace.py && diff -q Grace.py Grace_kid.py

echo "Testing Sully..."
./Sully
for i in {5..1}; do
    [ -f "Sully_$i.c" ] && [ -f "Sully_$i" ] && echo "Sully_$i OK"
done
[ -f "Sully_0.c" ] && [ ! -f "Sully_0" ] && echo "Sully_0 OK (no executable)"

echo "All tests completed!"
```

### Edge Cases

```bash
# Test Sully starting from 0
cp Sully_0.c Sully_test.c
gcc -o Sully_test Sully_test.c
./Sully_test  # Should not create Sully_-1.c

# Test Sully file permissions
chmod 000 .
./Sully  # Should handle write errors gracefully
chmod 755 .

# Test with special characters in path
mkdir "test dir"
cp Colleen "test dir/"
cd "test dir" && ./Colleen
```

## 42 School Standards

### Project Standards

* ✅ No memory leaks (validated with valgrind for C/ASM versions)
* ✅ True quines (no external file reading)
* ✅ Proper format string usage for self-replication
* ✅ Multi-language implementation (C, Python, ASM)
* ✅ Recursive generation with proper termination (Sully)
* ✅ Norm compliance for C code

### Quine Requirements

* ✅ Colleen outputs to stdout (exact source match)
* ✅ Grace writes to file (Grace_kid.*)
* ✅ Sully creates recursive generations (5 → 0)
* ✅ No reading of own source file
* ✅ No use of external quine libraries or tools

### Technical Requirements

* ✅ Proper comment placement in source code
* ✅ Correct format specifier usage (%s, %d, etc.)
* ✅ String escape handling (quotes, newlines, backslashes)
* ✅ System calls for compilation and execution (Sully)
* ✅ File I/O operations (Grace, Sully)
* ✅ Counter decrement and base case (Sully)

### Code Quality

* ✅ Clean, readable self-referential code structure
* ✅ Minimal code duplication across languages
* ✅ Proper error handling for file operations
* ✅ Efficient string manipulation techniques
* ✅ Clear demonstration of Kleene's recursion theorem

### Bonus Features (Optional)

* ✅ Additional language implementations (Shell, etc.)
* ✅ Polyglot quines (valid in multiple languages)
* ✅ Optimized quine size and complexity
* ✅ Creative variations on core quine concepts

## Contact

* **GitHub**: [@TuroTheReal](https://github.com/TuroTheReal)
* **Email**: [arthurbernard.dev@gmail.com](mailto:arthurbernard.dev@gmail.com)
* **LinkedIn**: [Arthur Bernard](https://www.linkedin.com/in/arthurbernard92/)

---

[![Made with C](https://img.shields.io/badge/Made%20with-C-blue.svg)](https://img.shields.io/badge/Made%20with-C-blue.svg)
[![Python](https://img.shields.io/badge/Python-3.x-green.svg)](https://img.shields.io/badge/Python-3.x-green.svg)
[![Assembly](https://img.shields.io/badge/ASM-x86__64-red.svg)](https://img.shields.io/badge/ASM-x86__64-red.svg)
[![Quine Theory](https://img.shields.io/badge/Theory-Kleene's%20Recursion-orange.svg)](https://img.shields.io/badge/Theory-Kleene's%20Recursion-orange.svg)
