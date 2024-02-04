#include <systemc>
#include "driver.h" // Assuming you have a driver for EA
#include "monitor.h" // Assuming you have a monitor for EA
#include "ea.h" // Include your Evolutionary Algorithm module

int sc_main(int argc, char* argv[]) {

    sc_signal<sc_uint<8>> input_signal1;
    sc_signal<sc_uint<8>> input_signal2;
    sc_signal<sc_uint<8>> input_signal3;
    sc_signal<bool> output_signal1;
    sc_signal<sc_uint<8>> output_signal2;
    sc_signal<bool> control_signal1;
    sc_signal<bool> control_signal2;

    driver d("driver");
    d.input_signal1(input_signal1);
    d.input_signal2(input_signal2);
    d.input_signal3(input_signal3);
    d.output_signal1(output_signal1);
    d.output_signal2(output_signal2);
    d.control_signal1(control_signal1);
    d.control_signal2(control_signal2);

    EvolutionaryAlgorithm ea("ea");
    ea.input_signal1(input_signal1);
    ea.input_signal2(input_signal2);
    ea.input_signal3(input_signal3);
    ea.output_signal1(output_signal1);
    ea.output_signal2(output_signal2);
    ea.control_signal1(control_signal1);
    ea.control_signal2(control_signal2);

    monitor m("monitor");
    m.output_signal1(output_signal1);
    m.output_signal2(output_signal2);
    m.control_signal1(control_signal1);
    m.control_signal2(control_signal2);

    sc_start(200, SC_NS);

    return 0; // End
}
