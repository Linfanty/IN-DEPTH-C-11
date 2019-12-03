#include<iostream>
#include<cxxabi.h>
using namespace std;

template <class T>
typename enable_if <is_arithmetic<T>::value, int>::type fool(T t) {
    cout << t << endl;
    return 0;
}

template <class T>
typename enable_if <!is_arithmetic<T>::value, int>::type fool(T &t) {
    cout << abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr) << endl;
    return 1;
}

int main() {
    cout << fool(123) << endl;
    cout << fool("string") << endl;
}
