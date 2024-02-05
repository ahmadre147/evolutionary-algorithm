#include "ea.h"

void EvolutionaryAlgorithm::update_best_solution() {
    // Find the index of the individual with the highest fitness
    unsigned int best_index = 0;
    for (unsigned int i = 1; i < POPULATION_SIZE; i++) {
        if (fitness[i] > fitness[best_index]) {
            best_index = i;
        }
    }

    // Update the best solution array
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        solution[i] = (i == best_index);
    }
}

sc_uint<16> EvolutionaryAlgorithm::calculate_fitness(bool solution[]) {
    // Calculate fitness based on the provided solution
    sc_uint<16> fitness_value = 0;
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        if (solution[i]) {
            // Fitness calculation logic (replace with your own fitness function)
            fitness_value += 1;
        }
    }
    return fitness_value;
}

void EvolutionaryAlgorithm::crossover() {
    // Perform crossover operation
    // For simplicity, we'll use single-point crossover for demonstration purposes
    unsigned int crossover_point = rand() % POPULATION_SIZE;
    for (unsigned int i = crossover_point; i < POPULATION_SIZE; i++) {
        solution[i] = solution[i];
    }
}

void EvolutionaryAlgorithm::mutate() {
    // Apply mutation to each dimension of each individual in the offspring
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        for (int j = 0; j < INDIVIDUAL_SIZE; ++j) {
            // Generate Gaussian noise for each dimension
            double gaussian_noise = sc_random() - sc_random(); // N(0,1) - N(0,1)
            
            // Update the standard deviation (sigma) for each dimension
            // This assumes a constant mutation rate for all dimensions
            double sigma_j = MUTATION_RATE * exp(gaussian_noise);

            // Apply mutation to the current dimension
            offspring[i][j] = population[i][j] + sigma_j * (sc_random() - sc_random()); // x_j + sigma_j * N(0,1)
        }
    }
}

void EvolutionaryAlgorithm::iterate() {
    if (!POPULATION_SIZE) return;
    for (unsigned int generation = 0; generation < MAX_GENERATIONS; generation++) {
        // Selection, Crossover, Mutation, and Fitness Evaluation
        crossover();
        mutate();
        fitness[generation] = calculate_fitness(solution);

        // Update the best solution
        update_best_solution();

        // Notify that one iteration is done
        iteration_done.notify();
    }
}
