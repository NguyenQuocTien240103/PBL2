#include<iostream>
#include<fstream>
#include "thongtinhocsinh.h"
using namespace std;

HocSinh::HocSinh(){}

HocSinh::HocSinh(string ten,string ngaysinh,string lop){
	this->ten=ten;
	this->ngaysinh=ngaysinh;
	this->lop=lop;
}

string HocSinh::get_ten(){
	return this->ten;
}

string HocSinh::get_ngaysinh(){
	return this->ngaysinh;
}

string HocSinh::get_lop(){
	return this->lop;
}
void HocSinh::nhapthongtin(){
	cin.ignore();
	cout<<"nhap ten hoc sinh: "; getline(cin,this->ten);
	cout<<"nhap ngay sinh cua hoc sinh: "; cin>>this->ngaysinh;
	cout<<"nhap lop cua hoc sinh do: ";cin>>this->lop;
}
void HocSinh::set_lop(string lop){
	this->lop=lop;
}
void HocSinh::set_ngaysinh(string ngaysinh){
	this->ngaysinh=ngaysinh;
}
void HocSinh::set_ten(string ten){
	this->ten=ten;
}
void HocSinh::xuat_thong_tin(){
	cout<<"ten:"<<this->ten<<endl;
	cout<<"ngaysinh:"<<this->ngaysinh<<endl;
	cout<<"lop:"<<this->lop<<endl;
}

void HocSinh::docFile_hocsinh(ifstream& filein){
	filein.ignore();
	getline(filein,this->ten);
	filein>>this->ngaysinh;
	filein>>this->lop;
}
HocSinh::~HocSinh(){}
