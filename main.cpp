#include "fib_heap.h"
#include <iostream>
#include <map>
using namespace std;
int main() {
    fib_heap<int> h;
    map<int, fib_heap<int>::node*> m;
    for(int i = 100; i >=0; i--) {
        m[i] = h.push(i);
    }
    cout<<h.peek()<<endl;

    h.decrease_key(m[100], -1);
    cout<<h.peek()<<endl;

    return 0;
}