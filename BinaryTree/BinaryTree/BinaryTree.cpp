
#include <iostream>

struct  Node
{
    int m_data;
    Node* m_left;
    Node* m_right;

    Node(int d) {
        m_data = d;
        m_left = nullptr;
        m_right = nullptr;
    }
};

class BinaryTree {
private:
    Node* m_root = nullptr;
    int m_size = 0;

    bool Inner_find(int t, Node* current) {
        if (current->m_data == t) {
            return true;
        }
        else if (current->m_data > t) {
            return Inner_find(t, current->m_left);
        }
        else if (current->m_data < t) {
            return Inner_find(t, current->m_right);
        }
        else { //if (current == nullptr)
            return false;
        }
    }

    Node* Inner_insert(int t, Node* current) {
        if (current == 0) {
            return new Node(t);
            ++m_size;
        }
        else if (current->m_data > t) {
            current->m_left = Inner_insert(t, current->m_left);
        }            
        else if (current->m_data < t) {
            current->m_right = Inner_insert(t, current->m_right);
        }
        return current;
    }

public:
    BinaryTree() {}

    bool Find(int t) {
        return Inner_find(t, m_root);
    }

    void Insert(int t) {
        m_root = Inner_insert(t, m_root);
    }

    int Size() {
        return m_size;
    }
};

int main()
{
    return 0;
}