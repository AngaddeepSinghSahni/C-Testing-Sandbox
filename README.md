# C Software Reliability & Boundary Testing Lab

This repository is an educational sandbox designed to explore modular code architecture, custom build automation (Makefiles), and explicit edge-case discovery in low-level C programming. 

Instead of writing complex application logic, these micro-projects focus on defensive design and software constraints: parsing strings securely, mapping numeric type limitations (INT_MAX), and identifying boundary errors.

---

## Core Engineering Takeaways
* **Modular Separation:** Separated interface specifications (.h), functional logic (.c), and verification suites into isolated files to ensure zero leakage between tests and runtime binaries.
* **Granular Build Optimization:** Configured rule-based Makefiles utilizing compiler object files (.o) to enable incremental compilation and prevent redundant build steps.
* **Defensive Boundary Mapping:** Explored memory constraints, array limits, string null-termination mechanics, and structural overflows across distinct environments.

---

## Repository Architecture

```text
c-testing-sandbox
├── c_string_functions          # Pure logic implementations of string functions
│   ├── string_function.h
│   ├── string_function.c
│   ├── test_string_function.c
│   └── Makefile
├── c_grade_checker             # Input parsing and grade classification engine
│   ├── grade_checker.h
│   ├── grade_checker.c
│   ├── test_grade_checker.c
│   └── Makefile
└── c_triangle_classifier       # Geometrical analysis under numeric limits
    ├── triangle_classifier.h
    ├── triangle_classifier.c
    ├── test_triangle_classifier.c
    └── Makefile
```

---

## Build and Execution Guide

Every module contains an independent, professional build automation workflow. Navigate to any individual directory in your terminal to build or test the programs.

### 1. String Function Module (c_string_function)
This sub-project reconstructs standard C string library mechanics (strlen, strcpy, strcmp, strcat, strstr) to verify tracking of array indices and null termination.

* **To compile and execute the test runner:**
  ```bash
  cd c_string_function && make && ./tester
  ```
* **To clean up generated object files and binaries:**
  ```bash
  make clean
  ```

### 2. Grade Checker Module (c_grade_checker)
This project takes raw terminal string arrays, validates character-by-character digit matrices, and applies structured interval checks.

* **To compile and execute the 25+ test verification suite:**
  ```bash
  cd c_grade_checker && make test_runner && ./test_runner
  ```
* **To build and execute the interactive production app:**
  ```bash
  make grade_checker && ./grade_checker 85
  ```
* **To clean up:**
  ```bash
  make clean
  ```

### 3. Triangle Classifier Module (c_triangle_classifier)
An exploration of geometry boundary logic. It tracks flat lines, impossible shapes, and handles potential math overflows by converting inputs to safe mathematical types (long long) before computing triangle inequalities.

* **To compile and execute the 50+ assertion suite (including INT_MAX limits):**
  ```bash
  cd c_triangle_classifier && make test_runner && ./test_runner
  ```
* **To build and execute the interactive classification app:**
  ```bash
  make triangle_classifier && ./triangle_classifier 3 4 5
  ```
* **To clean up:**
  ```bash
  make clean
  ```

---

## Current Limitations & Roadmap

While these automated assertion matrices systematically challenge hardcoded inputs and structural boundary criteria, they are structurally brittle. Changing an interior enum or function index can fracture the test environment. 

### Future Optimization Goals:
1. **Transition to Fuzz Testing:** Replace rigid, hand-typed assertion scenarios with programmatic generation loops (e.g., generating millions of true Pythagorean triples to evaluate the triangle classifier).
2. **Robust Fault Propagation:** Shift away from legacy -1 error signals in numerical string conversion to explicit, pointer-passed error parameters.

