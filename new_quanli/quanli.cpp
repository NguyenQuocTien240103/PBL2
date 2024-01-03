#include<iostream>
#include<fstream>
#include "quanli.h"
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

void QuanLi::xoa_hoc_sinh_o_vi_tri_bat_ki(int id){
	int count=1;
	Node*temp=Head;
	Node*current=NULL;
	while(1){
		if(temp->student.get_id()==id){
			break;
		}
		else{
			current=temp;
			temp=temp->next;
			count++;
		}
	}
	if(count==1){
		Head=Head->next;
	}
	else{
		current->next=temp->next;
	}
	delete temp;
}

void QuanLi::sua_diem_cho_hoc_sinh(int id){
		Node*temp=Head;
		while(temp!=NULL){
			if(temp->student.get_id()==id){
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(temp==NULL){
			cout<<"ID khong ton tai"<<endl;
		}
		else{
		int n;
		cout<<endl;
		cout<<"\t\t\t1.Sua diem toan"<<endl;
		cout<<"\t\t\t2.Sua diem li"<<endl;
		cout<<"\t\t\t3.Sua diem hoa"<<endl;
		cout<<"\t\t\t4.Sua diem van"<<endl;
		cout<<"\t\t\t5.Sua diem anh"<<endl;
		cout<<"\t\t\t6.Sua diem tin"<<endl;
		cout<<"\t\t\tNhap TH can sua:"; cin>>n;
		cout<<endl;
		if(n==1){
			double a;
			cout<<"So diem toan can sua la:"; cin>>a;
			temp->subject.set_toan(a);
		}
		if(n==2){
			double a;
			cout<<"So diem li can sua la:"; cin>>a;
			temp->subject.set_li(a);
		}
		if(n==3){
			double a;
			cout<<"So diem hoa can sua la:"; cin>>a;
			temp->subject.set_hoa(a);
		}
		if(n==4){
			double a;
			cout<<"So diem van can sua la:"; cin>>a;
			temp->subject.set_van(a);
		}
		if(n==5){
			double a;
			cout<<"So diem anh can sua la:"; cin>>a;
			temp->subject.set_anh(a);
		}
		if(n==6){
			double a;
			cout<<"So diem tin can sua la:"; cin>>a;
			temp->subject.set_tin(a);
		}
	}
}


void QuanLi::tim_kiem_hoc_sinh(int  id){
	int count=0;
	Node*temp=Head;
	while(temp!=NULL){
		if(temp->student.get_id() == id){
			count++; // danh dau 
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
		}
		temp=temp->next;

	}
	if(count==0){
		cout<<"Khong co hoc sinh nao giong ID ban da nhap!!!"<<endl;
		return;
	}
	cout<<endl;
}

void QuanLi::HienThiDanhSach(){
	int count=0;
	Node *temp=Head;
	if(temp==NULL){
		cout<<"\t\t\t\t\t\t*****DANH SACH HOC SINH*****"<<endl;
		cout<<"DANH SACH RONG"<<endl;
		cout<<endl;
	
	}
	else{
		cout<<"\t\t\t\t\t\t*****DANH SACH HOC SINH*****"<<endl;
		while(temp!=NULL){
			cout<<"STT:"<<++count<<endl;
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
			temp=temp->next;
			cout<<endl;
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

