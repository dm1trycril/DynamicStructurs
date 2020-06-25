
#include <iostream>

struct Node {
    int data;
    Node* next = 0;
};

class Queue {
private:
    int __size = 0;
    Node* pbeg = 0;
    Node* pend = 0;
public:
    void push(int d) {
        Node* node = new Node();
        node->data = d;
        if (pend) {
            pend->next = node;
        }
        else {
            pbeg = node;
        }
        pend = node;
        ++__size;
    }
    void pop() {
        Node* node = new Node();
        node = pbeg;
        pbeg = pbeg->next;
        --__size;
        if (__size == 0)
            pend = 0;
        delete node;
    }
    int front() {
        return pbeg->data;
    }
    void clear() {
        while (__size > 0) {
            pop();
        }
    }
    int size() {
        return __size;
    }
    bool empty() {
        return __size == 0;
    }
};

int main()
{
    std::cout << "ok";
    return 0;
}