#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>      // std::accumulate
#include <functional>   // std::mem_fn

using namespace std;

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result) {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);

    if (!length) {
        return init;
    }

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();

    unsigned long const num_threads =
        std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i])
        );
        block_start = block_end;
    }

    // 最后一块在主线程中处理
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    std::vector<int> v(10000, 1);  // 10000 个 1

    int total = parallel_accumulate(v.begin(), v.end(), 0); //& 编译器能根据参数自动推导出模板类型，就不需要显式写出来

    std::cout << "Total sum = " << total << std::endl;  // 应该输出 10000
    return 0;
}