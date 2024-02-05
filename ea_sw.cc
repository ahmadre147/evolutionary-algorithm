#include "ea.h"
#include <cmath> // for exp()

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

sc_uint<16> EvolutionaryAlgorithm::calculate_fitness(bool solution[]) {
    // Calculate fitness based on the provided solution
    sc_uint<16> fitness_value = 0;
    for (unsigned int i = 0; i < INDIVIDUAL_SIZE; i++) {
        if (solution[i]) {
            // Fitness calculation logic (replace with your own fitness function)
            fitness_value += 1; // Placeholder, replace with actual fitness function
        }
    }
    return fitness_value;
}

void EvolutionaryAlgorithm::crossover() {
    // Perform crossover operation
    // For simplicity, we'll use single-point crossover for demonstration purposes
    unsigned int crossover_point = rand() % INDIVIDUAL_SIZE;
    for (unsigned int i = crossover_point; i < INDIVIDUAL_SIZE; i++) {
        offspring[0][i] = population[0][i];
        offspring[1][i] = population[1][i];
    }
}

void EvolutionaryAlgorithm::mutate() {
    // Apply mutation to each dimension of each individual in the offspring
    for (unsigned int i = 0; i < POPULATION_SIZE; ++i) {
        for (unsigned int j = 0; j < INDIVIDUAL_SIZE; ++j) {
            // Generate Gaussian noise for each dimension
            double gaussian_noise = rand() % 2 == 0 ? (double)rand() / RAND_MAX : -((double)rand() / RAND_MAX); // N(0,1) - N(0,1)
            
            // Update the standard deviation (sigma) for each dimension
            // This assumes a constant mutation rate for all dimensions
            double sigma_j = MUTATION_RATE * exp(gaussian_noise);

            // Apply mutation to the current dimension
            offspring[i][j] = population[i][j] + sigma_j * (rand() % 2 == 0 ? (double)rand() / RAND_MAX : -((double)rand() / RAND_MAX)); // x_j + sigma_j * N(0,1)
        }
    }
}

void EvolutionaryAlgorithm::iterate() {
    if (!POPULATION_SIZE) return;
    for (unsigned int generation = 0; generation < MAX_GENERATIONS; generation++) {
        // Selection, Crossover, Mutation, and Fitness Evaluation
        crossover();
        mutate();
        fitness[generation] = calculate_fitness(offspring[0]); // Use the first individual for simplicity

        // Update the best solution
        update_best_solution();

        // Notify that one iteration is done
        iteration_done.notify();
    }
}
