#include "Random1.h"
#include <cstdlib>
#include <cmath>

// Not sure what this does
#if !defined(_MSC_VER)
using namespace std;
#endif

double GetOneGaussianBySummation() {
    double Result;
    unsigned long j;

    Result = 0;
    // Begin summation
    for (j = 0; j < 12; j++) {
        Result += rand() / static_cast<double>(RAND_MAX);
        Result -= 6.0;
    }

    return Result;
}

double GetOneGaussianByBoxMuller() {
    double Result, x, y;
    double SizeSquared;
    do
    {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;

        SizeSquared = x*x + y*y;
    } while (SizeSquared >= 1.0);

    Result = x * sqrt(-2 * log(SizeSquared) / SizeSquared);
    
    return Result;
}