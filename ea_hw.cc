#include "ea.h"

void EvolutionaryAlgorithm::read_input() {
    while (true) {
        wait();
        for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
            wait();
            fitness[i] = fitness_input.read();
        }
        input_done.notify();
    }
}

void EvolutionaryAlgorithm::initialize() {
    // Initialize best_solution array
    for (unsigned int i = 0; i < INDIVIDUAL_SIZE; i++) {
        best_solution[i] = false;
    }

    generate_initial_population();
    initialization_done.notify();
}

void EvolutionaryAlgorithm::generate_initial_population() {
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        // Generate a random initial solution for each individual in the population
        for (unsigned int j = 0; j < INDIVIDUAL_SIZE; j++) {
            population[i][j] = (rand() % 2 == 0);
        }
    }
}

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

void EvolutionaryAlgorithm::write_output() {
    while (true) {
        wait();
        done.write(true);
        solution_output.write(population[0]);  // Output the best solution for simplicity
        wait(); // Adjust timing based on your requirements
        done.write(false);
    }
}
