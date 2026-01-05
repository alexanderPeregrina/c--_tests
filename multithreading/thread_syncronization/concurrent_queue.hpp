// Simple concurrent queue implementation
// pop() busy waits when the queue is empty
#ifndef CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_H

#include <queue>
#include <mutex>
#include <thread>

using namespace std::literals;

template <class T>
class concurrent_queue {
	std::mutex mut;
	std::timed_mutex t_mut;
	std::queue<T> que;
	int max{50};
public:
	concurrent_queue() = default;
	concurrent_queue(int max) : max(max) {};
	
	void push(T value) {
		std::unique_lock<std::mutex> uniq_lck(mut);
		
		while (que. size() > max) {
			uniq_lck.unlock();
			std::this_thread::sleep_for(50ms);
			uniq_lck.lock();
		}
		
		que.push(value);
	}

	void pop(T& value) {
		std::unique_lock<std::mutex> uniq_lck(mut);
		
		while (que.empty()) {
			uniq_lck.unlock();
			std::this_thread::sleep_for(50ms);
			uniq_lck.lock();
		}
		
		value = que.front();
		que.pop();
	}
	
	bool try_push(T value) {
	  // Lock the mutex with a time-out
	  std::unique_lock<std::timed_mutex> lck_guard(t_mut, std::defer_lock);
	  
	  // Cannot lock - return immediately
	  if (!lck_guard.try_lock_for(1ms)  || que.size() > max) {
	  	return false;
	  }
	  
	  // Locked - add the element to the queue
	  que.push(value);
	  
	  return true;
	}

	bool try_pop(T& value) {
		// Lock the mutex with a time-out
		std::unique_lock<std::timed_mutex> lck_guard(t_mut, std::defer_lock);
		
		// Cannot lock - return immediately
		if (!lck_guard.try_lock_for(1ms) || que.empty()) {
			return false;
		}
		
		// Locked - remove front element from the queue
		value = que.front();
		que.pop();
		
		return true;
	}

	size_t get_queue_length()
	{
	  std::unique_lock<std::mutex> uniq_lck(mut);
	  return que.size();
	}
};

#endif //CONCURRENT_QUEUE_H