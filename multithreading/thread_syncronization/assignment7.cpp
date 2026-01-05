#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;
using namespace std::chrono;

// Global variables
mutex mut;
bool write_process_completed = false;
string sdata{"Empty"};

// Waiting thread
void reader() {
	unique_lock<mutex> guard(mut);                  // Acquire lock
    cout << "Executing read process\n";
	while(!write_process_completed)
    {
      guard.unlock();
      this_thread::sleep_for(10ms);
      guard.lock();
    }                  
	cout << "Data is " << sdata << endl;           // Wake up and use the new value
}

// Modyifing thread
void writer() {
	cout << "Writing data..." << endl;
	{
		lock_guard<std::mutex> lg(mut);            // Acquire lock
		std::this_thread::sleep_for(2s);           // Pretend to be busy...
		sdata = "Populated";                       // Modify the data
        write_process_completed = true;
	}
}

int main() {
	cout << "Data is " << sdata << endl;
	thread read{reader};
    thread write{writer};
	/*
	// If the writer thread finishes before the reader thread starts, the notification is lost
	thread write{writer};
	std::this_thread::sleep_for(500ms);
	thread read{reader};
	*/
	write.join();
	read.join();
}