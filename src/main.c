#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "colorize.h"
#include "prompt.h"
#include "cmd_processor.h"

void handle_signal(int signal)
{
    if (signal == SIGINT)
    {
        printf(RESET "\n");
        exit(EXIT_SUCCESS);
    }
}

#define BUFFER_SIZE 1024

char welcome_buf[BUFFER_SIZE];
char prompt_buf[BUFFER_SIZE];

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        fprintf(stderr, RED("USAGE ") "%s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    (void)argv;

    print_welcome_msg();

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    signal(SIGINT, handle_signal);

    while (1)
    {
        printf("\n");
        print_prompt();

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
    }

    exit(EXIT_SUCCESS);
}
