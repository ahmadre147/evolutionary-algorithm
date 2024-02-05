#include "driver.h"

void Driver::generate_input() {
    // Example data for the knapsack problem
    sc_uint<8> fitness_values[4] = {30, 25, 35, 40};
    bool solutions[4][INDIVIDUAL_SIZE] = {
        {1, 1, 0, 0, 1, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 1, 1}
    };

    wait(5, SC_NS); // Initial delay

    // Send data to the algorithm
    reset.write(true);
    read.write(false);
    initialize.write(false);
    start_iteration.write(false);
    wait(2, SC_NS);

    reset.write(false);
    wait(1, SC_NS);

    // Send fitness values and solutions
    for (int i = 0; i < 4; ++i) {
        fitness_output.write(fitness_values[i]);
        for (int j = 0; j < INDIVIDUAL_SIZE; ++j) {
            solution_output[j].write(solutions[i][j]);
        }

        start_iteration.write(true);
        wait(2, SC_NS);

        start_iteration.write(false);
        wait(1, SC_NS);
    }

    initialization_done.notify(); // Notify that initialization is done
}
