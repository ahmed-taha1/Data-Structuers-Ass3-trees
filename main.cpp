#include <bits/stdc++.h>
#include <unistd.h>
#include "BST.cpp"
#include "AVL.cpp"
using namespace std;


vector<Student> students;

void BST_1(){
    int id;  string name, dep;  float gpa;
    BST univeristy;
    for(auto student : students)
        univeristy.insert(student);
    system("cls");
    int choose = -1;
    while (choose != 5){
        cout << "Choose one of the following options:\n";
        cout << "\t1. Add student\n";
        cout << "\t2. Remove student\n";
        cout << "\t3. Search student\n";
        cout << "\t4. Print All (sorted by id)\n";
        cout << "\t5. Return to main menu\n";
        cout << "\t>> ";    cin >> choose;

        switch (choose){
        case 1:
            cout << "id: ";     cin >> id;
            cin.ignore();
            cout << "Name: ";   getline(cin, name, '\n');
            cout << "GPA: ";    cin >> gpa;
            cout << "Department: "; cin >> dep;
            univeristy.insert( Student(id, name, gpa, dep) );
            break;
        case 2:
            cout << "id: ";     cin >> id;
            univeristy.remove(id);
            break;
        case 3:
            cout << "id: ";     cin >> id;
            univeristy.search(id);
            break;
        case 4:
            univeristy.print();
            break;
        default:
            cout << "wrong input please try again\n";
            break;
        }
        sleep(2);
    }
}

int main(){
    int n;  cin >> n;
    while (n--){
        int id;     cin >> id;
        cin.ignore();
        string name;    getline(cin, name, '\n');
        float gpa;      cin >> gpa;
        string dep;     cin >> dep;
        Student s(id, name, gpa, dep);
        students.push_back(s);
    }
    
    int choose = -1;
    while (choose != 5){
        cout << "Choose Data Structure:\n";
        cout << "\t1. BST\n";
        cout << "\t2. AVL\n";
        cout << "\t3. Min Heap\n";
        cout << "\t4. Max Heap\n";
        cout << "\t5. Exit Program\n";
        cout << "\t>> ";
        cin >> choose;

        switch (choose){
        case 1:
            BST_1();
            break;
        // case 2:
        //     AVL_2();
        //     break;
        default:
            cout << "wrong input please try again\n";
            break;
        }
    }
}