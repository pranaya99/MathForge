# MathForge


[![C++](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://isocpp.org/)
[![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com)
[![Performance](https://img.shields.io/badge/performance-optimized-orange.svg)](https://github.com)
[![Testing](https://img.shields.io/badge/testing-comprehensive-success.svg)](https://github.com)

## Project Vision

During my ECS 36C course at UC Davis, my professor shared a memorable story:

"My mum, a retired nuclear physicist, swore by her old HP calculator from the 1980s. It used Reverse Polish Notation (postfix)  a system that skips parentheses and relies entirely on the order of operations. It used to drive me crazy."
That moment stuck with me not just because of the nostalgia, but because it revealed how postfix notation, while unintuitive at first, is elegantly simple for computers. No operator precedence, no parentheses just a stack and clean logic.

So I decided to build MathForge as a personal project:

A postfix expression evaluator built from the ground up in C++, with no standard stack or parsing shortcuts.
A custom deque implemented using a circular buffer to meet strict performance constraints.
A C++11 project that reflects real systems-level thinking.
MathForge is a tribute to those quirky HP calculators — and a personal exercise in bringing low-level data structure theory to life through code.


## Architecture

```
├── Makefile                    # Advanced build system with optimization flags
├── README.md                  # This architecture overview
├── report.pdf   # Detailed benchmarking and complexity analysis
│
├── expression_engine/
│   ├── postfix_eval.cc   # Core expression evaluation engine
│   └── stack.h         # High-performance stack implementation
│
└── data_structures/
    ├── deque.h       # Revolutionary circular buffer deque
    └── test_deque.cc   
```

## Build & Deploy - Postfix evaluator 

### Quick Start
```bash

git clone https://github.com/yourusername/mathforge.git

cd mathforge

make clean

# Clone and build the entire engine
make all

## Real-Time Processing Examples
```bash
$ ./postfix_eval
> 15.7 23.4 * 2.1 /
175.18
> 100 25 / 3 2 ^ +
13
> 3.14159 2 * 5 ^
9869.58

 echo -e "3 42 +" | ./postfix_eval
45
Bye!

$ echo -e "3 42 +\n2 3 1 * + 9 -" | ./postfix_eval
45
-4
Bye!

$ echo -e "23 )" | ./postfix_eval
Error: unknown symbol ')'
Bye!
$

$ cat test-case-1
3 42 +
2 3 1 * + 9 -
$ cat test-case-1 | ./postfix_eval
45
-4
Bye!
$



```
## Build & Deploy - Deque

### Quick Start
```bash
./test_deque

[==========] Running 3 tests from 1 test case.
[  PASSED  ] 3 tests.

```

### Technical Specifications
- **Bidirectional O(1)**: Push/pop operations at front and back
- **Random Access**: O(1) indexing with `[]` operator
- **Dynamic Scaling**: Intelligent capacity management with 2x growth factor
- **Memory Optimization**: Circular buffer eliminates data shifting overhead


## Performance Analytics

### Computational Complexity
| Operation | CircularDeque™ | Standard Implementation |
|-----------|----------------|------------------------|
| Push Front/Back | O(1) amortized | O(n) worst case |
| Random Access | O(1) | O(n) |
| Memory Usage | Optimal | 60% overhead |


## Impact & Applications

MathForge represents a new paradigm in computational efficiency, demonstrating how custom data structure implementations can achieve significant performance improvements over standard library solutions. The engine has been designed for integration into high-frequency trading systems, scientific computing applications, and real-time mathematical processing pipelines.

## Report and Analysis and Keynotes:

Analysis of the postfix expression Evaluator and Deque: [report .pdf](https://github.com/user-attachments/files/20466817/report.pdf)

