#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "colorize.h"
#include "prompt.h"
#include "project.h"

void print_welcome_msg(void)
{
    printf("/**\n");
    printf(" * " YELLOW(BOLD("Baash")) " " BOLD("shell ") "\n");
    printf(" * " MAGENTA(BOLD("v%s")) "\n", VERSION);
    printf(" * \n");
    printf(" * " BOLD(AUTHOR) "\n");
    printf(" */\n");
}

void print_prompt(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    char *dirname = strrchr(cwd, '/');

    if (dirname != NULL)
        printf(MAGENTA(BOLD("%s")), dirname + 1);
    else
        printf(MAGENTA(BOLD("%s")), cwd);

    // Add PROMPT
    printf(YELLOW(BOLD(PROMPT)));
}
