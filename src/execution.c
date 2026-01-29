//
// Created by William Petersmeyer on 1/28/26.
//

#include <unistd.h>
#include <sys/wait.h>

#include "headers/execution.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/builtin_functions.h"


int new_process(char** args) {
    pid_t pid = fork();
    int child_status;

    if (pid < 0) perror("mesh"); // Process failed while forking

    else if (pid == 0) { // Child process
        if (execvp(args[0], args) < 0) perror("mesh");
        exit(EXIT_FAILURE);
    } else { // Parent process

        do {
            waitpid(pid, &child_status, WUNTRACED);
        } while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
    }

    return 1;

}

int execute(char** args) {

    if (args[0] == NULL) return 1;

    int i=0;
    while (i < get_total_builtins()) {
        if (strcmp(args[0], builtin_names[i]) == 0)
            return (*builtin_functions[i])(args);
        i++;
    }

    return new_process(args);

}