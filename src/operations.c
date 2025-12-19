#include <errno.h>
#include <math.h>

#include "ccalc/operations.h"

/* --- math operations --- */

static float
add(float lhs, float rhs)
{
    return lhs + rhs;
}

static float
subtract(float lhs, float rhs)
{
    return lhs - rhs;
}

static float
multiply(float lhs, float rhs)
{
    return lhs * rhs;
}

static float
divide(float lhs, float rhs)
{
    if (rhs == 0.0f) {
        errno = EDOM;
        return NAN;
    }
    return lhs / rhs;
}

/* --- public table --- */

const Operation operations[] = {
    { "addition",       add },
    { "subtraction",    subtract },
    { "multiplication", multiply },
    { "division",       divide },
};

const size_t NUM_OPERATIONS = sizeof(operations) / sizeof(operations[0]);
