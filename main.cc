#include <systemc>
#include "ea.h"
#include "monitor.h"
#include "driver.h"

int sc_main(int argc, char* argv[]) {
    // Signals
    sc_signal<sc_uint<8>> v;
    sc_signal<sc_uint<8>> w;
    sc_signal<sc_uint<8>> W;
    sc_signal<bool> x;
    sc_signal<sc_uint<8>> f;
    sc_signal<bool> read;
    sc_signal<bool> done;

    // Create instances
    Driver driver("driver");
    driver.v(v);
    driver.w(w);
    driver.W(W);
    driver.x(x);
    driver.f(f);
    driver.read(read);
    driver.done(done);

    EvolutionaryAlgorithm ea("evolutionary_algorithm");
    ea.fitness_input(f);
    ea.solution_output(x);
    ea.read(read);
    ea.done(done);

    Monitor monitor("monitor");
    monitor.f(f);
    monitor.x(x);
    monitor.done(done);

    // Start simulation
    sc_start(200, sc_core::SC_NS);

    return 0;
}
