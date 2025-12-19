#include <stdio.h>
#include <math.h>

#include "ccalc/operations.h" // NUM_OPERATIONS
#include "ccalc/output.h"
#include "ccalc/colors.h"

void 
print_menu(void)
{
    printf("%s------------------%s\n",   COLOR_CYAN, COLOR_RESET);
    printf("%sChoose an operation:%s\n\n", COLOR_CYAN, COLOR_RESET);

    for (size_t i = 0; i < NUM_OPERATIONS; i++) {
        printf("%s%zu - %s%s\n", COLOR_YELLOW, i, operations[i].name, COLOR_RESET);
    }
    
    printf("%s------------------%s\n", COLOR_CYAN, COLOR_RESET);
}

    void
print_result(float value)
{
    if (isnan(value)) {
        printf("%sResult is undefined%s\n", COLOR_RED, COLOR_RESET);
        return;
    }

    float rounded = roundf(value);

    // If value is effectively an integer, print without decimals
    if (fabsf(value - rounded) < 1e-6f) {
        printf("%sResult: %.0f%s\n", COLOR_GREEN, rounded, COLOR_RESET);
        return;
    }

    printf("%sResult: %f%s\n", COLOR_GREEN, value, COLOR_RESET);
}
