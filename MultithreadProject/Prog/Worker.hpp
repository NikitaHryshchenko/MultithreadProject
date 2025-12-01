#ifndef WORKER_HPP
#define WORKER_HPP

#include <string>
#include <fstream>
#include <chrono>
#include "DataStruct.hpp"

long long run_file(DataStruct& d, const std::string& name) {
    std::ifstream f(name);
    auto start = std::chrono::high_resolution_clock::now();
    std::string op;
    while (f >> op) {
        if (op == "write") {
            int i, v;
            f >> i >> v;
            d.set(i, v);
        }
        else if (op == "read") {
            int i;
            f >> i;
            d.get(i);
        }
        else if (op == "string") {
            std::string t = (std::string)d;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

#endif
