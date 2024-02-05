#include <systemc.h>
#include <iostream>

#ifndef EA_MONITOR_H
#define EA_MONITOR_H

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Monitor) {
    // Ports
    sc_in<bool> done; // Indicates when the algorithm is done
    sc_in<sc_uint<8>> best_fitness; // Best fitness value
    sc_in<bool> best_solution[INDIVIDUAL_SIZE]; // Best solution vector


    // Method to display the best solution
    void display_result();

    // Constructor
    SC_CTOR(Monitor) {
        SC_METHOD(display_result);
        sensitive << done;
    }
};

#endif // EA_MONITOR_H
