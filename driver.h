#include <systemc.h>
#include "ea.h"

SC_MODULE(driver) {
    // Ports for the evolutionary algorithm
    sc_out<sc_uint<8>> v;
    sc_out<sc_uint<8>> w;
    sc_out<sc_uint<8>> W;
    sc_out<sc_uint<8>> n;
    sc_in<bool> x;
    sc_in<sc_uint<8>> f;
    sc_out<bool> read;
    sc_in<bool> done;

    void drive();

    SC_CTOR(driver) {
        SC_THREAD(drive);
    }
};
