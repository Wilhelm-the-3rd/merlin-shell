#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void shell_loop(void);

char* read_input(void);
char** tokenize(char* line);
int execute(char** cmd);

int main(const int argc, char *argv[]) {

    
    if (argc > 1) {
        printf("MeSh does not support multiple arguments at this time.\nUsage: %s", argv[0]);
    }

    shell_loop(); 

    return EXIT_SUCCESS;
}

void shell_loop() {
    for (;;)
    {
        printf("<> "); 

        char **tokenized_input = tokenize(
            read_input() 
            );

        const int cmd_success = execute(tokenized_input); 

        free(tokenized_input); 

        if (!cmd_success) break;
    }
}

#define MESH_IN_BUFSIZE 1024
char* read_input() {

    int buffer_size = MESH_IN_BUFSIZE, input_position = 0;
    char* buffer = malloc(buffer_size * sizeof(char));

    if (!buffer) { fprintf(stderr, "MeSh: Memory could not be allocated.\n"); exit(EXIT_FAILURE); }

    for (;;) {

        const char current_char = getchar();

        if (current_char == '\n' || current_char == EOF) { buffer[input_position] = '\0'; return buffer; }

        buffer[input_position] = current_char;
        input_position++;

        if (input_position >= buffer_size)
        {
            buffer_size += MESH_IN_BUFSIZE;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) { fprintf(stderr, "MeSh: Memory could not be allocated.\n"); exit(EXIT_FAILURE);}
        }
    }
}

#define MESH_TOKEN_BUFSIZE 32
#define MESH_DELIM "\a\t\r\n "

char** tokenize(char* str) {

    int buffer_size = MESH_IN_BUFSIZE, input_position = 0;
    char** token_list = malloc(buffer_size * sizeof(char));
    char* token;

    if (!token_list) { fprintf(stderr, "MeSh: Memory could not be allocated.\n"); exit(EXIT_FAILURE); }

    token = strtok(str, MESH_DELIM);

    while (token) {

    }


}