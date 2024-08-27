#include<iostream>
#include<fstream>
#include"monhoc.h"
#include<iomanip>
#include<cmath>
using namespace std;

MonHoc::MonHoc(){}

MonHoc::MonHoc(double toan,double li,double hoa,double van,double anh,double tin,int id){
	this->toan=toan;
	this->li=li;
	this->hoa=hoa;
	this->van=van;
	this->anh=anh;
	this->tin=tin;
    this->id=id;
}

void MonHoc::nhapdiem(int x){
    // cout<<"Nhap id cua hoc sinh do: "; cin>>this->id;
	this->id=x;
	cout<<"Nhap diem toan: "; cin>>this->toan;
	cout<<"Nhap diem li: "; cin>>this->li;
	cout<<"Nhap diem hoa: "; cin>>this->hoa;
	cout<<"Nhap diem van: "; cin>>this->van;
	cout<<"Nhap diem anh: "; cin>>this->anh;
	cout<<"Nhap diem tin: "; cin>>this->tin;
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
int MonHoc::get_id(){
	return this->id;
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
void MonHoc::set_id(int id){
	this->id=id;
}

void MonHoc::set_diem_trung_binh(double diemtrungbinh){
	this->diemtrungbinh=diemtrungbinh;
}

void MonHoc::set_hoc_luc(string hocluc){
	this->hocluc=hocluc;
}

void MonHoc::xuatdiem(ofstream& fileout){
	fileout<<"toan:"<<this->toan<<endl;
	fileout<<"li:"<<this->li<<endl;
	fileout<<"hoa:"<<this->hoa<<endl;
	fileout<<"van:"<<this->van<<endl;
	fileout<<"anh:"<<this->anh<<endl;
	fileout<<"tin:"<<this->tin<<endl;
	double tb=round(get_diem_trung_binh()*10)/10;
	// double rounded_tb = round(tb * 10) / 10;
	set_diem_trung_binh(tb);
	fileout<<"diem trung binh:"<<setprecision(1) << fixed<<this->diemtrungbinh<<endl;
	string hl =get_hoc_luc();
	set_hoc_luc(hl);
	fileout<<"hoc luc:"<<this->hocluc<<endl;
}
void MonHoc::docFile_MonHoc(ifstream& filein){
    filein>>this->id;
	filein>>this->toan;
	filein>>this->li;
	filein>>this->hoa;
	filein>>this->van;
	filein>>this->anh;
	filein>>this->tin;
}
MonHoc::~MonHoc(){}