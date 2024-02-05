#include "driver.h"

void Driver::generate_input() {
        while (true) {
            wait();
            // Set your item values, weights, and knapsack capacity
            v.write(6); w.write(2); W.write(20);
            wait();
            // Set other items or change values as needed
            // Item 2
            v.write(5); w.write(3);
            wait();
            // Item 3
            v.write(8); w.write(6);
            wait();
            // Item 4
            v.write(9); w.write(7);
            wait();
            // Item 5
            v.write(6); w.write(5);
            wait();
            // Item 6
            v.write(7); w.write(9);
            wait();
            // Item 7
            v.write(3); w.write(3);
            wait();
            // Item 8
            v.write(6); w.write(4);
            wait();
            // Item 9
            v.write(8); w.write(5);
            wait();

            // Notify the EA that data is ready
            read.write(true);
            // Wait for a response
            wait(done.posedge_event());
            read.write(false);
        }
    }
