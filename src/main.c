#include <stdio.h>
#include <stdlib.h>
#include "microscript.h"

char *readCodeFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        fclose(file);
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';

    fclose(file);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int debug = 0;
    #ifdef DEBUG
        debug = 1;
    #endif
    char *code = readCodeFromFile(argv[1]); // コマンドライン引数からファイル名を取得し、コードを読み込む
    MicroScriptInterpreter interpreter;
    initInterpreter(&interpreter, code, 0); // デバッグモードをオフにしてインタプリタを初期化
    interpret(&interpreter);
    free(code); // メモリを解放する
    return 0;
}
