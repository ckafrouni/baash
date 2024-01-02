#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colorize.h"
#include "cmd_processor.h"
#include "cmd_executor.h"

void process_cmd(char *line)
{
    if (line[0] == '\n')
        return;

    // collect arguments
    char *args[1024];
    int i = 0;
    char *token = strtok(line, " \n");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    execute_cmd(args);
}
