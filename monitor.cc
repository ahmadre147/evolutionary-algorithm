#include<iostream>
#include "monitor.h"

using namespace std;

void monitor::display_result() {
        if (done.read()) {
            std::cout << "Best Fitness: " << best_fitness.read() << std::endl;
            std::cout << "Best Solution: ";
            for (int i = 0; i < INDIVIDUAL_SIZE; ++i) {
                std::cout << best_solution[i].read() << " ";
            }
            std::cout << std::endl;
        }
    }