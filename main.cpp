#include "fib_heap.h"
#include <iostream>
#include <map>
using namespace std;
int main() {
    fib_heap<int> h;
    map<int, fib_heap<int>::node*> m;
    for(size_t i = 10; i >=0; i--) {
        m[i] = h.push(i);
    }
    cout<<h.peek();
    return 0;
}