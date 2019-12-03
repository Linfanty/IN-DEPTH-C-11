#include<iostream>
#include<cxxabi.h>
using namespace std;

/*
template <typename... Args>
struct sum;

template <typename First, typename... Rest>
struct sum <First, Rest...> : std::integral_constant<int, sum<First>::value
+ sum<Rest...>::value>
{

} ;

template <typename Last>
struct sum <Last> : std::integral_constant<int, sizeof(Last)>
{

};

int main() {
    cout << sum<int, double, short>::value << endl;
}
*/

template<int...>
struct IndexSeq{};

template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

template<int.. Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSeq<Indexes...> type;
};

int main()
{
    using T = MakeIndexes<3>::type;
    cout << typeid(T).name() << endl;
}
