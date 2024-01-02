#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "colorize.h"
#include "prompt.h"

void prompt(char *buf, size_t size)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    char *dirname = strrchr(cwd, '/');

    if (dirname != NULL)
        snprintf(buf, size, MAGENTA(BOLD("%s")), dirname + 1);
    else
        snprintf(buf, size, MAGENTA(BOLD("%s")), cwd);

    // Add PROMPT
    strncat(buf, YELLOW(BOLD(PROMPT)), size - strlen(buf) - 1);
}
