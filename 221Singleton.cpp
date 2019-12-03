#include <chrono>
#include <iostream>
using namespace std;

struct A{
    A(const string&) { cout << "Lvalue" << endl; }
    A(string&& x) { cout << "Rvalue" << endl; };
};

struct B{
    B(const string&) { cout << "Lvalue" << endl; }
    B(string&& x) { cout << "Rvalue" << endl; };
};

struct C{
    C(int x, double y) {}
    void Fun() { cout << "test" << endl;}
};

template<typename T>
class Singleton
{
public:
    template<typename... Args>
    static T* Instance(Args... args) {
        if( m_instance == nullptr)
            m_instance = new T(std::forward<Args>(args)... );
    }

    static T* GetInstance() {
        if(m_instance == nullptr)
            throw std::logic_error("not init");
        return m_instance;
    }

    static void DestroyInstance() {
        delete m_instance;
        m_instance = nullptr;
    }


private:
    Singleton(void);
    virtual ~ Singleton(void);
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);
private:
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = nullptr;

int main() {
    string str = "bb";
    Singleton<A>::Instance(str);
    Singleton<B>::Instance(std::move(str));
    Singleton<C>::Instance(1, 3.14);
    Singleton<C>::GetInstance()->Fun();

    Singleton<C>::DestroyInstance();
}
/*
140.82.113.4 github.com
199.232.5.194 github.global.ssl.fastly.net
140.82.113.10 codeload.github.com
*/
