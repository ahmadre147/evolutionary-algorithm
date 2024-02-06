#include "ea.h"

/**
 * This methods loads specific values into the memory.
 * So it can be implemented in HARDWARE
*/
void EvolutionaryAlgorithm::reset() {
    // Reset fitness and solution arrays
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        fitness[i] = 0;
        for (unsigned int j = 0; j < INDIVIDUAL_SIZE; j++) {
            population[i][j] = false;
        }
    }
    reset_done.notify();
}

/**
 * Copies the current solution to the best solution vector
 * It just copies some block of memory so it can be implemented in HARDWARE
*/
void EvolutionaryAlgorithm::update_best_solution() {
    // Find the index of the individual with the highest fitness
    unsigned int best_index = 0;
    for (unsigned int i = 1; i < POPULATION_SIZE; i++) {
        if (fitness[i] > fitness[best_index]) {
            best_index = i;
        }
    }

    // Update the best solution array
    for (unsigned int i = 0; i < INDIVIDUAL_SIZE; i++) {
        best_solution[i] = population[best_index][i];
    }
}

/**
 * this method copies a block of memory onto another
 * so it can be implemented in hardware
*/
void EvolutionaryAlgorithm::crossover() {
    // Perform crossover operation
    // For simplicity, we'll use single-point crossover for demonstration purposes
    unsigned int crossover_point = rand() % INDIVIDUAL_SIZE;
    for (unsigned int i = crossover_point; i < INDIVIDUAL_SIZE; i++) {
        offspring[0][i] = population[0][i];
        offspring[1][i] = population[1][i];
    }
}
