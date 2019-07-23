#include <thread>
#include <string>
#include <functional>
#include <atomic>
#include <iostream>

using namespace std;

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        if(state != 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state++;
    }

    void second(function<void()> printSecond) {
        while(state != 1) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state++;
    }

    void third(function<void()> printThird) {
        while(state != 2) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        state++;
    }

private:
    std::atomic<int> state{0};

};

int main()
{
    
}

