#include<iostream>
#include<fstream>
#include"diemmonhoc.h"
using namespace std;

MonHoc::MonHoc(){}

MonHoc::MonHoc(double toan,double li,double hoa,double van,double anh,double tin){
	this->toan=toan;
	this->li=li;
	this->hoa=hoa;
	this->van=van;
	this->anh=anh;
	this->tin=tin;
}

void MonHoc::nhapdiem(){ 
	cout<<"nhap diem toan: "; cin>>this->toan;
	cout<<"nhap diem li: "; cin>>this->li;
	cout<<"nhap diem hoa: "; cin>>this->hoa;
	cout<<"nhap diem van: "; cin>>this->van;
	cout<<"nhap diem anh: "; cin>>this->anh;
	cout<<"nhap diem tin: "; cin>>this->tin;
}

double MonHoc::get_toan(){
	return this->toan;
}

double MonHoc::get_li(){
	return this->li;
}

double MonHoc::get_hoa(){
	return this->hoa;
}

double MonHoc::get_van(){
	return this->van;
}

double MonHoc::get_anh(){
	return this->anh;
}

double MonHoc::get_tin(){
	return this->tin;
}

double MonHoc::get_diem_trung_binh(){
	return this->diemtrungbinh=(toan+li+hoa+van+anh+tin)/6;
}

string MonHoc::get_hoc_luc(){
	if(this->diemtrungbinh>=8)
		this->hocluc="Gioi";
	else if(this->diemtrungbinh>=6.5 && this->diemtrungbinh<8)
		this->hocluc="Kha";
	else if(this->diemtrungbinh>=5 && this->diemtrungbinh<6.5)
		this->hocluc="Trung Binh";
	else{
		this->hocluc="Yeu";
	}
	return this->hocluc;
}

void MonHoc::set_toan(double toan){
	this->toan=toan;
}

void MonHoc::set_li(double li){
	this->li=li;
}

void MonHoc::set_hoa(double hoa){
	this->hoa=hoa;
}

void MonHoc::set_van(double van){
	this->van=van;
}

void MonHoc::set_anh(double anh){
	this->anh=anh;
}

void MonHoc::set_tin(double tin){
	this->tin=tin;
}

void MonHoc::set_diem_trung_binh(double diemtrungbinh){
	this->diemtrungbinh=diemtrungbinh;
}

void MonHoc::set_hoc_luc(string hocluc){
	this->hocluc=hocluc;
}

void MonHoc::xuatdiem(){
	cout<<"toan:"<<this->toan<<endl;
	cout<<"li:"<<this->li<<endl;
	cout<<"hoa:"<<this->hoa<<endl;
	cout<<"van:"<<this->van<<endl;
	cout<<"anh:"<<this->anh<<endl;
	cout<<"tin:"<<this->tin<<endl;
	double tb=get_diem_trung_binh();
	set_diem_trung_binh(tb);
	cout<<"diem trung binh:"<<this->diemtrungbinh<<endl;
	string hl =get_hoc_luc();
	set_hoc_luc(hl);
	cout<<"hoc luc:"<<this->hocluc<<endl;
}
void MonHoc::docFile_MonHoc(ifstream& filein){
	filein>>this->toan;
	filein>>this->li;
	filein>>this->hoa;
	filein>>this->van;
	filein>>this->anh;
	filein>>this->tin;
}
MonHoc::~MonHoc(){}

