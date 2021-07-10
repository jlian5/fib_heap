#pragma once
#include <vector>
#include <set>
#include <unordered_set>
#include <functional>

template <class T, class Compare = std::less<T> >
class fib_heap {
    public:
        class node{
            public:
                node *parent;
                std::unordered_multiset<node *> child_list;

                T key;
                size_t degree;
                bool mark;
        };

        fib_heap();
        node* push(const T elem);
        T pop();
        T peek() const;

        void decrease_key(node* n);
        void delete_node(node* n);

    private:
        size_t size;
        node* top;
        std::unordered_multiset<node*> rootlist;
        Compare higher_priority;

        void consolidate();

};

#include "fib_heap.cpp"