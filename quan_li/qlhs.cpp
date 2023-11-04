#include<iostream>
#include<fstream>
#include "qlhs.h"
using namespace std;

QuanLi::QuanLi(){
	this->Head=NULL;
}

int QuanLi::dem_so_luong_hoc_sinh(){
	Node*temp=Head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

void QuanLi::them_hoc_sinh_vao_dau(HocSinh student,MonHoc subject){
	Node * new_student=new Node(student,subject);
	if(Head==NULL)
		Head=new_student;
	else{
		new_student->next=Head;
		Head=new_student;
	}
}

void QuanLi::them_hoc_sinh_vao_cuoi(HocSinh student,MonHoc subject){
	Node*new_student=new Node(student,subject);
	if(Head==NULL)
		Head=new_student;
	else{
		Node*temp=Head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_student;
	}
}

void QuanLi::them_hoc_sinh_vao_vi_tri_bat_ki(HocSinh student,MonHoc subject,int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1 || pos>k+1)
		cout<<"vi tri chen khong hop le";
	else if(pos==1){
		them_hoc_sinh_vao_dau(student,subject);
	}
	else{
		Node* temp=Head;
		Node* new_student=new Node(student,subject);
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
		}
		new_student->next=temp->next;
		temp->next=new_student;
	}
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_dau_tien(){
	if(Head==NULL)
		cout<<"danh sach rong";
	else{
		Node*temp=Head;
		Head=Head->next;
		delete temp;
	}
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_cuoi_cung(){
	if(Head==NULL)
		cout<<"danh sach rong";
	Node*temp=Head;
	Node*current=NULL;
	while(temp->next!=NULL){
		current=temp;
		temp=temp->next;
	}
	current->next=NULL;
	delete temp;
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_bat_ki(int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1||pos>k){
		cout<<"vi tri xoa khong hop le";
	}
	else if(pos==1){
		xoa_hoc_sinh_o_vi_tri_dau_tien();
	}
	else{
		Node*temp=Head;
		Node*current=NULL;
		for(int i=1;i<pos;i++){
			current=temp;
			temp=temp->next;
		}
		current->next=temp->next;
		delete temp;
	}
}

void QuanLi::sua_diem_cho_hoc_sinh(int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1||pos>k){
		cout<<"vi tri can sua diem khong ton tai"<<endl;
	}
	else{
		Node*temp=Head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		int n;
		cout<<"1.sua diem toan"<<endl;
		cout<<"2.sua diem li"<<endl;
		cout<<"3.sua diem hoa"<<endl;
		cout<<"4.sua diem van"<<endl;
		cout<<"5.sua diem anh"<<endl;
		cout<<"6.sua diem tin"<<endl;
		cout<<"nhap TH can sua:"; cin>>n;
		if(n==1){
			double a;
			cout<<"so diem toan can sua la:"; cin>>a;
			temp->subject.set_toan(a);
		}
		if(n==2){
			double a;
			cout<<"so diem li can sua la:"; cin>>a;
			temp->subject.set_li(a);
		}
		if(n==3){
			double a;
			cout<<"so diem hoa can sua la:"; cin>>a;
			temp->subject.set_hoa(a);
		}
		if(n==4){
			double a;
			cout<<"so diem van can sua la:"; cin>>a;
			temp->subject.set_van(a);
		}
		if(n==5){
			double a;
			cout<<"so diem anh can sua la:"; cin>>a;
			temp->subject.set_anh(a);
		}
		if(n==6){
			double a;
			cout<<"so diem tin can sua la:"; cin>>a;
			temp->subject.set_tin(a);
		}
	}
}

void QuanLi::tim_kiem_hoc_sinh(string ten){
	int count=0;
	Node*temp=Head;
	while(temp!=NULL){
		if(temp->student.get_ten().compare(ten) == 0){
			count++; // danh dau 
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
		}
		temp=temp->next;

	}
	if(count==0){
		cout<<"khong co hoc sinh nao giong ten ban da nhap!!!"<<endl;
		return;
	}
}

void QuanLi::HienThiDanhSach(){
	Node *temp=Head;
	if(temp==NULL)
		cout<<"danh sach rong"<<endl;
	else{
		cout<<"danh sach hoc sinh"<<endl;
		while(temp!=NULL){
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
			temp=temp->next;
		}
	}
}
void QuanLi::sap_xep_diem(){
	Node *temp=Head;
	Node *current=NULL;
	while(temp!=NULL){
		current=temp;
		while(current!=NULL){
			if(temp->subject.get_diem_trung_binh() >= current->subject.get_diem_trung_binh()){
				HocSinh a= temp->student;
				temp->student=current->student;
				current->student=a;
				MonHoc b= temp->subject;
				temp->subject=current->subject;
				current->subject=b;
			}
			current=current->next;
		}
		temp=temp->next;	
	}
}
QuanLi::~QuanLi(){
	Node *temp=Head;
	while(temp!=NULL){
		Node*current=temp->next;
		delete temp;
		temp=current;
	}
	Head=NULL;
}

