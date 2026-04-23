# Elements

> *"Think like a Programmer" — one element at a time.*

## About

This repository is a **programmer's casebook** — a living collection of code snippets and algorithm implementations built up through consistent daily practice. The name is drawn from chemistry: just as chemical elements are the simplest building blocks of all matter, the programs here are the fundamental building blocks of larger, more complex software.

From the casebook method used in law schools ("thinking like a lawyer"), this project adapts the same philosophy to software engineering: study small, self-contained problems deeply, internalize the patterns, and build the confidence to compose them into anything.

> *"External third-party APIs can be no substitute for the confidence one has in one's own code."*

---

## Languages

| Language   | Directory      |
|------------|----------------|
| C++        | `cpp/`         |
| Java       | `java/`        |
| JavaScript | `javascript/`  |
| Python     | `python/`      |

---

## Contents

### C++ (`cpp/`)

| File | Description |
|------|-------------|
| `array_playground.cpp` | Array manipulation experiments |
| `binary_search_iterative.cpp` | Iterative binary search |
| `binary_search_recursive.cpp` | Recursive binary search |
| `butterfly_pattern.cpp` | Butterfly/diamond pattern printing |
| `censor_string.cpp` | String censoring utility |
| `check_ascending_order.cpp` | Check if array is sorted ascending |
| `class_template.cpp` | Generic class template example |
| `count_down.cpp` / `count_up.cpp` | Basic loop counting |
| `csv_num.cpp` | CSV number parsing |
| `decode_msg.cpp` | Message decoding |
| `dynamic_1D_array.cpp` | Dynamic 1-D array allocation |
| `dynamic_2D_array.cpp` | Dynamic 2-D array allocation |
| `dynamic_3D_aray.cpp` | Dynamic 3-D array allocation |
| `insertion_sort.cpp` | Insertion sort implementation |
| `is_unique_string.cpp` | Check string for unique characters |
| `luhn_checksum_validation.cpp` | Luhn algorithm for credit-card validation |
| `point.cpp` / `point.h` | Point class (OOP example) |
| `point_test.cpp` | Unit tests for Point class |
| `remove_duplicates.cpp` | Remove duplicate elements |
| `reverse_pyramid.cpp` | Reverse pyramid pattern |
| `reverse_string.cpp` | String reversal |
| `rotate_matrix.cpp` | In-place matrix rotation |
| `rotate_mode.cpp` | Mode-based rotation |
| `sideways_triangle.cpp` | Sideways triangle pattern |
| `stack.cpp` | Stack data structure |
| `string_api_tests.cpp` | Standard library string API exploration |
| `string_functions.cpp` / `string_functions_test.cpp` | Custom string utilities and tests |
| `student_sort.cpp` / `students.cpp` | Sorting student records |
| `definitions.h` | Shared type/constant definitions |

### Java (`java/`)

| File | Description |
|------|-------------|
| `IsUnique.java` | Check string for unique characters |

### JavaScript (`javascript/`)

| File | Description |
|------|-------------|
| `binary_search_iterative.js` | Iterative binary search |
| `selection_sort.js` | Selection sort implementation |

### Python (`python/`)

| File | Description |
|------|-------------|
| `binary_search_recursive.py` | Recursive binary search |
| `bubble_sort.py` | Bubble sort implementation |
| `insertion_sort.py` | Insertion sort implementation |
| `is_unique.py` | Check string for unique characters |
| `merge_lines.py` | Merge lines from a file |
| `merge_sort.py` | Merge sort implementation |
| `remove_duplicates.py` | Remove duplicate elements |
| `remove_duplicates_old_algo.py` | Alternative duplicate-removal approach |
| `reverse_c_string.py` | Reverse a C-style (null-terminated) string |
| `reverse_string.py` | Standard string reversal |
| `selection_sort.py` | Selection sort implementation |

### Test Data (`test_data/`)

| File | Description |
|------|-------------|
| `decode_message_input.txt` | Sample input for the decode-message programs |

---

## Topics Covered

- **Searching**: Binary search (iterative & recursive)
- **Sorting**: Bubble, insertion, selection, merge sort
- **Strings**: Reversal, censoring, uniqueness checks, custom utilities
- **Arrays & Matrices**: Dynamic allocation, rotation, duplicate removal
- **Data Structures**: Stack, dynamic arrays
- **Patterns**: Butterfly, pyramid, sideways triangle
- **OOP**: Class templates, point class
- **Validation**: Luhn checksum
- **File I/O**: CSV parsing, message decoding

---

## Getting Started

Each file is self-contained and can be compiled or run independently.

**C++**
```bash
g++ -std=c++17 -o out cpp/<filename>.cpp && ./out
```

**Java**
```bash
javac java/<FileName>.java && java -cp java <ClassName>
```

**JavaScript**
```bash
node javascript/<filename>.js
```

**Python**
```bash
python3 python/<filename>.py
```

---

## License

This project is open for personal study and reference. Feel free to use any snippet as a building block for your own work.
