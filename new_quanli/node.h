#include<iostream>
#include "hocsinh.cpp"
#include "monhoc.cpp"
using namespace std;
class Node{
	public:
		HocSinh student;
		MonHoc	subject;
		Node *next;
	public:
		Node();
		Node(HocSinh,MonHoc);
		~Node();
};

