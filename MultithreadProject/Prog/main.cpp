#include <iostream>
#include <thread>
#include "Worker.hpp"

int main() {
    DataStruct d(3);

    long long t1 = run_file(d, "file_single.txt");
    std::cout << "Single thread: " << t1 << "us\n";

    DataStruct d2(3);
    long long t2, t3;
    std::thread a([&]() { t2 = run_file(d2, "file_t1.txt"); });
    std::thread b([&]() { t3 = run_file(d2, "file_t2.txt"); });
    a.join();
    b.join();
    std::cout << "Two threads: " << t2 + t3 << "us\n";

    DataStruct d3(3);
    long long u1, u2, u3;
    std::thread x([&]() { u1 = run_file(d3, "file_a.txt"); });
    std::thread y([&]() { u2 = run_file(d3, "file_b.txt"); });
    std::thread z([&]() { u3 = run_file(d3, "file_c.txt"); });
    x.join();
    y.join();
    z.join();
    std::cout << "Three threads: " << u1 + u2 + u3 << "us\n";

    return 0;
}
