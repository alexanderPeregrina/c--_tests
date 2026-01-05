#include <thread>
#include <mutex>

int x{0};

std::mutex m1;


void func() {
    std::lock_guard lck_guard(m1);
    while (x == 0) {
        x = 1 - x;
    }
}

int main()
{
    std::thread thr1{ func };
    std::thread thr2{ func };
	
	thr1.join();
	thr2.join();
}

