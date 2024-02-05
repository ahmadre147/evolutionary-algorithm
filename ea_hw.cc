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
    generate_initial_population();
    initialization_done.notify();
}

void EvolutionaryAlgorithm::generate_initial_population() {
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        // Generate a random initial solution for each individual in the population
        solution[i] = (rand() % 2 == 0);
    }
}

void EvolutionaryAlgorithm::reset() {
    // Reset fitness and solution arrays
    for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
        fitness[i] = 0;
        solution[i] = false;
    }
    reset_done.notify();
}

void EvolutionaryAlgorithm::write_output() {
    while (true) {
        wait();
        done.write(true);
        solution_output.write(solution[0]);
        wait(); // Adjust timing based on your requirements
        done.write(false);
    }
}
