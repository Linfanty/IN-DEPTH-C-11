#include <iostream>
#include "StringRealize.h"
using std::cout;using std::cin;
using std::endl;

int main(int, char**) {
    StringRealize s = "145";
    s = s + "456";
    cin >> s;
    cout << s << endl; 
}
