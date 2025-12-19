#include <stdio.h>

#include "ccalc/colors.h"
#include "ccalc/banner.h"

void 
print_banner(void)
{
    printf(
        "%s" 
        " ▗▄▄▖ ▗▄▄▖ ▗▄▖ ▗▖    ▗▄▄▖ \n"
        "▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌    \n"
        "▐▌   ▐▌   ▐▛▀▜▌▐▌   ▐▌    \n"
        "▝▚▄▄▖▝▚▄▄▖▐▌ ▐▌▐▙▄▄▖▝▚▄▄▖ \n"
        "                          \n"
        "%s\n", 
        COLOR_GREEN, 
        COLOR_RESET
    );
}

