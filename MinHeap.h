//
// Created by Ismail Magdy on 14/05/2023.
//
#ifndef HEAP_MIN_HEAP_H
#define HEAP_MIN_HEAP_H

#include <iostream>
#include <vector>
#include <deque>

class MinHeap {
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

int MinHeap::size() const {
    return this->tree.size();
}
bool MinHeap::isEmpty() const {
    return this->tree.empty();
}
Student MinHeap::top()const{
    if(this->isEmpty())
        throw ("MaxHeap is Empty");
    return this->tree.front();
}
void MinHeap::push(Student element) {
    this->tree.push_back(element);
    trickleUp(this->tree.size()-1);
}
void MinHeap::trickleUp(int i) {
    if(i == 0 || this->tree[i].GPA > this->tree[(i-1)/2].GPA)
        return;
    std::swap(this->tree[i],this->tree[(i-1)/2]);
    trickleUp((i-1)/2);
}
void MinHeap::pop(){
    std::swap(this->tree.front(),this->tree.back());
    this->tree.pop_back();
    trickleDown(0);
}

void MinHeap::trickleDown(int i) {
    if(2*i+1 >= this->tree.size())return;
    int dist;
    if(2*i+1 < this->tree.size()) dist = 2*i+1;
    if(2*i+2 < this->tree.size() && this->tree[2*i+1].GPA < this->tree[2*i+2].GPA)dist = 2*i+1;
    else if(2*i+2 < this->tree.size() )dist = 2*i+2;
    if(this->tree[dist].GPA < this->tree[i].GPA){
        std::swap(this->tree[i],this->tree[dist]);
        trickleDown(dist);
    }
}

void MinHeap::print() const {
    MinHeap temp = *this;
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


#endif
