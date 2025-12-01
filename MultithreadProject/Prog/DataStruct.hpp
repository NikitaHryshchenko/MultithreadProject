#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <string>
#include <mutex>
#include <sstream>
#include <vector>

class DataStruct {
public:
    DataStruct(int n) : fields(n, 0), locks(n) {}

    int get(int i) {
        std::lock_guard<std::mutex> g(locks[i]);
        return fields[i];
    }

    void set(int i, int v) {
        std::lock_guard<std::mutex> g(locks[i]);
        fields[i] = v;
    }

    operator std::string() {
        std::lock_guard<std::mutex> g(global);
        std::stringstream ss;
        for (int v : fields) ss << v << " ";
        return ss.str();
    }

private:
    std::vector<int> fields;
    std::vector<std::mutex> locks;
    std::mutex global;
};

#endif
