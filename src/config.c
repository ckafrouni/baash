#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "toml.h"
#include "config.h"
#include "colorize.h"

void strip_quotes(char *str)
{
    int len = strlen(str);
    if (str[0] == '"' && str[len - 1] == '"')
    {
        str[len - 1] = '\0';
        memmove(str, str + 1, len - 1);
        strip_quotes(str);
    }
}

void strip_newline(char *str)
{
    int len = strlen(str);
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void load_general(toml_table_t *toml, config_t *config)
{
    // Load general table
    toml_table_t *general_table = toml_table_in(toml, "general");
    if (general_table == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find general table in config file\n");
        exit(EXIT_FAILURE);
    }

    const char *name = toml_raw_in(general_table, "name");
    if (name == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find name in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->name, name);
    strip_quotes(config->name);
    strip_newline(config->name);

    const char *version = toml_raw_in(general_table, "version");
    if (version == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find version in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->version, version);
    strip_quotes(config->version);
    strip_newline(config->version);

    const char *author = toml_raw_in(general_table, "author");
    if (author == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find author in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->author, author);
    strip_quotes(config->author);
    strip_newline(config->author);
}

void load_messages(toml_table_t *toml, config_t *config)
{
    // Load message table
    toml_table_t *msg_table = toml_table_in(toml, "messages");
    if (msg_table == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find message table in config file\n");
        exit(EXIT_FAILURE);
    }

    // Load welcome message
    const char *welcome_msg = toml_raw_in(msg_table, "welcome");
    if (welcome_msg == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find welcome_msg in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->welcome_msg, welcome_msg);
    strip_quotes(config->welcome_msg);
    strip_newline(config->welcome_msg);

    // Load exit message
    const char *exit_msg = toml_raw_in(msg_table, "exit");
    if (exit_msg == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find exit_msg in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->exit_msg, exit_msg);
    strip_quotes(config->exit_msg);
    strip_newline(config->exit_msg);

    // Load pre_builtin message
    const char *pre_builtin_msg = toml_raw_in(msg_table, "pre_builtin");
    if (pre_builtin_msg == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find pre_builtin_msg in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->pre_builtin_msg, pre_builtin_msg);
    strip_quotes(config->pre_builtin_msg);
    strip_newline(config->pre_builtin_msg);
}

void load_prompts(toml_table_t *toml, config_t *config)
{
    // Load prompt table
    toml_table_t *prompt_table = toml_table_in(toml, "prompts");
    if (prompt_table == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find prompt table in config file\n");
        exit(EXIT_FAILURE);
    }

    // Load prompt
    const char *prompt = toml_raw_in(prompt_table, "p1");
    if (prompt == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not find prompt in config file\n");
        exit(EXIT_FAILURE);
    }
    strcpy(config->prompt, prompt);
    strip_quotes(config->prompt);
    strip_newline(config->prompt);
}

config_t *load_config(char *config_file)
{
    config_t *config = (config_t *)malloc(sizeof(config_t));

    FILE *fp = fopen(config_file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not open config file: %s\n", config_file);
        exit(EXIT_FAILURE);
    }

    char err[200];
    toml_table_t *toml = toml_parse_file(fp, err, sizeof(err));
    if (toml == NULL)
    {
        fprintf(stderr, RED("ERROR ") "Could not parse config file: %s\n", err);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    load_general(toml, config);
    load_messages(toml, config);
    load_prompts(toml, config);

    return config;
}

void print_config(config_t *config)
{
    printf("Config:\n");

    printf("name: %s\n", config->name);
    printf("version: %s\n", config->version);
    printf("author: %s\n", config->author);
    printf("welcome_msg: %s\n", config->welcome_msg);
    printf("exit_msg: %s\n", config->exit_msg);
    printf("pre_builtin_msg: %s\n", config->pre_builtin_msg);
    printf("prompt: %s\n", config->prompt);
}
