#include <bits\stdc++.h>
#include "Student.cpp"
using namespace std;

struct node{
    node* parent;
    node* left;
    node* right;
    Student data;
    node(){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        data = Student();
    }
};

class BST{
    private:
        node* root;
        map<string, int> departments;
        int size;
        node* find(int id){
            node* curr = root;
            while (curr != nullptr){
                if(curr->data.id == id)
                    break;
                if(curr->data.id > id)
                    curr = curr -> left;
                else
                    curr = curr -> right;
            }
            return curr;
        }
    public:
        BST(){
            root = nullptr;
            size = 0;
        }

        void insert(Student value){
            node* temp = new node();
            temp->data = value;
            if(root == nullptr){
                root = temp;
                size++;
                departments[value.dep]++;
                cout << "The student is added.\n";
                return;
            }

            node* curr = root;
            node* parent = nullptr;
            while (curr != nullptr){
                parent = curr;

                if(value > curr->data)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
            if(value > parent->data)
                parent->right = temp;
            else
                parent->left = temp;
            temp->parent = parent;
            departments[value.dep]++;
            size++;
            cout << "The student is added.\n";
        }

        void print() {
            cout << "\nPrint " << size << " Students\n";
            print(root);
            cout << "Students per Departments:\n";
            for(auto i : departments)
                cout << i.first << ' ' << i.second << " Students\n";
            cout << '\n';
        }

        void print(node* curr){
            if(curr == nullptr)
                return;
            print(curr->left);
            cout << curr -> data << '\n';
            print(curr->right);
        }

        bool search(int id){
            node* temp = find(id);
            if(temp == nullptr){
                cout << "Student not found\n\n";
                return 0;
            }
            cout << "Student found\n";
            cout << temp->data;
            return 1;
        }

        void remove(int id){
            if(!search(id))
                return;
            node* temp = find(id);
            departments[temp->data.dep]--;
            // no childs case
            if(temp->left == nullptr && temp->right == nullptr){
                if(temp->parent != nullptr)
                    if(temp->parent->left == temp)
                        temp->parent->left = nullptr;
                    else
                        temp->parent->right = nullptr;
            }

            // one child only case in the right
            else if(temp->left == nullptr){
                if(temp == root){
                    root->right->parent = nullptr;
                    root = root->right;
                    temp->right = nullptr;
                }
                else{
                    temp -> right -> parent = temp -> parent;
                    if(temp->parent->right == temp)
                        temp -> parent -> right = temp -> right;
                    else
                        temp -> parent -> left = temp -> right;
                    temp->parent = nullptr;
                    temp->right = nullptr;
                }
            }

            // one child only case in the left
            else if(temp -> right == nullptr){
                if(temp == root){
                    root->left->parent = nullptr;
                    root = root->left;
                    temp->left = nullptr;
                }
                else{
                    temp -> left -> parent = temp -> parent;
                    if(temp->parent->right == temp)
                        temp -> parent -> right = temp -> left;
                    else
                        temp -> parent -> left = temp -> left;
                    temp->parent = nullptr;
                    temp->left = nullptr;
                }
            }

            // two childs case
            else{
                node* curr = temp->right;
                node* nod = nullptr;
                while (curr != nullptr){
                    nod = curr;
                    curr = curr -> left;
                }
                if(nod->right != nullptr){
                    nod->right->parent = nod -> parent;
                    if(nod->parent->right == nod)
                        nod -> parent -> right = nod -> right;
                    else
                        nod->parent->left = nod -> right;
                    nod->parent = nullptr;
                    nod->right = nullptr;
                }
                else{
                    if(nod->parent->right == nod)
                        nod->parent->right = nullptr;
                    else
                        nod->parent->left = nullptr;
                }
                temp -> data = nod -> data;
                nod = nullptr;
                cout << "Student has been removed\n\n";
                size--;
                return;
            }
            cout << "Student has been removed\n\n";
            temp = nullptr;
            size--;
        }
};

// int main(){
//     BST test;
//     test.insert(Student(10, "ahmed taha10", 3.10, "css2"));
//     test.insert(Student(4, "Ahmed taha4", 3.14, "cs4"));
//     test.insert(Student(3, "Ahmed taha3", 3.13, "cs3"));
//     test.insert(Student(1, "Ahmed taha1", 3.11, "cs1"));
//     test.insert(Student(6, "Ahmed taha6", 3.12, "cs2"));
//     test.insert(Student(8, "Ahmed taha8", 3.12, "cs2"));
//     test.insert(Student(5, "Ahmed taha5", 3.12, "cs2"));

//     // test.print();
//     test.search(3);
//     // test.remove(2);
//     test.remove(1);
//     // test.remove(4);
//     test.print();
// }