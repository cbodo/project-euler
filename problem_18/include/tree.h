#include "node.h"

class Tree {
    public:
        Tree() : root(nullptr) {}
        ~Tree() {}

        Node* get_root() { return root; }
        void insert(int value);
        bool search(int value);
        void remove(int value);
    private:
        Node* root;
};