# ccalc

**ccalc** is a command-line calculator written in C, created as a small exercise to understand the use of **function pointers** and modularity in C.

![Demo GIF](./assets/showcase.gif)

---

## What does this project solve?

ccalc provides a quick and lightweight way to perform basic arithmetic operations directly in the terminal. It is useful for testing simple calculations without relying on heavy GUIs.

---

## How to run

```bash
git clone https://github.com/geovannewashington/ccalc
cd ccalc
make
./bin/ccalc
```

Options:

- `--no-banner`: disables the ASCII banner

> Currently, the calculator only supports 4 basic operations (addition, subtraction, multiplication, division) and works with two operands (lhs and rhs).

## How to install

Compile from source:

```bash
git clone https://github.com/geovannewashington/ccalc.git
cd ccalc
make
sudo make install   # optional: installs the binary
```

Or download **precompiled binaries** from the [Release page](https://github.com/geovannewashington/ccalc/releases)

> ⚠️ Currently, the project has only been tested on Linux.

## Why is this project interesting?

- Demonstrates **modularity** in C
- Allows easy addition of new operations (pull requests welcome!)
- Introduces **function pointers** and command-line argument parsing
- Implements **error handling** and input validation
- Uses **ANSI colors** for a better terminal experience

## Technologies and concepts applied

- **C (C11)** – pointers, functions, and memory management
- **Modular programming** – separate header and implementation files
- **Makefile** – automates compilation and binary generation
- **Command-line argument parsing** – flexible usage
- **ANSI colors** – improved terminal output
- **Error handling** – program robustness
