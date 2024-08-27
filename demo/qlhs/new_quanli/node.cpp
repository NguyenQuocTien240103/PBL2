#include<iostream>
#include "node.h"

Node::Node(){}

Node::Node(HocSinh student, MonHoc subject){
	this->student=student;
	this->subject=subject;
	this->next=NULL;
}

Node::~Node(){}

