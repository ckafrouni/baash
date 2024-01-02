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
#include <unistd.h>

#include "colorize.h"
#include "prompt.h"
#include "cmd_processor.h"

#define VERSION "0.0.1"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        fprintf(stderr, RED("USAGE ") "%s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    (void)argv;

    printf("/**\n");
    printf(" * " YELLOW(BOLD("Baash")) " " BOLD("shell ") "\n");
    printf(" * " MAGENTA(BOLD("v%s")) "\n",
           VERSION);
    printf(" * " BOLD("ckafrouni ;)") "\n");
    printf(" */\n\n");

    char prompt_buf[1024];

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        prompt(prompt_buf, sizeof(prompt_buf));
        printf("%s", prompt_buf);

        printf("\033[36m");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            printf("\n");
            break;
        }
        printf(RESET);
        fflush(stdout);

        process_cmd(line);
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}
