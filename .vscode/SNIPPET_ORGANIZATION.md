# Snippet Organization Summary

## Structure
```
C:\Users\Asger\Uni\Github\UNI\.vscode\
├── snippets/
│   ├── Python/
│   │   ├── complex-snippets.code-snippets
│   │   ├── pla-snippets.code-snippets
│   │   └── dsb-snippets.code-snippets
│   └── CPP/
│       ├── ho-programming-snippets.code-snippets
│       ├── cpp-algorithms-lambdas-advanced.code-snippets
│       ├── cpp-containers-control.code-snippets
│       ├── cpp-functions.code-snippets
│       ├── cpp-includes.code-snippets
│       ├── cpp-iterators-premade.code-snippets
│       ├── cpp-memory-lifecycle.code-snippets
│       ├── cpp-structures.code-snippets
│       └── shortcuts.code-snippets
```

## Python Snippets (Scope: python,jupyter)
- **complex-snippets.code-snippets**: Complex number array operations for NumPy
- **pla-snippets.code-snippets**: Practical Linear Algebra - vectors, matrices, linear systems
- **dsb-snippets.code-snippets**: Digital Signal Processing - signal generation, FFT, filtering

## C++ Snippets (Scope: cpp,h)
All C++ snippets are scoped to C++ and header files only (won't appear in Python files):

### From Root .vscode:
- **ho-programming-snippets.code-snippets**: Higher-order programming, lambdas, function objects

### From OOP Lesson .vscode (now scoped to C++):
- **cpp-algorithms-lambdas-advanced.code-snippets**: Advanced algorithm and lambda examples
- **cpp-containers-control.code-snippets**: STL containers (vector, set, map) and control structures
- **cpp-functions.code-snippets**: Function declarations and implementations
- **cpp-includes.code-snippets**: Standard library includes
- **cpp-iterators-premade.code-snippets**: Iterator patterns and loops
- **cpp-memory-lifecycle.code-snippets**: Memory management, constructors, smart pointers
- **cpp-structures.code-snippets**: Classes, structs, inheritance, polymorphism
- **shortcuts.code-snippets**: VS Code keyboard shortcuts (now C++ scoped)

## How to Use
1. Snippets in `snippets/Python/` will ONLY show when editing Python files
2. Snippets in `snippets/CPP/` will ONLY show when editing C++ or header files
3. All snippets are automatically available - no additional configuration needed
