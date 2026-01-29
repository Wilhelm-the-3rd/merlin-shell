#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "headers/input.h"
#include "headers/execution.h"

void shell_loop(void);

int main(const int argc, char *argv[]) {
    if (argc > 1) {
        printf("MeSh does not support multiple arguments at this time.\nUsage: %s", argv[0]);
    }

    shell_loop(); 

    return EXIT_SUCCESS;
}

void shell_loop() {

    char* username = getlogin();
    char wd[1024];

    while (1)
    {
        if (getcwd(wd, 1024) == NULL) perror("mesh");

        printf("%s @ %s -> ", username, wd);

        char **tokenized_input = tokenize(read_input());
        const int cmd_success = execute(tokenized_input);

        free(tokenized_input); 

        if (!cmd_success) break;
    }
}