//
// Created by William Petersmeyer on 1/28/26.
//

#include "headers/builtin_functions.h"

#include <stdio.h>
#include <unistd.h>

char *builtin_names[] =
{
    "cd",
    "exit",
    "help",
    "echo",
    "pwd"
};

int (*builtin_functions[]) (char**) =
{
    &mesh_cd,
    &mesh_exit,
    &mesh_help,
    &mesh_echo,
    &mesh_pwd,
};

int get_total_builtins() {
    return sizeof(builtin_functions) / sizeof(char *);
}

// <-- Built-in Function Implementations -->

int mesh_cd(char** args) {
    if (args[1] == NULL)
        fprintf(stderr, "MeSh: \"cd\" requires at least one argument.\n");
    else
    {
        if (chdir(args[1]) != 0) perror("mesh");
    }
    return 1;
}

int mesh_exit(char** args) {
    return 0;
}

int mesh_help(char** args) {
    printf("MeSh: I don't want to write this\n");
    return 1;
}

int mesh_echo(char** args) {
    args[0] = "";

    if (args[1] == NULL)
        fprintf(stderr, "MeSh: \"echo\" requires at least one argument.\n");
    else printf("%p", args);


    return 1;
}

int mesh_pwd(char** args) {

    char wd[1024];

    if (getcwd(wd, 1024) == NULL) {
        perror("mesh");
        return 0;
    }

    printf("%s\n", wd);
    return 1;
}

