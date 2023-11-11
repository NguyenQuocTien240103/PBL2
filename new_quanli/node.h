#include<iostream>
// #include "hocsinh.h"
// #include "monhoc.h"
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

