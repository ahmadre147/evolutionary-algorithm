#include <systemc>

#ifndef MONITOR_H

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Monitor) {
    // Ports
    sc_in<bool> x;      // Solution vector
    sc_in<sc_uint<8>> f; // Fitness
    sc_in<bool> done;    // Done signal

    // Method to monitor output
    void monitor_output();

    // Method to print the solution vector
    void print_solution();

    // Constructor
    SC_CTOR(Monitor) {
        SC_THREAD(monitor_output);
        sensitive << done;
    }
};

#endif // MONITOR_H
