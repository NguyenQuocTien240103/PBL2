#include<iostream>
#include"thongtinhocsinh.cpp"
#include"diemmonhoc.cpp"
#include"node.cpp"
#include"qlhs.cpp"
using namespace std;
int main(){
	QuanLi a;
	HocSinh student;
	MonHoc subject;
	int n;
	do{
		cout<<"0.them file vao danh sach"<<endl;
		cout<<"1.them hoc sinh vao dau danh sach"<<endl;
		cout<<"2.them hoc sinh vao cuoi danh sach"<<endl;
		cout<<"3.them hoc sinh vao vi tri bat ki"<<endl;
		cout<<"4.xoa hoc sinh o dau danh sach"<<endl;
		cout<<"5.xoa hoc sinh o cuoi danh sach"<<endl;
		cout<<"6.xoa hoc sinh o vi tri bat ki"<<endl;
		cout<<"7.sua diem cho hoc sinh"<<endl;
		cout<<"8.tim kiem hoc sinh"<<endl;
		cout<<"9.hien thi danh sach hoc sinh"<<endl;
		cout<<"nhap TH:";cin>>n;
		if(n==0){
			int so_luong;
			ifstream filein1,filein2,filein3;
			filein1.open("thongtinhocsinh.txt");
			filein2.open("diemmonhoc.txt");
			filein3.open("so_luong.txt");
			filein3>>so_luong;
			for(int i=0;i<so_luong;i++){
			student.docFile_hocsinh(filein1);
			subject.docFile_MonHoc(filein2);
			a.them_hoc_sinh_vao_cuoi(student,subject);
			}
		}
		else if(n==1){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_dau(student,subject);
		}
		else if(n==2){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_cuoi(student,subject);
		}
		else if(n==3){
			int pos;
			cout<<"nhap vi tri can them hoc sinh:"; cin>>pos;
			cout<<"nhap thong tin va` diem cua hoc sinh do:"<<endl;
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
		}
		else if(n==4){
			a.xoa_hoc_sinh_o_vi_tri_dau_tien();
		}
		else if(n==5){
			a.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
		}
		else if(n==6){
			int pos;
			cout<<"nhap vi tri can xoa:"; cin>>pos;
			a.xoa_hoc_sinh_o_vi_tri_bat_ki(pos);
		}
		else if(n==7){
			int pos;
			cout<<"nhap vi tri can sua diem cho hoc sinh:";cin>>pos;
			a.sua_diem_cho_hoc_sinh(pos);
		}
		else if(n==8){
			string name;
			cout<<"tim kiem hoc sinh bang cach loc ten"<<endl;
			cout<<"nhap ten hoc sinh ma` ban muon tim` kiem:";
			cin.ignore();
			getline(cin,name);
			cout<<"thong tin hoc sinh ma` ban tim kiem la:"<<endl;
			a.tim_kiem_hoc_sinh(name);
		}
		else if(n==9){
			a.HienThiDanhSach();
		}
		
	}while(n==0||n==1||n==2||n==3||n==4||n==5||n==6||n==7||n==8||n==9);
}
