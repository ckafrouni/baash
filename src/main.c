#include <stdio.h>
#include <stdlib.h>

#include "colorize.h"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf(BOLD(UNDERLINE("argv")) BOLD(BLUE(" = [")) "\n");
        for (int i = 1; i < argc; ++i)
        {
            printf("%*s", 2, " ");
            printf(MAGENTA("%s "), argv[i]);
            if (i != argc - 1)
                printf(GREEN(",") "\n");
            else
                printf("\n");
        }
        printf(BOLD(BLUE("]")) "\n");
    }
    else
    {
        printf("Hello World !\n");
    }

    return EXIT_SUCCESS;
}
