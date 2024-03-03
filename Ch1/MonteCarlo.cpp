#include <iostream>

int main() {
    float RiskFreeReturn, ExpiryDate, InitialPrice, Sigma;

    // Ask user for constant values
    std::cout << "Please provide a risk free return rate: " << std::endl;
    // Check if value is of correct type
    if(!(std::cin >> RiskFreeReturn)) {
        std::cout << "Invalid input. Exiting Program" << std::endl;
        return 0;
    }

    std::cout << "Please provide an expiry date: " << std::endl;
    if(!(std::cin >> ExpiryDate)) {
        std::cout << "Invalid input. Exiting Program" << std::endl;
        return 0;
    }

    std::cout << "Please provide an initial price: " << std::endl;
    if(!(std::cin >> InitialPrice)) {
        std::cout << "Invalid input. Exiting Program" << std::endl;
        return 0;
    }

    std::cout << "Please provide a sigma: " << std::endl;
    if(!(std::cin >> Sigma)) {
        std::cout << "Invalid input. Exiting Program" << std::endl;
        return 0;
    }

    return 0;
}