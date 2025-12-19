#ifndef CCALC_INPUT_H
#define CCALC_INPUT_H

/* Reads an integer from stdin.
 * Returns 1 on success, 0 on failure.
 */
int read_int(const char *prompt, int *out);

/* Reads a float from stdin.
 * Returns 1 on success, 0 on failure.
 */
int read_float(const char *prompt, float *out);

#endif /* CCALC_INPUT_H */
