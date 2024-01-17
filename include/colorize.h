#ifndef __COLORIZE_H__
#define __COLORIZE_H__

#define RESET "\033[0m"

#define BLACK(str) "\033[30m" str RESET
#define RED(str) "\033[31m" str RESET
#define GREEN(str) "\033[32m" str RESET
#define YELLOW(str) "\033[33m" str RESET
#define BLUE(str) "\033[34m" str RESET
#define MAGENTA(str) "\033[35m" str RESET
#define CYAN(str) "\033[36m" str RESET
#define WHITE(str) "\033[37m" str RESET

#define BG_BLACK(str) "\033[40m" str RESET
#define BG_RED(str) "\033[41m" str RESET
#define BG_GREEN(str) "\033[42m" str RESET
#define BG_YELLOW(str) "\033[43m" str RESET
#define BG_BLUE(str) "\033[44m" str RESET
#define BG_MAGENTA(str) "\033[45m" str RESET
#define BG_CYAN(str) "\033[46m" str RESET
#define BG_WHITE(str) "\033[47m" str RESET

#define BOLD(str) "\033[1m" str RESET
#define UNDERLINE(str) "\033[4m" str RESET

#define CLEAR "\033[2J"
#define CURSOR_TO_ORIGIN "\033[H"

/**
 * @brief Prints a Colorized string based on a custom format
 *
 * @example
 * `{MB:Bush} {B:- Barelly Usable Shell}` -> `MAGENTA(BOLD("Bush")) BOLD("- Barelly Usable Shell")`
 *
 * @param formatted_str The string to be formatted
 */
void print_colored(char *formatted_str);

#endif // __COLORIZE_H__
