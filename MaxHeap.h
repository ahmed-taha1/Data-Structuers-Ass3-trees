//
// Created by Ismail Magdy on 14/05/2023.
//
#ifndef HEAP_MAX_HEAP_H
#define HEAP_MAX_HEAP_H

#include <iostream>
#include <vector>
#include <deque>
#include "AVL.h"

class MaxHeap {
public:
    int size()const;
    bool isEmpty()const;
    Student top()const;
    void push(Student element);
    void pop();
    void print()const;
private:
    std::vector<Student>tree;
    void trickleUp(int i);
    void trickleDown(int i);
};

int MaxHeap::size() const {
    return this->tree.size();
}
bool MaxHeap::isEmpty() const {
    return this->tree.empty();
}
Student MaxHeap::top()const{
    if(this->isEmpty())
        throw ("MaxHeap is Empty");
    return this->tree.front();
}
void MaxHeap::push(Student element) {
    this->tree.push_back(element);
    trickleUp(this->tree.size()-1);
}
void MaxHeap::trickleUp(int i) {
    if(i == 0 || this->tree[i].GPA < this->tree[(i-1)/2].GPA)
        return;
    std::swap(this->tree[i],this->tree[(i-1)/2]);
    trickleUp((i-1)/2);
}
void MaxHeap::pop(){
    std::swap(this->tree.front(),this->tree.back());
    this->tree.pop_back();
    trickleDown(0);
}

void MaxHeap::trickleDown(int i) {
    if(2*i+1 >= this->tree.size())return;
    int dist;
    if(2*i+1 < this->tree.size()) dist = 2*i+1;
    if(2*i+2 < this->tree.size() && this->tree[2*i+1].GPA > this->tree[2*i+2].GPA)dist = 2*i+1;
    else if(2*i+2 < this->tree.size() )dist = 2*i+2;
    if(this->tree[dist].GPA > this->tree[i].GPA){
        std::swap(this->tree[i],this->tree[dist]);
        trickleDown(dist);
    }
}

void MaxHeap::print() const {
    MaxHeap temp = *this;
   cout<<"Printing "<<this->size()<<" Student(s):\n";
    deque<Student>students;
    while (!temp.isEmpty()){
        students.push_back(temp.top());
        temp.pop();
    }
    for (int i = 0; i < students.size(); ++i) {
        cout<<"[";
        cout<<students[i].id<<", ";
        cout<<students[i].name<<", ";
        cout<<students[i].GPA<<", ";
        cout<<students[i].dep<<"]\n";
    }
}


#endif //HEAP_MAX_HEAP_H
