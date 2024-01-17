#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "toml.h"
#include "config.h"
#include "colorize.h"
#include "prompt.h"
#include "cmd_processor.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        fprintf(stderr, RED("USAGE ") "%s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    (void)argv;

    // Load config
    char *config_path = "./bush.toml";
    config_t *config = load_config(config_path);

    print_config(config);
    print_colored(config->welcome_msg);

    print_colored("{B;MA;B_BLU:Bush} ++ {B:- Barelly Usable Shell}");

    // print_welcome_msg();

    // char *line = NULL;
    // size_t len = 0;
    // ssize_t read;

    // while (1)
    // {
    //     printf("\n");
    //     print_prompt();

    //     printf("\033[36m");
    //     read = getline(&line, &len, stdin);
    //     if (read == -1)
    //     {
    //         printf("\n");
    //         break;
    //     }
    //     printf(RESET);
    //     fflush(stdout);

    //     process_cmd(line);
    // }

    exit(EXIT_SUCCESS);
}
