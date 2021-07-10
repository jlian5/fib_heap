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

        void decrease_key(node* n, const T new_key);
        void delete_node(node* n, const T min_value_of_type);

    private:
        size_t size;
        node* top;
        std::unordered_multiset<node*> rootlist;
        Compare higher_priority;

        void consolidate();
        void cut(node* to_remove, node* parent);
        void cascading_cut(node* n);

};

#include "fib_heap.cpp"