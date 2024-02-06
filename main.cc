#include <systemc>
#include "ea.h"
#include "monitor.h"
#include "driver.h"

int sc_main(int argc, char* argv[]) {
    // Signals
    sc_signal<sc_uint<8>> v;
    sc_signal<sc_uint<8>> w;
    sc_signal<sc_uint<8>> W;
    sc_signal<sc_uint<8>> n;
    sc_signal<bool> x;
    sc_signal<sc_uint<8>> f;
    sc_signal<bool> read;
    sc_signal<bool> done;

    // Create instances
    driver d("driver");
    d.v(v);
    d.w(w);
    d.W(W);
    d.n(n);
    d.x(x);
    d.f(f);
    d.read(read);
    d.done(done);

    EvolutionaryAlgorithm ea("evolutionary_algorithm");
    ea.v(v);
    ea.w(w);
    ea.W(W);
    ea.n(n);
    ea.x(x);
    ea.f(f);
    ea.read(read);
    ea.done(done);

    Monitor m("monitor");
    m.x(x);
    m.f(f);
    m.done(done);

    // Start simulation
    sc_start(200, sc_core::SC_NS);

    return 0;
}
