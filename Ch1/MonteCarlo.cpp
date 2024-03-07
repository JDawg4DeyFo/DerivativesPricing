#include <iostream>
#include <cmath>
#include <random>


int main() {
	int i;
	// Constants
	double RiskFreeReturn, ExpiryDate, InitialPrice, Sigma, Iterations;
	// Iteration variables.
	double CurrentIteration, IterativeValue, RandomNum;
	double DebugVariable;


	// Seed RNG
	std::random_device rd;
	std::mt19937 gen(rd());
	// Define normal distribution
	std::normal_distribution<double> dist(0.0, 1.0);


	// Ask user for constant values
	std::cout << "Please provide a risk free return rate: ";
	if(!(std::cin >> RiskFreeReturn)) {
		std::cout << "Invalid input. Exiting Program" << std::endl;
		return 0;
	}
	// Expiry date
	std::cout << std::endl;
	std::cout << "Please provide an expiry date: ";
	if(!(std::cin >> ExpiryDate)) {
		std::cout << "Invalid input. Exiting Program" << std::endl;
		return 0;
	}
	// Initial Price
	std::cout << std::endl;
	std::cout << "Please provide an initial price: ";
	if(!(std::cin >> InitialPrice)) {
		std::cout << "Invalid input. Exiting Program" << std::endl;
		return 0;
	}
	// Sigma?? don't know what this should be
	std::cout << std::endl;
	std::cout << "Please provide a sigma: ";
	if(!(std::cin >> Sigma)) {
		std::cout << "Invalid input. Exiting Program" << std::endl;
		return 0;
	}
	// Iterations
	std::cout << "Please speicfy the number of iterations: ";
	if (!(std::cin >> Iterations)) {
		std::cout << "Invalid input. Exiting Program" << std::endl;
		return 0;
	}
	std::cout << std::endl;
	
	// Debugging
	RandomNum = dist(gen);
	std::cout << "RandomNum for debug: " << RandomNum << std::endl;
	DebugVariable = sqrt(ExpiryDate);
	std::cout << "DebugVariable: " << DebugVariable << std::endl;
	DebugVariable = (Sigma * sqrt(ExpiryDate) * RandomNum);
	std::cout << "DebugVariable sigma sqrtexpiry random: " << DebugVariable << std::endl;
	DebugVariable = ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2));
	std::cout << "DebugVariable expiry risk pow sigma 2: " << DebugVariable << std::endl;
	DebugVariable =	InitialPrice * exp((ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2))) + (Sigma * sqrt(ExpiryDate) * RandomNum));
	std::cout << "Iteration equivalent debug: " << DebugVariable << std::endl;
			
	// Main iteration
	for (i = 1, IterativeValue = 0; i <= Iterations; i++) {
		// Choose Random (0,1)
		RandomNum = dist(gen);
		// Calculate f(x)
		CurrentIteration = InitialPrice * exp((ExpiryDate * (RiskFreeReturn - .5 * pow(Sigma, 2))) + (Sigma * sqrt(ExpiryDate) * RandomNum));

		if (CurrentIteration > 0) {
	IterativeValue += CurrentIteration;
	}
	}

	// Multiply result by exp(-rT)/N
	IterativeValue /= Iterations;
	IterativeValue *= exp(-RiskFreeReturn * ExpiryDate);
	std::cout << "Calculated Value: " << IterativeValue << std::endl;
	return 0;
}
