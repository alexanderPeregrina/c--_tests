// Thread pool with single queue
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <functional>
#include "concurrent_queue_cv.hpp"

// Type alias to simplify the code
// All the task functions will have this type
using Func = std::function<void()>;

class thread_pool {
	bool all_task_finished = false;
	// Queue of task functions
	concurrent_queue_cv<Func> work_queue;
	
	// Vector of thread objects which make up the pool
	std::vector<std::thread> threads;
	
	// Entry point function for the threads
	void worker();
	
	// The number of threads in the pool
	int thread_count;
public:
	thread_pool();
	~thread_pool();
	
	// Add a task to the queue
	void submit(Func func);
};

#endif //THREAD_POOL_H