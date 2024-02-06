#include <systemc>
#include <iostream>
#include <cmath>

#ifndef EA_EA_H
#define EA_EA_H

#define MAX_GENERATIONS 100
#define POPULATION_SIZE 50
#define MUTATION_RATE 0.1
#define INDIVIDUAL_SIZE 9 // Size of each individual in the population

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(EvolutionaryAlgorithm) {
    // Ports
    sc_in<sc_uint<8>> v; // value serial input
    sc_in<sc_uint<8>> w; // weight serial input
    sc_in<sc_uint<8>> W; // maximum weight
    sc_in<sc_uint<8>> n; // number of items
    sc_out<bool> x; // best solution serial output
    sc_out<sc_uint<8>> f; // objective function value
    // Synchronization ports
    sc_in<bool> read; // Read input on each rising edge
    sc_out<bool> done; // Pulse when done

    // Internal signals
    bool population[POPULATION_SIZE][INDIVIDUAL_SIZE]; // Population array
    bool offspring[POPULATION_SIZE][INDIVIDUAL_SIZE];  // Offspring array
    sc_uint<8> fitness[POPULATION_SIZE];               // Fitness array
    bool best_solution[INDIVIDUAL_SIZE];               // Best solution array

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
    sc_uint<16> calculate_fitness(bool x[]);
    void crossover();
    void mutate();
    void iterate();
    void write_output();

    // Constructor
    SC_CTOR(EvolutionaryAlgorithm) {
        SC_THREAD(read_input);
        sensitive << read.pos();
        SC_METHOD(reset);
        sensitive << input_done;
        SC_METHOD(initialize);
        sensitive << reset_done;
        SC_METHOD(iterate);
        sensitive << initialization_done;
        SC_THREAD(write_output);
    }
};

#endif // EA_H
