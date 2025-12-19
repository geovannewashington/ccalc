#ifndef CCALC_ARGS_H
#define CCALC_ARGS_H

// Result of argument parsing
typedef struct {
    int show_banner;   // 1 = show banner, 0 = don't show 
    int has_operation; // 1 = operation was passed via CLI
    int operation;     // operation index
} Args;

int parse_args(int argc, char **argv, Args *out);

#endif /* CCALC_ARGS_H */
