#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
// 要计算的函数，这里使用简单的平方函数作为示例
int square(int x)
{
    return x * x;
}

// 线程函数，计算从 start 到 end 的结果并将结果保存到结果向量中
void compute_results(int start, int end, std::vector<int> &results, std::mutex &mtx)
{
    for (int i = start; i <= end; ++i)
    {
        int result = square(i);
        // 加锁，避免多个线程同时修改结果向量
        std::lock_guard<std::mutex> lock(mtx);
        results.push_back(result);
    }
}

void test_thread()
{
    // 设置计算范围和线程数量
    int start = 1;
    int end = 10;
    int num_threads = 4;

    // 结果向量和互斥量
    std::vector<int> results;
    std::mutex mtx;

    // 创建线程并启动
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i)
    {
        int thread_start = start + i * ((end - start + 1) / num_threads);
        int thread_end = thread_start + ((end - start + 1) / num_threads) - 1;
        threads.emplace_back(compute_results, thread_start, thread_end, std::ref(results), std::ref(mtx));
    }

    // 等待所有线程完成
    for (auto &thread : threads)
    {
        thread.join();
    }

    // 打印结果
    for (int i = 0; i < results.size(); ++i)
    {
        std::cout << "Result[" << i << "]: " << results[i] << std::endl;
    }
}

void test_multiprocess()
{
    // 设置计算范围和进程数量
    int start = 1;
    int end = 10;
    int num_processes = 4;

    // 父进程和子进程的结果向量
    std::vector<int> parent_results;
    std::vector<int> child_results(num_processes);

    // 创建多个子进程并启动
    for (int i = 0; i < num_processes; ++i)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            // 子进程中计算结果
            int process_start = start + i * ((end - start + 1) / num_processes);
            int process_end = process_start + ((end - start + 1) / num_processes) - 1;
            for (int j = process_start; j <= process_end; ++j)
            {
                child_results[i] += square(j);
            }
            // 子进程计算完成后退出
            exit(0);
        }
        else if (pid < 0)
        {
            // 失败处理
            std::cerr << "Fork failed!" << std::endl;
        }
    }

    // 等待所有子进程完成
    int status;
    while (wait(&status) > 0)
        ;

    // 将子进程的结果合并到父进程的结果向量中
    for (int result : child_results)
    {
        parent_results.push_back(result);
    }

    // 打印结果
    for (int i = 0; i < parent_results.size(); ++i)
    {
        std::cout << "Result[" << i << "]: " << parent_results[i] << std::endl;
    }
}