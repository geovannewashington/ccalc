#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

#include "ccalc/input.h"

// -- Internal Helpers

static char *
skip_spaces(char *s)
{
    while (isspace((unsigned char)*s)) {
        s++;
    }
    return s;
}

static int
only_trailing_whitespace(const char *s)
{
    while (*s) {
        if (!isspace((unsigned char)*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

// -- Public API

int
read_int(const char *prompt, int *out)
{
    char buf[64];
    char *end;
    long value;

    fputs(prompt, stdout);

    if (!fgets(buf, sizeof buf, stdin)) {
        return 0;
    }

    char *start = skip_spaces(buf);

    errno = 0;
    value = strtol(start, &end, 10);

    if (errno != 0 || start == end) {
        return 0;
    }

    if (!only_trailing_whitespace(end)) {
        return 0;
    }

    if (value < INT_MIN || value > INT_MAX) {
        return 0;
    }

    *out = (int)value;
    return 1;
}

int
read_float(const char *prompt, float *out)
{
    char buf[64];
    char *end;
    float value;

    fputs(prompt, stdout);

    if (!fgets(buf, sizeof buf, stdin)) {
        return 0;
    }

    char *start = skip_spaces(buf);

    errno = 0;
    value = strtof(start, &end);

    if (errno != 0 || start == end) {
        return 0;
    }

    if (!only_trailing_whitespace(end)) {
        return 0;
    }

    *out = value;
    return 1;
}
