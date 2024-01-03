#include<iostream>
#include<fstream>
#include "hocsinh.h"
using namespace std;

HocSinh::HocSinh(){}

HocSinh::HocSinh(string ten,string ngaysinh,int id){
	this->ten=ten;
	this->ngaysinh=ngaysinh;
	this->id=id;
}

string HocSinh::get_ten(){
	return this->ten;
}

string HocSinh::get_ngaysinh(){
	return this->ngaysinh;
}

int HocSinh::get_id(){
	return this->id;
}
void HocSinh::nhapthongtin(int x){
	this->id=x;
	cin.ignore();
	cout<<"nhap ten hoc sinh: "; getline(cin,this->ten);
	cout<<"nhap ngay sinh cua hoc sinh: "; cin>>this->ngaysinh;
	
}
void HocSinh::set_id(int id){
	this->id=id;
}
void HocSinh::set_ngaysinh(string ngaysinh){
	this->ngaysinh=ngaysinh;
}
void HocSinh::set_ten(string ten){
	this->ten=ten;
}
void HocSinh::xuat_thong_tin(){
	cout<<"id:"<<this->id<<endl;
	cout<<"ten:"<<this->ten<<endl;
	cout<<"ngaysinh:"<<this->ngaysinh<<endl;
}

void HocSinh::docFile_hocsinh(ifstream& filein){
    // filein>>this->id;
	// filein.ignore();
	// getline(filein,this->ten);
	// filein>>this->ngaysinh;
	filein >> this->id;
   	getline(filein, this->ten,',');
	getline(filein, this->ngaysinh);
}
HocSinh::~HocSinh(){}
