#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "./PayOff1.h"

double SimpleMonteCarlo2(const PayOff & ThePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberofPaths);
#endif