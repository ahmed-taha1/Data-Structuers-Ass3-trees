#include <bits/stdc++.h>
#include "Node.cpp"
#include "student.cpp"
using namespace std;
void heapify(vector<Student> &students,int n,int i)
{
 int l=2*i+1;
 int r=2*i+2;
 int max=i;
 if(l<n && students[l]>students[max])
 {
     max=l;
 }
 if(r<n && students[r]>students[max])
 {
     max=r;
 }

 if(max!=i)
 {
     swap(students[max],students[max]);
     heapify(students,n,max);
 }
}

void buildHeap(vector<Student> &students,int n)
{
    for (int i = n/2 - 1; i >=0 ; i--) {
        heapify(students,n,i);
    }
}

void MAX_HEAP(vector<Student> &students,int n)
{
    buildHeap(students,n);
    for (int i = n-1; i >=0 ; i--) {
        swap(students[0],students[i]);
        heapify(students,i,0);
    }
}

