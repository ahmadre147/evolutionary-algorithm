#include<iostream>
#include "monitor.h"

using namespace std;

void Monitor::monitor_output() {
        while (true) {
            wait(done.posedge_event());
            // Output solution and fitness
            std::cout << "Solution: ";
            print_solution();
            std::cout << "Fitness: " << f.read() << std::endl;
        }
    }

void Monitor::print_solution() {
        for (int i = 0; i < 9; ++i) {
            std::cout << x.read() << " ";
        }
        std::cout << std::endl;
    }
