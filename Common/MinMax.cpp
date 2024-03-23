#include "./MinMax.h"

double Max(double Val, double Val2) {
    if (Val > Val2) {
        return Val;
    }
    // implicit else
    return Val2;
}

double Min(double Val, double Val2) {
    if (Val > Val2) {
        return Val2;
    }
    return Val;
}