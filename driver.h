#include <systemc>

#ifndef DRIVER_H

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Driver) {
    // Ports
    sc_out<sc_uint<8>> v;  // Item values
    sc_out<sc_uint<8>> w;  // Item weights
    sc_out<sc_uint<8>> W;  // Knapsack capacity
    sc_out<bool> x;        // Solution vector
    sc_out<sc_uint<8>> f;  // Fitness
    sc_out<bool> read;     // Read signal
    sc_out<bool> done;     // Done signal

    // Method to generate input
    void generate_input();

    // Constructor
    SC_CTOR(Driver) {
        SC_THREAD(generate_input);
    }
};

#endif // DRIVER_H
