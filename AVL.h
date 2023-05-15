#include "BST.h"
using namespace std;

class AVLTree {
    private:
        Node* root;
        int size;
        map<string, int> departments;

        int getHeight(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return node->height;
        }

        int getBalanceFactor(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return getHeight(node->left) - getHeight(node->right);
        }

        void updateHeight(Node* node) {
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        }

        void leftRotation(Node*& node) {
            // store the right node
            Node* Rnode = node->right;
            // store the right left node
            Node* RLnode = Rnode->left;
            // make the left of the right node equal the parent node
            Rnode->left = node;
            // make the right node of the parent equal to the right left node
            node->right = RLnode;
            // recalculate the height
            updateHeight(node);
            updateHeight(Rnode);
            // replace the right node to it's place
            node = Rnode;
        }

        void rightRotation(Node*& node) {
            // store the left node
            Node* Lnode = node->left;
            // store the left right node
            Node* LRnode = Lnode->right;
            // make the right of the left node equal the parent node
            Lnode->right = node;
            // make the left node of the parent equal to the left right node
            node->left = LRnode;
            // recalculate the height
            updateHeight(node);
            updateHeight(Lnode);
            // replace the left node to it's place
            node = Lnode;
        }

        void balance(Node*& node) {
            int balanceFactor = getBalanceFactor(node);

            // left case
            if (balanceFactor > 1) {
                // left right violation
                if (getBalanceFactor(node->left) < 0)
                    leftRotation(node->left);
                // left left
                rightRotation(node);
            }
            
            // right case
            else if (balanceFactor < -1) {
                // right left
                if (getBalanceFactor(node->right) > 0)
                    rightRotation(node->right);
                // right right
                leftRotation(node);
            }

            // update height of the node (will be called from leafs to the root)
            updateHeight(node);
        }

        void insert(Student value, Node*& node) {
            // base case reach empty node
            if (node == nullptr){
                node = new Node(value);
                size++;
                departments[value.dep]++;
                cout << "student has been added!\n";
                return;
            }
            // if value is less than the value in the current node go left
            if (value < node->value)
                insert(value, node->left);
            // else go right
            else
                insert(value, node->right);
            // balance and keep balance while back track until reach the root
            balance(node);
        }

        void print(Node* node) {
            // base case
            if (node == nullptr) {
                return;
            }
            print(node->left);
            cout << node->value << '\n';
            print(node->right);
        }

        void remove(int id, Node*& node) {
            // if node not found
            if (node == nullptr)
                return;
            // if value less than the value in the current node (move left)
            if (id < node->value.id)
                remove(id, node->left);
            // if the value greate thant the value in the current node (move right)
            else if (id > node->value.id)
                remove(id, node->right);

            // if found
            else{
                // Case 1: Node has no children
                if (node->left == nullptr && node->right == nullptr) {
                    delete node;
                    node = nullptr;
                    // this return will backtrack
                    return;
                }

                // Case 2: Node has one child
                if (node->left == nullptr) {
                    // swap thier places
                    swap(node, node->right);
                    // remove it after swapping
                    delete node->right;
                    node->right = nullptr;
                    return;
                }
                else if (node->right == nullptr) {
                    // swap thier places
                    swap(node, node->left);
                    // remove it after swapping
                    delete node->left;
                    node->left = nullptr;
                    return;
                }

                // Case 3: Node has two children
                // find successor
                Node* successor = node->right;
                while (successor->left != nullptr)
                    successor = successor->left;
                // put a copy from the successor in my place
                node->value = successor->value;
                // remove the successor (we must remove it by function calling to update height from depth and balance from depth)
                remove(successor->value.id, node->right);
            }
            balance(node);
        }

        Node* find(int id, Node*& curr){
            if(curr == nullptr || curr->value.id == id)
                return curr;
            if(curr->value.id > id)
                return find(id, curr->left);
            else
                return find(id, curr->right);
        }

    public:
        AVLTree() {
            root = nullptr;
            size = 0;
        }

        void insert(Student value) {
            insert(value, root);
        }

        void print() {
            cout << "\nPrint " << size << " Students\n";
            print(root);
            cout << "Students per Departments:\n";
            for(auto i : departments)
                cout << i.first << ' ' << i.second << " Students\n";
            cout << '\n';
        }

        void remove(int id) {
            Node* temp = find(id, root);
            if(search(id)){
                remove(id, root);
                size--;
                departments[temp->value.dep]--;
                cout << "student has been deleted!\n";
            }
        }

        bool search(int id){
            Node* temp = find(id, root);
            if(temp == nullptr){
                cout << "Student not found\n\n";
                return 0;
            }
            cout << "Student found\n";
            cout << temp->value;
            return 1;
        }
};

// int main(){
//     AVLTree test;
//     test.insert(Student(10, "ahmed taha10", 3.10, "css2"));
//     test.insert(Student(4, "Ahmed taha4", 3.14, "cs4"));
//     test.insert(Student(3, "Ahmed taha3", 3.13, "cs3"));
//     test.insert(Student(1, "Ahmed taha1", 3.11, "cs1"));
//     test.insert(Student(6, "Ahmed taha6", 3.12, "cs2"));
//     test.insert(Student(8, "Ahmed taha8", 3.12, "cs2"));
//     test.insert(Student(5, "Ahmed taha5", 3.12, "cs2"));

//     // test.print();
//     // test.search(3);
//     test.remove(10);
//     // test.remove(4);
//     test.print();
// }
