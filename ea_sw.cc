#include "ea.h"
#include <cmath> // for exp()


/**
 * This function reads inputs from serial ports
 * It needs to wait for IO to be ready
 * So it's implemented on SOFTWARE
*/
void EvolutionaryAlgorithm::read_input() {
    while (true) {
        wait();
        // Read inputs v, w, W, and n for each individual
        for (unsigned int i = 0; i < POPULATION_SIZE; i++) {
            wait();
            for (unsigned int j = 0; j < INDIVIDUAL_SIZE; j++) {
                if (j < n.read()) {
                    population[i][j] = (v.read() / w.read()); // Example logic, modify accordingly
                } else {
                    population[i][j] = 0; // Padding zeros for unused dimensions
                }
            }
        }
        input_done.notify();
    }
}

/**
 * This method calculates the fittness based on a specific method
 * this method could be changed over time so it is better to implement it in SOFTWARE
*/
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

/**
 * Main process of the algorithm
 * It is a sequential process so it can not be parallelized
 * So it is better to implement it in SOFTWARE
*/
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

/**
 * Main process of the algorithm
 * It is a sequential process so it can not be parallelized
 * So it is better to implement it in SOFTWARE
*/
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


/**
* Generate a initial solution based on a simple greedy method
* It needs to store serial input data in a vector in memory
* Also it is pending on the read signal
* Assign to CPU
*/
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

/**
 * This function writes output to serial ports
 * It needs to wait for IO to be ready
 * So it's implemented on SOFTWARE
*/
void EvolutionaryAlgorithm::write_output() {
    while (true) {
        wait();
        done.write(true);
        x.write(population[0]);  // Output the best solution for simplicity
        wait(); // Adjust timing based on your requirements
        done.write(false);
    }
}