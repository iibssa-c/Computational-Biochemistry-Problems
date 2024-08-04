#include <iostream>
#include <vector>
#include <fstream>

// Calculate reaction rate using Michaelis-Menten equation
double calculateRateofReaction(double vmax, double substrateConcen, double km){ 
    return (vmax * substrateConcen) / (km * substrateConcen); 
}   

std::vector<double> simulateReaction(double initialConcen, double vmax, const double km, double dt, double timePassed){
    std::vector<double> substrateConcenOverTime = {}; // Vector to store the changing concentration overtime 
    double substrate = initialConcen; // Declaring of initial concentraiton of the substrate
    double reactionTime = 0.0; // Start of the reaction 

    // While loop that will calculate the rate of the reaction     
    while (reactionTime <= timePassed) {
        double rateOfReaction = calculateRateofReaction(vmax, km, substrate); 
        substrate -= rateOfReaction * dt; 
        if(substrate < 0) { 
            substrate = 0;
            substrateConcenOverTime.push_back(substrate);
        }
    }

    return substrateConcenOverTime; 
}

int main() { 
    double substrateInitial = 10.0; // Initial substrate concentration 
    double vmax = 1.0; // Max reaction rate
    double dt = 0.1; // Time step
    double km = 0.5; // Michaelis Constant
    double timePassed = 10.0; // Total time of simulation 

    // Simulated reaction
    std::vector<double> results = simulateReaction(substrateInitial, vmax, dt, km, timePassed); 

    // Print Results
    std::cout << "The results of the reaction: " << calculateRateofReaction << std::endl;
}


