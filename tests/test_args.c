#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "args.h"
#include "operations.h" // NUM_OPERATIONS

int
parse_args(int argc, char **argv, Args *out)
{
    // default values 
    out->show_banner   = 1;
    out->has_operation = 0;
    out->operation     = -1;

    int i = 1;

    if (i < argc && strcmp(argv[i], "--no-banner") == 0) {
        out->show_banner = 0;
        i++;
    }
    
    // Operation via CLI
    if (i < argc) {
        char *end;
        long value;

        errno = 0;
        value = strtol(argv[i], &end, 10);

        if (errno != 0 || *end != '\0') {
            return 0;
        }

        if (value < 0 || value >= (long)NUM_OPERATIONS) {
            return 0;
        }

        out->has_operation = 1;
        out->operation     = (int)value;
        i++;
    }
    
    // Extra arguments not allowed
    if (i < argc) {
        return 0;
    }

    return 1;
}
