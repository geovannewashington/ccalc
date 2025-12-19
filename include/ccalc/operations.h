#ifndef CCALC_OPERATIONS_H
#define CCALC_OPERATIONS_H

#include <stddef.h>

// Function pointer type for binary operations
typedef float (*binary_op_fn)(float, float);

typedef struct {
    const char   *name;
    binary_op_fn fn;
} Operation;

// Public operations table
extern const Operation operations[];
extern const size_t NUM_OPERATIONS;

#endif /* CCALC_OPERATIONS_H */
