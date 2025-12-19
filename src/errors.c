#include <stdio.h>
#include <stdlib.h>

#include "ccalc/errors.h"
#include "ccalc/colors.h"

int
fatal(const char *msg)
{
    fprintf(stderr, "%s%s%s\n", COLOR_RED, msg, COLOR_RESET);
    return EXIT_FAILURE;
}
