#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) { }
    void reset() {m_begin = high_resolution_clock::now(); }

    template<typename Duration = milliseconds>
    int64_t elapsed() const {
        return duration_cast<Duration>(high_resolution_clock::now() - m_begin).count();
    }

    int64_t elapsed_micro() { return elapsed<microseconds>(); }
    int64_t elapsed_nano() { return elapsed<nanoseconds>(); }
    int64_t elapsed_second() { return elapsed<seconds>(); }
    int64_t elapsed_minutes() { return elapsed<minutes>(); }

private:
    time_point<high_resolution_clock> m_begin;
};

void fun() { cout << "hello" << endl;}

int main() {
    Timer t;
    fun();
    cout << t.elapsed() << endl;
    cout << t.elapsed_micro() << endl;
    cout << t.elapsed_nano() << endl;
    cout << t.elapsed_second() << endl;
    cout << t.elapsed_minutes() << endl;
}

