#include<iostream>
#include "monitor.h"

using namespace std;

void monitor::monita() {
    while (true) {
        wait();
        wait(2, SC_NS);
        while (done.read()) {
            cout << x.read() << " ";
            wait(2, SC_NS);
        }
        cout << endl << "f = " << f.read() << endl;
    }
}
