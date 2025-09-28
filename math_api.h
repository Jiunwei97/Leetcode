#ifndef MATH_API_H   // If MATH_API_H is not defined
#define MATH_API_H   // Define it to prevent multiple inclusion

// Function prototype
static inline int compfunc(const void*a, const void*b){
    return (*(int*)a- *(int*)b);
}

// Macro definition
#define PI 3.14159
#define MAX(a, b) (a > b ? a : b)

// Structure definition
// typedef struct {
//     int x;
//     int y;
// } Point;
#endif // MATH_API_H