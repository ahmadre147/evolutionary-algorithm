#include <systemc>

#ifndef EA_EA_H
#define EA_EA_H

#define MAX_GENERATIONS 100
#define POPULATION_SIZE 50

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(EvolutionaryAlgorithm) {
    // Ports
    sc_in<sc_uint<8>> fitness_input; // Fitness serial input
    sc_out<bool> solution_output; // Best solution serial output
    // Synchronization ports
    sc_in<bool> read; // Read input on each rising edge
    sc_out<bool> done; // Pulse when done

    // Internal signals
    sc_uint<8> fitness[MAX_GENERATIONS]; // Fitness array
    bool solution[MAX_GENERATIONS]; // Best solution array

    // Events
    sc_event iteration_done;
    sc_event reset_done;
    sc_event input_done;
    sc_event initialization_done;

    // Methods
    void read_input();
    void initialize();
    void generate_initial_population();
    void update_best_solution();
    void reset();
    sc_uint<16> calculate_fitness(bool solution[]);
    void crossover();
    void mutate();
    void iterate();
    void write_output();

    // Constructor
    SC_CTOR(EvolutionaryAlgorithm) {
        SC_THREAD(read_input);
        sensitive << read.pos();
        SC_METHOD(reset);
        sensitive << data_ready;
        SC_METHOD(initialize);
        sensitive << reset_done;
        SC_METHOD(iterate);
        sensitive << init_done;
        SC_THREAD(write_output);
    }
};

#endif // EA_EA_H
