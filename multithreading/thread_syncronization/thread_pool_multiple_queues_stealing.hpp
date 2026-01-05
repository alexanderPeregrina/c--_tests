// Thread pool with multiple queues
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <mutex>
#include <functional>
#include <memory>
#include <atomic>
#include <random>
#include "concurrent_queue.hpp"

// Type aliases to simplify the code
// All the task functions will have this type
using Func = std::function<void()>;

// Alias for concurrent queue type
using Queue = concurrent_queue<Func>;

class thread_pool {
    // Random number engine
    std::mt19937 mt;
	// Each thread has its own queue of task functions
	std::unique_ptr<Queue []> work_queues;

    //array to keep track of queues lengths;
	//std::vector<size_t> queues_lengths;

    // mutex to lock access to queues_lengths
    //std::mutex mut;
	// Vector of thread objects which make up the pool
	std::vector<std::thread> threads;
	
	// Entry point function for the threads
	void worker(int idx);
	
	// The number of threads in the pool
	int thread_count;
	
	// Index into the vector of queues
	std::atomic<int> pos{0};

    int get_random();
	
  public:
	thread_pool();
	~thread_pool();
	
	// Add a task to the queue
	void submit(Func func);

    // Function to check whether all queues are empty
    bool all_tasks_finished();

};

#endif //THREAD_POOL_H