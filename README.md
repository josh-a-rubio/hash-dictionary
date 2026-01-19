# HashDict (C data structure programming)

A lightweight terminal application that demonstrates a hash table in C, allowing users to insert words, check for duplicates, and visualize collisions across buckets in real time.

---

## Demo / Screenshot

> <img width="403" height="422" alt="Screenshot 2026-01-19 at 4 54 53 PM" src="https://github.com/user-attachments/assets/86b184a3-9a78-45ad-b6fb-fb7b6e70eac3" />

> - Inserted words and duplicate detection
> - Lookup results for words
> - Visual printout of all 26 buckets
> - Linked list arrows showing collisions
> - Real-time interactive input/output

## Overview

### Problem
Most introductory data structure examples are abstract or non-interactive, making it hard to see how hash tables, collisions, and linked lists work in practice. Users rarely get a hands-on view of buckets or chaining in a simple, visual way.

### Solution

This project provides a **fast, minimal, terminal-first hash table demo** for words. It allows users to insert words, detect duplicates, and visualize collisions across buckets in real time.

This application demonstrates a **systems-style architecture** where:

- **C** handles performance-critical logic, memory allocation, insertion, lookup, and linked list management
- The program uses a **hash table with 26 buckets** to simplify demonstration
- Collisions are handled via **chaining with linked lists**
- The user interacts with **one binary only**, entering words and immediately seeing the table state

Every execution allows **interactive, real-time exploration** of hash table behavior.

---

## Key Features

- Simple hash table with 26 buckets
- Chaining via linked lists to handle collisions
- Insert and lookup operations
- Visual printout of buckets for demonstration
- Proper dynamic memory allocation and deallocation

---

## Tech Stack

- **Language:** C
- **Compiler:** GCC or compatible C compiler

---

## Architecture / System Design

```
┌─────────────┐
│ hashdict    │ (C executable)
└─────┬───────┘
      │ user input (words)
      ▼
┌─────────────┐
│ hash table  │ (26 buckets)
│ - array of  │
│ linked      │
│ lists       │
└─────┬───────┘
      ▼
┌─────────────┐
│ bucket N    │
│ - node      │
│ word →      │
│ next →      │
│ ...         │
└─────────────┘
```

- Hash table implemented as a global array of linked list heads
- Nodes store a single word (max 50 characters) and a pointer to the next node
- Hash function sums ASCII values of characters and mods by table size
- Insert adds to the head of the linked list in the corresponding bucket
- Lookup traverses the linked list for matches
- Free function iterates all buckets to release allocated memory

---

## Getting Started

### Prerequisites

- Operating system: recommended Unix-like (macOS, Linux) — Windows works with a C compiler
- C compiler (clang or gcc)

> No external dependencies required at runtime

> Pure C program

### Clone & Prepare

```bash
git clone https://github.com/josh-a-rubio/hash-dictionary
cd HashDict/src
```

### Build

```
gcc -o hashdict main.c
```

Make sure the following files are in the same directory:
- `hashdict` (compiled executable)
- `main.c`

### Run

```bash
./hashdict
```

---





