#include <systemc.h>

#ifndef EA_DRIVER_H
#define EA_DRIVER_H

#define INDIVIDUAL_SIZE 9

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Driver) {
    // Ports
    sc_out<bool> read; // Signal to trigger reading input
    sc_out<bool> reset; // Signal to reset the algorithm
    sc_out<bool> initialize; // Signal to initialize the algorithm
    sc_out<bool> start_iteration; // Signal to start each iteration
    sc_out<sc_uint<8>> fitness_output; // Output fitness value
    sc_out<bool> solution_output[INDIVIDUAL_SIZE]; // Output solution vector

    // Events
    sc_event initialization_done;

    // Methods
    void generate_input();

    // Constructor
    SC_CTOR(Driver) {
        SC_THREAD(generate_input);
    }
};

#endif // EA_DRIVER_H
