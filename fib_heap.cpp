#include <cmath>
#include <algorithm>
#include <assert.h>

template <class T, class Compare>
fib_heap<T,Compare>::fib_heap() {
    size = 0;
    top = nullptr;
}

template <class T, class Compare>
typename fib_heap<T, Compare>::node* fib_heap<T, Compare>::push(const T elem) {
    fib_heap<T, Compare>::node *x = new fib_heap<T, Compare>::node();
    x->degree = 0;
    x->parent = nullptr;
    x->mark = false;
    x->key = elem;
    rootlist.insert(x);

    if(top == nullptr || higher_priority(elem, top->key)) {
        top = x;
    }

    size++;
    return x;
}

template <class T, class Compare>
T fib_heap<T, Compare>::peek() const{
    return top->key;
}

template <class T, class Compare>
T fib_heap<T, Compare>::pop() {
    node* z = top;
    if (z != nullptr) {
        for (node* child : z->child_list) {
            rootlist.insert(child);
            child->parent = nullptr;
        }
        rootlist.erase(z);
        if(rootlist.size() == 0)
            top = nullptr;
        else {
            top = *(rootlist.begin());
            consolidate();
        }
        size--;
        return z->key;
    }

    return T();
    
}

template <class T, class Compare>
void fib_heap<T,Compare>::decrease_key(node* n, const T new_key){
    assert(higher_priority(new_key, n->key));

    n->key = new_key;
    node* y = n->parent;

    if(y != nullptr && higher_priority(n->key, y->key)) {
        cut(n,y);
        cascading_cut(y);
    }

    if(higher_priority(n->key, top->key))
        top = n;
}

template <class T, class Compare>
void fib_heap<T,Compare>::delete_node(node* n, const T min_value_of_type){
    decrease_key(n, min_value_of_type);
    pop();
}

template <class T, class Compare>
void fib_heap<T, Compare>::consolidate()
{
    size_t max_degree = (size_t)(log(size) / log(1.62));
    std::vector<node *> a = std::vector<node *>(max_degree + 1, nullptr);

    for (node *root : rootlist)
    {
        node *x = root;
        size_t d = x->degree;

        while (a[d] != nullptr)
        {
            node *y = a[d];
            if (higher_priority(y->key, x->key))
                std::swap(x, y);

            // rootlist.erase(y);
            x->child_list.insert(y);
            y->parent = x;
            x->degree++;

            a[d] = nullptr;
            d++;
        }
        a[d] = x;
    }
    top = nullptr;
    rootlist.clear();
    for (size_t i = 0; i <= max_degree; i++)
    {
        if (a[i] != nullptr)
        {
            rootlist.insert(a[i]);
            if (top == nullptr || a[i]->key < top->key)
                top = a[i];
        }
    }
}

template <class T, class Compare>
void fib_heap<T, Compare>::cut(node *to_remove, node *parent) {
    parent->child_list.erase(to_remove);
    rootlist.insert(to_remove);
    to_remove->parent = nullptr;
    to_remove->mark = false;
}

template <class T, class Compare>
void fib_heap<T, Compare>::cascading_cut(node *n) {
    node* z = n->parent;
    if(z != nullptr) {
        if(n->mark) {
            cut(n, z);
            cascading_cut(z);
        }else {
            n->mark = true;
        }
    }
}