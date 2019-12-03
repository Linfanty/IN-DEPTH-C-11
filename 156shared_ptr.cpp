#include <iostream>
#include <functional>
#include <memory>
using namespace std;
#define GUAND(p) std::shared_ptr<void> p##p(p, [](void*p) { GetHandle()->Release(p); } );
// how to realize make_unique
template <class T, class... Args> inline
typename enable_if <!is_array<T>::value, unique_ptr<T> >::type make_unique(Args&&... args)
{
    return unique_ptr<T> (new T(std::forward<Args>(args)...) );
}

template <class T> inline
typename enable_if <is_array<T>::value && extent<T>::value == 0, unique_ptr<T> >::type
make_unique(size_t size) {
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T> (new U[size]());
}

template <class T, class... Args>
typename enable_if < extent<T>::value != 0, void>::type make_unique(Args&&...) = delete;

// Dividing Line -------
struct A : public std::enable_shared_from_this<A> {
    shared_ptr<A> GetSelf() {
        return shared_from_this();
    }
    ~A() {
        cout << "A is deleted\n";
    }
};

int main() {
    shared_ptr<int> p(new int(1));
    shared_ptr<int> p2 = p;
    shared_ptr<int> ptr;

    ptr.reset(new int(1));

    if(ptr) cout << "ptr is not null\n";

    shared_ptr<int> sp = make_shared<int>(10);
    weak_ptr<int> wp(sp);

    cout << wp.use_count() << endl; // use count

    if(wp.expired())
        cout << "invalid \n";
    else {
        cout << "Effective\n";
        auto spt = wp.lock();
        cout << *spt << "\n";
    }


    shared_ptr<A> spy(new A);
    shared_ptr<A> spy2 = spy->GetSelf();
}

