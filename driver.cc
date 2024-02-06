#include "driver.h"

void driver::drive(void) {
    auto vv = std::vector<sc_uint<8>>{ 6, 5, 8, 9, 6, 7, 3, 6, 8 };
    auto wv = std::vector<sc_uint<8>>{ 2, 3, 6, 7, 5, 9, 3, 4, 5 };
    auto count = vv.size();
    auto max_weight = 9;

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
