#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T value) {
    unsigned int cpu_cores = std::thread::hardware_concurrency();

}

int main() {
    std::vector<long> v(100000);
    std::iota(std::begin(v), std::end(v), 0);
    long res = std::accumulate(std::begin(v), std::end(v), 0);
    long parallel_res = parallel_accumulate(std::begin(v), std::end(v), 0);
}