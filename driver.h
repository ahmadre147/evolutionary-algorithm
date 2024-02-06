#include <systemc.h>

SC_MODULE(driver){
    // Ports
    sc_out<sc_uint<8>> v; // value serial input
    sc_out<sc_uint<8>> w; // weight serial input
    sc_out<sc_uint<8>> W; // maximum weight
    sc_out<sc_uint<8>> n; // number of items
    sc_in<bool> x; // best solution serial output
    sc_in<sc_uint<8>> f; // objective function value
    // Synchronization ports
    sc_out<bool> read;
    sc_in<bool> done;
	
	void drive(void);

	SC_CTOR(driver){
		SC_THREAD(drive)
	}
};
