# MicroScript

MicroScript is a minimalistic interpreter for a simple Turing-complete language, designed to run on constrained environments and demonstrate basic interpreter concepts.

## Features

- **Minimalistic Design:** Written in C, MicroScript implements basic operations such as tape movement, increment, decrement, and loops using a compact code base.
- **Input/Output:** Supports reading ASCII input into tape cells (`_`) and printing ASCII characters from tape cells (`|`).
- **Debug Mode:** Optional debug mode provides insight into program execution, showing each command executed, tape state, and more.

## Usage

1. **Compile:** Compile MicroScript using a C compiler.
   
   ```
   gcc -o microscript main.c microscript.c
   ```

2. **Run:** Execute MicroScript with a script file containing MicroScript code.

   ```
   ./microscript script.txt
   ```

3. **Debug:** Enable debug mode (`initInterpreter(&interpreter, code, 1);`) to trace program execution.

## Example

```plaintext
$ cat script.txt
++++++++++[>++++++<-]>|

$ ./microscript script.txt
*
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
