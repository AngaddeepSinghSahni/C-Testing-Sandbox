# C Foundations & Defensive Testing Sandbox

I'm a first-year computer science student using this repository as a personal sandbox to master low-level mechanics, clean project structure, and defensive programming in C.

## Core Concepts & Modules

* **Custom String Functions (c_string_functions/):** Rebuilding standard string behaviors (strlen, strcpy, etc.) focusing on pointer tracking and trailing (\0) null-terminators.
  Run tests with `cd c_string_functions && make && ./tester`.
* **Command Line Grade Checker (c_grade_checker/):** Parses CLI arguments and validates digit boundaries.
  Run tests with `cd c_grade_checker && make test_runner && ./test_runner`.
* **Triangle Classifier (c_triangle_classifier/):** Evaluates triangle inequalities with overflow mitigation using (long long) types against inputs like (INT_MAX).
  Run tests with `cd c_triangle_classifier && make test_runner && ./test_runner`.

## Repository Structure

```text
c-testing-sandbox/
├── c_string_functions/     # Custom string implementations & tests
├── c_grade_checker/        # CLI input validation & logic tests
└── c_triangle_classifier/  # Triangle validation & overflow handling
```

## Upcoming Roadmap
1. **Dynamic Memory Safety:** Integrating AddressSanitizer (ASan) into Makefiles to automatically catch buffer overflows.
2. **Robust Errors:** Replacing simple -1 flags with explicit pointer-based error handling patterns.
3. **Advance testing framework:** Expand beyond rudimentary initial unit tests to implement end-to-end integration testing and stress analysis.
