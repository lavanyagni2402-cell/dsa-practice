#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    char* stack[3000];
    int top = -1;

    char* token = strtok(path, "/");

    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            // Ignore current directory
        }
        else if (strcmp(token, "..") == 0) {
            // Go to parent directory
            if (top >= 0)
                top--;
        }
        else {
            // Valid directory
            stack[++top] = token;
        }

        token = strtok(NULL, "/");
    }

    // Allocate memory for result
    char* result = (char*)malloc(3001);
    result[0] = '\0';

    if (top == -1) {
        strcpy(result, "/");
        return result;
    }

    for (int i = 0; i <= top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    return result;
}