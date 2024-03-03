#include <iostream>
#include <random>

double PayOff (double AssetValue) {
    return 0;
}

int main() {
    int i;
    // Constants
    double RiskFreeReturn, ExpiryDate, InitialPrice, Sigma, Iterations;
    // Iteration variables.
    double CurrentIteration, IterativeValue;
    int RandomNum;


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


    // Main iteration
    for (i = 1, IterativeValue = 0; i <= Iterations; i++) {
        // Choose Random (0,1)
        RandomNum = dist(gen);

        // Calculate x of f(x)

        // f(x)
        IterativeValue += PayOff(CurrentIteration);
    }

    return 0;
}