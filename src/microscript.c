#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "microscript.h"

void initInterpreter(MicroScriptInterpreter *interpreter, char *code, int debug) {
    memset(interpreter->tape, 0, sizeof(interpreter->tape));
    interpreter->pointer = 0;
    interpreter->codePointer = 0;
    interpreter->code = code;
    interpreter->loopStackPointer = 0;
    interpreter->debug = debug;
}

void interpret(MicroScriptInterpreter *interpreter) {
    int codeLength = strlen(interpreter->code);

    while (interpreter->codePointer < codeLength) {
        char command = interpreter->code[interpreter->codePointer];

        switch (command) {
            case '>':
                ++interpreter->pointer;
                if (interpreter->pointer >= 2048) {
                    interpreter->pointer = 0;
                }
                break;
            case '<':
                --interpreter->pointer;
                if (interpreter->pointer < 0) {
                    interpreter->pointer = 2047;
                }
                break;
            case '+':
                ++interpreter->tape[interpreter->pointer];
                break;
            case '-':
                --interpreter->tape[interpreter->pointer];
                break;
            case '[':
                if (interpreter->tape[interpreter->pointer] == 0) {
                    int loopDepth = 1;
                    while (loopDepth > 0) {
                        ++interpreter->codePointer;
                        if (interpreter->codePointer >= codeLength) {
                            fprintf(stderr, "Unmatched '[' at position %d\n", interpreter->codePointer - 1);
                            exit(1);
                        }
                        if (interpreter->code[interpreter->codePointer] == '[') {
                            ++loopDepth;
                        } else if (interpreter->code[interpreter->codePointer] == ']') {
                            --loopDepth;
                        }
                    }
                } else {
                    interpreter->loopStack[interpreter->loopStackPointer++] = interpreter->codePointer;
                }
                break;
            case ']':
                if (interpreter->loopStackPointer == 0) {
                    fprintf(stderr, "Unmatched ']' at position %d\n", interpreter->codePointer);
                    exit(1);
                }
                if (interpreter->tape[interpreter->pointer] != 0) {
                    interpreter->codePointer = interpreter->loopStack[interpreter->loopStackPointer - 1];
                } else {
                    --interpreter->loopStackPointer;
                }
                break;
            case '_': {
                char input[2];
                printf("Input a character: ");
                fgets(input, sizeof(input), stdin);
                interpreter->tape[interpreter->pointer] = (int)input[0];
                break;
            }
            case '|':
                printf("%c", (char)interpreter->tape[interpreter->pointer]);
                break;
            default:
                // Ignore other characters
                break;
        }

        ++interpreter->codePointer;

        if (interpreter->debug) {
            printf("Executed command: %c\n", command);
            printf("Pointer: %d\n", interpreter->pointer);
            printf("Current cell value: %d\n", interpreter->tape[interpreter->pointer]);
            printf("Tape state: ");
            for (int i = 0; i < 10; ++i) {
                printf("%d ", interpreter->tape[i]);
            }
            printf("\n");
        }
    }

    if (interpreter->loopStackPointer > 0) {
        fprintf(stderr, "Unmatched '[' at position %d\n", interpreter->loopStack[--interpreter->loopStackPointer]);
        exit(1);
    }

    if (interpreter->debug) {
        printf("Final tape state: ");
        for (int i = 0; i < 10; ++i) {
            printf("%d ", interpreter->tape[i]);
        }
        printf("\n");
    }
}
