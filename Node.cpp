#include <bits\stdc++.h>
#include "student.cpp"


struct Node{
    Node* parent;
    Node* left;
    Node* right;
    Student value;
    int height;
    Node(Student st){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        height = 1;
        value = st;
    }
    Node(){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        height = 1;
        value = Student();
    }
};