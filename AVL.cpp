#include <bits/stdc++.h>
#include "Student.cpp"
using namespace std;

struct node{
    node* parent;
    node* left;
    node* right;
    int info;
    int height;
    int balanceFactor;
    node(){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        info = 0;
        balanceFactor = 0;
    }
};

class AVL{
    private:
        node* root;
    public:
        AVL(){
            root = nullptr;
        }
        int getBalanceFactor(node* nod){
            int right = 0, left = 0;
            if(nod->right != nullptr)
                right = nod->right->height;
            if(nod->left != nullptr)
                left = nod->left->height;
            return left - right;
        }

        int getNodeHeight(node* nod){
            int left = 0, right = 0;
            if(nod->left != nullptr)
                left = nod->left->height;
            if(nod->right != nullptr)
                right = nod->right->height;
            return max(left, right);
        }

        void insert( int key)
        {
            node* val = new node();
            val->info = key;
            if (root == nullptr) {
                root = val;
                return;
            }
            node* prev = NULL;
            node* temp = root;
            while (temp != nullptr) {
                temp->height++;
                if (temp->info > key) {
                    prev = temp;
                    temp = temp->left;
                }
                else if (temp->info < key) {
                    prev = temp;
                    temp = temp->right;
                }
            }
            if (prev->info > key){
                prev->left = val;
            }
            else{
                prev->right = val;
            }
        }

        void printRoot(){
            cout << root->info << ' '; 
        }
};

// int main(){
//     AVL test;
//     test.insert(1);
//     test.insert(2);
//     test.insert(3);
//     test.printRoot();
// }