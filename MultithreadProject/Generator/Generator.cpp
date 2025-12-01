#include <iostream>
#include <fstream>
#include <random>

void gen(const std::string& name, int m, double pr0, double pw0, double pr1, double pw1, double pr2, double pw2, double ps) {
    std::ofstream f(name);
    std::mt19937 g(1);
    std::uniform_real_distribution<double> u(0, 100);

    for (int i = 0; i < 200000; i++) {
        double x = u(g);
        if (x < pr0) f << "read 0\n";
        else if (x < pr0 + pw0) f << "write 0 1\n";
        else if (x < pr0 + pw0 + pr1) f << "read 1\n";
        else if (x < pr0 + pw0 + pr1 + pw1) f << "write 1 1\n";
        else if (x < pr0 + pw0 + pr1 + pw1 + pr2) f << "read 2\n";
        else if (x < pr0 + pw0 + pr1 + pw1 + pr2 + pw2) f << "write 2 1\n";
        else f << "string\n";
    }
}

int main() {
    gen("file_single.txt", 3, 10, 5, 10, 5, 10, 20, 40);
    gen("file_t1.txt", 3, 10, 5, 10, 5, 10, 20, 40);
    gen("file_t2.txt", 3, 10, 5, 10, 5, 10, 20, 40);

    gen("file_a.txt", 3, 10, 10, 10, 10, 10, 10, 10);
    gen("file_b.txt", 3, 10, 10, 10, 10, 10, 10, 10);
    gen("file_c.txt", 3, 10, 10, 10, 10, 10, 10, 10);

    gen("wild.txt", 3, 1, 50, 40, 1, 5, 1, 2);

    return 0;
}
