#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Project headers
#include "ccalc/colors.h"
#include "ccalc/banner.h"
#include "ccalc/input.h"
#include "ccalc/operations.h"
#include "ccalc/output.h"
#include "ccalc/args.h"
#include "ccalc/errors.h"

int
main(int argc, char **argv)
{
    disable_colors_if_needed();

    Args args;
    if (!parse_args(argc, argv, &args)) {
        return fatal("Invalid command-line arguments");
    }

    if (args.show_banner) {
        print_banner();
    }

    int   op_index;
    float lhs;
    float rhs;

    if (args.has_operation) {
        op_index = args.operation;
        printf(
            "%sOperation selected: %s%s\n\n",
            COLOR_CYAN,
            operations[op_index].name,
            COLOR_RESET
        );
    } else {
        print_menu();
        if (!read_int("Operation: ", &op_index)) {
            return fatal("Invalid operation input");
        }
    }

    if (op_index < 0 || (size_t)op_index >= NUM_OPERATIONS) {
        return fatal("Operation out of range");
    }

    if (!read_float("First number: ", &lhs) ||
        !read_float("Second number: ", &rhs)) {
        return fatal("Invalid numeric input");
    }

    errno = 0;
    float result = operations[op_index].fn(lhs, rhs);

    if (errno != 0) {
        return fatal("Math error occurred");
    }

    print_result(result);
    return EXIT_SUCCESS;
}
