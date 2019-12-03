/*#include <iostream>
/*
int main(int, char**) {
    std::cout << "Hello, world!\n";
}
*/

#include <iostream>
#include "vector.h"
using std::cout;
using std::endl;
using stl::Vector;

int main() {
    Vector<int> v(3);
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);
    v.push_back(600);
    
    for(Vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << (*i) << endl;
    }
/*
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    cout << endl << (*v.begin()) << endl;
    return 0;
*/

}
// http://www.hahack.com/codes/cmake/