//
// Created by William Petersmeyer on 1/28/26.
//

#include "headers/input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESH_IN_BUFFER_SIZE 1024

char* read_input() {

    int buffer_size = MESH_IN_BUFFER_SIZE, input_position = 0;
    char* buffer = malloc(buffer_size * sizeof(char*));

    if (!buffer) {
        fprintf(stderr, "MeSh: Memory could not be allocated while getting user input.\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {

        const char current_char = getchar();

        if (current_char == '\n' || current_char == EOF) {
            buffer[input_position] = '\0';
            return buffer;
        }

        buffer[input_position] = current_char;
        input_position++;

        if (input_position >= buffer_size)
        {
            buffer_size += MESH_IN_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size * sizeof(char*));
            if (!buffer) {
                fprintf(stderr, "MeSh: Memory could not be allocated while getting user input.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define MESH_TOKEN_BUFFER_SIZE 32
#define MESH_DELIMITER "\a\t\r\n "

char** tokenize(char* str) {

    int buffer_size = MESH_TOKEN_BUFFER_SIZE, input_position = 0;
    char** token_list = malloc(buffer_size * sizeof(char*));

    if (!token_list) {
        fprintf(stderr, "MeSh: Memory could not be allocated while preforming tokenization.\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(str, MESH_DELIMITER);

    while (token) {

        token_list[input_position] = token;
        input_position++;

        if (input_position >= buffer_size) {
            buffer_size += MESH_TOKEN_BUFFER_SIZE;
            token_list = realloc(token_list, buffer_size * sizeof(char*));
            if (!token_list) {
                fprintf(stderr, "MeSh: Memory could not be allocated while preforming tokenization.\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, MESH_DELIMITER);
    }

    token_list[input_position] = NULL;
    return token_list;

}