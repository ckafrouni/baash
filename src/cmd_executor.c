#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "colorize.h"
#include "cmd_executor.h"

// list of built-in commands
char *builtin_str[] = {
    "cd",
    "exit",
    "clear",
    "pwd",
};

void execute_builtin(char *args[])
{
    printf(BLACK(BOLD("Baash: ")));

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            fprintf(stderr, RED("USAGE ") "cd <path>\n");
            return;
        }
        if (chdir(args[1]) != 0)
        {
            perror(RED("chdir() error"));
            return;
        }
        printf("Moved to /%s\n", args[1]);
        return;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        printf("Arrivederci!\n");
        exit(EXIT_SUCCESS);
    }

    if (strcmp(args[0], "clear") == 0)
    {
        printf(CLEAR CURSOR_TO_ORIGIN);
        return;
    }

    if (strcmp(args[0], "pwd") == 0)
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL)
        {
            perror("getcwd() error");
            exit(EXIT_FAILURE);
        }
        printf("%s\n", cwd);
        return;
    }

    fprintf(stderr, RED("Not Implemented: ") "%s\n", args[0]);
}

void execute_cmd(char *args[])
{
    if (args[0] == NULL)
    {
        return;
    }

    // check if the command is a built-in command
    // if so, execute it and return
    // otherwise, execute the command using execvp

    for (size_t i = 0; i < sizeof(builtin_str) / sizeof(char *); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            execute_builtin(args);
            return;
        }
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror(RED("fork() error"));
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // child process
        if (execvp(args[0], args) == -1)
        {
            perror(RED("execvp() error"));
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // parent process
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror(RED("waitpid() error"));
            exit(EXIT_FAILURE);
        }
    }
}
