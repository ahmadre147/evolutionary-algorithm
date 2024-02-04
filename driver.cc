#include "driver.h"

void driver::drive() {
    auto vv = std::vector<sc_uint<8>>{ 5, 6, 7, 9 };
    auto wv = std::vector<sc_uint<8>>{ 1, 2, 1, 4 };
    auto count = vv.size();
    auto max_weight = 5;

    n.write(count);
    W.write(max_weight);
    read.write(true);
    wait(2, SC_NS);
    read.write(false);
    wait(2, SC_NS);

    for (unsigned int i = 0; i < count; i++) {
        v.write(vv[i]);
        w.write(wv[i]);
        read.write(true);
        wait(2, SC_NS);
        read.write(false);
        wait(2, SC_NS);
    }
}
