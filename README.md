# MicroScript
[![CMake on multiple platforms](https://github.com/sktryo/MicroScript/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/sktryo/MicroScript/actions/workflows/cmake-multi-platform.yml)

MicroScript is a minimalistic interpreter for a simple Turing-complete language, implemented in C. It supports basic operations such as tape manipulation, increment, decrement, loops, and simple I/O.

## Features

- **Minimalistic Design:** Implemented in C with a focus on simplicity and clarity.
- **Basic Operations:** Supports `>`, `<`, `+`, `-`, `[`, `]`, `_`, and `|` commands.
- **Input/Output:** Reads ASCII input into tape cells (`_`) and prints ASCII characters from tape cells (`|`).
- **Debug Mode:** Optional debug mode (`-DDEBUG=ON`) enables debug messages and verbose output.

## Usage

1. **Building MicroScript:**
   ```bash
   mkdir build
   cd build
   cmake -DDEBUG=ON ..
   cmake --build .
   ```

2. **Running MicroScript:**
   ```bash
   ./microscript script.txt
   ```

   Replace `script.txt` with the path to your MicroScript code file.

3. **Debug Mode:**
   Enable debug mode by defining `-DDEBUG=ON` during the build. This will include debug messages during execution.

4. **MicroScript Code Example:**
   ```plaintext
   script.txt:
   +++++++++++++++++++++++++++++++++|     # Increment current cell to 33 and print as ASCII '!'
   ```

5. **License:**
   This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Requirements

- CMake 3.10 or higher
- C compiler (e.g., GCC, Clang)

## Contributing

Contributions are welcome! Please fork the repository, make your changes, and submit a pull request.

