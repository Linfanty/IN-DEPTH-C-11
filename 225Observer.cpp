class NonCopyable {
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator = (const NonCopyable&) = delete;
};

#include <iostream>
#include <string>
#include <functional>
#include <map>
using namespace std;

template <typename Func>
class Event : NonCopyable {
public:
    Event() {}
    ~Event() {}
    int Connect (Func&& f) { return Assgin(f); }
    int Connect (const Func& f) { return Assgin(f); }
    void Disconnect (int key) { m_connections.erase(key); }

    template <typename... Args>
    void Notify(Args... args) {
        for(auto& it : m_connections)
            it.second(std::forward<Args>(args)...); /*****/
    }

private:
    template<typename F>
    int Assgin(F&& f) {
        int k = m_observerId++;

        m_connections.emplace(k, std::forward<F>(f));
        return k;
    }

    int m_observerId = 0;
    std::map<int, Func> m_connections;
};

struct stA {
    int a, b;
    void print(int a, int b) { cout << a << ", " << b << endl;}
};
void print(int a, int b) { cout << a << ", " << b << endl;}

int main() {
    Event< function<void(int, int)> > myevent;

    // 1 function
    auto key = myevent.Connect(print);

    // 2 lambda
    stA t;
    // auto lambdakey = myevent.Connect([&t](int a, int b) {t.a = a, t.b = b;});

    // 3 function
    auto f = bind(&stA::print, &t, placeholders::_1, placeholders::_2);
    myevent.Connect(f);


    int a = 1, b = 2;
    myevent.Notify(a, b);

    //myevent.Disconnect(key);
}
