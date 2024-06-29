#ifndef MICROSCRIPT_H
#define MICROSCRIPT_H

typedef struct {
    int tape[2048];
    int pointer;
    int codePointer;
    char *code;
    int loopStack[1000];
    int loopStackPointer;
    int debug;
} MicroScriptInterpreter;

void initInterpreter(MicroScriptInterpreter *interpreter, char *code, int debug);
void interpret(MicroScriptInterpreter *interpreter);

#endif /* MICROSCRIPT_H */
