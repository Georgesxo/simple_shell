#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define FMODE S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH

#define FFLAG O_CREAT|O_WRONLY|O_TRUNC


int portion_argv(const char *str, const char *dilim, char ***argvp);

void freeargv(char **argv);

char *get_fpath(char *comand);

int spawn(char *comand, char **args);

void h_pipe(char *comands);

void exedir(char s, int ini, int outi);

int padiri(char *comand);

int padiro(char *comand);

void change_dir(char **args);

void exit_prog(void);

void alias(char **args);

char *itoa(int val, char *str, int bas);

#endif
