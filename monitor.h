#include <systemc.h>

SC_MODULE(monitor) {
    void monita();

    sc_in<bool> x;
    sc_in<sc_uint<8>> f;
    sc_in<bool> done;

    SC_CTOR(monitor) {
        SC_THREAD(monita);
        sensitive << done.pos();
    }
};
