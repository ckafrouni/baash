#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colorize.h"

#define RESET "\033[0m"

// Function to map format specifiers to ANSI codes
const char *getAnsiCode(const char *format)
{
    if (strcmp(format, "B") == 0)
        return "\033[1m";
    if (strcmp(format, "U") == 0)
        return "\033[4m";
    if (strcmp(format, "MA") == 0)
        return "\033[35m"; // Magenta
    // Add more format specifiers as needed
    return "";
}

// Main function to process the input string
char *formatString(const char *input)
{
    char *output = malloc(1000 * sizeof(char)); // Allocate memory for the output string
    if (output == NULL)
        return NULL; // Check for allocation failure

    output[0] = '\0'; // Initialize the output string

    const char *token;
    char *inputCopy = strdup(input); // Duplicate the input string for tokenizing
    char *rest = inputCopy;

    while ((token = strtok_r(rest, "{};", &rest)))
    {
        if (token[0] == 'B' || token[0] == 'U' || strncmp(token, "MA", 2) == 0)
        {                                       // Check for formatting codes
            strcat(output, getAnsiCode(token)); // Append the ANSI code
        }
        else
        {
            strcat(output, token); // Append the text
        }
    }

    strcat(output, "\033[0m"); // Reset formatting at the end

    free(inputCopy); // Free the duplicated string
    return output;
}

// {bold;mag;bg_black:Bush} {B:- Barelly Usable Shell}
void print_colored(char *formatted_str)
{
    char *formatted = formatString(formatted_str);
    printf("%s", formatted);
    free(formatted);
}
