# fib_heap

C++ implementation of the fibonacci heap described in CLRS book from MIT Press.
Difference is that I tried using stl unordered_sets as childlists / rootlist to make the code shorter.

Amortize runtimes for c++ unordered_sets:

insert: O(1)
erase: O(1)
clear: O(n) where n is the size of the set\

Amortize runtimes for fibonacci set:

push: O(1)
pop: O(log N)
peek: O(1)
decrease_key: O(1)
delete: O(log N)

beware of constant factors, experience suggests that fibonacci heap can sometimes perform worse than binary heaps because of the large constant factors.
