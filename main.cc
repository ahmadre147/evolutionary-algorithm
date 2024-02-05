#include <systemc>
#include "driver.h"
#include "ea.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<8>> fitness_input;
    sc_signal<bool> read, done;
    sc_signal<bool> solution_output[INDIVIDUAL_SIZE];

    Driver driver("driver");
    driver.fitness_output(fitness_input);
    driver.read(read);
    driver.done(done);
    for (int i = 0; i < INDIVIDUAL_SIZE; ++i) {
        driver.solution_output[i](solution_output[i]);
    }

    EvolutionaryAlgorithm ea("ea");
    ea.fitness_input(fitness_input);
    ea.read(read);
    ea.done(done);
    for (int i = 0; i < INDIVIDUAL_SIZE; ++i) {
        ea.solution_output[i](solution_output[i]);
    }

    Monitor monitor("monitor");
    monitor.fitness_input(fitness_input);
    monitor.solution_output(solution_output);

    sc_start();

    return 0;
}
