#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

struct Student{
    int id;
    string name;
    float GPA;
    string dep;

    Student(int ID, string nam, float gpa, string Dep){
        id = ID;
        name = nam;
        GPA = gpa;
        dep = Dep;
    }

    Student(){
        id = 0;
        name = "";
        GPA = 0.0;
        dep = "null";
    }

    bool operator>(Student s2){
        return (this->id > s2.id);
    }

    bool operator<(Student s2){
        return (this->id < s2.id);
    }

    friend ostream& operator<<(ostream& out, const Student& stu){
        out << "[" << stu.id << ", " << stu.name << ", " << stu.GPA << ", " << stu.dep << "]\n";
        return out;
    }
    void operator=(Student s2){
        this->id = s2.id;
        this->name = s2.name;
        this->GPA = s2.GPA;
        this->dep = s2.dep;
    }
};