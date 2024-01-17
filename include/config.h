#ifndef __CONFIG_H__
#define __CONFIG_H__

#define TINY_BUF 32
#define SMALL_BUF 256
#define BIG_BUF 1024

typedef struct
{
    char name[TINY_BUF];
    char small_desc[SMALL_BUF];
    char long_desc[BIG_BUF];
    char version[TINY_BUF];
    char author[SMALL_BUF];
    char welcome_msg[SMALL_BUF];
    char pre_builtin_msg[SMALL_BUF];
    char exit_msg[SMALL_BUF];
    char prompt[SMALL_BUF];
} config_t;

config_t *load_config(char *config_file);

void print_config(config_t *config);

#endif // __CONFIG_H__
