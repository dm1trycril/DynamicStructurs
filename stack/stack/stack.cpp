#include <iostream>
#include <string.h>

struct Node {
    int data;
    Node* prev;
};

class Stack {
private:
    Node* top = 0;
    int __size = 0;
public:
    void push(int d) {
        Node* node = new Node();
        node->data = d;
        node->prev = top;
        top = node;
        __size++;
    }
    void pop() {
        Node* node = top;
        top = top->prev;
        delete node;
        --__size;
    }
    int size() {
        return __size;
    }
    bool empty() {
        return __size == 0;
    }
    void clear() {
        while (__size > 0) {
            pop();
        }
    }
    int back() {
        return top->data;
    }
};

int main()
{
    Stack st;

    std::string s;
    std::cin >> s;
    while (s != "exit") {
        if (s == "push") {
            int n;
            std::cin >> n;
            st.push(n);
        }
        else if (s == "pop") {
            if (st.empty()) {
                std::cout << "error\n";
            }
            else {
                std::cout << st.back() << '\n';
                st.pop();
            }
        }
        else if (s == "back") {
            if (st.empty()) {
                std::cout << "error\n";
            }
            else {
                std::cout << st.back() << '\n';
            }
        }
        else if (s == "size") {
            std::cout << st.size() << '\n';
        }
        else if (s == "clear") {
            st.clear();
            std::cout << "ok\n";
        }
        std::cin >> s;
    }
    std::cout << "bye" << std::endl;
    return 0;
}