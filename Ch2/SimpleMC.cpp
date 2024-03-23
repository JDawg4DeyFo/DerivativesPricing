#include <cmath>
#include "./SimpleMC.h"
#include "../Common/Random1.h"

#ifndef _MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo2(const PayOff & ThePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths) {
    double Variance = Vol * Vol * Expiry;
    double RootVariance = sqrt(Variance);
    double ItoCorrection = -0.5 * Variance;

    double MovedSpot = Spot * exp(r * Expiry + ItoCorrection);
    double ThisSpot;
    double RunningSum = 0;

    // Law of large nums loop
    for (unsigned long i = 0; i < NumberOfPaths; i++) {
        double ThisGaussian = GetOneGaussianByBoxMuller();
        ThisSpot = MovedSpot*exp(RootVariance * ThisGaussian);
        double ThisPayOff = ThePayOff(ThisSpot);
        RunningSum += ThisPayOff;
    }

    // get dat mean
    double mean = RunningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);

    return mean;
}