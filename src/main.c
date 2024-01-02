/**
 * @file main.c
 * @author Christophe Kafrouni (contact@ckaf.dev)
 * @brief Basic implementation of a bash like shell
 * @version 0.1
 * @date 2024-01-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colorize.h"
#include <unistd.h>

#define PROMPT MAGENTA(BOLD("baash> "))

void process(char *line)
{
    if (strcmp(line, "exit\n") == 0)
    {
        printf(BLUE("Exiting...") "\n");
        exit(EXIT_SUCCESS);
    }
    printf(YELLOW(BOLD("Processing: ")) UNDERLINE("%s") "\n", line);
}

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        fprintf(stderr, RED("USAGE ") "%s\n", argv[0]);
        return (EXIT_FAILURE);
    }

    (void)argv;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf(PROMPT);
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            printf("\n");
            break;
        }

        process(line);
    }

    return (EXIT_SUCCESS);
}
