#ifndef CCALC_COLORS_H
#define CCALC_COLORS_H

// Enables / disables ANSI color output 
void disable_colors_if_needed(void);

// ANSI color macros (empty strings if disabled)
extern int colors_enabled;

#define COLOR_RED    (colors_enabled ? "\033[31m" : "")
#define COLOR_GREEN  (colors_enabled ? "\033[32m" : "")
#define COLOR_YELLOW (colors_enabled ? "\033[33m" : "")
#define COLOR_CYAN   (colors_enabled ? "\033[36m" : "")
#define COLOR_RESET  (colors_enabled ? "\033[0m"  : "")

#endif /* CCALC_COLORS_H */
