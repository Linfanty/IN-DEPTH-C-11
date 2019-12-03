#include<iostream>
#include <functional>
using std::cout;
using std::endl;

template <typename T>
struct function_traits;

template <typename Ret, typename... Args>
struct function_traits<Ret(Args...)> {
public:
    enum { arity = sizeof...(Args) };
    typedef Ret function_type(Args...);
    typedef Ret return_type;
    using stl_function_type = std::function<function_type>;
    typedef Ret(*pointer)(Args...);

    template<size_t I>
    struct args{
        static_assert(I < arity, "index is out of range, must less than size_of Args");
        using type = typename std::tuple_element<I, std::tuple<Args...> >::type;
    };
};

template<typename T>
void printType()
{
    cout << typeid(T).name() << endl;
}

int main() {
    int func(int a, std::string b);
    std::function<int(int)> f = [](int a) { return a; };
    //function_traits<>::arity;

    cout << function_traits<decltype(func)>::arity << endl;
    cout << typeid(function_traits<decltype(func)>::function_type).name() << endl;
    printType<function_traits<decltype(func)>::return_type>() ;
    printType<function_traits<decltype(func)>::stl_function_type>() ;
    printType<function_traits<decltype(func)>::pointer>() ;
}
