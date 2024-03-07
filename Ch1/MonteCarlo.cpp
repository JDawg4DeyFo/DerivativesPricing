#include <iostream>
#include <cmath>
#include <random>

#include "../Common/Random1.h"
using namespace std;

int main() {
	int i;
	// Constants
	double RiskFreeReturn, ExpiryDate, InitialPrice, Sigma, Iterations;
	// Iteration variables.
	double CurrentIteration, IterativeValue, RandomNum;
	double DebugVariable;

	// Ask user for constant values
	cout << "Please provide a risk free return rate: ";
	if(!(cin >> RiskFreeReturn)) {
		cout << "Invalid input. Exiting Program" << endl;
		return 0;
	}
	// Expiry date
	cout << endl;
	cout << "Please provide an expiry date: ";
	if(!(cin >> ExpiryDate)) {
		cout << "Invalid input. Exiting Program" << endl;
		return 0;
	}
	// Initial Price
	cout << endl;
	cout << "Please provide an initial price: ";
	if(!(cin >> InitialPrice)) {
		cout << "Invalid input. Exiting Program" << endl;
		return 0;
	}
	// Sigma?? don't know what this should be
	cout << endl;
	cout << "Please provide a sigma: ";
	if(!(cin >> Sigma)) {
		cout << "Invalid input. Exiting Program" << endl;
		return 0;
	}
	// Iterations
	cout << "Please speicfy the number of iterations: ";
	if (!(cin >> Iterations)) {
		cout << "Invalid input. Exiting Program" << endl;
		return 0;
	}
	cout << endl;
	
	// Debugging
	// RandomNum = GetOneGaussianByBoxMuller();
	// cout << "RandomNum for debug: " << RandomNum << endl;
	// DebugVariable = sqrt(ExpiryDate);
	// cout << "DebugVariable: " << DebugVariable << endl;
	// DebugVariable = (Sigma * sqrt(ExpiryDate) * RandomNum);
	// cout << "DebugVariable sigma sqrtexpiry random: " << DebugVariable << endl;
	// DebugVariable = ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2));
	// cout << "DebugVariable expiry risk pow sigma 2: " << DebugVariable << endl;
	// DebugVariable =	InitialPrice * exp((ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2))) + (Sigma * sqrt(ExpiryDate) * RandomNum));
	// cout << "Iteration equivalent debug: " << DebugVariable << endl;
			
	// Main iteration
	for (i = 1, IterativeValue = 0; i <= Iterations; i++) {
		// Choose Random (0,1)
		RandomNum = GetOneGaussianByBoxMuller();
		// Calculate f(x)
		CurrentIteration = InitialPrice * exp((ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2))) + (Sigma * sqrt(ExpiryDate) * RandomNum));

		if (CurrentIteration > 0) {
	IterativeValue += CurrentIteration;
	}
	}

	// Multiply result by exp(-rT)/N
	IterativeValue /= Iterations;
	IterativeValue *= exp(-RiskFreeReturn * ExpiryDate);
	cout << "Calculated Value: " << IterativeValue << endl;
	return 0;
}
