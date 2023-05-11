#include <bits/stdc++.h>
#include <unistd.h>
#include "maxHeap.cpp"
using namespace std;


vector<Student> students;

void BST_1();
void AVL_2();
void MIN_HEAP();
void MAX_HEAP();


int main(){
    string fileName = "input.in";
    ifstream file(fileName);

    int n;  file >> n;
    while (n--){
        int id;     file >> id;
        file.ignore();
        string name;    getline(file, name, '\n');
        float gpa;      file >> gpa;
        string dep;     file >> dep;
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
        case 2:
            AVL_2();
            break;
        // case 3:
        //     MIN_HEAP();
        //     break;
        // case 3:
        //     MAX_HEAP();
        //     break;
        default:
            cout << "wrong input please try again\n";
            break;
        }
    }
}

void BST_1(){
    int id;  string name, dep, enter;  float gpa;
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
        case 5:
            break;
        default:
            cout << "wrong input please try again\n";
            break;
        }
        cout << "please wait...\n";
        sleep(5);
    }
}

void AVL_2(){
    int id;  string name, dep, enter;  float gpa;
    AVLTree univeristy;
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
        case 5:
            break;
        default:
            cout << "wrong input please try again\n";
            break;
        }
        cout << "please wait...\n";
        sleep(5);
    }
}