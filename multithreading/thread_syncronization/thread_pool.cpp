// Thread pool with single queue
#include <iostream>
#include "thread_pool.hpp"

// Constructor
thread_pool::thread_pool() {
	thread_count = std::thread::hardware_concurrency() - 1;
	std::cout << "Creating a thread pool with " << thread_count << " threads\n";

	// Start the threads
    // When entry point function is a member function you need to pass a pointer 
    // to the member function and a pointer to the actual object
	for (int i = 0; i < thread_count; ++i)
		threads.push_back(std::thread{&thread_pool::worker, this});
}

// Destructor
thread_pool::~thread_pool() {
	// Wait for the threads to finish
	for (auto& thr: threads) {
		thr.join();
	}
}

// Entry point function for the threads
void thread_pool::worker() {
	while (!all_task_finished) {
		Func task;
		
		// Take a task function off the queue
		work_queue.pop(task);
		
		// Invoke it
		task();

        if (work_queue.get_queue_length() == 0)
          all_task_finished = true;
	}
}

// Add a task to the queue
void thread_pool::submit(Func func) {
	work_queue.push(func);
}
