#include <stdlib.h>

#ifdef __unix__ 
#include <unistd.h>
#endif

int colors_enabled = 1;

void
disable_colors_if_needed()
{
    if (getenv("NO_COLOR")) {
        colors_enabled = 0;
        return;
    }

#ifdef __unix__ 
    // Disable colors when stdout is not a TTY
    if (!isatty(STDOUT_FILENO)) {
        colors_enabled = 0;
    }
#endif
}
