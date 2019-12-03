#include<iostream>
#include<cxxabi.h>
using namespace std;

template <class... T>
void print_num(T... args) {
    cout << sizeof...(args) << endl;
}

void print() {
    cout << "empty" << endl;
}

template <class T, class... Args>
void print(T head, Args... rest) {
    cout << "HEAD: " << head << endl;
    print(rest...);
}

template <typename T>
void print_args(T t) {
    cout << t << endl;
}

template <typename... Args>
void print_dot(Args... args) {
    initializer_list<int> {
        (
         [&]{ cout << args << endl; }()
        // print_args(args)
        , 0)
        ...
        };
}

int main() {
    print_num(1);
    print_num(1, 2);
    print_num(1, 2, 3);
    print(11, 22, 33);
    print4(4, 5, 6);
}
