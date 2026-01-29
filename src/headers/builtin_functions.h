//
// Created by William Petersmeyer on 1/28/26.
//

#ifndef MERLIN_SHELL_BUILTIN_FUNCTIONS_H
#define MERLIN_SHELL_BUILTIN_FUNCTIONS_H

extern char* builtin_names[];
extern int (*builtin_functions[])(char**);

int mesh_cd(char**);
int mesh_exit(char**);
int mesh_help(char**);
int mesh_pwd(char**);
int mesh_echo(char**);

int get_total_builtins(void);

#endif //MERLIN_SHELL_BUILTIN_FUNCTIONS_H